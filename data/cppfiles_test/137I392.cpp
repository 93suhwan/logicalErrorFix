#include <bits/stdc++.h>
using namespace std;
bool check(int a[], int b[], int La, int Lb, int L) {
  if (La + L > Lb) return false;
  for (int i = L, j = 0; j < La; i++, j++)
    if (a[j] != b[i]) return false;
  return true;
}
bool solve(int a[], int b[], int La, int Lb) {
  int flag = 0;
  for (int i = 0; i < Lb; i++) {
    if (a[0] == b[i] && check(a, b, La, Lb, i)) {
      for (int j = 0; j < i; j++)
        if (b[j] == 0) {
          flag = 1;
          break;
        }
      if (flag == 0) {
        for (int j = i + La; j < Lb; j++)
          if (b[j] == 0) {
            flag = 1;
            break;
          }
      }
      if (flag == 0) return true;
    }
  }
  return false;
}
int main() {
  long long n, m;
  scanf("%lld %lld", &n, &m);
  int a[100] = {0}, b[100] = {0}, La = 0, Lb = 0;
  if (n == m) {
    printf("YES\n");
    return 0;
  }
  while (n) {
    a[La++] = n % 2;
    n /= 2;
  }
  while (m) {
    b[Lb++] = m % 2;
    m /= 2;
  }
  if (solve(a, b, La, Lb)) {
    printf("YES\n");
    return 0;
  }
  for (int i = La - 1; i >= 0; i--)
    if (a[i] != 0) {
      La = i + 1;
      break;
    }
  reverse(a, a + La);
  if (solve(a, b, La, Lb))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
