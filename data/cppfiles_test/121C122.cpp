#include <bits/stdc++.h>
#pragma GCC optimize("O4,unroll-loops,no-stack-protector")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int arr[2][2];
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (s == t) {
      cout << 0 << "\n";
      continue;
    }
    int one = 0;
    arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1] = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') one++;
      arr[s[i] - '0'][t[i] - '0']++;
    }
    if (one == 0) {
      cout << -1 << "\n";
      continue;
    }
    int ans = 1e9;
    if (arr[0][1] == arr[1][0]) {
      ans = min(ans, arr[0][1] * 2);
    }
    if (arr[1][1] == arr[0][0] + 1) {
      ans = min(ans, arr[1][1] * 2 - 1);
    }
    cout << (ans == 1e9 ? -1 : ans) << "\n";
  }
}
