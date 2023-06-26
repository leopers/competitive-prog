#include"stdc++.h"
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

class SecondThenMinusFirstOrdering{
    public:
    bool operator() (ii a, ii b) {
        ii newA = {a.second, -a.first};
        ii newB = {b.second, -b.first};

        // default ordering of pair is first then second
        return newA < newB;
    }
};

class Lowest{
    map<string, int> lowests;

    public:
    Lowest(map<string, int>& lowests) : lowests(lowests){}

    bool operator() (string a, string b) {
        return lowests.at(a) > lowests.at(b);
    }
};

int main()
{
    vector<ii> pairs{ {1, 3}, {-5, 4}, {12, 1}, {0, 1}, {2, -2}, {1, 23}, {12, 3} };

    cout << "Unordered:" << endl;
    for(auto [first, second] : pairs)
        cout << first << " " << second << endl;
    cout << endl;

    sort(pairs.begin(), pairs.end());
    cout << "Default ordering:" << endl;
    for(auto [first, second] : pairs)
        cout << first << " " << second << endl;
    cout << endl;

    sort(pairs.begin(), pairs.end(), SecondThenMinusFirstOrdering());
    cout << "Custom ordering with functor:" << endl;
    for(auto [first, second] : pairs)
        cout << first << " " << second << endl;
    cout << endl;

    sort(pairs.begin(), pairs.end(), [](ii a, ii b){
        // Minus first then second
        ii newA = {-a.first, a.second};
        ii newB = {-b.first, b.second};
        return newA < newB;
    });
    cout << "Custom ordering with lambda function:" << endl;
    for(auto [first, second] : pairs)
        cout << first << " " << second << endl;
    cout << endl;

    // Now we are going to pass other parameters to the sort methods
    vector<string> names = {"Joe", "Spira", "Masterchef", "Gandhi", "Bob", "Alice"};
    map<string, int> grades;
    grades["Joe"] = 8;
    grades["Spira"] = 4;
    grades["Masterchef"] = 6;
    grades["Gandhi"] = 7;
    grades["Bob"] = 2;
    grades["Alice"] = 9;

    sort(names.begin(), names.end(), [grades](string a, string b){
        return grades.at(a) < grades.at(b);
    });
    cout << "Names ordered by ascending grades using lambda" << endl;
    for(auto name : names)
        cout << name << endl;
    cout << endl;

    sort(names.begin(), names.end(), Lowest(grades));
    cout << "Names ordered by descending grades using functor" << endl;
    for(auto name : names)
        cout << name << endl;
    cout << endl;

    return 0;
}