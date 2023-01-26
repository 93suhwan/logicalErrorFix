#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
long long n, a[maxn], ans;
long long res(long long one, long long two) {
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long kom = a[i], lom = INT64_MAX - 100;
    for (int j = 0; j <= one; j++) {
      for (int z = 0; z <= two; z++) {
        if (0 <= (kom - j - (2 * z)) && (kom - j - (2 * z)) % 3 == 0) {
          lom = min(lom, (kom - j - (2 * z)) / 3);
        }
      }
    }
    ans = max(ans, lom);
  }
  return ans;
}
void solve() {
  cin >> n;
  ans = INT64_MAX;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= 5; i++) {
    for (int j = 0; j <= 5; j++) {
      ans = min(ans, res(i, j) + i + j);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
