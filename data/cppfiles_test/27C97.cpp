#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
void test_case() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long massimo = k - 2;
  if (m < n - 1) {
    cout << "NO" << endl;
    return;
  }
  if (n == 1) {
    if (m == 0 && massimo >= 0) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
    return;
  }
  if (massimo <= 0) {
    cout << "NO" << endl;
    return;
  }
  if (m > (n * (n - 1)) / 2) {
    cout << "NO" << endl;
    return;
  }
  if (m == (n * (n - 1)) / 2) {
    cout << "YES" << endl;
    return;
  }
  cout << (massimo >= 2 ? "YES" : "NO") << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    test_case();
  }
}
