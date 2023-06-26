#include "stdc++.h"
using namespace std;
#define LSOne(S) ((S) & -(S)) // the key operation
typedef long long ll;         // for extra flexibility
typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree
{
private:
    vll ft; // internal FeenwickTree is an array; index 0 is not used

public:
    FenwickTree(int m) { ft.assign(m + 1, 0); } // create an empty FT

    void build(const vll &freq)
    {
        int m = freq.size() - 1; // note freq[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i)
        {                                  // O(m)
            ft[i] += freq[i];                 // add this value
            if (i + LSOne(i) <= m)         // i has parent
                ft[i + LSOne(i)] += ft[i]; // add to that parent
        }
    }

    FenwickTree(const vll &freq) { build(freq); } // create FT based on f

    FenwickTree(int m, const vi &vec)
    { // create FT based on vec
        vll freq(m + 1, 0);
        for (int i = 0; i < vec.size(); ++i) // do the conversion first
            ++freq[vec[i]];                  // in O(n)
        build(freq);                         // in O(m)
    }

    ll rsq(int j)
    { // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    void update(int i, ll value)
    {
        for (; i < ft.size(); i += LSOne(i))
            ft[i] += value;
    }

    int select(ll k)
    { // O(log m)
        int p = 1;
        while (p * 2 < ft.size())
            p *= 2;
        int i = 0;
        while (p)
        {
            if (k > ft[i + p])
            {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

int main()
{
    // first index must always be 0
    vll frequencyTable{0, 3, 1, 2, 2, 0, 9, 0, 7, 11, 5, 0};
    for(auto frequency : frequencyTable)
        cout << frequency << " ";
    cout << endl;

    FenwickTree fenwickTree(frequencyTable);

    int a, b; cin >> a >> b;

    cout << fenwickTree.rsq(a, b) << endl;

    return 0;
}