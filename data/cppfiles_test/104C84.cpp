#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int inf = 2e9;
long long a[maxn], b[maxn], l[maxn], r[maxn];
long long m, n;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    long long sum = 0, L = 0, R = 0;
    vector<pair<long long, long long>> tl, tr;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld%lld", &a[i], &b[i]);
      sum += a[i] - b[i];
      long long deta = a[i] - b[i];
      pair<long long, long long> curl, curr;
      if (a[i] >= m)
        l[i] = a[i] - m - b[i] - deta, curl.first = m, curl.second = 0;
      else
        l[i] = 0 - (b[i] - (m - a[i])) - deta, curl.first = a[i],
        curl.second = m - a[i];
      if (b[i] >= m)
        r[i] = a[i] - (b[i] - m) - deta, curr.first = 0, curr.second = m;
      else
        r[i] = (a[i] - (m - b[i])) - deta, curr.first = (m - b[i]),
        curr.second = b[i];
      tl.push_back(curl);
      tr.push_back(curr);
      L += l[i];
      R += r[i];
    }
    vector<pair<long long, long long>> ans;
    if (-sum >= L && -sum <= R) {
      long long deta = -sum - L;
      ans = tl;
      for (int i = 1; i <= n; ++i) {
        if (r[i] - l[i] >= deta) {
          ans[i - 1].first -= deta / 2;
          ans[i - 1].second += deta / 2;
          deta = 0;
        } else if (r[i] - l[i] < deta) {
          ans[i - 1] = tr[i - 1];
          deta -= r[i] - l[i];
        }
      }
    } else if (-sum < L) {
      ans = tl;
    } else if (-sum > R) {
      ans = tr;
    }
    long long as = 0;
    for (int i = 1; i <= n; ++i) {
      as += (a[i] - ans[i - 1].first) - (b[i] - ans[i - 1].second);
    }
    as = abs(as);
    printf("%lld\n", as);
    for (auto u : ans) printf("%lld %lld\n", u.first, u.second);
  }
}
