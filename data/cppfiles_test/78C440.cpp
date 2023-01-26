#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], b[N];
void work() {
  scanf("%d%d", &n, &m);
  if (m >= n * 2) {
    printf("%d\n", (m - 1) / 2);
  } else
    printf("%d\n", m - n);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
