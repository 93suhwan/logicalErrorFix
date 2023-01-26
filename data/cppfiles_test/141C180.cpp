#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  string a, b;
  cin >> a >> b;
  string s = "";
  ll i = a.size() - 1;
  ll j = b.size() - 1;
  int ok = 1;
  for (i; i >= 0; i--) {
    if (a[i] <= b[j]) {
      s = (char)(b[j] - a[i] + '0') + s;
      j--;
    } else {
      ll p = (b[j] - '0') + (b[j - 1] - '0') * 10 - (a[i] - '0');
      if (p >= 0 && p <= 9) {
        s = (char)(p + '0') + s;
        j = j - 2;
      } else {
        ok = 0;
        break;
      }
    }
  }
  if (ok == 1) {
    while (j >= 0) {
      s = b[j] + s;
      j--;
    }
    ll i = 0;
    while (s[i] == '0') {
      i++;
    }
    for (; i < s.size(); i++) {
      cout << s[i];
    }
    cout << endl;
  } else
    cout << -1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  string s;
  getline(cin, s);
  while (t--) {
    solve();
  }
  return 0;
}
