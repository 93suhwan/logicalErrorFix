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
    pt q = {1, 1};
    pt d = mv({8, 8});
    int u = 1, v = 7, l = 1, r = 7;
    auto thing = [&]() {
      if (d.x == 1) {
        u++;
        return;
      }
      if (d.x == -1) {
        v--;
        return;
      }
      if (d.y == 1) {
        l++;
        return;
      }
      if (d.y == -1) {
        r--;
        return;
      }
    };
    auto getq = [&]() {
      pt z;
      z.x = q.x == 1 ? u - 1 : v + 1;
      z.y = q.y == 1 ? l - 1 : r + 1;
      return z;
    };
    while (!d && (u != v || l != r)) {
      if (d * q < 0) {
        pt oldq = getq();
        thing();
        d = mv(oldq + d);
      } else {
        thing();
        if (d.x == q.x) {
          q.x *= -1;
        } else {
          q.y *= -1;
        }
        auto cq = getq();
        d = mv(cq);
      }
    }
    q = getq();
    while (!d) {
      q = q + d;
      d = mv(q);
    }
  }
}
