#include "stdc++.h"
using namespace std;
typedef vector<int> vi;

class UnionFind
{
private:
    vi p, rank, setSize; // vi p is the key part
    int numSets;

public:
    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N;          // optional feature
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    int numDisjointSets() { return numSets; }            // optional

    int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

    void unionSet(int i, int j)
    {
        if (isSameSet(i, j))
            return;                         // i and j are in same set
        int x = findSet(i), y = findSet(j); // find both rep items
        if (rank[x] > rank[y])
            swap(x, y); // keep x 'shorter' than y
        p[x] = y;       // set x under y
        if (rank[x] == rank[y])
            ++rank[y];            // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        --numSets;                // a union reduces numSets
    }
};

int main()
{
    UnionFind sets(7);

    cout << sets.isSameSet(0, 4) << endl;
    sets.unionSet(0, 4);
    cout << sets.isSameSet(0, 4) << endl;

    sets.unionSet(0,1);
    sets.unionSet(4,6);
    cout << sets.isSameSet(1, 6) << endl;

    sets.unionSet(2,3);
    sets.unionSet(1,2);
    cout << sets.isSameSet(1,2) << endl;

    return 0;
}