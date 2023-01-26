#include <bits/stdc++.h>
using namespace std;
void google(long long t) { cout << "Case #" << t << ": "; }
const long long mod = 1e9 + 7;
const long long N = 1e6 + 100;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return (a * power(a, b - 1));
  long long temp = power(a, b / 2);
  return (temp * temp);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    string s, t;
    cin >> s >> t;
    sort((s).begin(), (s).end());
    if (!(t == "abc")) {
      cout << s << '\n';
      continue;
    }
    long long cntb = 0;
    long long cntc = 0;
    long long cnta = 0;
    for (long long i = 0; i < s.size(); i++) {
      if (s[i] == 'a')
        cnta++;
      else if (s[i] == 'b')
        cntb++;
      else if (s[i] == 'c')
        cntc++;
    }
    string ans = "";
    if (t == "abc") {
      if (cnta == 0 || cntb == 0 || cntc == 0) {
        cout << s << '\n';
        continue;
      }
      string aa = string(cnta, 'a');
      string bb = string(cntb, 'b');
      string cc = string(cntc, 'c');
      ans += aa;
      ans += cc;
      ans += bb;
    }
    long long st = cnta + cntb + cntc;
    long long si = (long long)((s).size());
    while (st < si) {
      ans += s[st];
      st++;
    }
    cout << ans << '\n';
  }
  return 0;
}
