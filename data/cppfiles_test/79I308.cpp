#include <bits/stdc++.h>
using namespace std;
char s[55];
bool isprime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
int main() {
  int t, k;
  scanf("%d", &t);
  while (t--) {
    scanf("%d ", &k);
    scanf("%s+1", &s);
    int f = 0;
    for (int i = 1; i <= k; i++) {
      int x = s[i] - '0';
      if (x == 1 || x == 4 || x == 6 || x == 8 || x == 9) {
        printf("1\n%d\n", x);
        f = 1;
        break;
      }
    }
    if (f) continue;
    for (int i = 1; i <= k; i++) {
      for (int j = i + 1; j <= k; j++) {
        int x = (s[i] - '0') * 10 + s[j] - '0';
        if (!isprime(x)) {
          printf("2\n%d\n", x);
          f = 1;
          break;
        }
      }
      if (f) break;
    }
  }
  return 0;
}
