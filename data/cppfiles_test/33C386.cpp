#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  long long mx = -1;
  for (int i = 0; i < n - 1; i++) {
    mx = max(mx, 1LL * arr[i] * arr[i + 1]);
  }
  printf("%lld\n", mx);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
