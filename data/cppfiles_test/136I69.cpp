#include <bits/stdc++.h>
using namespace std;
const int NMAX = 2e5 + 5;
int v[NMAX];
int dif[NMAX];
int d[NMAX];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  int last = n - 1;
  for (int i = 0; i < n; ++i) {
    dif[i] = v[last] - v[i];
    last = i;
  }
  for (int i = 0; i < n; ++i) {
    int next = (i + 1) % n;
    d[i] = dif[i] - dif[next];
    int check = d[i];
    if (check < 0) check *= -1;
    if (check % n) {
      printf("NO\n");
      return;
    }
    d[i] /= n;
  }
  for (int i = n - 2; i >= 0; --i) d[i] += d[i + 1];
  if (d[0] != 0) {
    printf("NO\n");
    return;
  }
  int sum_n = 1;
  int sum = 0;
  for (int i = n - 1, j = 2; i > 0; --i, ++j) {
    sum_n += j;
    sum += j * d[i];
  }
  v[0] -= sum;
  if (v[0] < 0 || v[0] % sum_n) {
    printf("NO\n");
    return;
  }
  int nn = v[0] / sum_n;
  for (int i = 0; i < n; ++i)
    if (nn + d[i] <= 0) {
      printf("NO\n");
      return;
    }
  printf("YES\n");
  for (int i = 0; i < n; ++i) printf("%d ", nn + d[i]);
  printf("\n");
}
int main() {
  int n;
  scanf("%d", &n);
  for (; n; n--) solve();
  return 0;
}
