#include "bits/stdc++.h"
using namespace std;
typedef int64_t         ll;
typedef uint64_t        ul;
typedef double          ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
typedef pair<ld, ld>    pdd;
typedef vector<int>     vi;
#define fi              first
#define se              second
#define pb              push_back
#define do(i, j, k)     for (int i = (j); i <= (k); i ++)
#define dec(i, j, k)    for (int i = (j); i >= (k); i --)
#define mfil(a, x)      memset(a, x, sizeof(a))
#define mcpy(a, b)      memcpy(a, b, sizeof(b))
#define fio(x)          freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
template<class T>
inline bool chkmin(T &x, T y) { return y < x ? (x=y, true) : false; }
template<class T>
inline bool chkmax(T &x, T y) { return x < y ? (x=y, true) : false; }
typedef int _ISTR_TYPE;
inline _ISTR_TYPE _() {
    _ISTR_TYPE ret = 0; char ch = getchar(); while (ch < '0' || ch > '9') ch = getchar();
    do { ret = 10 * ret + ch - '0'; ch = getchar(); } while ('0' <= ch && ch <= '9');
    return ret;
}
#define multi void init(); void work();\
              int main() { int T; cin >> T; while (T --) { init(); work(); } }
#define G     struct node { int v, w; node *nxt; } pool[2*maxm], *h[maxn]; int cnt;\
              void adde(int u, int v, int w) { node *p = &pool[++cnt]; *p = (node){v, w, h[u]}; h[u] = p; }\
              void addedge(int u, int v, int w) { adde(u, v, w), adde(v, u, w) }
struct __init__ {
    __init__() {
        srand(time(0) ^ ul(new char));
        cin.sync_with_stdio(false);
        cin.tie(0); cout.precision(16);
    }
} static _init_;

/* default code ends here */


typedef vector<string> vs;
vs split(string s, char ch) {
    vs ret;
    string t;
    for (char c : s) {
        if (c == ch) {
            ret.pb(t);
            t.clear();
        } else {
            t.pb(c);
        }
    }
    ret.pb(t);
    return ret;
}

ll s2l(string s) {
    bool flag = false;
    ll ret = 0;
    for (char c : s) {
        if (c == '-')
            flag ^= 1;
        else if (isdigit(c))
            ret = ret * 10 + c - '0';
    }
    return (flag ? -ret : ret);
}

ll maxLag;
ll gen_uni_lag() {
    return rand() % maxLag;
}

ifstream fin("randList");
ll readInt() {
    static int tot = 999;
    if ((++ tot) == 1000) {
        tot = 0;
        system("sh ./b.sh");
        fin.close();
        fin.clear();
        fin.open("randList");
    }
    ll ret;
    fin >> ret;
    return ret;
}

int main(int argc, char **argv) {
    if (argc >= 2) freopen(argv[1], "r", stdin);
    if (argc >= 3) freopen(argv[2], "w", stdout);

    string s;
    getline(cin, s);
    // key	value	eventTime	arrivalTime	processedTime
    assert(s == "team,key,value,eventTime");
    cout << "team,key,value,eventTime,arrivalTime,processedTime" << endl;
    while (getline(cin, s)) {
        vs ret = split(s, ',');
        assert(ret.size() == 4);
        cout << s;
        cout << ',';
        cout << s2l(ret[3]) + readInt() << ',' << 0 << endl;
    }
}