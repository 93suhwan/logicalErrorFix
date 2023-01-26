#include <bits/stdc++.h>
using namespace std;
struct reads {
  int x, y;
};
bool operator<(reads a, reads b) { return a.x * b.y < a.y * b.x; }
bool operator==(reads a, reads b) { return a.x * b.y == a.y * b.x; }
reads p[200000 + 1], st;
int n, k, t, rt, length, ps, S[200000 + 1];
double ans;
map<reads, int> P;
bool cmp(int a, int b) {
  if (p[a].x != p[b].x) return p[a].x < p[b].x;
  return p[a].y < p[b].y;
}
reads slope(int a, int b) { return (reads){p[b].y - p[a].y, p[b].x - p[a].x}; }
double dist(int a, int b) {
  return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) +
              (p[a].y - p[b].y) * (p[a].y - p[b].y));
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
  while (1) {
    t = rand() % n + 1, P.clear();
    for (int i = 1; i <= n; ++i)
      if (i != t) P[slope(i, t)]++;
    if (P.size() == 2) break;
  }
  for (auto it : P)
    if (it.second == n - 2) st = it.first;
  for (int i = 1; i <= n; ++i) {
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
  for (int i = 1; i <= length; ++i)
    if (S[i] == k) ps = i;
  ans = 1e9;
  if (ps == 1) {
    for (int i = 1; i <= length - 1; ++i)
      ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                         min(dist(rt, S[length]), dist(rt, S[i + 1])) +
                         dist(S[i + 1], S[length]));
    ans = min(ans, dist(S[ps], S[length]) + dist(S[length], rt));
  } else if (ps == length) {
    for (int i = 2; i <= length; ++i)
      ans = min(ans, dist(S[ps], S[i]) + dist(S[i], rt) +
                         min(dist(rt, S[1]), dist(rt, S[i - 1])) +
                         dist(S[1], S[i - 1]));
    ans = min(ans, dist(S[ps], S[1]) + dist(S[1], rt));
  } else {
    for (int i = 1; i <= length; ++i) {
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
