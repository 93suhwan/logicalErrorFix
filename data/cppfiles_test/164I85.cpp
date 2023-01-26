//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

//randoms
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define trace(x) cout << #x << " = " << (x) << endl;
#define all(x) x.begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define unique(x) x.erase(unique(all(x)), (x).end())
#define ld long double
#define sz(s) (int) size(s)
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)


const int N = 200001;
const ll infL = 1e18;
const int infI = 1e9 + 7;
const int LG = 19;
int n, k, l[N], r[N], d[N], jump[LG][N];
bool used[N];
char c[N];

void init() {
    for (int j = 1; j < LG; ++j) {
        for (int i = 0; i < n; ++i)
            jump[j][i] = jump[j - 1][jump[j - 1][i]];
    }
}

int lca(int v, int u) {
    if (d[u] < d[v]) swap(u, v);
    for (int i = LG - 1; i > -1; --i)
        if (d[jump[i][u]] >= d[v])
            u = jump[i][u];
    if (v == u) {
        return v;
    }
    for (int i = LG - 1; i > -1; --i) {
        if (jump[i][u] != jump[i][v]) {
            u = jump[i][u];
            v = jump[i][v];
        }
    }
    return jump[0][u];
}

string wow;
int idx[N];

void precalc(int v, int dep, int p) {
    d[v] = dep;
    jump[0][v] = p;
    if (l[v] != -1) precalc(l[v], dep + 1, v);
    idx[v] = sz(wow);
    wow.push_back(c[v]);
    if (r[v] != -1) precalc(r[v], dep + 1, v);
}

vector<int> colored;

bool yay(int v) {
    if (colored.empty() && d[v] + 1 <= k) {
        colored.push_back(v);
        k -= d[v] + 1;
        return true;
    } else if (colored.empty()) return false;
    int u = colored.back();
    int cc = lca(u, v);
    int len = d[cc] - d[u];
    if (len <= k) {
        k -= len;
        colored.push_back(v);
        return true;
    }
    return false;
}


void dfs(int v, bool fuck) {
    if (l[v] != -1) dfs(l[v], fuck);
    bool now = fuck && (wow[idx[v]] > c[v]);
    if (now) used[v] = yay(v);
    if (r[v] != -1) {
        dfs(r[v], now);
    }
}
string ans;
void getAns(int v){
    if (l[v] != -1) {used[v] |= used[l[v]];getAns(l[v]);}
    if (r[v] != -1) used[v] |= used[r[v]];
    ans.push_back(c[v]);
    if (used[v]) ans.push_back(c[v]);
    if (r[v] != -1) getAns(r[v]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k ;
    string str;
    cin >> str;
    for (int i = 0; i < n; ++i)
        c[i] = str[i];
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }
    precalc(0, 0, 0);
    wow.push_back(char(0));
    string zz = wow;
    for (int i = sz(wow) - 2; i > -1; --i) {
        if (zz[i] == zz[i + 1])
            wow[i] = wow[i + 1];
        else
            wow[i] = zz[i + 1];
    }
    init();
    dfs(0, true);
    getAns(0);
    cout << ans;
    return 0;
}