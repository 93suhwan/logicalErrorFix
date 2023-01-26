#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
long long a[maxn];
int n;
long long llen, rlen;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int i = 0, j = n - 1;
  while (i < n && a[i] < a[i + 1]) i++;
  while (j > 0 && a[j] < a[j - 1]) j--;
  puts((i + 1) & 1 || (n - j) & 1 ? "Alice" : "Bob");
  return 0;
}
