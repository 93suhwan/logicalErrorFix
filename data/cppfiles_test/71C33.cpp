#include <bits/stdc++.h>
using namespace std;
struct reads {
  long long x, y;
};
bool operator<(reads a, reads b) { return a.x * b.y < a.y * b.x; }
bool operator==(reads a, reads b) { return a.x * b.y == a.y * b.x; }
reads p[200000 + 1], q[200000 + 1], st;
long long n, k, t, rt, length, ps, S[200000 + 1], leng;
double ans;
map<reads, long long> P;
bool cmp(long long a, long long b) {
  if (p[a].x != p[b].x) return p[a].x < p[b].x;
  return p[a].y < p[b].y;
}
bool CMP(reads a, reads b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}
reads slope(long long a, long long b) {
  return (reads){p[b].y - p[a].y, p[b].x - p[a].x};
}
double dist(long long a, long long b) {
  return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) +
              (p[a].y - p[b].y) * (p[a].y - p[b].y));
}
double F(long long l, long long r) {
  if (l > r) return 0;
  return dist(S[l], S[r]) + min(dist(rt, S[l]), dist(rt, S[r]));
}
signed main() {
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
  while (1) {
    t = rand() % n + 1, P.clear();
    for (long long i = 1; i <= n; ++i)
      if (i != t) P[slope(i, t)]++;
    if (P.size() == 2) break;
  }
  for (auto it : P)
    if (it.second == n - 2) st = it.first;
  for (long long i = 1; i <= n; ++i) {
    if (slope(i, t) == st)
      S[++length] = i;
    else
      rt = i;
  }
  sort(S + 1, S + length + 1, cmp);
  if (rt == k) {
    printf("%0.6lf\n",
           min(dist(S[1], k), dist(S[length], k)) + dist(S[1], S[length]));
    return 0;
  }
  for (long long i = 1; i <= length; ++i)
    if (S[i] == k) ps = i;
  ans = 1e18;
  for (long long i = 1; i <= length; ++i) {
    ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) + F(1, length));
    ans = min(ans, dist(S[ps], S[1]) + dist(S[1], S[i]) + dist(S[i], rt) +
                       F(max(i, ps) + 1, length));
    ans = min(ans, dist(S[ps], S[length]) + dist(S[length], S[i]) +
                       dist(S[i], rt) + F(1, min(i, ps) - 1));
  }
  printf("%0.6lf\n", ans);
  return 0;
}
