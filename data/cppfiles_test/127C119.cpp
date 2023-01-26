#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}
const double PI = 3.14159265358979323846;
const double eps = 1e-10;
string s, t;
int cnt1, cnt2;
char s1[110], s2[110];
void solve() {
  cin >> s >> t;
  int isa, isb, isc, ca, cb, cc;
  cnt2 = ca = cb = cc = isa = isb = isc = 0;
  for (decay<decltype((int)(s).size())>::type i = (0), _i = ((int)(s).size());
       i < _i; ++i) {
    if (s[i] == 'a') {
      isa = 1;
      ca++;
    } else if (s[i] == 'b') {
      isb = 1;
      cb++;
    } else if (s[i] == 'c') {
      isc = 1;
      cc++;
    } else
      s2[++cnt2] = s[i];
  }
  if (isa + isb + isc < 3) {
    sort((s).begin(), (s).end());
    cout << s << '\n';
    return;
  }
  if (t == "abc") {
    for (decay<decltype(ca)>::type i = (0), _i = (ca); i < _i; ++i) cout << "a";
    for (decay<decltype(cc)>::type i = (0), _i = (cc); i < _i; ++i) cout << "c";
    for (decay<decltype(cb)>::type i = (0), _i = (cb); i < _i; ++i) cout << "b";
    sort(s2 + 1, s2 + cnt2 + 1);
    for (decay<decltype(cnt2 + 1)>::type i = (1), _i = (cnt2 + 1); i < _i; ++i)
      cout << s2[i];
    cout << '\n';
  } else {
    for (decay<decltype(ca)>::type i = (0), _i = (ca); i < _i; ++i) cout << "a";
    for (decay<decltype(cb)>::type i = (0), _i = (cb); i < _i; ++i) cout << "b";
    for (decay<decltype(cc)>::type i = (0), _i = (cc); i < _i; ++i) cout << "c";
    sort(s2 + 1, s2 + cnt2 + 1);
    for (decay<decltype(cnt2 + 1)>::type i = (1), _i = (cnt2 + 1); i < _i; ++i)
      cout << s2[i];
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
