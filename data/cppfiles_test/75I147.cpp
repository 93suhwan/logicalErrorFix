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
  if (a[1] < a[n]) {
    ans = searchRight();
  } else if (a[1] > a[n]) {
    ans = searchLeft();
  } else
    ans = searchLeft() || searchRight();
  if (ans)
    printf("Alice");
  else
    printf("Bob");
  return 0;
}
