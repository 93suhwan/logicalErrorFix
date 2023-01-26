#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
template <class T>
void read(T &val) {
  T x = 0;
  T bz = 1;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  if (c == '-') {
    bz = -1;
    c = getchar();
  }
  for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - 48;
  val = x * bz;
}
const int maxn = 1e6 + 10;
const int mod = 998244353;
int a[maxn], n, m, t, k;
int fa[maxn];
map<int, int> mx;
int b[maxn], tot;
struct node {
  int first, second, time;
  bool operator<(const node b) const {
    if (second == b.second) {
      return first < b.first;
    }
    return second < b.second;
  }
} p[maxn];
int find(int x) { return x == fa[x] ? fa[x] : fa[x] = find(fa[x]); }
void init() {
  mx.clear();
  tot = 0;
  vector<int> miTime(n + 1, INF);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) {
    miTime[i] = p[i].time;
    if (i > 1 && p[i].second == p[i - 1].second &&
        p[i].first - p[i - 1].first <= k) {
      fa[i] = find(i - 1);
      miTime[fa[i]] = min(miTime[fa[i]], p[i].time);
    }
    if (mx.count(p[i].first) && p[i].second - p[mx[p[i].first]].second <= k) {
      int faB = find(mx[p[i].first]);
      int faA = find(i);
      miTime[faB] = min(miTime[faB], miTime[faA]);
      fa[faA] = faB;
    }
    mx[p[i].first] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      b[++tot] = miTime[i];
    }
  }
  sort(b + 1, b + 1 + tot);
}
int solve() {
  int l = 1, ans = tot - 1;
  b[0] = 0;
  for (int i = 0; i <= tot; i++) {
    while (b[i] == b[l] && l <= tot) l++;
    int left = tot - l + 1;
    if (left <= b[i] + 1) {
      return min(ans, b[i]);
    }
    ans = min(ans, left - 1);
    i = l - 1;
  }
  return ans;
}
int main() {
  read(t);
  while (t--) {
    read(n);
    read(k);
    for (int i = 1; i <= n; i++) {
      read(p[i].first);
      read(p[i].second);
      read(p[i].time);
    }
    sort(p + 1, p + 1 + n);
    init();
    printf("%d\n", solve());
  }
  return 0;
}
