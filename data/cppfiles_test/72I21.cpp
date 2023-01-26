#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
constexpr int kInf = 1000 * 1000 * 1000 + 7;
constexpr long long kInfLL = 1e18;
int Ask(int x, int y) {
  cout << "? " << x << ' ' << y << endl;
  int d;
  cin >> d;
  return d;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long bound = 1e9;
  long long a = Ask(1, 1);
  long long b = Ask(1, bound);
  long long c = Ask(bound, 1);
  long long x1 = (a + b - bound + 3) / 2;
  long long y1 = a - x1 + 2;
  long long min_x = Ask(1, y1) + 1;
  long long y2 = (a + c - bound + 3) / 2;
  long long x2 = a - x2 + 2;
  long long min_y = Ask(1, x2) + 1;
  long long max_x = bound - Ask(bound, min_y);
  long long max_y = bound - Ask(min_x, bound);
  cout << "! " << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl;
}
