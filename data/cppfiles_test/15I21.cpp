#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& p) {
  return out << "(" << p.first << ", " << p.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < v.size(); ++i) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
const int N = 106;
int n, k;
vector<long long> fact;
vector<int> adj[N];
bool vis[N] = {false};
vector<int> dis[N];
void init() {
  for (int i = (0); i < (n); ++i) {
    vector<int>().swap(adj[i]);
    vector<int>().swap(dis[i]);
    dis[i].resize(N);
    vis[i] = false;
  }
}
int start;
void dfs(int f, int v, int cost) {
  dis[start][v] = cost;
  for (int to : adj[v]) {
    if (to == f) continue;
    dfs(v, to, cost + 1);
  }
}
const long long MOD = 1e9 + 7;
inline long long mul(long long x, long long y) { return x * y % MOD; }
long long ksm(long long base, long long pow) {
  long long now = base, ret = 1;
  for (; pow; pow >>= 1) {
    if (pow & 1) {
      ret = mul(ret, now);
    }
    now = mul(now, now);
  }
  return ret;
}
long long inv(long long x) { return ksm(x, MOD - 2); }
long long C(int n, int m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return mul(fact[n], mul(inv(fact[m]), inv(fact[n - m])));
}
void sol() {
  cin >> n >> k;
  for (int i = (0); i < (n); ++i) {
    dis[i].resize(n);
  }
  for (int i = (1); i < (n); ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long ans = 0;
  if (k == 2) {
    ans = C(n, 2);
  } else {
    for (int i = (0); i < (n); ++i) {
      start = i;
      dfs(-1, i, 0);
    }
    for (int i = (0); i < (n); ++i) {
      if (adj[i].size() >= k) {
        map<int, long long> cnt;
        for (int j = (0); j < (n); ++j) {
          ++cnt[dis[i][j]];
        }
        for (auto [fi, se] : cnt) {
          if (se >= k) {
            ans += C(se, k);
          }
        }
      }
    }
  }
  cout << ans << endl;
  init();
}
int main(int argc, char const* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fact.resize(N);
  fact[0] = fact[1] = 1;
  for (int i = (2); i < (N); ++i) {
    fact[i] = mul(fact[i - 1], i);
  }
  int t;
  cin >> t;
  for (; t; --t) {
    sol();
  }
  return 0;
}
