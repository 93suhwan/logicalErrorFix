#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll loops")
using namespace std;
const long long int MOD = 998244353;
const long long int INF = 1e18;
void solve() {
  long long int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    if (s.length() % 2 == 1) {
      cout << "NO" << endl;
    } else {
      long long int i = 0, j = s.length() / 2;
      while (j < s.length() && s[i] == s[j]) {
        i++;
        j++;
      }
      if (j == s.length()) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
