#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    bool flag;
    long long ans = n + 1;
    for (int i = 0; i < 26; i++) {
      long long count = 0;
      char dlt = 'a' + i;
      long long start = 0, end = s.size() - 1;
      while (start < end) {
        if (s[start] == s[end]) {
          start++;
          end--;
        } else if (s[start] == dlt) {
          start++;
          count++;
        } else if (s[end] == dlt) {
          end--;
          count++;
        } else {
          count = n + 1;
          break;
        }
      }
      ans = min(ans, count);
    }
    if (ans == n + 1) ans = -1;
    cout << ans << endl;
  }
  return 0;
}
