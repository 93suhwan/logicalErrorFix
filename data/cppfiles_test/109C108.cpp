#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    while (s[i] == '0') i++;
    if (i == s.length()) {
      cout << 0 << endl;
      continue;
    }
    string a = s.substr(i);
    long long ans = 0;
    i = a.length() - 1;
    while (i >= 0) {
      if (i == a.length() - 1) {
        ans += a[i] - '0';
      } else if (a[i] != '0') {
        ans += 1 + (a[i] - '0');
      }
      i--;
    }
    cout << ans << endl;
  }
}
