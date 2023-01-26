#include <bits/stdc++.h>
using namespace std;
bool not_prime(int a) {
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) {
      return true;
    }
  }
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int tot = accumulate(a.begin(), a.end(), 0);
  if (not_prime(tot)) {
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  } else {
    bool used = false;
    cout << n - 1 << '\n';
    for (int i = 0; i < n; ++i) {
      if (!used && a[i] % 2 == 1) {
        used = true;
      } else {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
