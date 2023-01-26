#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, n, x, ans = 0;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    for (i = 0; i < n; i++) {
      if (s2[i] == '1') {
        if (i != 0 && s1[i - 1] == '1')
          ans++;
        else if (s1[i] == '0') {
          ans++;
          s1[i] = '2';
        } else if (i != n - 1 && s1[i + 1] == '1') {
          ans++;
          s1[i + 1] = '2';
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
