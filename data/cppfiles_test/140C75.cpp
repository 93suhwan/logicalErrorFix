#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {-1, 0, 1, 0, -1, -1, 1, 1, 0};
const int dy[9] = {0, 1, 0, -1, -1, 1, -1, 1, 0};
long long n;
void solve() {
  long long a, b, c;
  {
    long long left = 0, right = 1e5;
    while (left < right) {
      long long mid = left + right + 1 >> 1;
      long long y = mid * mid;
      if (y <= n)
        left = mid;
      else
        right = mid - 1;
    }
    a = left;
  }
  {
    long long left = 0, right = 1e5;
    while (left < right) {
      long long mid = left + right + 1 >> 1;
      long long y = mid * mid * mid;
      if (y <= n)
        left = mid;
      else
        right = mid - 1;
    }
    b = left;
  }
  {
    long long left = 0, right = 1e3;
    while (left < right) {
      long long mid = left + right + 1 >> 1;
      long long y = mid * mid * mid * mid * mid * mid;
      if (y <= n)
        left = mid;
      else
        right = mid - 1;
    }
    c = left;
  }
  cout << a + b - c << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    solve();
  }
  return 0;
}
