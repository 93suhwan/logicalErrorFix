#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
const int MOD = 1e9 + 7;
int E[MAX];
void euler() {
  E[1] = 1;
  for (int i = 2; i < MAX; i++) {
    if (!E[i])
      for (int j = i; j < MAX; j += i) {
        if (!E[j]) E[j] = j;
        E[j] = E[j] / i * (i - 1);
      }
  }
}
int n;
int a[MAX], cnt[MAX];
vector<int> G[MAX];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  euler();
  for (int i = 1; i <= 100000; i++)
    for (int j = 1; j <= sqrt(i); j++)
      if (i % j == 0) {
        G[i].push_back(j);
        if (j * j != i) G[i].push_back(i / j);
      }
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> v;
    for (int j = i; j <= n; j += i) {
      for (int k : G[a[j]]) {
        if (!cnt[k]) v.push_back(k);
        cnt[k]++;
      }
    }
    for (int j : v) {
      ans += 1ll * E[i] * E[j] % MOD * cnt[j] % MOD * cnt[j] % MOD, ans %= MOD;
      cnt[j] = 0;
    }
  }
  cout << ans << '\n';
  return 0;
}
