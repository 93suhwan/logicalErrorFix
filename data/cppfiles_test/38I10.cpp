#include <bits/stdc++.h>
using namespace std;
struct IO {
  static const int S = 1 << 21;
  char buf[S], *p1, *p2;
  int st[105], Top, bs;
  IO& operator<<(const char c) {
    pc(c);
    return *this;
  }
  ~IO() { clear(); }
  void clear() {
    fwrite(buf, 1, Top, stdout);
    Top = 0;
  }
  void pc(const char c) {
    Top == S && (clear(), 0);
    buf[Top++] = c;
  }
  char gc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2)
               ? EOF
               : *p1++;
  }
  IO() { bs = 6; }
  IO& operator>>(char& c) {
    while (T(c = gc()))
      ;
    return *this;
  }
  int T(char c) { return c == ' ' || c == '\n' || c == '\r' || c == EOF; }
  IO& operator>>(string& s) {
    s = "";
    char c;
    while (T(c = gc()))
      ;
    while (s += c, !T(c = gc()))
      ;
    return *this;
  }
  IO& operator>>(char* c) {
    while (T(*c = gc()))
      ;
    while (!T(*++c = gc()))
      ;
    return *c = ' ', *this;
  }
  IO& operator>>(double& x) {
    x = 0;
    bool f = 0;
    char c;
    while (!isdigit(c = gc())) f ^= (c == '-');
    while (x = x * 10 + (c ^ 48), isdigit(c = gc()))
      ;
    if (c != '.') return *this;
    c = gc();
    double k = 1;
    while (x += (c ^ 48) * (k *= 0.1), isdigit(c = gc()))
      ;
    f && (x = -x);
    return *this;
  }
  template <typename T>
  IO& operator>>(T& x) {
    x = 0;
    bool f = 0;
    char c;
    while (!isdigit(c = gc())) f ^= (c == '-');
    while (x = (x << 3) + (x << 1) + (c ^ 48), isdigit(c = gc()))
      ;
    f && (x = -x);
    return *this;
  }
  IO& operator<<(string s) {
    int len = s.length();
    for (int i = 0; i < len; i++) pc(s[i]);
    return *this;
  }
  IO& operator<<(char* c) {
    int len = strlen(c);
    for (int i = 0; i < len; i++) pc(c[i]);
    return *this;
  }
  IO& operator<<(const char* c) {
    int len = strlen(c);
    for (int i = 0; i < len; i++) pc(c[i]);
    return *this;
  }
  IO& operator<<(double x) {
    x < 0 && (pc('-'), x = -x);
    if (!bs) return *this << long long(x + 0.5);
    *this << long long(x) << '.';
    x -= long long(x);
    for (int i = 1; i < bs; i++) pc(int(x *= 10) + '0'), x -= int(x);
    pc(int(x * 10 + 0.5) + '0');
    return *this;
  }
  template <typename T>
  IO& operator<<(T x) {
    x < 0 && (pc('-'), x = -x);
    while (st[++st[0]] = x % 10, x /= 10)
      ;
    while (st[0]) pc(48 ^ st[st[0]--]);
    return *this;
  }
} fout;
const int N = 1e6 + 10;
int n, m, q;
string s[N];
vector<int> ans;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int j = 1; j < m; j++) {
    for (int i = 1; i < n; i++) {
      if (s[i - 1][j] == 'X' && s[i][j - 1] == 'X') {
        ans.push_back(j);
      }
    }
  }
  cin >> q;
  sort(ans.begin(), ans.end());
  for (auto x : ans) fout << x << '\n';
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x == y) {
      fout << "YES\n";
      continue;
    }
    if (ans.empty() || ans[ans.size() - 1] <= x) {
      fout << "YES\n";
      continue;
    }
    if (*upper_bound(ans.begin(), ans.end(), x) <= y)
      fout << "NO\n";
    else
      fout << "YES\n";
  }
  return 0;
}
