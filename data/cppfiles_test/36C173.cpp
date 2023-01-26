#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using i64 = long long;
const i64 MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  vector<bool> sieve(20000, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int i = 2; i < 20000; ++i) {
    if (sieve[i]) {
      for (int j = 2 * i; j < 20000; j += i) {
        sieve[j] = false;
      }
    }
  }
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s += a[i];
    }
    int skip = -1;
    if (sieve[s]) {
      for (int i = 0; i < n; ++i) {
        if (!sieve[s - a[i]]) {
          skip = i;
          break;
        }
      }
    }
    if (skip == -1)
      cout << n << '\n';
    else
      cout << n - 1 << '\n';
    for (int i = 0; i < n; ++i) {
      if (i == skip) continue;
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
