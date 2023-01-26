#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
int pa[maxn];
int cnt[maxn];
long long pre[maxn];
map<int, vector<long long>> mp;
int find(int x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
struct Ans {
  int id;
  long long k, res;
} ans[maxn];
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  vector<pair<long long, int>> a(n + m + 10);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = 1;
    sum += a[i].first;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i + n].first;
    a[i + n].second = 0;
  }
  sort(a.begin() + 1, a.begin() + n + m + 1);
  for (int i = 1; i <= n + m; i++) {
    pa[i] = i;
    cnt[i] = a[i].second;
    pre[i] = pre[i - 1] + a[i].first;
    if (i > 1) mp[a[i].first - a[i - 1].first].push_back(i - 1);
  }
  for (int i = 1; i <= q; i++) {
    cin >> ans[i].k;
    ans[i].id = i;
  }
  sort(ans + 1, ans + q + 1, [&](Ans &x, Ans &y) { return x.k < y.k; });
  auto it = mp.begin();
  for (int i = 1; i <= q; i++) {
    if (ans[i].k == ans[i - 1].k) {
      ans[i].res = sum;
      continue;
    }
    while (it != mp.end() && it->first <= ans[i].k) {
      for (int j : it->second) {
        int fx = find(j), fy = find(j + 1);
        sum -= pre[fy] - pre[fy - cnt[fy]];
        sum -= pre[fx] - pre[fx - cnt[fx]];
        cnt[fy] += cnt[fx];
        pa[fx] = fy;
        sum += pre[fy] - pre[fy - cnt[fy]];
      }
      ++it;
    }
    ans[i].res = sum;
  }
  sort(ans + 1, ans + 1 + q, [&](Ans &x, Ans &y) { return x.id < y.id; });
  for (int i = 1; i <= q; i++) {
    cout << ans[i].res << '\n';
  }
}
int main() { solve(); }
