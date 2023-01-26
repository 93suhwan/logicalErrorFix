#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
const int inf = 1e9 + 10;
const long long llinf = 1e18 + 10;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
int n;
int a[maxn];
int l[maxn];
int r[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = n; i >= 1; i--) {
    l[i] = 1;
    if (i != n) {
      if (a[i] < a[i + 1]) l[i] = l[i + 1] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    r[i] = 1;
    if (i != 1) {
      if (a[i] < a[i - 1]) r[i] = r[i - 1] + 1;
    }
  }
  int L = 1, R = n;
  int cnt = 0, mi = -1;
  while (L <= R) {
    if (n == 1) break;
    if (mi >= a[L] && mi >= a[R]) break;
    cnt++;
    if (a[L] <= mi) {
      if (r[R] % 2 == 0) cnt++;
      break;
    } else if (a[R] <= mi) {
      if (l[L] % 2 == 0) cnt++;
      break;
    } else {
      if (a[L] >= a[R]) {
        if (l[L] % 2) {
          break;
        } else {
          mi = a[R];
          R--;
        }
      } else if (a[L] < a[R]) {
        if (r[R] % 2)
          break;
        else {
          mi = a[L];
          L++;
        }
      }
    }
  }
  if (cnt % 2 || n == 1)
    printf("Alice\n");
  else
    printf("Bob\n");
}
