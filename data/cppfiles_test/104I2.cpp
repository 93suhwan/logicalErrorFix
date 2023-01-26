#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N];
int first[N], second[N];
int out[N], out2[N];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long sum = 0, sum2 = 0;
    long long ans = 0, ans2 = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i], &b[i]);
      if (a[i] >= m)
        sum2 += m, second[i] = m;
      else
        sum2 += a[i], second[i] = a[i];
      if (b[i] >= m)
        sum += 0, first[i] = 0;
      else
        sum += m - b[i], first[i] = m - b[i];
      ans += a[i], ans2 += b[i];
    }
    long long s = 1ll * m * n;
    long long maxn = abs((ans - sum) - (ans2 - (s - sum)));
    long long l = sum, r = sum2;
    while (l < r) {
      long long mid = l + r + 1 >> 1;
      if (abs((ans - mid) - (ans2 - (s - mid))) < maxn) {
        maxn = abs((ans - mid) - (ans2 - (s - mid)));
        l = mid;
      } else
        r = mid - 1;
    }
    if (maxn > abs((ans - sum2) - (ans2 - (s - sum2)))) {
      l = sum2;
      maxn = abs((ans - sum2) - (ans2 - (s - sum2)));
    }
    cout << maxn << endl;
    queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) {
      if (l >= second[i]) {
        q.push({second[i] - first[i], i});
        out[i] = second[i];
        out2[i] = m - second[i];
        l -= second[i];
      } else if (l >= first[i]) {
        q.push({l, i});
        out[i] = l;
        out2[i] = m - l;
        l = 0;
      } else {
        int gg = first[i] - l;
        while (q.size()) {
          pair<int, int> p = q.front();
          q.pop();
          if (p.first > gg) {
            out[p.second] -= gg;
            out2[p.second] += gg;
            q.push({p.first - first[i] + 1, p.second});
            gg = 0;
            break;
          } else if (p.first == gg) {
            out[p.second] -= gg;
            out2[p.second] += gg;
            gg = 0;
            break;
          } else {
            gg -= p.first;
          }
        }
        out[i] = first[i];
        out2[i] = m - first[i];
      }
    }
    for (int i = 1; i <= n; i++) {
      printf("%d %d\n", out[i], out2[i]);
    }
  }
  return 0;
}
