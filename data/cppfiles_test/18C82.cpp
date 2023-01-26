#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int t, n, k;
struct ab {
  int l, r;
  int ll, rr;
} aa[N + 5];
int cc[N * 2 + 5];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    set<int> q;
    for (int i = 1; i <= n; ++i) {
      q.insert(i);
      q.insert(i + n);
    }
    int co = 0;
    for (int i = 1; i <= k; ++i) {
      scanf("%d%d", &aa[i].l, &aa[i].r);
      if (aa[i].l > aa[i].r) {
        swap(aa[i].l, aa[i].r);
      }
      aa[i].ll = aa[i].l;
      aa[i].rr = aa[i].r;
      q.erase(aa[i].l);
      q.erase(aa[i].r);
      cc[++co] = aa[i].l;
      cc[++co] = aa[i].r;
    }
    sort(cc + 1, cc + co + 1);
    for (int i = 1; i <= n; ++i) {
      aa[i].l = lower_bound(cc + 1, cc + co + 1, aa[i].l) - cc;
      aa[i].r = lower_bound(cc + 1, cc + co + 1, aa[i].r) - cc;
    }
    co = 0;
    for (auto v : q) {
      cc[++co] = v;
    }
    long long ans = 0;
    for (int p = 1; p <= k; ++p) {
      int mx = k + 1;
      int mi = 0;
      int noww = k - p + 1;
      for (int i = 1; i <= k; ++i) {
        if (aa[i].l <= 0) {
          continue;
        }
        int c = abs(aa[i].l % (2 * noww) - aa[i].r % (2 * noww));
        if (min(c, noww * 2 - c) < mx) {
          mi = i;
          mx = min(c, noww * 2 - c);
        }
      }
      ans += mx - 1;
      for (int i = 1; i <= k; ++i) {
        if (i == mi || aa[i].l <= 0) {
          continue;
        }
        if (aa[i].r > aa[mi].r) {
          aa[i].r -= 2;
        } else if (aa[i].r > aa[mi].l) {
          aa[i].r -= 1;
        }
        if (aa[i].l > aa[mi].r) {
          aa[i].l -= 2;
        } else if (aa[i].l > aa[mi].l) {
          aa[i].l -= 1;
        }
      }
      int ll = lower_bound(cc + 1, cc + co + 1, aa[mi].ll) - cc;
      int rr = lower_bound(cc + 1, cc + co + 1, aa[mi].rr) - cc;
      ans += min(rr - ll, co - (rr - ll));
      aa[mi].l = -1e5;
    }
    ans += (long long)(n - k) * (long long)(n - k - 1) / 2;
    printf("%lld\n", ans);
  }
  return 0;
}
