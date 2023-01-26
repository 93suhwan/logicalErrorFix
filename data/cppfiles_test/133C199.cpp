#include <bits/stdc++.h>
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<string> d(n - 2);
  for (int i = 0; i < n - 2; ++i) cin >> d[i];
  string p = "";
  int x;
  for (int i = 0; i < n - 3; ++i) {
    if (d[i][1] == d[i + 1][0])
      continue;
    else {
      p = "";
      p += d[i][1];
      p += d[i + 1][0];
      x = i + 1;
      break;
    }
  }
  if (p == "") {
    x = n - 2;
    p = "";
    p += d[n - 3][1];
    p += 'a';
  }
  string ans = "";
  for (int i = 0; i < min(n - 2, x); ++i) ans += d[i][0];
  ans += p[0];
  for (int i = x; i < n - 2; ++i) ans += d[i][0];
  if (x == n - 2)
    ans += p[1];
  else
    ans += d[n - 3][1];
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
