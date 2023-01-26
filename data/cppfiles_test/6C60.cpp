#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<int> f[MAXN];
int phi[MAXN];
int a[MAXN];
int cnt[MAXN];
long long calc(vector<int> a) {
  long long sm = 0;
  for (auto x : a) {
    for (auto y : f[x]) {
      int h = (2 * cnt[y] + 1);
      sm = (sm + 1ll * phi[y] * h) % MOD;
      cnt[y] += 1;
    }
  }
  for (auto x : a) {
    for (auto y : f[x]) {
      cnt[y] = 0;
    }
  }
  return sm;
}
int main() {
  for (int i = 1; i < MAXN; i++) {
    for (int j = 1; j * i < MAXN; j++) {
      f[i * j].push_back(i);
    }
  }
  phi[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    phi[i] = i;
    for (auto x : f[i]) {
      if (x == i) {
        continue;
      }
      phi[i] -= phi[x];
    }
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int j = 1; j <= n; j++) {
    vector<int> cur;
    for (int k = j; k <= n; k += j) {
      cur.push_back(a[k]);
    }
    ans += 1ll * calc(cur) * phi[j] % MOD;
    ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}
