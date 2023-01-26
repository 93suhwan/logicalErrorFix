#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, k;
char a[N];
bool ok() {
  int sz = strlen(a);
  for (int i = 1; i < sz; ++i)
    if (a[i] != a[i - 1]) return 1;
  return 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    int one = count(a, a + strlen(a), '1'), z = strlen(a) - one;
    if (one && !z)
      puts("0");
    else if (!one && z)
      puts("1");
    else if (z > 1 && ok())
      puts("2");
    else
      puts("1");
  }
  return 0;
}
