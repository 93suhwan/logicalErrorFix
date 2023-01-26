#include <bits/stdc++.h>
using namespace std;
long long flag = 0;
string tree[1000][1000];
bool traversable(string grid[], long long x, long long y) {
  bool check = true;
  if (y > 1 || y < 0 || x < 0 || x >= grid[0].size()) return false;
  if (grid[y][x] == '1') return false;
  return true;
}
void traverse(string grid[], long long x, long long y) {
  if (!traversable(grid, x, y)) return;
  if (x == grid[0].size() - 1 && y == 1) {
    flag = 1;
    return;
  }
  if (!flag) traverse(grid, x + 1, y);
  if (!flag) traverse(grid, x, y + 1);
  if (!flag) traverse(grid, x + 1, y + 1);
  if (!flag) traverse(grid, x + 1, y - 1);
  if (!flag) traverse(grid, x, y - 1);
}
void solve() {
  long long n;
  cin >> n;
  string grid[2];
  cin >> grid[0];
  cin >> grid[1];
  traverse(grid, 0, 0);
  if (flag == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
}
