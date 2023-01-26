#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int now, n, a[200005];
char str[200005];
char Rev(char c) {
  if (c == 'L')
    return 'R';
  else
    return 'L';
}
int b[200005];
char op[200005];
signed main() {
  n = read();
  for (register int i = (1); i <= (n); ++i) a[i] = read();
  sort(a + 1, a + n + 1);
  cin >> str + 1;
  int l = 1, r = n;
  bool rev = 1;
  for (register int i = (n); i >= (1); --i) {
    if (i == 1) {
      b[i] = a[l];
      op[i] = str[i];
      break;
    }
    if ((str[i] != str[i - 1]) != (rev)) rev ^= 1;
    if (rev)
      b[i] = a[r], op[i] = ((n - r + 1) % 2 ? str[n] : Rev(str[n])), --r;
    else
      b[i] = a[l], op[i] = ((n - l + 1) % 2 ? str[n] : Rev(str[n])), ++l;
  }
  for (register int i = (1); i <= (n); ++i)
    cout << b[i] << ' ' << op[i] << endl;
  return 0;
}
