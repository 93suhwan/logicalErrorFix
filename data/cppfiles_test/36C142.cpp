#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
int n, a[N];
bool isprime(int x) {
  for (int j = 2; j * j <= x; ++j) {
    if (x % j == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  cin >> n;
  int sum = 0;
  int odd = -1;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
    sum += a[i];
    if (a[i] % 2) {
      odd = i;
    }
  }
  if (!isprime(sum)) {
    cout << n << '\n';
    for (int i = 0; i < (n); ++i) {
      cout << i + 1 << ' ';
    }
  } else {
    cout << n - 1 << '\n';
    for (int i = 0; i < (n); ++i) {
      if (i != odd) {
        cout << i + 1 << ' ';
      }
    }
  }
  cout << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
