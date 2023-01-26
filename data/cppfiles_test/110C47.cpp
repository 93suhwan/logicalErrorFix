#include <bits/stdc++.h>
using namespace std;
int n, X[100005], Y[100005], C[100005];
int ax[100005], ay[100005], ix, iy;
struct Nod {
  int x, y, c;
  Nod(int _x = 0, int _y = 0, int _c = 0) : x(_x), y(_y), c(_c) {}
} dx[100005], dy[100005];
inline bool cmpx(const Nod &a, const Nod &b) { return a.x < b.x; }
inline bool cmpy(const Nod &a, const Nod &b) { return a.y < b.y; }
int getx(int i, int x, int v) {
  while (i && i <= n && dx[i].x == x) i += v;
  return i > n ? 0 : i;
}
int prex(int st, int c, int k) {
  if (!st) return 0;
  for (int i = st; i >= 1; --i)
    if (dx[i].c == c) {
      if (!(--k)) return i;
    }
  return 0;
}
int nxtx(int st, int c, int k) {
  if (!st) return 0;
  for (int i = st; i <= n; ++i)
    if (dx[i].c == c) {
      if (!(--k)) return i;
    }
  return 0;
}
int gety(int i, int y, int v) {
  while (i && i <= n && dy[i].y == y) i += v;
  return i > n ? 0 : i;
}
int prey(int st, int c, int k) {
  if (!st) return 0;
  for (int i = st; i >= 1; --i)
    if (dy[i].c == c) {
      if (!(--k)) return i;
    }
  return 0;
}
int nxty(int st, int c, int k) {
  if (!st) return 0;
  for (int i = st; i <= n; ++i)
    if (dy[i].c == c) {
      if (!(--k)) return i;
    }
  return 0;
}
bool Judge(int c1, int c2, int c3, int k) {
  int p, lft, lx, ly;
  p = 1;
  p = nxtx(p, c1, k);
  p = getx(p, dx[p].x, 1);
  p = nxtx(p, c2, k);
  p = getx(p, dx[p].x, 1);
  p = nxtx(p, c3, k);
  if (p) return true;
  p = 1;
  p = nxty(p, c1, k);
  p = gety(p, dy[p].y, 1);
  p = nxty(p, c2, k);
  p = gety(p, dy[p].y, 1);
  p = nxty(p, c3, k);
  if (p) return true;
  lft = k;
  for (int i = 1; i <= n; ++i)
    if (dx[i].c == c1) {
      if (!(--lft)) {
        lx = dx[i].x;
        break;
      }
    }
  lft = k;
  for (int i = 1; i <= n; ++i)
    if (dy[i].c == c2 && dy[i].x > lx) {
      if (!(--lft)) {
        ly = dy[i].y;
        break;
      }
    }
  if (!lft) {
    lft = k;
    for (int i = 1; i <= n; ++i)
      if (dy[i].c == c3 && dy[i].x > lx && dy[i].y > ly) {
        if (!(--lft)) break;
      }
    if (!lft) return true;
  }
  lft = k;
  for (int i = n; i >= 1; --i)
    if (dx[i].c == c1) {
      if (!(--lft)) {
        lx = dx[i].x;
        break;
      }
    }
  lft = k;
  for (int i = 1; i <= n; ++i)
    if (dy[i].c == c2 && dy[i].x < lx) {
      if (!(--lft)) {
        ly = dy[i].y;
        break;
      }
    }
  if (!lft) {
    lft = k;
    for (int i = 1; i <= n; ++i)
      if (dy[i].c == c3 && dy[i].x < lx && dy[i].y > ly) {
        if (!(--lft)) break;
      }
    if (!lft) return true;
  }
  lft = k;
  for (int i = 1; i <= n; ++i)
    if (dy[i].c == c1) {
      if (!(--lft)) {
        ly = dy[i].y;
        break;
      }
    }
  lft = k;
  for (int i = 1; i <= n; ++i)
    if (dx[i].c == c2 && dx[i].y > ly) {
      if (!(--lft)) {
        lx = dx[i].x;
        break;
      }
    }
  if (!lft) {
    lft = k;
    for (int i = 1; i <= n; ++i)
      if (dx[i].c == c3 && dx[i].x > lx && dx[i].y > ly) {
        if (!(--lft)) break;
      }
    if (!lft) return true;
  }
  lft = k;
  for (int i = n; i >= 1; --i)
    if (dy[i].c == c1) {
      if (!(--lft)) {
        ly = dy[i].y;
        break;
      }
    }
  lft = k;
  for (int i = 1; i <= n; ++i)
    if (dx[i].c == c2 && dx[i].y < ly) {
      if (!(--lft)) {
        lx = dx[i].x;
        break;
      }
    }
  if (!lft) {
    lft = k;
    for (int i = 1; i <= n; ++i)
      if (dx[i].c == c3 && dx[i].x > lx && dx[i].y < ly) {
        if (!(--lft)) break;
      }
    if (!lft) return true;
  }
  return false;
}
bool check(int k) {
  int p[3] = {1, 2, 3};
  do {
    if (Judge(p[0], p[1], p[2], k)) return true;
  } while (next_permutation(p, p + 3));
  return false;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> X[i] >> Y[i] >> C[i];
    ax[++ix] = X[i];
    ay[++iy] = Y[i];
  }
  sort(ax + 1, ax + ix + 1);
  ix = unique(ax + 1, ax + ix + 1) - ax - 1;
  sort(ay + 1, ay + iy + 1);
  iy = unique(ay + 1, ay + iy + 1) - ay - 1;
  for (int i = 1; i <= n; ++i) {
    int x = lower_bound(ax + 1, ax + ix + 1, X[i]) - ax;
    int y = lower_bound(ay + 1, ay + iy + 1, Y[i]) - ay;
    dx[i] = Nod(x, y, C[i]);
    dy[i] = Nod(x, y, C[i]);
  }
  sort(dx + 1, dx + n + 1, cmpx);
  sort(dy + 1, dy + n + 1, cmpy);
  int l = 1, r = n / 3, mid;
  while (l < r) {
    mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l * 3 << endl;
  return 0;
}
