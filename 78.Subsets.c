// C bit manipulation

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 1 << numsSize;
    int ** ret = malloc(sizeof(int*) * *returnSize);
    *returnColumnSizes = malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++)
    {
        int temp = i;
        // (*returnColumnSizes)[i] = 0;
        // for (int j = 0; j < numsSize; j++)
        // {
        //     if (temp & 1)
        //         (*returnColumnSizes)[i]++;
        //     temp >>= 1;
        // }
        // temp = i;
        // ret[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
        // for (int j = 0, k = 0; j < numsSize; j++)
        // {
        //     if (temp & 1)
        //     {
        //         ret[i][k] = nums[j];
        //         k++;
        //     }
        //     temp >>= 1;
        // }
        (*returnColumnSizes)[i] = 0;
        ret[i] = malloc(sizeof(int) * numsSize);
        for (int j = 0, k = 0; j < numsSize; j++)
        {
            if (temp & 1)
            {
                ret[i][k] = nums[j];
                k++;
                (*returnColumnSizes)[i]++;
            }
            temp >>= 1;
        }
    }
    return ret;
}
