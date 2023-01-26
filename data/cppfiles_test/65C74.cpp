#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N], ans[N];
string s;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (register int i = (1); i <= (n); ++i) cin >> a[i];
  cin >> s;
  for (register int i = (1); i <= (n); ++i) b[i] = (s[i - 1] == 'L');
  int p = n, fu = (b[n] == 1);
  for (register int i = (n - 1); i >= (1); --i)
    if (b[i] != b[i + 1]) ans[i + 1] = p--;
  ans[1] = p--;
  sort(a + 1, a + 1 + n);
  for (register int i = (1); i <= (n); ++i)
    if (!ans[i]) ans[i] = p--;
  for (register int i = (1); i <= (n); ++i)
    cout << a[ans[i]] << ' ' << (((ans[i] & 1) ^ (n & 1) ^ fu) ? 'L' : 'R')
         << '\n';
  return 0;
}
