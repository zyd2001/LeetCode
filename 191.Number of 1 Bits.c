int hammingWeight(uint32_t n) 
{
    int i = 0;
    while (n > 0)
    {
        i += n & 1;
        n >>= 1;
    }
    return i;
}