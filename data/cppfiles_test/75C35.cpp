#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 10;
bool ans;
int a[maxn];
int n;
bool searchLeft() {
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (a[i + 1] <= a[i]) break;
    cnt++;
  }
  return cnt & 1;
}
bool searchRight() {
  int cnt = 1;
  for (int i = n; i > 1; i--) {
    if (a[i - 1] <= a[i]) break;
    cnt++;
  }
  return cnt & 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  ans = searchRight() || searchLeft();
  if (ans)
    printf("Alice");
  else {
    if (n == 1 || a[1] <= a[n] && a[n - 1] <= a[n] ||
        a[2] <= a[1] && a[n] <= a[1])
      printf("Alice");
    else
      printf("Bob");
  }
  return 0;
}
