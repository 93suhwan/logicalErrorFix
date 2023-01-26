#include <bits/stdc++.h>
const double E = exp(1.0);
const double pi = 3.1415926;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    q;
struct P {
  int sum, l, r;
} p[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (x > 0) q.push({x, i});
    }
    long long ans = 0;
    int num1, num2, num;
    int idx1, idx2;
    int idx = 0;
    while (q.size() > 1) {
      idx++;
      num1 = q.top().first, idx1 = q.top().second, q.pop();
      num2 = q.top().first, idx2 = q.top().second, q.pop();
      num = min(num1, num2);
      num1 -= num, num2 -= num;
      if (num1 > 0) q.push({num1, idx1});
      if (num2 > 0) q.push({num2, idx2});
      ans += num;
      p[idx].sum = num;
      p[idx].l = idx1, p[idx].r = idx2;
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= idx; ++i) {
      while (p[i].sum--) {
        printf("%d %d\n", p[i].l, p[i].r);
      }
    }
    for (int i = 0; i <= idx; i++) p[i].sum = 0, p[i].l = 0, p[i].r = 0;
    while (!q.empty()) q.pop();
  }
}
