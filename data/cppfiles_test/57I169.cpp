#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s < k) {
      cout << "NO" << '\n';
      continue;
    }
    if (s == k) {
      cout << "YES" << '\n';
      continue;
    }
    long long mn = max(1ll, n - s + k), mx = min(n - 1, k);
    if (mn <= mx)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
