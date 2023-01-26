#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string arr[n - 2];
    for (int i = 0; i < n - 2; ++i) {
      cin >> arr[i];
    }
    string c = arr[0];
    string ans = "a";
    ans = c[0];
    string a;
    string b;
    for (int i = 1; i < n - 2; ++i) {
      a = arr[i - 1];
      b = arr[i];
      if (b[0] == a[1]) {
        ans = ans + b[0];
      } else if (b[0] != a[1]) {
        ans = ans + a[1];
        ans = ans + b[0];
      }
    }
    string d = arr[n - 3];
    ans = ans + d[1];
    if (ans.length() != n) {
      ans = ans + "a";
    }
    cout << ans << "\n";
  }
}
