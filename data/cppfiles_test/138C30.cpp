#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
pair<int, int> a[maxn << 1];
vector<pair<int, int> > qry, del;
int n, m, q;
long long s[maxn << 1], f[maxn << 1], ans[maxn], init;
long long cal(int l, int r) {
  if (l == 0) return s[r];
  long long c = f[r] - f[l - 1];
  return s[r] - s[r - c];
}
void solve() {
  scanf("%d %d %d", &n, &m, &q);
  int cnt = 0;
  for (int i = (1); i <= (n); i++) {
    int x;
    scanf("%d", &x);
    init += x;
    a[++cnt] = {x, 1};
  }
  for (int i = (1); i <= (m); i++) {
    int x;
    scanf("%d", &x);
    a[++cnt] = {x, 0};
  }
  sort(a + 1, a + 1 + cnt);
  for (int i = (1); i <= (cnt); i++) {
    s[i] = s[i - 1] + a[i].first;
    f[i] = f[i - 1] + a[i].second;
    if (i > 1) del.push_back({a[i].first - a[i - 1].first, i});
  }
  sort(del.begin(), del.end());
  for (int i = (0); i < (q); i++) {
    int x;
    scanf("%d", &x);
    qry.push_back({x, i});
  }
  sort(qry.begin(), qry.end());
  set<int> vel;
  for (int i = (1); i <= (cnt + 1); i++) vel.insert(i);
  int l = 0;
  for (auto x : qry) {
    for (int len = del.size(); l < len && del[l].first <= x.first; l++) {
      auto itr = vel.lower_bound(del[l].second);
      auto itr1 = itr, itr2 = itr;
      itr1--;
      itr2++;
      init -= cal(*itr1, *itr - 1);
      init -= cal(*itr, *itr2 - 1);
      init += cal(*itr1, *itr2 - 1);
      vel.erase(itr);
    }
    ans[x.second] = init;
  }
  for (int i = (0); i < (q); i++) {
    printf("%lld\n", ans[i]);
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
