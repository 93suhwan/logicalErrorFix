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
    while (!d && (u != v || l != r)) {
      if (d * q < 0) {
        thing();
        if (q.x == 1)
          d = mv({v + 1, r + 1});
        else
          d = mv({u - 1, r + 1});
      } else {
        thing();
        if (q.x == 1) {
          d = mv({u - 1, r + 1});
        } else {
          d = mv({v + 1, r + 1});
        }
        q.x *= -1;
      }
    }
    if (q.x == 1)
      q = {v + 1, r + 1};
    else
      q = {u - 1, r + 1};
    while (!d) {
      q = q + d;
      d = mv(q);
    }
  }
}
