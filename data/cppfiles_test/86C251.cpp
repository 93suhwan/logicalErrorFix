#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i, t;
  cin >> t;
  for (i = 1; i <= t; i++) {
    long long int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    long long int j;
    long long int ans = 0;
    for (j = 0; j < n;) {
      if (s1[j] != s2[j]) {
        ans = ans + 2;
        j++;
      } else if (s1[j] == '0') {
        if (s1[j + 1] == s2[j + 1] && (s1[j + 1]) == '1' && (j + 1) < n) {
          ans = ans + 2;
          j = j + 2;
        } else {
          ans = ans + 1;
          j++;
        }
      } else {
        if (s1[j + 1] == s2[j + 1] && (s1[j + 1]) == '0' && (j + 1) < n) {
          ans = ans + 2;
          j = j + 2;
        } else {
          j++;
        }
      }
    }
    cout << ans << endl;
  }
}
