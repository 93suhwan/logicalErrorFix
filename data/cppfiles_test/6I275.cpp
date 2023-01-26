#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
int T;
int n;
long long l[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i];
  long long ans = 1;
  for (int i = 2; i <= 1000; i++) {
    long long res = 1;
    for (int j = 2; j <= n; j++)
      if (l[j] % i == l[j - 1] % i)
        res++, ans = max(ans, res);
      else
        res = 1;
  }
  cout << ans << '\n';
}
int main(void) {
  clock_t c1 = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  cin >> T;
  while (T--) solve();
end:
  cerr << "Time Used:" << clock() - c1 << "ms" << '\n';
  return 0;
}
