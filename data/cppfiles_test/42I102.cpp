#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
void setIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
const int64_t N = 4e5 + 1;
const int64_t L = 2e1 + 1;
const int64_t inf = 2e17;
const int64_t mod = 1e9 + 7;
int64_t xyz = 1;
int64_t n, m;
int64_t ans = 0;
int64_t bit[N];
int64_t idx[N];
int64_t val[N];
int64_t use[N];
int64_t ord[N];
pair<int64_t, int64_t> arr[N];
void add(int64_t i, int64_t x) {
  for (; i < N; i += (-i & i)) {
    bit[i] += x;
    bit[i] %= mod;
  }
}
int64_t get(int64_t i) {
  int64_t res = 0;
  for (; i > 0; i -= (-i & i)) {
    res += bit[i];
    res %= mod;
  }
  return res;
}
bool cmp(int64_t a, int64_t b) { return arr[a] < arr[b]; }
void run() {
  cin >> n;
  for (int64_t i = 1; i <= n; i++) {
    cin >> arr[i].second >> arr[i].first;
    idx[arr[i].second] = -i;
    idx[arr[i].first] = +i;
  }
  cin >> m;
  int64_t z;
  for (int64_t i = 1; i <= m; i++) cin >> z, use[z] = true;
  for (int64_t i = 1; i <= n + n; i++) {
    if (idx[i] > 0) {
      int64_t j = idx[i];
      int64_t p = arr[j].second;
      int64_t x = val[j] = (get(n + n) - get(p) + 1 + mod) % mod;
      add(p, x);
    }
  }
  for (int64_t i = 1; i <= n; i++) {
    ans += val[i];
    ans %= mod;
  }
  int64_t l = 0;
  int64_t r = n + n + 1;
  iota(ord + 1, ord + 1 + n, 1);
  sort(ord + 1, ord + 1 + n, cmp);
  int64_t pos = n + 1;
  for (int64_t i = n; i >= 1; i--) {
    int64_t j = ord[i];
    if (l < arr[j].second && arr[j].first < r) {
      if (use[j]) {
        pos = i;
        ((l) = max(arr[j].second, l));
        ((r) = min(arr[j].first, r));
      } else {
        ans += mod - val[j];
        ans %= mod;
      }
    }
  }
  ans += mod - val[ord[pos]] + 1;
  cout << ans % mod << "\n";
}
signed main() {
  setIO();
  while (xyz--) run();
  return 0;
}
