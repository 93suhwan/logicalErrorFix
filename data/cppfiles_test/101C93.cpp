#include <bits/stdc++.h>
using namespace std;
int t;
int n, m, k;
int x, y;
long long ans;
map<int, int> hang;
map<int, int> lie;
vector<int> h;
vector<int> l;
int hq[1000005];
int lq[1000005];
map<pair<int, int>, int> hnum;
map<pair<int, int>, int> lnum;
int main() {
  scanf(" %d", &t);
  while (t--) {
    ans = 0;
    hang.clear();
    lie.clear();
    hnum.clear();
    lnum.clear();
    h.clear();
    l.clear();
    scanf(" %d %d %d", &n, &m, &k);
    for (int i = 0; i <= n + 1; i++) hq[i] = 0;
    for (int i = 0; i <= m + 1; i++) lq[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf(" %d", &x);
      hang[x] = 1;
      h.push_back(x);
    }
    for (int i = 1; i <= m; i++) {
      scanf(" %d", &y);
      lie[y] = 1;
      l.push_back(y);
    }
    for (int i = 1; i <= k; i++) {
      scanf(" %d %d", &x, &y);
      if (hang[x] && lie[y]) continue;
      if (hang[x]) {
        int inx = lower_bound(l.begin(), l.end(), y) - l.begin();
        pair<int, int> p;
        p.first = x;
        p.second = inx;
        int cnt1 = lq[inx] - hnum[p];
        ans += cnt1;
        lq[inx]++;
        hnum[p]++;
      } else {
        int inx = lower_bound(h.begin(), h.end(), x) - h.begin();
        pair<int, int> p;
        p.first = y;
        p.second = inx;
        int cnt1 = hq[inx] - lnum[p];
        ans += cnt1;
        hq[inx]++;
        lnum[p]++;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
