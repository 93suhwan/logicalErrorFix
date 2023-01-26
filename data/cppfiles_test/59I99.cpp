#include <bits/stdc++.h>
using namespace std;
template <typename U>
using pq = priority_queue<U>;
template <typename U>
using pqg = priority_queue<U, vector<U>, greater<U>>;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) is >> x;
  return is;
}
template <typename T, typename U>
bool umax(T& a, U b) {
  return a < b ? a = b, 1 : 0;
}
template <typename T, typename U>
bool umin(T& a, U b) {
  return a < b ? 0 : a = b, 1;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9 + 5;
const long long LLINF = (long long)1e18 + 5;
const int MOD = 1e9 + 7;
const char nl = '\n';
int i4[4] = {1, 0, -1, 0};
int j4[4] = {0, 1, 0, -1};
int N, M;
const int mxN = 1005;
int A[mxN], B[mxN];
bool vis[mxN];
vector<int> adj[mxN];
long long add = 0;
bool go(int u, int p, long long power) {
  if (power <= A[u]) return false;
  vis[u] = 1;
  for (int x : adj[u]) {
    if (x == p) continue;
    if (vis[x]) return true;
    if (go(x, u, power + B[u])) {
      add += B[x];
      return true;
    }
  }
  vis[u] = 0;
  return false;
}
bool check(long long initial) {
  for (int i = 1; i < N; i++) vis[i] = 0;
  add = 0;
  vis[0] = 1;
  long long power = initial;
  auto get = [&]() {
    int ret = 0;
    for (int i = 0; i < N; i++) ret += !vis[i];
    return ret;
  };
  while (get()) {
    bool ch = 0;
    for (int i = 0; i < N && !ch; i++) {
      if (!vis[i]) continue;
      for (int x : adj[i]) {
        if (!vis[x]) {
          if (go(x, i, power)) {
            ch = 1;
            power += add + B[x];
            break;
          }
        }
      }
    }
    if (!ch) break;
  }
  return get() == 0;
}
void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) adj[i].clear();
  for (int i = 1; i < N; i++) cin >> A[i];
  for (int i = 1; i < N; i++) cin >> B[i];
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b, --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int lo = 1, hi = 1e9 + 5, best = -1;
  while (lo <= hi) {
    int m = (lo + hi) / 2;
    if (check(m)) {
      hi = m - 1;
      best = m;
    } else
      lo = m + 1;
  }
  cout << best << nl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  clock_t myClock = clock();
  int tt = 1;
  cin >> tt;
  for (int i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
