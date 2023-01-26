#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int _runtimeTerror_() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    if (i % 2 != a[i] % 2) {
      cout << "-1\n";
      return 0;
    }
  }
  vector<int> op;
  auto make_op = [&](int x) {
    for (int i = 1; i <= n; ++i) {
      if (a[i] == x) {
        op.push_back(i);
        reverse(a.begin() + 1, a.begin() + i + 1);
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == x - 1) {
        op.push_back(i - 1);
        reverse(a.begin() + 1, a.begin() + i);
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == x - 1) {
        op.push_back(i + 1);
        reverse(a.begin() + 1, a.begin() + i + 2);
        break;
      }
    }
    op.push_back(3);
    reverse(a.begin() + 1, a.begin() + 4);
    op.push_back(x);
    reverse(a.begin() + 1, a.begin() + x + 1);
  };
  for (int i = n; i >= 3; i -= 2) {
    make_op(i);
  }
  cout << (long long)op.size() << "\n";
  for (auto &j : op) cout << j << " ";
  cout << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  cin >> TESTS;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
