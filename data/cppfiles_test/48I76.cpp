#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 50;
int n, m, T;
int c[maxn];
long long ans;
int lowbit(int i) { return i & (-i); }
int insert(int i, int x) {
  while (i <= n) {
    c[i] += x;
    i += lowbit(i);
  }
  return 0;
}
int getsum(int i) {
  int sum = 0;
  while (i > 0) {
    sum += c[i];
    i -= lowbit(i);
  }
  return sum;
}
int main() {
  scanf("%d", &T);
  for (int oo = 1; oo <= T; ++oo) {
    scanf("%d", &n);
    ans = 0;
    for (int i = 1; i <= n; ++i) c[i] = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      insert(a, 1);
      ans += i - getsum(a);
    }
    if (ans && n < 3) {
      printf("NO\n");
      continue;
    }
    if (ans % 2 == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
