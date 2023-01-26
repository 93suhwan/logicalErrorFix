#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 4e6 + 10;
const int N = 1e5 + 10;
int n, m;
int a[4][N];
int sum1[N], sum2[N];
void work() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[1][i];
    sum1[i] = a[1][i] + sum1[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[2][i];
    sum2[i] = a[2][i] + sum2[i - 1];
  }
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, max(sum2[i - 1], sum1[n] - sum1[i]));
  }
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) work();
  return 0;
}
