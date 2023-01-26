#include <bits/stdc++.h>
using namespace std;
const int N = 204;
const long long INF = 1000000000000000000;
int n, k;
struct data {
  int ans;
  long long S;
  void chkmax(data x) {
    if (x.ans > ans || (x.ans == ans && x.S > S)) ans = x.ans, S = x.S;
  }
} f[N][N];
struct point {
  long long x, y;
} p[N];
point operator-(point a, point b) { return (point){a.x - b.x, a.y - b.y}; }
long long operator*(point a, point b) { return a.x * b.y - a.y * b.x; }
data operator+(data x, data y) { return (data){x.ans + y.ans, x.S + y.S}; }
bool check(long long S) {
  for (int j = 3; j <= n; ++j)
    for (int i = j - 2; i >= 1; --i) {
      f[i][j] = (data){0, 0};
      for (int k = i; k <= j; ++k) {
        data tmp = f[i][k] + f[k][j];
        tmp.S += abs((p[i] - p[k]) * (p[j] - p[k]));
        if (tmp.S >= S) tmp.S = 0, ++tmp.ans;
        f[i][j].chkmax(tmp);
      }
    }
  return f[1][n].ans > k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);
  long long l = 1, r = INF;
  while (l <= r)
    check((l + r >> 1)) ? l = (l + r >> 1) + 1 : r = (l + r >> 1) - 1;
  printf("%lld\n", l - 1);
  return 0;
}
