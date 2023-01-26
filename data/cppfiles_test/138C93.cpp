#include <bits/stdc++.h>
const int N = 4e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
map<long long int, multiset<long long int>> use, waste;
long long int par[N];
long long int sum = 0;
bool cmp(pair<long long int, pair<long long int, long long int>> a,
         pair<long long int, pair<long long int, long long int>> b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second.first < b.second.first;
}
long long int findpar(long long int x) {
  if (x != par[x]) {
    par[x] = findpar(par[x]);
  }
  return par[x];
}
void uniona(long long int x, long long int y) {
  long long int a = findpar(x);
  long long int b = findpar(y);
  if (use[a].size() + waste[a].size() < use[b].size() + waste[b].size())
    swap(a, b);
  for (long long int i : use[b]) {
    use[a].insert(i);
  }
  for (long long int i : waste[b]) {
    waste[a].insert(i);
  }
  waste[b].clear();
  use[b].clear();
  while (!waste[a].empty() && !use[a].empty() &&
         *use[a].begin() < *waste[a].rbegin()) {
    sum -= *use[a].begin();
    sum += *waste[a].rbegin();
    use[a].insert(*waste[a].rbegin());
    waste[a].insert(*use[a].begin());
    use[a].erase(use[a].begin());
    waste[a].erase(--waste[a].end());
  }
  par[b] = a;
}
void solve() {
  long long int n, m, q;
  cin >> n >> m >> q;
  long long int a[n + 2];
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long int b[m + 2];
  for (long long int i = 0; i <= m - 1; i++) {
    cin >> b[i];
  }
  long long int query[q + 2];
  for (long long int i = 0; i <= q - 1; i++) {
    cin >> query[i];
  }
  vector<pair<long long int, long long int>> tot;
  for (long long int i = 0; i <= n - 1; i++) {
    tot.push_back({a[i], 1});
  }
  for (long long int i = 0; i <= m - 1; i++) {
    tot.push_back({b[i], 0});
  }
  sort(tot.begin(), tot.end());
  for (long long int i = 0; i <= n + m - 1; i++) {
    par[i] = i;
    if (tot[i].second)
      use[i].insert(tot[i].first);
    else
      waste[i].insert(tot[i].first);
  }
  vector<pair<long long int, pair<long long int, long long int>>> v;
  for (long long int i = 0; i <= n + m - 2; i++) {
    v.push_back({tot[i + 1].first - tot[i].first, {0, i}});
  }
  for (long long int i = 0; i <= q - 1; i++) {
    v.push_back({query[i], {1, i}});
  }
  sort(v.begin(), v.end(), cmp);
  long long int ans[q + 2];
  for (auto i : v) {
    if (i.second.first == 1) {
      ans[i.second.second] = sum;
    } else {
      uniona(i.second.second, i.second.second + 1);
    }
  }
  for (long long int i = 0; i <= q - 1; i++) {
    cout << ans[i] << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  solve();
}
