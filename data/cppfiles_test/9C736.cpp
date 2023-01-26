#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.size();
    long long int cnt = 1, ans = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      if (s[i] == s[i + 1]) {
        cnt++;
      } else {
        if (cnt >= 2) {
          ans = ans + 2;
        } else {
          ans += cnt;
        }
        cnt = 1;
      }
    }
    cout << ans / 2 << endl;
  }
  return 0;
}
