#include <bits/stdc++.h>
const double E = exp(1.0);
const double pi = 3.1415926;
const long long INF = 0x3f3f3f3f;
const long long N = 2e5 + 5;
using namespace std;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               less<pair<long long, long long> > >
    q;
struct P {
  long long sum, l, r;
} p[N];
signed main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    long long x;
    for (long long i = 1; i <= n; i++) {
      scanf("%lld", &x);
      if (x > 0) q.push({x, i});
    }
    long long ans = 0;
    pair<long long, long long> num1, num2;
    long long num;
    long long idx = 0;
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
    for (long long i = 1; i <= idx; ++i) {
      while (p[i].sum--) {
        printf("%lld %lld\n", p[i].l, p[i].r);
      }
    }
    for (long long i = 0; i <= idx; i++) p[i].sum = 0, p[i].l = 0, p[i].r = 0;
    while (!q.empty()) q.pop();
  }
}
