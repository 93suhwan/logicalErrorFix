#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, k, a[N];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) a[i] = (i - 1) / k + 1;
  printf("%d\n", a[n]);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", a[j]);
  return 0;
}
