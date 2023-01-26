#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct Pair {
  int x;
  int y;
  Pair(int x = 0, int y = 0) : x(x), y(y) {}
};
Pair process(string s, int n, int m) {
  int r = 0, l = 0;
  int u = 0, d = 0;
  int w = 1, h = 1;
  Pair pos = Pair(0, 0);
  int len = s.length();
  for (int i = 0; i < len; i++) {
    Pair pos2 = pos;
    if (s[i] == 'L') {
      pos2.x--;
    }
    if (s[i] == 'R') {
      pos2.x++;
    }
    if (s[i] == 'D') {
      pos2.y--;
    }
    if (s[i] == 'U') {
      pos2.y++;
    }
    int l_ = l, u_ = u;
    l = min(l, pos2.x);
    r = max(r, pos2.x);
    d = min(d, pos2.y);
    u = max(u, pos2.y);
    w = r - l + 1, h = u - d + 1;
    if (h > n || w > m) return Pair(u_ + 1, -l_ + 1);
    pos = pos2;
  }
  return Pair(u + 1, -l + 1);
}
int main() {
  int T = 0;
  scanf("%d", &T);
  int n = 0, m = 0;
  string s;
  while (T--) {
    scanf("%d%d", &n, &m);
    cin >> s;
    Pair ans = process(s, n, m);
    printf("%d %d\n", ans.x, ans.y);
  }
  return 0;
}
