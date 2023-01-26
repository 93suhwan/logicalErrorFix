#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int n;
int a[N];
void solve() {
  scanf("%d", &n);
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  printf("%d\n", sum % n ? 1 : 0);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
