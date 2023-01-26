#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
void print(vector<long long> x) {
  for (long long i = 0; i < (long long)x.size(); i++)
    printf("%lld%c", x[i], " \n"[i == (long long)x.size() - 1]);
}
struct Node {
  long long v, r;
};
Node max(Node a, Node b) {
  if (a.v > b.v || (a.v == b.v && a.r > b.r))
    return a;
  else
    return b;
}
struct Vec {
  long long x, y;
} a[205];
Vec operator-(Vec a, Vec b) { return (Vec){a.x - b.x, a.y - b.y}; }
long long cross(Vec a, Vec b) { return a.x * b.y - a.y * b.x; }
Node f[205][205];
long long n, m;
bool chk(long long mid) {
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 2; j <= n; j++)
      f[i][j] = (Node){-0x3f3f3f3f, -0x3f3f3f3f};
  for (long long len = 3; len <= n; len++) {
    for (long long i = 1; i + len - 1 <= n; i++) {
      long long j = i + len - 1;
      for (long long k = i + 1; k <= j; k++) {
        Node go =
            (Node){f[i][k].v + f[k][j].v,
                   f[i][k].r + f[k][j].r + cross(a[i] - a[j], a[k] - a[i])};
        if (go.r >= mid) go.v++, go.r = 0;
        f[i][j] = max(f[i][j], go);
      }
    }
  }
  return f[1][n].v >= m;
}
signed main() {
  cin >> n >> m;
  m++;
  for (long long i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
  long long l = 0, r = 0x3f3f3f3f3f3f3f3f, ans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (chk(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  cout << ans << endl;
  return 0;
}
