#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1000000007LL;
const int N = 1e6 + 10;
const long long Inf = 2242545357980376863LL;
const long long Log = 30;
struct FenwickTree {
  using T = long long;
  T fen[N];
  int n = N;
  FenwickTree() { memset(fen, 0, sizeof fen); }
  void Add(int idx, T x) {
    for (; idx < n; idx += (idx & (-idx))) (fen[idx] += x) %= Mod;
  }
  T Get(int idx) {
    T res = 0;
    for (; idx; idx -= (idx & (-idx))) res += fen[idx];
    return res % Mod;
  }
};
FenwickTree DS;
int a[N], b[N], dp[N];
long long mx[N];
int Main() {
  int n;
  cin >> n;
  vector<int> V;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    V.push_back(i);
  }
  sort(V.begin(), V.end(), [&](int i, int j) { return a[i] > a[j]; });
  long long ans = 0;
  long long q;
  cin >> q;
  int u;
  for (int i = 0; i < q; i++) {
    cin >> u;
    u--;
    mx[a[u]] = b[u];
    ans += dp[u - 1];
    ans %= Mod;
  }
  for (int i = n + n; i >= 0; i--) mx[i] = max(mx[i], mx[i + 1]);
  for (int i = 0; i < n; i++) {
    int ii = V[i];
    long long res = Mod + 1 + DS.Get(b[ii]);
    res %= Mod;
    DS.Add(b[ii], res);
    dp[ii] = res;
    if (mx[a[ii]] >= b[ii]) ans += dp[ii];
  }
  cout << ans % Mod << '\n';
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) Main();
  return 0;
}
