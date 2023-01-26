#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long su = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) su = su * 10 + c - '0';
  return su * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
int sx[100005][5];
int sy[100005][5];
int n;
vector<int> Gx, Gy;
int Mx, My, p[5];
struct node {
  int x, y, c, w;
} a[100005], b[100005];
int ans;
bool chk1(int x) {
  int nowl = -1;
  for (int i = 1; i <= Mx; i++)
    if (sx[i][1] >= x) {
      nowl = i;
      break;
    }
  if (nowl == -1) return 0;
  int nowr = -1;
  for (int i = nowl + 1; i <= Mx; i++)
    if (sx[i][2] - sx[nowl][2] >= x) {
      nowr = i;
      break;
    }
  if (nowr == -1) return 0;
  if (sx[Mx][3] - sx[nowr][3] >= x) return 1;
  return 0;
}
bool chk2(int x) {
  int nowl = -1;
  for (int i = 1; i <= Mx; i++)
    if (sx[i][1] >= x) {
      nowl = i;
      break;
    }
  if (nowl == -1) return 0;
  for (int i = 1; i <= n; i++) {
    if (b[i].x > nowl) sy[b[i].y][b[i].w]++;
  }
  for (int i = 1; i <= My; i++) {
    for (int j = 1; j <= 3; j++) sy[i][j] += sy[i - 1][j];
  }
  int res = 0;
  for (int i = 1; i <= My; i++) {
    if (sy[i][2] >= x && sy[My][3] - sy[i][3] >= x) res = 1;
  }
  for (int i = 1; i <= My; i++) {
    for (int j = 1; j <= 3; j++) sy[i][j] = 0;
  }
  return res;
}
bool chk3(int x) {
  int nowl = -1;
  for (int i = Mx; i >= 1; i--)
    if (sx[Mx][1] - sx[i - 1][1] >= x) {
      nowl = i;
      break;
    }
  if (nowl == -1) return 0;
  for (int i = 1; i <= n; i++) {
    if (b[i].x < nowl) sy[b[i].y][b[i].w]++;
  }
  for (int i = 1; i <= My; i++) {
    for (int j = 1; j <= 3; j++) sy[i][j] += sy[i - 1][j];
  }
  int res = 0;
  for (int i = 1; i <= My; i++) {
    if (sy[i][2] >= x && sy[My][3] - sy[i][3] >= x) res = 1;
  }
  for (int i = 1; i <= My; i++) {
    for (int j = 1; j <= 3; j++) sy[i][j] = 0;
  }
  return res;
}
bool check(int x) { return chk1(x) | chk2(x) | chk3(x); }
void work() {
  for (int i = 1; i <= n; i++) a[i].w = p[a[i].c];
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
    b[i].x = lower_bound(Gx.begin(), Gx.end(), b[i].x) - Gx.begin() + 1;
    b[i].y = lower_bound(Gy.begin(), Gy.end(), b[i].y) - Gy.begin() + 1;
    sx[b[i].x][b[i].w]++;
  }
  Mx = Gx.size(), My = Gy.size();
  for (int i = 1; i <= Mx; i++) {
    for (int j = 1; j <= 3; j++) sx[i][j] += sx[i - 1][j];
  }
  int l = 1, r = n / 3;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (check(mid)) {
      ans = max(ans, mid);
      l = mid + 1;
    } else
      r = mid - 1;
  }
  for (int i = 1; i <= Mx; i++) {
    for (int j = 1; j <= 3; j++) sx[i][j] = 0;
  }
}
void What_will_Diana_eat_today() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i].x = read(), a[i].y = read(), a[i].c = read();
  }
  Gx.clear();
  Gy.clear();
  for (int i = 1; i <= n; i++) Gx.push_back(a[i].x), Gy.push_back(a[i].y);
  sort(Gx.begin(), Gx.end());
  Gx.erase(unique(Gx.begin(), Gx.end()), Gx.end());
  sort(Gy.begin(), Gy.end());
  Gy.erase(unique(Gy.begin(), Gy.end()), Gy.end());
  for (int i = 1; i <= 3; i++) p[i] = i;
  do {
    work();
  } while (next_permutation(p + 1, p + 3 + 1));
  for (int i = 1; i <= n; i++) {
    swap(a[i].x, a[i].y);
  }
  Gx.clear();
  Gy.clear();
  for (int i = 1; i <= n; i++) Gx.push_back(a[i].x), Gy.push_back(a[i].y);
  sort(Gx.begin(), Gx.end());
  Gx.erase(unique(Gx.begin(), Gx.end()), Gx.end());
  sort(Gy.begin(), Gy.end());
  Gy.erase(unique(Gy.begin(), Gy.end()), Gy.end());
  for (int i = 1; i <= 3; i++) p[i] = i;
  do {
    work();
  } while (next_permutation(p + 1, p + 3 + 1));
  writeln(ans * 3);
}
signed main() {
  int T = 1;
  while (T--) {
    What_will_Diana_eat_today();
  }
}
