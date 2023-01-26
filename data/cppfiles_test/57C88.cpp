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
    if (s == k) {
      cout << "YES" << '\n';
      continue;
    }
    if (s < k) {
      cout << "NO" << '\n';
      continue;
    }
    long long a = s % k + 1;
    long long b = k - a;
    long long m;
    if ((s / k) & 1)
      m = s + k - a;
    else
      m = s + k - b;
    if (m >= 2 * n + 1)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
  return 0;
}
