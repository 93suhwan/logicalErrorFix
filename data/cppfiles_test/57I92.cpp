#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 5;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (k > s) {
      cout << "NO" << endl;
      continue;
    }
    long long cnt = n / k, sum = 0;
    sum += cnt * k * 2 + n % k;
    if (sum <= s)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
