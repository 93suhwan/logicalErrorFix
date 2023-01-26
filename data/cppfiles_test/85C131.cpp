#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, k;
char a[N];
bool ok() {
  int sz = strlen(a), last = -1;
  for (int i = 0; i < sz; ++i)
    if (a[i] == '0') {
      if (last == -1)
        last = i;
      else if (last + 1 != i)
        return 1;
      last = i;
    }
  return 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s", a);
    int one = count(a, a + strlen(a), '1'), z = strlen(a) - one;
    if (ok())
      puts("2");
    else if (one && !z)
      puts("0");
    else
      puts("1");
  }
  return 0;
}
