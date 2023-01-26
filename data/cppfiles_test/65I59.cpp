#include <bits/stdc++.h>
using namespace std;
long long n, a[200000 + 1];
char c[200000 + 1];
void output(long long x, bool op) {
  if (!op)
    cout << x << ' ' << 'L' << endl;
  else
    cout << x << ' ' << 'R' << endl;
  return;
}
void work(char op1, char op2, long long x, long long y) {
  if (op1 == 'L' && op2 == 'L')
    output(y, 0), output(x, 1);
  else if (op1 == 'L' && op2 == 'R')
    output(x, 0), output(y, 1);
  else if (op1 == 'R' && op2 == 'L')
    output(x, 1), output(y, 0);
  else
    output(y, 1), output(x, 0);
  return;
}
void solve(long long l, long long r) {
  if (l == r) {
    if (c[1] == 'L')
      output(a[l], 0);
    else
      output(a[l], 1);
  } else if (l + 1 == r)
    work(c[1], c[2], a[l], a[r]);
  else {
    long long lst = r - l + 1;
    if (c[lst] == c[lst - 2])
      solve(l, r - 2), work(c[lst - 1], c[lst], a[r - 1], a[r]);
    else
      solve(l + 1, r - 1), work(c[lst - 1], c[lst], a[l], a[r]);
  }
  return;
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  for (long long i = 1; i <= n; ++i) cin >> c[i];
  sort(a + 1, a + n + 1), solve(1, n);
  return 0;
}
