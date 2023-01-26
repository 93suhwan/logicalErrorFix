#include <bits/stdc++.h>
using namespace std;
bool prime(long long p) {
  for (long long i = 2; i <= sqrt(p); i++) {
    if (p % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    string d;
    for (int j = 0; j < 2 * (n - 2); j += 2) {
      string s;
      cin >> s;
      d.push_back(s[0]);
      d.push_back(s[1]);
    }
    string ans;
    ans.push_back(d[0]);
    ans.push_back(d[1]);
    bool fl = false;
    for (int j = 2; j < d.size(); j += 2) {
      if (d[j] != d[j - 1] && fl == false) {
        ans.push_back(d[j - 1]);
        ans.push_back(d[j]);
        fl = true;
      } else {
        ans.push_back(d[j]);
      }
    }
    if (fl == false) {
      ans.push_back(ans[2 * (n - 2) - 1]);
      cout << ans << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}
