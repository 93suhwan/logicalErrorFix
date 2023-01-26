#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  if (x <= 1) {
    return false;
  }
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  int s = 0;
  for (int i = 0; i < n; i += 1) {
    cin >> a[i].first;
    s += a[i].first;
    a[i].second = i;
  }
  if (!isPrime(s)) {
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
      cout << i << ' ';
    }
    cout << endl;
  } else {
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      if (!isPrime(s - a[i].first)) {
        cout << n - 1 << endl;
        for (int x = 0; x < n; ++x) {
          if (a[i].second != a[x].second) {
            cout << a[x].second + 1 << ' ';
          }
        }
        cout << endl;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
