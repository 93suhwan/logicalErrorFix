#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,sse4,avx")
struct Vector {
  long long first, second;
  Vector() { first = second = 0; }
  Vector(long long x2, long long y2) {
    first = x2;
    second = y2;
  }
  Vector(Vector a, Vector b) {
    first = b.first - a.first;
    second = b.second - a.second;
  }
};
long long operator*(Vector a, Vector b) {
  return a.first * b.second - a.second * b.first;
}
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long md(long long first) {
  if (first < 0) return (-first % 4 + 4) % 4;
  return first % 4;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<Vector> pol(n);
  for (long long i = 0; i < n; i++) cin >> pol[i].first >> pol[i].second;
  long long answer = 0;
  for (long long i = 0; i < n; i++) {
    long long cnt[4][4];
    for (long long i = 0; i < 4; i++)
      for (long long j = 0; j < 4; j++) cnt[i][j] = 0;
    for (long long j = 0; j < n; j++) {
      if (j == i) continue;
      long long first = md(pol[j].first - pol[i].first);
      long long second = md(pol[j].second - pol[i].second);
      cnt[first][second]++;
    }
    for (long long x1 = 0; x1 < 4; x1++) {
      for (long long y1 = 0; y1 < 4; y1++) {
        long long x2 = x1;
        long long y2 = y1;
        if (md(x1 * y2 - x2 * y1) ==
            md(gcd(x1, y1) + gcd(x2, y2) + gcd(x1 - x2, y1 - y2)))
          answer += cnt[x1][y1] * (cnt[x2][y2] - 1);
        for (x2 = 0; x2 < 4; x2++) {
          for (y2 = 0; y2 < 4; y2++) {
            if (tie(x2, y2) == tie(x1, y1)) continue;
            if (md(x1 * y2 - x2 * y1) ==
                md(gcd(x1, y1) + gcd(x2, y2) + gcd(x1 - x2, y1 - y2)))
              answer += cnt[x1][y1] * cnt[x2][y2];
          }
        }
      }
    }
  }
  cout << answer / 6;
  return 0;
}
