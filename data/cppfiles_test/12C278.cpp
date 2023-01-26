#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX_N = 2e5 + 10;
int n, m, k;
void solve() {
  scanf("%d%d%d", &n, &m, &k);
  bool f;
  int row = k, col = n * m / 2 - k;
  if (row == 0) {
    if (n % 2 == 1)
      f = 0;
    else
      f = 1;
  } else if (col == 0) {
    if (m % 2 == 1)
      f = 0;
    else
      f = 1;
  } else if (m % 2 == 1) {
    if (col >= n / 2 && (col - n / 2) % 2 == 0) {
      f = 1;
    } else {
      f = 0;
    }
  } else if (n % 2 == 1) {
    if (row >= m / 2 && (row - m / 2) % 2 == 0) {
      f = 1;
    } else {
      f = 0;
    }
  } else {
    if ((abs(row - n) % n) % 2 == 1) {
      f = 0;
    } else {
      f = 1;
    }
  }
  if (f)
    printf("YES\n");
  else
    printf("NO\n");
}
int main() {
  int TCASE = 1;
  scanf("%d", &TCASE);
  while (TCASE--) solve();
  return 0;
}
