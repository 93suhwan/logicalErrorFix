#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1 >> s2;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        while (i + 1 < n && (s1[i + 1] != '0' && s2[i + 1] != '0')) {
          i++;
        }
        if (i + 1 == n) {
          break;
        } else {
          ans += 2;
          i++;
        }
      } else if (s1[i] != s2[i]) {
        ans += 2;
      } else {
        if (i + 1 < n && (s1[i + 1] == '1' && s2[i + 1] == '1')) {
          ans += 2;
          i++;
        } else
          ans++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
