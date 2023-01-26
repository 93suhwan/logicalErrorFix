#include <bits/stdc++.h>
using namespace std;
int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
const int N = 3e2 + 5;
int n, m, p, q;
pair<int, int> a[N * N];
int id(int i, int j) { return (i - 1) * m + j; }
void work() {
  n = read(), m = read();
  for (int i = 1; i <= n * m; i++) {
    a[i] = (pair<int, int>){read(), i};
  }
  sort(a + 1, a + 1 + n * m);
  for (int i = 1; i <= n * m; i++) {
    a[i].second *= -1;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    sort(a + id(i, 1), a + id(i, m) + 1);
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k < j; k++) {
        if (a[id(i, j)].second < a[id(i, k)].second) res++;
      }
    }
  }
  cout << res << "\n";
}
int main() {
  q = read();
  while (q--) work();
  return 0;
}
