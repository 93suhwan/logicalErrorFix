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
  int x = (a + b - bound) / 2;
  int val = Ask(1, x);
  int l = -1, r = x;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int cur = Ask(1, x - l);
    if (val == cur)
      l = m;
    else
      r = m;
  }
  int min_x = x - l;
  int max_x = (a + b) % 2 ? x + l + 1 : x + l;
  int min_y = a - min_x;
  int c = Ask(bound, 1);
  int d = (a + c - bound) / 2 - (a - min_x);
  int max_y = (a + c) % 2 ? min_y + d + 1 : min_y + d;
  cout << "! " << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl;
}
