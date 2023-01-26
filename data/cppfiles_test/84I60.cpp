#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int maxn = 1e5 + 233;
int phi[maxn];
vector<int> prime;
bool vis[maxn];
using ll = long long;
ll sum[maxn];
vector<pair<int, ll> > pre[maxn];
void init() {
  phi[1] = 1;
  for (int i = 2; i < maxn; i += 1) {
    if (!vis[i]) phi[i] = i - 1, prime.emplace_back(i);
    for (int j = 0; j < prime.size() && i * prime[j] < maxn; j += 1) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      phi[i * prime[j]] = phi[i] * (prime[j] - 1);
    }
  }
  for (int i = 1; i < maxn; i += 1) {
    sum[i] = sum[i - 1] + phi[i];
  }
}
ll C(int l, int r) {
  ll res = 0;
  for (int ll = l, rr; ll <= r; ll = rr + 1) {
    rr = r / (r / ll);
    res += (rr - ll + 1) * sum[r / ll];
  }
  return res;
}
ll res[3 * maxn];
vector<pair<int, int> > ask[maxn];
ll dp[20][maxn];
int T;
void solve(int k, int L, int R, int l, int r) {
  if (L > R || l > r) return;
  int mid = l + r >> 1;
  int p = L;
  for (int i = L; i <= min(mid - 1, R); i += 1) {
    ll tmp = C(i + 1, mid);
    if (dp[k][mid] > dp[k - 1][i] + tmp) {
      dp[k][mid] = dp[k - 1][i] + tmp;
      p = i;
    }
  }
  solve(k, L, p, l, mid - 1);
  solve(k, p, R, mid + 1, r);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  init();
  cin >> T;
  for (int i = 1; i <= T; i += 1) {
    int n, k;
    cin >> n >> k;
    if (k >= 20) {
      continue;
    }
    ask[k].emplace_back(n, i);
  }
  for (int i = 0; i < 20; i += 1) {
    for (int j = 0; j < maxn; j += 1) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i < 20; i += 1) {
    solve(i, 0, maxn - 1, 1, maxn - 1);
    for (auto [n, id] : ask[i]) {
      res[id] = dp[i][n];
    }
  }
  for (int i = 1; i <= T; i += 1) {
    cout << res[i] << "\n";
  }
  return 0;
}
