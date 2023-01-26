#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(s.begin(), s.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
