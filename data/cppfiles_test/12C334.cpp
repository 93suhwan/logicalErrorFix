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
    int l = ((m * n) / 2) - k;
    ;
    if (n & 1) {
      if (k < (m / 2)) {
        { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
        continue;
      } else {
        k -= m / 2;
      }
    } else if (m & 1) {
      if (l < (n / 2)) {
        { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
        continue;
      } else {
        l -= n / 2;
      }
    }
    if (k & 1 || l & 1) {
      { 0 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
    } else {
      { 1 ? cout << "YES" << '\n' : cout << "NO" << '\n'; };
    }
  }
  return 0;
}
