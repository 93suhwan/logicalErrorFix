#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  string s, s1;
  cin >> s >> s1;
  int ans = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    string temp = "";
    for (int j = i; j < n; j++) {
      temp += s[j];
      string temp1 = temp;
      if (temp1 == s1) {
        ans = 1;
        break;
      }
      for (int k = j - 1; k >= 0; k--) {
        temp1 += s[k];
        if (temp1 == s1) {
          ans = 1;
          break;
        }
      }
      if (ans == 1) {
        break;
      }
    }
    if (ans == 1) {
      break;
    }
  }
  if (ans == 1) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
