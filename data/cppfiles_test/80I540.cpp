#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int z = 0, o = 0;
  for (auto x : s) x == '0' ? z++ : o++;
  if (z == 0 || o == 0) {
    cout << "1 " << n - 1 << " 2 " << n << endl;
  }
  int i = 0, j = (n / 2) - 1;
  for (; j < n - 1; i++, j++) {
    if (s[i] == '0') {
      cout << i + 1 << ' ' << j + 2 << ' ' << i + 2 << ' ' << j + 2 << endl;
      return;
    }
    if (s[j + 1] == '0') {
      cout << i + 1 << ' ' << j + 2 << ' ' << i + 1 << ' ' << j + 1 << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
