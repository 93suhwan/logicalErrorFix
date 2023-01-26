#include <bits/stdc++.h>
using namespace std;
inline namespace FastIO {
const int BSZ = 1 << 15;
char ibuf[BSZ];
int ipos, ilen;
char nc() {
  if (ipos == ilen) {
    ipos = 0;
    ilen = fread(ibuf, 1, BSZ, stdin);
    if (!ilen) return EOF;
  }
  return ibuf[ipos++];
}
void readstr(string& x) {
  char ch;
  while (isspace(ch = nc()))
    ;
  do {
    x += ch;
  } while (!isspace(ch = nc()) && ch != EOF);
}
template <class T>
void readnum(T& x) {
  char ch;
  int sgn = 1;
  while (!isdigit(ch = nc()))
    if (ch == '-') sgn *= -1;
  x = ch - '0';
  while (isdigit(ch = nc())) x = x * 10 + (ch - '0');
  x *= sgn;
}
}  // namespace FastIO
const int mxn = 1e6 + 5;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  string s;
  cin >> s;
  vector<bool> d(30, false);
  map<char, int> oc;
  string ord = "";
  for (long long i = s.size() - 1; i >= 0; i--) {
    oc[s[i]]++;
    if (!d[s[i] - 'a']) {
      ord = s[i] + ord;
      d[s[i] - 'a'] = true;
    }
  }
  long long len = 0;
  for (long long i = 1; i <= ord.size(); i++) {
    char cur = ord[i - 1];
    if (oc[cur] % i != 0) {
      cout << -1 << '\n';
      return;
    }
    len += oc[cur] / i;
  }
  string t, ot;
  for (long long i = 1; i <= len; i++) t += s[i - 1];
  ot = t;
  string res = "";
  for (auto c : ord) {
    res += t;
    string nxt;
    for (char x : t)
      if (x != c) nxt += x;
    t = nxt;
  }
  if (res != s) {
    cout << "-1\n";
    return;
  }
  cout << ot << ' ' << ord << '\n';
}
int main() {
  fastio();
  int t;
  cin >> t;
  while (t--) solve();
}
