#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int mod = 998244353;
int fact[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  int ntest;
  cin >> ntest;
  while (ntest--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (a[n - 1] - a[n - 2] > 1) {
      cout << 0 << "\n";
      continue;
    }
    if (a[n - 1] == a[n - 2]) {
      cout << fact[n] << "\n";
      continue;
    }
    int cnt = count(a.begin(), a.end(), a[n - 2]);
    int sub = 1ll * fact[cnt];
    for (int i = 0; i < n - cnt - 1; ++i) {
      int left = cnt + 2 + i;
      sub = 1ll * sub * left % mod;
    }
    cout << (fact[n] - sub + mod) % mod << "\n";
  }
  return 0;
}
