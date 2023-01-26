#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long inf = 8e18;
const int LOG = 20;
long long pw(long long a, long long b, long long M = mod, long long ret = 1) {
  while (b) {
    ret = ret * (b & 1 ? a : 1) % M, a = a * a % M, b >>= 1;
  }
  return ret;
}
pair<int, int> arr[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int n, X[N], Y[N], cnt[2][2];
class Point {
 public:
  int x, y;
  Point(int a = 0, int b = 0) : x(a), y(b) {}
};
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int getBoundaryCount(Point p, Point q) {
  if (p.x == q.x) return abs(p.y - q.y) - 1;
  if (p.y == q.y) return abs(p.x - q.x) - 1;
  return gcd(abs(p.x - q.x), abs(p.y - q.y)) - 1;
}
int getInternalCount(Point p, Point q, Point r) {
  int BoundaryPoints = getBoundaryCount(p, q) + getBoundaryCount(p, r) +
                       getBoundaryCount(q, r) + 3;
  int doubleArea =
      abs(p.x * (q.y - r.y) + q.x * (r.y - p.y) + r.x * (p.y - q.y));
  return (doubleArea - BoundaryPoints + 2) / 2;
}
int ok(int x) {
  if (x) return 2;
  return 0;
}
int check(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
  A.first = ok(A.first);
  B.first = ok(B.first);
  C.first = ok(C.first);
  A.second = ok(A.second);
  B.second = ok(B.second);
  C.second = ok(C.second);
  Point p(A.first, A.second);
  Point q(B.first, B.second);
  Point r(C.first, C.second);
  return (getInternalCount(p, q, r) & 1);
}
inline long long C3(long long x) { return x * (x - 1) * (x - 2) / 6; }
inline long long C2(long long x) { return x * (x - 1) / 2; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &X[i], &Y[i]);
    cnt[(X[i] % 4) / 2][(Y[i] % 4) / 2]++;
  }
  long long tot = 0;
  for (int i = 0; i < 4; i++) {
    if (check(arr[i], arr[i], arr[i])) {
      tot += C3(cnt[arr[i].first][arr[i].second]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      if (check(arr[i], arr[i], arr[j])) {
        tot += C2(cnt[arr[i].first][arr[i].second]) *
               cnt[arr[j].first][arr[j].second];
      }
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      for (int k = 0; k < 4; k++) {
        if (i == k || j == k) continue;
        if (check(arr[i], arr[j], arr[k])) {
          tot += cnt[arr[i].first][arr[i].second] *
                 cnt[arr[j].first][arr[j].second] *
                 cnt[arr[k].first][arr[k].second];
        }
      }
    }
  }
  printf("%lld", tot);
  return 0;
}
