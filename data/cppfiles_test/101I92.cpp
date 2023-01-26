#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
long long p[maxn];
int v[maxn];
int r[maxn];
int b[maxn];
long long n, nr, nb, rr, bb;
bool cmp(int a, int b) { return a > b; }
void solve() {
  cin >> n;
  int fl = 0;
  nr = nb = rr = bb = 0;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    char ch;
    cin >> ch;
    if (ch == 'R')
      v[i] = 1, r[++nr] = p[i];
    else if (ch == 'B')
      v[i] = -1, b[++nb] = p[i];
  }
  sort(r + 1, r + 1 + nr, cmp);
  sort(b + 1, b + 1 + nb);
  long long anr = 0, anb = 0;
  for (int i = 1; i <= nr; i++) {
    anr += (n - i + 1);
    rr += r[i];
    if (rr > anr) fl = 1;
  }
  for (int i = 1; i <= nb; i++) {
    anb += i;
    bb += b[i];
    if (bb < anb) fl = 1;
  }
  if (fl == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  int __;
  cin >> __;
  while (__--) solve();
}
