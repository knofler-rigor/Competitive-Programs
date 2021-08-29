class Solution:
    def twoEggDrop(self, n: int) -> int:
        return int((-1+sqrt(8*n))/2) + 1 
