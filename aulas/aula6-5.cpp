#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

template<typename T>
class SegmentTree
{
    private:
    int n;
    vi A, st;

    T conquerObj;

    int conquer(int a, int b){
        if (a == -1)
            return b; // corner case
        if (b == -1)
            return a;
        return conquerObj(a, b);
    }

    int l(int p) { return p << 1; }       // go to left child
    int r(int p) { return (p << 1) + 1; } // go to right child

    void build(int p, int L, int R)
    { // O(n)
        if (L == R)
            st[p] = A[L]; // base case
        else
        {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    int RQ(int p, int L, int R, int i, int j)
    {                       // O(log n)
        if (i > j)
            return -1; // infeasible
        if (i <= L && R <= j)
            return st[p]; // found the segment
        int m = (L + R) / 2;
        return conquer(RQ(l(p), L, m, i, min(m, j)),
                       RQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    public:
    SegmentTree(int sz, T conquerObj) : n(sz), st(4 * n), conquerObj(conquerObj) {}

    SegmentTree(const vi &initialA, T conquerObj) : SegmentTree(initialA.size(), conquerObj)
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    int RQ(int i, int j) { return RQ(1, 0, n - 1, i, j); }
};


int main()
{
    vi vec{3, 1, 2, 2, 0, 9, 0, 7, 11, 5, 0};
    SegmentTree maxSegmentTree(vec, [](int a, int b)
    {
        return max(a, b);
    });

    SegmentTree minSegmentTree(vec, [](int a, int b)
    {
        return min(a, b);
    });

    SegmentTree sumSegmentTree(vec, [](int a, int b)
    {
        return a+b;
    });

    int a, b; cin >> a >> b;

    cout << maxSegmentTree.RQ(a, b) << endl;
    cout << minSegmentTree.RQ(a, b) << endl;
    cout << sumSegmentTree.RQ(a, b) << endl;

    return 0;
}