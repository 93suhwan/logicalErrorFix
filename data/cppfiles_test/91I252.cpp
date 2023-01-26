#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m;

map<int, int> G[N];
set<pair<int, int>> e[N];
multiset<ll> s;
set<tuple<int, int, int>> S;

void ins(int u) {
    auto it = e[u].begin(); ll su = 0;
    rep(i, 1, 3) {
        if(it == e[u].end()) return;
        S.emplace(it -> fi, u, it -> se), su += it++ -> fi;
    }
    s.insert(su);
}
void era(int u) {
    auto it = e[u].begin(); ll su = 0;
    rep(i, 1, 3) {
        if(it == e[u].end()) return;
        S.erase(tuple(it -> fi, u, it -> se)), su += it++ -> fi;
    }
    s.erase(s.find(su));
}
void add(int u, int v, int w) {
    G[u][v] = w, era(u), e[u].emplace(w, v), ins(u);
}
void del(int u, int v) {
    auto it = G[u].find(v); int w = it -> se;
    G[u].erase(it), era(u), e[u].erase(pair(w, v)), ins(u);
}
void solve() {
    ll as = 3e9;
    auto it = S.begin(); auto [w1, u1, v1] = *it;
    rep(i, 1, 12) {
        if(++it == S.end()) break;
        auto [w2, u2, v2] = *it;
        if(u1 ^ u2 && u1 ^ v2 && v1 ^ u2 && v1 ^ v2) { as = min(as, (ll)w1 + w2); break; }
    }
    auto x = e[u1].begin();
    rep(i, 1, 2) {
        if(++x == e[u1].end()) break;
        auto y = e[v1].begin();
        rep(j, 1, 2) {
            if(++y == e[v1].end()) break;
            if(x -> se ^ y -> se) as = min(as, 0ll + x -> fi + y -> fi);
        }
    }
    if(s.size()) as = min(as, *s.begin());
    printf("%lld\n", as);
}

int main() {
    cin >> n >> m;
    int u, v, w;
    while(m--) scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, w);
    solve();
    for(cin >> m; m--; solve()) {
        scanf("%d", &u);
        if(u == 0) scanf("%d%d", &u, &v), del(u, v), del(v, u);
        else scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, w);
    }
}