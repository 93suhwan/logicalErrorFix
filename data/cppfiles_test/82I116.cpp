#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 1;
int n, q, k;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
int a[MAXN];
int ans[MAXN];
vector<pair<int, pair<int, long long> > > v[MAXN];
set<pair<int, int>, greater<pair<int, int> > > s;
void upd(int i, int val) {
  if (v[i].size()) s.erase(make_pair(v[i].back().first, i));
  pair<int, long long> now;
  now = make_pair(1, val);
  while (!v[i].empty() && v[i].back().first >= val) {
    auto Tmp = v[i].back();
    v[i].pop_back();
    if (v[i].size())
      Tmp.second.first -= v[i].back().second.first,
          Tmp.second.second -= v[i].back().second.second;
    now.first += Tmp.second.first;
    now.second += 1ll * Tmp.second.first * val;
  }
  if (v[i].size())
    now.second += v[i].back().second.second,
        now.first += v[i].back().second.first;
  s.insert(make_pair(val, i));
  v[i].push_back(make_pair(val, now));
}
void modify(int i, int val) {
  s.erase(make_pair(v[i].back().first, i));
  pair<int, long long> now = v[i].back().second;
  v[i].pop_back();
  if (v[i].size()) now.first -= v[i].back().second.first;
  now.second = 1ll * now.first * val;
  while (!v[i].empty() && v[i].back().first >= val) {
    auto Tmp = v[i].back();
    v[i].pop_back();
    if (v[i].size())
      Tmp.second.first -= v[i].back().second.first,
          Tmp.second.second -= v[i].back().second.second;
    now.first += Tmp.second.first;
    now.second += 1ll * Tmp.second.first * val;
  }
  if (v[i].size())
    now.second += v[i].back().second.second,
        now.first += v[i].back().second.first;
  s.insert(make_pair(val, i));
  v[i].push_back(make_pair(val, now));
}
long long answer(int i, int len) {
  long long tot = v[i].back().second.second;
  len = v[i].back().second.first - len;
  int l = 0, r = v[i].size();
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    if (v[i][mid].second.first <= len) {
      l = mid;
    } else {
      r = mid;
    }
  }
  if (v[i][l].second.first <= len)
    tot -= v[i][l].second.second, len -= v[i][l].second.first;
  if (v[i][l].second.first <= len) l++;
  if (len) {
    tot -= 1ll * v[i][l].first * len;
  }
  return tot;
}
int main() {
  n = read();
  q = read();
  k = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  vector<pair<pair<int, int>, int> > queries;
  for (int T = 1; T <= q; ++T) {
    int l, r;
    scanf("%d%d", &l, &r);
    queries.push_back(make_pair(make_pair(l, r), T));
  }
  sort(queries.begin(), queries.end());
  reverse(queries.begin(), queries.end());
  int pt = 0;
  for (int i = n; i >= 1; --i) {
    upd(i % k, a[i]);
    while (!s.empty() && s.begin()->first > a[i]) {
      modify(s.begin()->second, a[i]);
    }
    while (pt < q && queries[pt].first.first == i) {
      ans[queries[pt].second] = answer(
          i % k,
          (queries[pt].first.second - queries[pt].first.first + 1 + k - 1) / k),
      pt++;
      if (queries[pt].second == 10) {
        cout << queries[pt].first.first << " " << queries[pt].first.second
             << " " << ans[queries[pt].second] << endl;
        exit(0);
      }
    }
  }
  for (int T = 1; T <= q; ++T) {
    printf("%d\n", ans[T]);
  }
  return 0;
}
