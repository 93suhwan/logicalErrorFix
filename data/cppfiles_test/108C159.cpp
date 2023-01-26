#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n;
bool dp[N], ans[N];
struct Node {
  int id, a, b, rp;
} p[N];
bool cmpa(Node x, Node y) { return x.a < y.a; }
bool cmpb(Node x, Node y) { return x.b < y.b; }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].a);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i].b), p[i].id = i;
    sort(p + 1, p + n + 1, cmpa);
    for (int i = 1; i <= n; i++) p[i].a = i;
    sort(p + 1, p + n + 1, cmpb);
    for (int i = 1; i <= n; i++) {
      p[i].rp = max(p[i - 1].rp, p[i].a);
    }
    sort(p + 1, p + n + 1, cmpa);
    for (int i = 1; i <= n; i++) p[i].rp = max(p[i - 1].rp, p[i].rp), dp[i] = 0;
    dp[n] = 1;
    for (int i = n - 1; i >= 1; i--) dp[i] = dp[p[i].rp];
    for (int i = 1; i <= n; i++) ans[p[i].id] = dp[i];
    for (int i = 1; i <= n; i++) printf("%d", ans[i] ? 1 : 0);
    puts("");
  }
  return 0;
}
