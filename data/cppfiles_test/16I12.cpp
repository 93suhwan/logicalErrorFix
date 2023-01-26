#include <bits/stdc++.h>
using namespace std;
using namespace std;
using ll = long long int;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    string str;
    str = s;
    ll ans = 0;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      if (str[i] != s[i]) ans++;
    }
    cout << s << " " << str << endl;
    cout << ans << endl;
  }
  return 0;
}
