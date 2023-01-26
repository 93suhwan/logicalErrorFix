#include <bits/stdc++.h>
using namespace std;
int T, n, a[110];
int get() {
  char ch = getchar();
  while (ch != 'R' && ch != 'B' && ch != '?') ch = getchar();
  if (ch == '?') return -1;
  return ch == 'R';
}
void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = get();
  int st = 0, res = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] != -1) {
      st = i;
      break;
    }
  for (int i = st + 1; i <= n; i++) {
    if (a[i] == -1) a[i] = 1 - a[i - 1];
    if (a[i] == a[i - 1]) res++;
  }
  for (int i = st - 1; i >= 1; i--) {
    if (a[i] == -1) a[i] = 1 - a[i + 1];
    if (a[i] == a[i + 1]) res++;
  }
  if (st == 0)
    for (int i = 1; i <= n; i++) a[i] = i & 1;
  for (int i = 1; i <= n; i++) printf("%c", a[i] ? 'R' : 'B');
  cout << endl;
}
int main() {
  a[0] = -2;
  cin >> T;
  while (T--) init();
}
