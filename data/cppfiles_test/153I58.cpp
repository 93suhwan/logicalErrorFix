#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int f[(1 << n)];
  int g[(1 << n)];
  for (int i = 0; i < (1 << n); i++) {
    f[i] = g[i] = 0;
  }
  for (int i = 1; i < (1 << n); i++) {
    vector<int> min_oc;
    min_oc.assign(26, 1e9);
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        vector<int> oc;
        oc.assign(26, 0);
        for (char c : v[j]) {
          oc[c - 'a']++;
        }
        for (int k = 0; k < 26; k++) {
          min_oc[k] = min(min_oc[k], oc[k]);
        }
      }
    }
    long long ans = 1;
    for (int j : min_oc) {
      ans *= (j + 1);
    }
    f[i] = ans;
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    g[i] = 0;
    for (int s = i; s; s = (s - 1) & i) {
      g[i] -= f[s] * pow(-1, __builtin_popcount(s));
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        res += __builtin_popcount(i) * (j + 1);
      }
    }
    ans ^= (res * g[i]);
  }
  cout << ans << '\n';
}
