#include <bits/stdc++.h>
using namespace std;
bool isrange(int second, int first, int n, int m) {
  if (0 <= second && second < n && 0 <= first && first < m) return true;
  return false;
}
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1},
    ddy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, ddx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
void solve(int tc) {
  int n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1 || a + b > n - 2)
    cout << "-1\n";
  else {
    if (a >= b) {
      int res = n - (a + b + 2);
      for (int e = 1; e <= res; e++) cout << e << " ";
      int lx = res + 1, rx = n;
      for (int e = 0; e < n - res; e++) {
        if (e % 2 == 0) {
          cout << (lx++) << " ";
        } else {
          cout << (rx--) << " ";
        }
      }
    } else {
      int res = n - (a + b + 2);
      for (int e = n; e > n - res; e--) cout << e << " ";
      int rx = n - res, lx = 1;
      for (int e = 0; e < n - res; e++) {
        if (e % 2 == 0) {
          cout << (rx--) << " ";
        } else {
          cout << (lx++) << " ";
        }
      }
    }
    cout << "\n";
  }
}
int main(void) {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  cin >> tc;
  for (int test_number = 1; test_number <= tc; test_number++) {
    solve(test_number);
  }
  return 0;
}
