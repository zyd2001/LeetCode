// C backtrack

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void subset(int * nums, int numsSize, int i, int *** ret_back, int * sub, int * sub_back, int ** rcz_back, int sub_size)
{
    memcpy(**ret_back, sub, sub_size * sizeof(int));
    (*ret_back)++;
    if (i == numsSize)
        return;
    int temp = nums[i] + 1;
    for (int j = i; j < numsSize; j++)
    {
        if (temp != nums[j])
        {
            *sub_back = nums[j];
            sub_back++;
            **rcz_back = sub_size + 1; 
            (*rcz_back)++;
            subset(nums, numsSize, j + 1, ret_back, sub, sub_back, rcz_back, sub_size + 1);
            temp = nums[j];
            sub_back--;
        }
    }
}

int cmp(const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b );
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    *returnSize = 1 << numsSize;
    int ** ret = malloc(sizeof(int*) * *returnSize);
    for (int i = 0; i < *returnSize; i++)
        ret[i] = malloc(sizeof(int) * numsSize);
    int * sub = malloc(sizeof(int) * numsSize);
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);
    **returnColumnSizes = 0;
    int * r = *returnColumnSizes + 1;
    int ** t = ret;
    subset(nums, numsSize, 0, &t, sub, sub, &r, 0);
    *returnSize = r - *returnColumnSizes;
    return ret;
}

