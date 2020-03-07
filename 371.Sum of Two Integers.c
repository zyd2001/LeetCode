int getSum(int a, int b)
{
    int res = 0;
    uint mask = 1, x, y;
    uint carry = 0;
    for (int i = 0; i < 32; i++)
    {
        x = a & mask;
        y = b & mask;
        res |= x ^ y ^ carry;
        carry = (x & y) | (x & carry) | (y & carry);
        carry <<= 1;
        mask <<= 1;
    }
    return res;
}