#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const long long N = 5e5 + 10, inf = 1e17;
long long n, d, cntb, cntc, ans;
struct node {
  long long s, a;
  bool operator<(const node& t) const { return a > t.a; }
} a[N], b[N], c[N];
multiset<node> s;
multiset<node>::iterator it;
inline bool cmp_s(node a, node b) { return a.s < b.s; }
inline bool cmp_a(node a, node b) { return a.a < b.a; }
signed main() {
  n = read();
  d = read();
  for (register long long i = 1; i <= n; i++) {
    a[i].s = read();
    a[i].a = read();
    if (a[i].s < d) continue;
    if (a[i].s >= a[i].a)
      b[++cntb] = a[i];
    else
      c[++cntc] = a[i];
  }
  sort(b + 1, b + 1 + cntb, cmp_a);
  sort(c + 1, c + 1 + cntc, cmp_s);
  long long i, j;
  for (i = 1, j = 1; i <= cntb && j <= cntc;) {
    (b[i].a > c[j].s) ? s.insert(c[j++]), 0 : (i++);
    while (!s.empty() && (*s.begin()).a > b[i].s) s.erase(s.begin());
  }
  vector<node> seq;
  for (; j <= cntc; j++) seq.push_back(c[j]);
  for (it = s.begin(); it != s.end(); it++) seq.push_back(*it);
  sort(seq.begin(), seq.end(), cmp_a);
  j = 1;
  for (long long i = 0; i < (long long)seq.size(); i++) {
    if (seq[i].s >= d) {
      while (j <= cntb && b[j].a <= seq[i].s) {
        if (b[j].s >= d) ans++;
        j++;
      }
      ans++;
      d = max(d, seq[i].a);
    }
  }
  sort(b + j, b + 1 + cntb, cmp_s);
  for (register long long i = j; i <= cntb; i++) {
    if (b[i].s >= d) {
      ans++;
      d = b[i].a;
    }
  }
  cout << ans << '\n';
  return 0;
}
