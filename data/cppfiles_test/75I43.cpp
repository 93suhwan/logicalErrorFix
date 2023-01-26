#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 1, r = n;
  while (l < n && a[l] < a[l + 1]) l++;
  while (r > 1 && a[r] < a[r - 1]) r--;
  r = n - r + 1;
  if ((l + r) & 1)
    printf("Alice");
  else
    printf("Bob");
  return 0;
}
