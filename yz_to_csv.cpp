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
typedef vector<ll> vl;
vl vs2vl(vs v_s) {
    vl ret;
    for (string s : v_s)
        ret.pb(s2l(s));
    return ret;
}

bool has(string s, char ch) {
    for (char c : s) if (c == ch)
        return true;
    return false;
}

pair<map<int, string>, map<int, int>> readYuanzhenMetadata() {
    ifstream fin("config.txt");
    string s;
    int tot = 0;
    map<int, string> id2name;
    map<int, int> sensor2player;
    while (getline(fin, s)) {
        if (has(s, '(')) {
            tot ++;
            vector<string> tmp = split(s, '(');
            id2name[tot] = tmp[0];
            tmp = split(tmp[1], ',');
            for (string st : tmp)
                sensor2player[s2l(split(st, ':')[1])] = tot;
        }
    }
    return make_pair(id2name, sensor2player);
}


int threshold = 500;
class node { public:
    int x, y, z; // biased coordinates in millimetres
    node(ll _x, ll _y, ll _z) : x(_x + 5e4), y(_y + 5e4), z(_z + 5e4) {
        assert(x >= 0 && y >= 0 && z >= 0);
    }
    uint64_t zone() {
        return x / threshold << 20 | y / threshold << 10 | z / threshold;
    }
};

void gen_desc() {
    cout << "team,key,value,eventTime" << '\n';
}
void to_csv(bool team, int key, int val, ll ts) {
    cout << team << ',' << key << ',' << val << ',' << ts << '\n';
}


int main(int argc, char ** argv) {
    assert(argc >= 3);
    const int tf = atoi(argv[1]);
    threshold = atoi(argv[2]);
    freopen(argc >= 4 ? argv[3] : "full-game-washed", "r", stdin);
    freopen(argc >= 5 ? argv[4] : "raw.csv", "w", stdout);
    auto meta = readYuanzhenMetadata();
    map<int, string> id2name = meta.first;
    map<int, int> sensor2player = meta.second;
    string s;
    vl a;
    int tot = 0;
    gen_desc();
    while (getline(cin, s)) {
        a = vs2vl(split(s, ','));
        int sensorId = a[0];
        if (!sensor2player.count(sensorId))
            continue;
        int PlayerId = sensor2player[sensorId];
        ll Timestamp = (a[1] - 10629342490369878ll) / (int)(1e6);
        to_csv((PlayerId <= 8), (node(a[2], a[3], a[4])).zone(), a[0], Timestamp);
    }
}