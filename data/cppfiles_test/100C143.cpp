#include <bits/stdc++.h>
using namespace std;
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
const int N = 2e5 + 5;
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  long long ans = a[1];
  for (int i = 2; i <= n; i++) {
    ans = max(ans, 1ll * (a[i] - a[i - 1]));
  }
  cout << ans << endl;
}
int main() {
  startTime = clock();
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
