#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
void solve() {
  long long int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  if (s1[0] == '0' && s2[n - 1] == '0') {
    for (long long int i = 0; i < n; i++) {
      if ((s1[i] == '1') + (s2[i] == '1') == 2) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES\n";
    return;
  } else {
    cout << "NO" << endl;
    return;
  }
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
