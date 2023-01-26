#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
void solve(int z) {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int a = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      a = i + 1;
      if (i + 1 <= n / 2) {
        cout << a << " " << n << " ";
        cout << a + 1 << " " << n << "\n";
      } else {
        cout << "1 " << a << " ";
        cout << "1 " << a - 1 << "\n";
      }
      return;
    }
  }
  cout << "1 " << n - 1 << " 2 " << n << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}
