#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5 + 5;
int t, n, a[N];
i64 ans, sum;
map<int, i64> cnt;
int main() {
  cin >> t;
  while (t--) {
    ans = sum = 0;
    cnt.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    i64 cur = (i64)(n - 2) * sum;
    if (cur % n) {
      puts("0");
      continue;
    }
    i64 x = sum - cur / n;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 1; i <= n; i++) {
      if (x - a[i] == a[i])
        ans += cnt[a[i]] - 1;
      else
        ans += cnt[a[i]];
    }
    cout << ans / 2 << "\n";
  }
  return 0;
}
