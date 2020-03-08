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

