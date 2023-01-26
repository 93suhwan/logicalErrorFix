#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 50;
string a[N];
char str[N];
int b[N];
int cmp(int x, int y) { return a[x] < a[y]; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = (1), _t = (n); i <= _t; ++i) {
    scanf("%s", str);
    for (int j = (0), _t = (m - 1); j <= _t; ++j) {
      if (j % 2 == 0)
        a[i] += str[j];
      else
        a[i] += 'Z' - str[j] + 'A';
    }
    b[i] = i;
  }
  sort(b + 1, b + n + 1, cmp);
  for (int i = (1), _t = (n); i <= _t; ++i) printf("%d ", b[i]);
  putchar('\n');
  return 0;
}
