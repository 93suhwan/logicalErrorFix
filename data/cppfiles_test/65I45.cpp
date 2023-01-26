#include <bits/stdc++.h>
using namespace std;
long long n, a[200000 + 1], t1[200000 + 1], t2[200000 + 1], length1, length2,
    lst, ps1, ps2;
bool op;
char c[200000 + 1];
void output(long long x, bool opt) {
  if (!(op ^ opt))
    cout << x << ' ' << 'L' << endl;
  else
    cout << x << ' ' << 'R' << endl;
  return;
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  for (long long i = 1; i <= n; ++i) cin >> c[i];
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; ++i) {
    if (i & 1)
      t1[++length1] = a[i];
    else
      t2[++length2] = a[i];
  }
  if ((c[n] == 'L') ^ (n & 1)) {
    op = 1;
    for (long long i = 1; i <= n; ++i) c[i] = 'L' + 'R' - c[i];
  }
  for (long long i = 1; i + 1 <= n; i += 2) {
    if (c[i] == 'L' && c[i + 1] == 'L') {
      if (!lst)
        lst = t1[ps1 + 1], output(t1[ps1 + 2], 0), output(t2[ps2 + 1], 1),
        ps1 += 2, ps2++;
      else
        output(t1[ps1 + 1], 0), output(t2[ps2 + 1], 1), ps1++, ps2++;
    } else if (c[i] == 'L' && c[i + 1] == 'R') {
      if (!lst)
        output(t1[ps1 + 1], 0), output(t2[ps2 + 1], 1), ps1++, ps2++;
      else
        output(lst, 0), output(t2[ps2 + 1], 1), ps2++, lst = 0;
    } else if (c[i] == 'R' && c[i + 1] == 'L') {
      if (!lst)
        lst = t1[ps1 + 1], output(t2[ps2 + 1], 1), output(t1[ps1 + 2], 0),
        ps1 += 2, ps2++;
      else
        output(t2[ps2 + 1], 1), output(t1[ps1 + 1], 0), ps1++, ps2++;
    } else {
      if (!lst)
        output(t2[ps2 + 1], 1), output(t1[ps1 + 1], 0), ps1++, ps2++;
      else
        output(t2[ps2 + 1], 1), output(lst, 0), ps2++, lst = 0;
    }
  }
  if (n & 1) {
    if (lst)
      output(lst, 0);
    else
      output(t1[length1], 0);
  }
  return 0;
}
