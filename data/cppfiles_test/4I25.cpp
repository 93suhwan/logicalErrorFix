#include <bits/stdc++.h>
using namespace std;
int Size[200005];
vector<pair<int, int> > v[200005];
int forbid[200005];
vector<int> tmp;
void dfs(int first, int f) {
  Size[first] = 1;
  tmp.push_back(first);
  for (auto it : v[first]) {
    if (it.first != f && !forbid[it.first]) {
      dfs(it.first, first);
      Size[first] += Size[it.first];
    }
  }
}
int cen(int first) {
  tmp.clear();
  dfs(first, 0);
  int xx = Size[first];
  int res = 0;
  for (auto it : tmp) {
    if (Size[it] >= (xx + 1) / 2) {
      res = it;
    }
  }
  return res;
}
long long S[4][200005];
int mod = 1e9 + 7;
void add(int first, int k, long long *s) {
  first++;
  for (int i = first; i < 200005; i += i & -i) {
    s[i] += k;
    s[i] %= mod;
  }
}
void reset(int first, long long *s) {
  first++;
  for (int i = first; i < 200005; i += i & -i) {
    s[i] = 0;
  }
}
long long query(int first, long long *s) {
  first++;
  long long res = 0;
  for (int i = first; i > 0; i -= i & -i) {
    res += s[i];
    res %= mod;
  }
  return res;
}
vector<pair<long long, long long> > vv;
long long a[200005];
void dfs(int first, int last, int f, int sum, long long sum2) {
  vv.push_back(make_pair(a[first] + sum2, sum));
  for (auto it : v[first]) {
    if (it.first != f && !forbid[it.first]) {
      dfs(it.first, it.second, first, sum + (it.second != last),
          sum2 + a[first]);
    }
  }
}
long long ans = 0;
int k;
vector<pair<int, int> > ttmp;
void go(int first) {
  first = cen(first);
  for (auto it : v[first]) {
    if (!forbid[it.first]) {
      dfs(it.first, it.second, first, 0, a[first]);
      for (auto it2 : vv) {
        ans += query(k - it2.second, S[it.second]);
        ans += query(k - it2.second, S[2 + it.second]) * it2.first;
        ans += query(k - it2.second - 1, S[it.second ^ 1]);
        ans += query(k - it2.second - 1, S[2 + (it.second ^ 1)]) * it2.first;
        if (it2.second <= k) ans += it2.first;
        ans %= mod;
      }
      for (auto it2 : vv) {
        add(it2.second, it2.first - a[first], S[it.second]);
        add(it2.second, 1, S[2 + it.second]);
        ttmp.push_back(it2);
      }
      vv.clear();
    }
  }
  for (auto it : ttmp) {
    reset(it.second, S[0]);
    reset(it.second, S[1]);
    reset(it.second, S[2]);
    reset(it.second, S[3]);
  }
  ttmp.clear();
  forbid[first] = 1;
  for (auto it : v[first]) {
    if (!forbid[it.first]) {
      go(it.first);
    }
  }
}
void solve() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), ans += a[i];
  for (int i = 1; i < n; i++) {
    int first, second, w;
    scanf("%d %d %d", &first, &second, &w);
    v[first].push_back(make_pair(second, w));
    v[second].push_back(make_pair(first, w));
  }
  go(1);
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
