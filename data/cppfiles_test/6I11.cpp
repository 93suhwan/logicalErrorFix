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
int a[MAX];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  euler();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    map<int, int> mp;
    for (int j = i; j <= n; j += i) {
      for (int k = 1; k <= sqrt(a[j]); k++) {
        if (a[j] % k == 0) mp[k]++;
        if (k * k != a[j]) mp[a[j] / k]++;
      }
    }
    long long sum = 0;
    for (pair<int, int> j : mp)
      sum += 1ll * E[j.first] * j.second % MOD * j.second % MOD, sum %= MOD;
    ans += sum * E[i] % MOD, ans %= MOD;
  }
  cout << ans << '\n';
  return 0;
}
