class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        if (a % 1337 == 0):
            return 0
        return pow(a, reduce(lambda x, y: x * 10 + y, b), 1337)