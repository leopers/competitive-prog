class SegmentTree:
    def __init__(self, listVals, operation) -> None:
        self.A = listVals
        self.n = len(listVals)
        self.st = [None for i in range(4*self.n)]
        self.Op = operation
        self._build(1, 0, self.n-1)

    def RQ(self, i, j):
        return self._RQ(1, 0, self.n-1, i, j)

    def _conquer(self, a, b):
        if a is None:
            return b
        elif b is None:
            return a
        return self.Op(a, b)

    def _l(self, p):
        return p << 1

    def _r(self, p):
        return (p << 1) + 1

    def _build(self, p, L, R):
        if L == R:
            self.st[p] = self.A[L]
        else:
            m = (L+R) // 2
            self._build(self._l(p), L, m)
            self._build(self._r(p), m+1, R)
            self.st[p] = self._conquer(
                self.st[self._l(p)],
                self.st[self._r(p)]
            )

    def _RQ(self, p, L, R, i, j):
        if i > j:
            return None
        if i <= L and R <= j:
            return self.st[p]
        m = (L+R) // 2
        return self._conquer(
            self._RQ(self._l(p), L, m, i, min(m, j)),
            self._RQ(self._r(p), m+1, R, max(i, m+1), j)
        )

words = ["Hello", "World", "my", "name", "is", "Joe"]
numbers = [3, 1, 2, 2, 0, 9, 0, 7, 11, 5, 0]
segmentTree = SegmentTree(words, lambda a, b : a + " " + b)
print(segmentTree.RQ(2, 5))