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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int bound = 1e9;
  int a = Ask(1, 1);
  int b = Ask(1, bound);
  int x = (a + b - bound + 3) / 2;
  int y = a - x + 2;
  int val = Ask(1, y);
  int min_x = val + 1;
  int l = -1, r = y;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int cur = Ask(1, y - m);
    if (val == cur)
      l = m;
    else
      r = m;
  }
  int min_y = y - l;
  int max_y = (a + b + 1) % 2 ? y + l - 1 : y + l;
  int max_x = bound - Ask(bound, min_y);
  cout << "! " << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl;
}
