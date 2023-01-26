#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int n, f_res = 0;
void solve() {
  int n, f_res = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') {
      f_res += int(s[i] - int('0'));
      if (i != n - 1) f_res++;
    }
  }
  cout << f_res << endl;
}
int main() {
  c_p_c();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
