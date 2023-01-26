#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    string rev = s;
    reverse(s.begin(), s.end());
    if (s == rev) {
      cout << 0 << endl;
    } else {
      long long int ans = n + 1;
      long long int p = 0, result;
      for (char x = 'a'; x <= 'z'; x++) {
        long long int l = 0;
        long long int r = n - 1;
        result = 0;
        while (r > l) {
          if (rev[l] == x && rev[r] != x) {
            l++;
            result++;
            continue;
          }
          if (rev[l] != x && rev[r] == x) {
            r--;
            result++;
            continue;
          }
          if (rev[l] != rev[r]) {
            result = -1;
            break;
          }
          l++;
          r--;
        }
        if (result != -1) {
          p = 1;
          ans = ((result > ans) ? ans : result);
        }
      }
      if (p)
        cout << ans << endl;
      else
        cout << "-1" << endl;
    }
  }
  return 0;
}
