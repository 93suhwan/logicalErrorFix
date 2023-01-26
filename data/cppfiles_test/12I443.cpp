#include <bits/stdc++.h>
using namespace std;
vector<int> dx{1, 0, -1, 0, 1, 1, -1, -1};
vector<int> dy{0, 1, 0, -1, 1, -1, 1, -1};
const int mxN = 1e5 + 5;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n & 1 && m & 1) {
      { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
    } else if (n & 1) {
      int x = m / 2;
      int y = k / x;
      if (k % x == 0 && y & 1) {
        { 1 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
      } else {
        { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
      }
    } else if (m & 1) {
      int x = n / 2;
      int k2 = ((m * n) / 2) - k;
      int y = k2 / x;
      if (k2 % x == 0 && y & 1) {
        { 1 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
      } else {
        { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
      }
    } else {
      if (k & 1) {
        { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
      } else {
        { 1 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
      }
    }
  }
  return 0;
}
