#include <bits/stdc++.h>
using namespace std;
int read();
const int N = 2e5 + 5;
int n, a[N], k;
char s[N];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  cin >> s + 1;
  for (int i = (2); i <= (n); ++i)
    if (s[i] != s[i - 1]) ++k;
  int l = n - k, r = n - k;
  cout << a[l--] << ' ' << s[1] << endl;
  int fl1 = (s[1] == 'L'), fl2 = (s[1] == 'L');
  for (int i = (2); i <= (n); ++i)
    if (s[i] == s[i - 1])
      cout << a[l--] << ' ' << ((fl1 ^= 1) ? 'L' : 'R') << endl;
    else
      cout << a[++r] << ' ' << ((fl2 ^= 1) ? 'L' : 'R') << endl;
  return 0;
}
const int S = 1 << 21;
char p0[S], *p1, *p2;
inline int read() {
  static int x, c, f;
  x = 0;
  f = 1;
  do
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++),
    c == '-' && (f = -1);
  while (!isdigit(c));
  do
    x = x * 10 + (c & 15),
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++);
  while (isdigit(c));
  return x * f;
}
