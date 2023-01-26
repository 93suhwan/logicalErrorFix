#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n) {
  if (n < 2) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    char s[60];
    int a[60];
    scanf("%d", &n);
    scanf("%s", &s);
    for (int i = 0; i < n; i++) a[i] = s[i] - '0';
    int len = 0, res;
    int flag = 1;
    for (int i = 0; i < n && flag; i++) {
      if (!is_prime(a[i]) || a[i] == 1) {
        len = 1;
        res = a[i];
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (!is_prime(a[i] * 10 + a[j])) {
            len = 2;
            res = a[i] * 10 + a[j];
            break;
          }
        }
      }
    }
    printf("%d\n", len);
    printf("%d\n", res);
  }
  return 0;
}
