#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e6 + 1;
int n, k;
int is[N];
int st[N], en[N];
pair<int, int> a[N];
set<pair<int, int> > s;
int fin[N];
long long dp[N];
long long bit[N];
void upd(int id, int v) {
  for (int i = id; i <= 2 * n; i += i & -i) bit[i] = (bit[i] + v) % mod;
}
long long qry(int id) {
  long long res = 0;
  for (int i = id; i >= 1; i -= i & -i) res = (res + bit[i]) % mod;
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> st[i] >> en[i];
    a[i] = {st[i], i};
  }
  sort(a + 1, a + n + 1);
  cin >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    is[x] = true;
    s.insert({en[x], x});
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i].second;
    auto it = s.lower_bound({en[x], x});
    if (it != s.end()) {
      fin[x] = 1;
    }
    if (is[x]) s.erase({en[x], x});
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i].second;
    dp[x] = qry(2 * n) - qry(en[x]);
    if (dp[x] < 0) dp[x] += mod;
    if (fin[x]) dp[x] = (dp[x] + 1) % mod;
    upd(en[x], dp[x]);
    ans = (ans + dp[x]) % mod;
  }
  cout << ans << '\n';
}
