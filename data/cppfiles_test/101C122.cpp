#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int MAXN = 3e5 + 10;
const int N = 3e5 + 10;
int n, m, k;
int a[N], b[N];
long long l[N], r[N];
struct node {
  int x, y;
} q[N];
bool cmp1(node a, node b) { return a.x < b.x; }
bool cmp2(node a, node b) { return a.y < b.y; }
void work() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= k; i++) {
    cin >> q[i].x >> q[i].y;
  }
  long long ans = 0;
  sort(q + 1, q + 1 + k, cmp1);
  int now = 1;
  for (int i = 1; i <= n - 1; i++) {
    while (now <= k && q[now].x == a[i]) now++;
    l[i] = now;
    while (now <= k && q[now].x < a[i + 1]) now++;
    r[i] = now - 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    long long res = 0, now = -1, resn = 0;
    resn += (r[i] - l[i] + 1) * (r[i] - l[i] + 1);
    if (r[i] - l[i] + 1 >= 2) sort(q + l[i], q + r[i] + 1, cmp2);
    for (int j = l[i]; j <= r[i]; j++) {
      if (q[j].y == now) {
        res++;
      } else {
        resn -= res * res;
        res = 1;
        now = q[j].y;
      }
    }
    resn -= res * res;
    ans += resn / 2;
  }
  sort(q + 1, q + 1 + k, cmp2);
  now = 1;
  for (int i = 1; i <= m - 1; i++) {
    while (now <= k && q[now].y == b[i]) now++;
    l[i] = now;
    while (now <= k && q[now].y < b[i + 1]) now++;
    r[i] = now - 1;
  }
  for (int i = 1; i <= m - 1; i++) {
    long long res = 0, now = -1, resn = 0;
    resn += (r[i] - l[i] + 1) * (r[i] - l[i] + 1);
    if (r[i] - l[i] + 1 >= 2) sort(q + l[i], q + r[i] + 1, cmp1);
    for (int j = l[i]; j <= r[i]; j++) {
      if (q[j].x == now) {
        res++;
      } else {
        resn -= res * res;
        res = 1;
        now = q[j].x;
      }
    }
    resn -= res * res;
    ans += resn / 2;
  }
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) work();
  return 0;
}
