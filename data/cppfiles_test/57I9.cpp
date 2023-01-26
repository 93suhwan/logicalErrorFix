#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (k > n) {
      cout << "NO" << '\n';
      continue;
    }
    if (k == n) {
      cout << "YES" << '\n';
      continue;
    }
    if (s == 1) {
      cout << "NO" << '\n';
      continue;
    }
    long long xx = (n) / (2 * k);
    long long su = xx * (k);
    long long zz = (n % (2 * k));
    if (zz > 0) {
      su += min(zz, k);
    }
    if (((n - k) % (2 * k)) < k) {
      su--;
    }
    su--;
    if (su < s - 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}
