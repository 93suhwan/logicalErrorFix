#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long dx[] = {0, 0, -1, 1};
long long dy[] = {1, -1, 0, 0};
long long inf = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long t_case = 1; t_case <= t; t_case++) {
    long long n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string prev = "";
    long long i = 0;
    long long ans = 0;
    bool flag = 0;
    while (i < n - 1) {
      flag = 0;
      if (s[i] == '0' && t[i] == '0') {
        if (prev == "11") {
          ans += 2;
          i++;
          prev = "";
        } else if (s[i + 1] == '1' && t[i + 1] == '1') {
          flag = 1;
          ans += 2;
          i += 2;
        } else {
          ans++;
          i++;
        }
      } else if (s[i] == '1' && t[i] == '1') {
        prev = "11";
        i++;
      } else {
        ans += 2;
        prev = "";
        i++;
      }
    }
    if (flag) {
      cout << ans << endl;
      continue;
    }
    if (s[n - 1] == '0' && t[n - 1] == '0') {
      if (prev == "11") {
        ans += 2;
        i++;
        prev = "";
      } else if (s[i + 1] == '1' && t[i + 1] == '1') {
        ans += 2;
        i += 2;
      } else {
        ans++;
        i++;
      }
    } else if (s[i] == '1' && t[i] == '1') {
      ;
    } else
      ans += 2;
    cout << ans << endl;
  }
  return 0;
}
