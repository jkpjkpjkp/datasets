#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<string> split(string s, char ch = ',') {
    vector<string> ret;
    string tmp;
    for (char c : s) 
        if (c == ch) {
            ret.push_back(tmp); tmp = ""; }
        else
            tmp.push_back(c);
    ret.push_back(tmp);
    return ret;
}

bool _cmp(const string a, const string b) {
    for (int i = 0; i < a.length(); i ++) if (a[i] != b[i])
        return a[i] < b[i];
}
bool operator < (const string a, const string b) {
    return a.length() != b.length() ? a.length() < b.length() : _cmp(a, b);
}
int digit_cnt(uint x) {
    return x < 10 ? 1 : digit_cnt(x / 10) + 1;
}

template<class T>
inline bool chkmin(T &x, T y) { return y < x ? (x=y, true) : false; }
template<class T>
inline bool chkmax(T &x, T y) { return x < y ? (x=y, true) : false; }

uint n;

int main(int argc, char ** argv) {
    if (argc >= 2) freopen(argv[1], "r", stdin);
    if (argc >= 3) freopen(argv[2], "w", stdout);

    string s;
    cin >> s;
    vector<string> schema = split(s);
    n = schema.size();

    unordered_set<string> st[n];
    while (cin >> s && s.length()) {
        vector<string> v = split(s);
        assert(v.size() == n);
        for (uint i = 0; i < n; i ++)
            st[i].insert(v[i]);
    }



    cout << "name,count,                     min,max" << '\n';
    for (uint i = 0; i < n; i ++) {
        string Min, Max = "";
        Min.resize(100);
        for (string s : st[i]) {
            chkmin(Min, s);
            chkmax(Max, s);
        }
        cout << schema[i] << ',' << st[i].size() << ',';
        int k = 30 - int(schema[i].length()) - int(digit_cnt(st[i].size()));
        chkmax(k, 0);
        while (k --) cout << ' ';
        cout << Min << "," << Max << '\n';
    }
    cout.flush();
    return 0;
}