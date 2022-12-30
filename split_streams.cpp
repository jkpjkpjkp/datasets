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
#define open(i, j, k)   for (int i = (j); i <  (k); i ++)
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

bool chk() {
    char c;
    bool ret = false;
    while ((c = getchar()) != EOF && c != ',') {
        if (c == '0' || c == '1')
            ret = c - '1';
    }
    return ret;
}

int main(int argc, char ** argv) {
    freopen(argc >= 2 ? argv[1] : "_res.csv", "r", stdin);
    ofstream f1(argc >= 3 ? argv[2] : "sTuple.csv");
    ofstream f2(argc >= 4 ? argv[3] : "rTuple.csv");
    string s;
    getline(cin, s);
    assert(s == "team,key,value,eventTime,arrivalTime,processedTime");
    f1 << "key,value,eventTime,arrivalTime,processedTime" << '\n';
    f2 << "key,value,eventTime,arrivalTime,processedTime" << '\n';

    bool flag = chk();
    char c;
    while ((c = getchar()) != EOF) {
        (flag ? f1 : f2) << c;
        if (c == '\n') {
            flag = chk();
        }
    }
}