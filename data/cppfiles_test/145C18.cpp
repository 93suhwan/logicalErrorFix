#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct node {
  int x, y, t, id;
} a[MAXN];
int n;
bool cmp(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
int minn[MAXN];
int f[MAXN];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void unionn(int u, int v) {
  minn[find(v)] = min(minn[find(v)], minn[find(u)]);
  f[find(u)] = find(v);
}
bool cmp2(node a, node b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
bool cmp1(int a, int b) { return a > b; }
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y >> a[i].t;
      a[i].id = i;
    }
    for (int i = 1; i <= n; i++) f[i] = i, minn[i] = a[i].t;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 2; i <= n; i++) {
      if (a[i].x == a[i - 1].x && (a[i].y - a[i - 1].y) <= k)
        unionn(a[i].id, a[i - 1].id);
    }
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 2; i <= n; i++) {
      if (a[i].y == a[i - 1].y && (a[i].x - a[i - 1].x) <= k)
        unionn(a[i].id, a[i - 1].id);
    }
    vector<int> V;
    for (int i = 1; i <= n; i++) {
      if (f[i] == i) V.push_back(minn[i]);
    }
    sort(V.begin(), V.end(), cmp1);
    int ans = -1;
    for (int i = 0; i < V.size(); i++) {
      if (ans < V[i]) {
        ans++;
      } else {
        continue;
      }
    }
    cout << ans << '\n';
  }
}
