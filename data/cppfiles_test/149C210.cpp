#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
T gcd(T a, T b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
void solve() {
  int n, k;
  long long x;
  cin >> n >> k >> x;
  string s;
  cin >> s;
  x--;
  int cnt = 0;
  vector<int> nm;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '*')
      cnt++;
    else {
      if (cnt) nm.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt) nm.push_back(cnt);
  int uwu = 0;
  vector<int> d;
  while (x > 0) {
    int cr = (nm[uwu++] * k) + 1;
    d.push_back(x % cr);
    x /= cr;
  }
  int ind = 0, lst = -1;
  string ans = "";
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'a')
      ans += 'a', lst = 1;
    else {
      if (!lst) continue;
      if (ind == (int)(d.size())) continue;
      for (int j = 0; j < (int)(d[ind]); j++) ans += 'b';
      ind++;
      lst = 0;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
