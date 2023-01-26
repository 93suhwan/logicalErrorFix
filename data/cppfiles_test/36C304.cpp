#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool isPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (!isPrime(sum)) {
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
      cout << i << ' ';
    }
    cout << '\n';
  } else {
    cout << n - 1 << '\n';
    int oddpos = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 != 0) {
        oddpos = i;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i != oddpos) cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
