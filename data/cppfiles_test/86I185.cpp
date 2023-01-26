#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, k;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    string s;
    long long int ans = 0;
    for (i = 0; i < n; i++) {
      if ((s1[i] == '0' && s2[i] == '1') || (s1[i] == '1' && s2[i] == '0'))
        ans += 2, s += '2';
      else if (s1[i] == '0' && s2[i] == '0')
        s += '0';
      else
        s += '1';
    }
    for (i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i && s[i - 1] == '1')
          ans += 2;
        else if ((i < n - 1) && s[i + 1] == '1')
          ans += 2, i++;
        else
          ans++;
      }
    }
    cout << ans;
    cout << endl;
  }
  return 0;
}
