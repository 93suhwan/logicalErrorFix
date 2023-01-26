#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(vector<T>& a) {
  for (auto& e : a) {
    cin >> e;
  }
}
template <class T>
void print(vector<T>& a) {
  for (auto& e : a) {
    cout << e << ' ';
  }
  cout << '\n';
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> a(n);
  read(a);
  if (n == 1) {
    cout << h << '\n';
    return;
  }
  vector<long long> b;
  for (long long i = 1; i < n; ++i) {
    b.push_back(a[i] - a[i - 1]);
  }
  long long l = 0, r = 1e18;
  while (l + 1 != r) {
    long long m = (l + r) / 2;
    long long res = m;
    for (long long i = 0; i < n - 1; ++i) {
      res += min(m, b[i]);
    }
    if (res >= h) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
