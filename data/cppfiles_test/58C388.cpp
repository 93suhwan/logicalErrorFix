#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  bool flag = false;
  for (long long i = 0; i < n; i++) {
    if (s1[i] == s2[i] and s1[i] == '1') flag = true;
  }
  if (flag) {
    cout << "NO\n";
  } else
    cout << "YES\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
