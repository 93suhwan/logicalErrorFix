#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int INF = 1e9 + 5;
const long long INF_INF = 1e18 + 5;
const long double PI = acos(-1.0);
long long Power(long long x, long long y) {
  if (!y) {
    return 1;
  }
  long long s = Power(x, y >> 1);
  s *= s;
  if (y & 1) {
    s *= x;
  }
  return s;
}
void TestCase() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n + 1, vector<char>(m + 1));
  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= m; col++) {
      cin >> grid[row][col];
    }
  }
  vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
  for (int row = 2; row <= n; row++) {
    for (int col = 1; col <= m; col++) {
      if ((grid[row][col] == 'X') && (grid[row - 1][col + 1] == 'X')) {
        prefix[row][col] = 1;
      }
    }
  }
  for (int row = 2; row <= n; row++) {
    for (int col = 2; col <= m; col++) {
      prefix[row][col] += prefix[row][col - 1];
    }
  }
  for (int col = 1; col <= m; col++) {
    for (int row = 2; row <= n; row++) {
      prefix[row][col] += prefix[row - 1][col];
    }
  }
  int queries;
  cin >> queries;
  while (queries--) {
    int col1, col2;
    cin >> col1 >> col2;
    if (col1 == col2) {
      cout << "YES" << '\n';
    } else {
      col2--;
      int sumAll = prefix[n][col2] - prefix[n][col1 - 1];
      if (sumAll) {
        cout << "NO" << '\n';
      } else {
        cout << "YES" << '\n';
      }
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testCases = 1;
  while (testCases--) {
    TestCase();
  }
  return 0;
}
