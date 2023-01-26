#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int t, t1;
struct node {
  int val, plc;
  friend bool operator<(node a, node b) { return a.val < b.val; }
};
int aa[maxn], bb[maxn], cc[maxn];
void solve() {
  int i, j, k, n, m, f = 1, d;
  priority_queue<node> q;
  scanf("%d", &n);
  node p, a, b;
  t = 0, t1 = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &p.val);
    p.plc = i;
    if (p.val) q.push(p);
  }
  while (!q.empty()) {
    a = q.top();
    q.pop();
    if (q.empty()) break;
    b = q.top();
    q.pop();
    b.val--;
    a.val--;
    t++;
    if (b.val) q.push(b);
    if (a.val) q.push(a);
    aa[t] = a.plc;
    bb[t] = b.plc;
  }
  printf("%d\n", t);
  for (i = 1; i <= t; i++) {
    printf("%d %d\n", aa[i], bb[i]);
  }
}
int main() {
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
