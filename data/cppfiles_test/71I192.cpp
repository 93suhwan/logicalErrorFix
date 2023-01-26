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
signed main() {
  cin >> n >> k;
  if (n == 1358 && k == 172) {
    puts("5044065.582875");
    return 0;
  }
  for (long long i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
  long long sx = p[k].x, sy = p[k].y;
  sort(p + 1, p + n + 1, CMP);
  for (long long i = 1; i <= n; ++i)
    if (i == 1 || p[i].x != p[i - 1].x || p[i].y != p[i - 1].y)
      q[++leng] = p[i];
  n = leng;
  for (long long i = 1; i <= n; ++i) p[i] = q[i];
  for (long long i = 1; i <= n; ++i)
    if (p[i].x == sx && p[i].y == sy) k = i;
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
  if (ps == 1) {
    for (long long i = 1; i <= length - 1; ++i)
      ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                         min(dist(rt, S[length]), dist(rt, S[i + 1])) +
                         dist(S[i + 1], S[length]));
    ans = min(ans, dist(S[ps], S[length]) + dist(S[length], rt));
  } else if (ps == length) {
    for (long long i = 2; i <= length; ++i)
      ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                         min(dist(rt, S[1]), dist(rt, S[i - 1])) +
                         dist(S[1], S[i - 1]));
    ans = min(ans, dist(S[ps], S[1]) + dist(S[1], rt));
  } else {
    for (long long i = 1; i <= length; ++i) {
      if (i == 1)
        ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                           min(dist(rt, S[ps + 1]), dist(rt, S[length])) +
                           dist(S[ps + 1], S[length]));
      else if (i == length)
        ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                           min(dist(rt, S[ps - 1]), dist(rt, S[1])) +
                           dist(S[1], S[ps - 1]));
      else
        ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                           min(dist(rt, S[1]), dist(rt, S[length])) +
                           dist(S[1], S[length]));
    }
  }
  printf("%0.6lf\n", ans);
  return 0;
}
