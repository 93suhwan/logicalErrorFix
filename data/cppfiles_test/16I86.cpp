#include <bits/stdc++.h>
const double E = exp(1.0);
const double pi = 3.1415926;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > >
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
    pair<int, int> num1, num2;
    int num;
    int idx = 0;
    while (q.size() > 1) {
      idx++;
      num1 = q.top(), q.pop();
      num2 = q.top(), q.pop();
      num = min(num1.first, num2.first);
      num1.first -= num, num2.first -= num;
      if (num1.first > 0) q.push(num1);
      if (num2.first > 0) q.push(num2);
      ans += num;
      p[idx].sum = num;
      p[idx].l = num1.second, p[idx].r = num2.second;
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
