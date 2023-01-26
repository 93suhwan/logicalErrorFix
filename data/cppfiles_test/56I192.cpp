#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = long unsigned long;
using ld = double long;
struct pt {
  int x, y;
  int operator*(const pt& b) const { return x * b.x + y * b.y; }
  pt operator+(const pt& b) const { return {x + b.x, y + b.y}; }
  bool operator!() const { return x != 0 || y != 0; }
};
int fit(int x) { return max(1, min(x, 8)); }
pt mv(pt p) {
  cout << p.x << ' ' << p.y << '\n' << flush;
  string s;
  cin >> s;
  if (s == "Down") return {1, 0};
  if (s == "Up") return {-1, 0};
  if (s == "Right") return {0, 1};
  if (s == "Left") return {0, -1};
  if (s == "Down-Right") return {1, 1};
  if (s == "Down-Left") return {1, -1};
  if (s == "Up-Right") return {-1, 1};
  if (s == "Up-Left") return {-1, -1};
  return {0, 0};
}
int main() {
  ios::sync_with_stdio(!cin.tie(0));
  int t;
  cin >> t;
  while (t--) {
    bool found = false;
    for (int c : {7, 6, 5, 4, 3, 2, 1}) {
      if (!!mv({2, c})) {
        found = true;
        break;
      }
    }
    if (found) continue;
    pt q = {-1, -1}, d = mv({1, 1});
    int u = 2, v = 8, l = 2, r = 8;
    auto getq = [&]() {
      pt z;
      z.x = q.x == -1 ? u - 1 : v + 1;
      z.y = q.y == -1 ? l - 1 : r + 1;
      return z;
    };
    while (!d) {
      if (d * q < 0) {
        pt oldq = getq();
        u = fit(u + d.x);
        v = fit(v + d.x);
        l = fit(l + d.y);
        r = fit(r + d.y);
        d = mv(oldq + d);
      } else {
        if (d.x == q.x) {
          if (q.x == 1)
            u++;
          else
            v--;
          q.x *= -1;
        } else {
          if (q.y == 1)
            l++;
          else
            r--;
          q.y *= -1;
        }
        d = mv(getq());
      }
    }
  }
}
