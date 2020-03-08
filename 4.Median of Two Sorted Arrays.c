#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int len = nums1Size + nums2Size;
    if (nums1Size > nums2Size)
    {
        nums1Size = nums1Size - nums2Size;
        nums2Size = nums2Size + nums1Size;
        nums1Size = nums2Size - nums1Size;
        int * temp;
        temp = nums1;
        nums1 = nums2;
        nums2 = temp;
    }
    if (len == 1)
        return *nums2;
    int i_min = 0, i_max = nums1Size;
    int i, j;
    int right, left;
    while (i_min <= i_max)
    {
        i = (i_min + i_max) / 2;
        j = (len + 1) / 2 - i;
        if (i > 0 && nums1[i - 1] > nums2[j])
            i_max = i - 1;
        else if (i < nums1Size && nums2[j - 1] > nums1[i])
            i_min = i + 1;
        else
        {
            if (i <= 0)
                left = nums2[j - 1];
            else if (j <= 0)
                left = nums1[i - 1];
            else
                left = max(nums1[i - 1], nums2[j - 1]);
            
            if (i >= nums1Size)
                right = nums2[j];
            else if (j >= nums2Size)
                right = nums1[i];
            else
                right = min(nums1[i], nums2[j]);
            
            if (len % 2 == 1)
                return left;
            
            return ((double) right + left) / 2;
        }
    }
    return 0;
}

double findMedianSortedArrays2(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int tol = nums1Size + nums2Size;
    double * rec = malloc(sizeof(double) * tol);
    int i = 0, j = 0, k = 0;
    
    while(i<nums1Size && j<nums2Size && k <= tol / 2){
        if(nums1[i] < nums2[j]){
            rec[k] = nums1[i];
            i++;
        }
        else{
            rec[k] = nums2[j];
            j++;
        }
        k++;
    }
    while(i<nums1Size && k <= tol / 2){
        rec[k] = nums1[i];
        i++;
        k++;
    }
    while(j<nums2Size && k <= tol / 2){
        rec[k] = nums2[j];
        j++;
        k++;
    }
    k--;
    return tol % 2 ? rec[k] : (rec[k] + rec[k-1]) / 2;
}

int cmp(const void *a, const void *b)
{
    return *((int*) a) - *((int*) b);
}

int main()
{
    int *a, *b;
    int len_a = 10000000, len_b = 7000000;
    a = malloc(sizeof(int) * len_a);
    b = malloc(sizeof(int) * len_b);
    srand(time(NULL));
    for (int i = 0; i < len_a; i++)
        a[i] = rand();
    for (int i = 0; i < len_b; i++)
        b[i] = rand();
    qsort(a, len_a, sizeof(int), cmp);
    qsort(b, len_b, sizeof(int), cmp);
    clock_t t; 
    t = clock(); 
    double med = findMedianSortedArrays(a, len_a, b, len_b);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("1 took %f seconds to execute \n", time_taken); 
    t = clock(); 
    double med2 = findMedianSortedArrays2(a, len_a, b, len_b);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    printf("2 took %f seconds to execute \n", time_taken); 
    printf("%f %f\n", med, med2);
}