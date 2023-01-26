#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &m) {
  if (m.empty())
    os << "empty vector";
  else
    os << m[0];
  for (int i = 1; i < m.size(); ++i) os << ' ' << m[i];
  return os;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &m) {
  os << '(' << m.first << ", " << m.second << ')';
  return os;
}
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &m) {
  for (int i = 0; i < m.size(); ++i) is >> m[i];
  return is;
}
template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &m) {
  is >> m.first >> m.second;
  return is;
}
vector<pair<long long int, long long int> > pos, ranks;
vector<bool> vis;
long long int sabka_baap, n;
vector<bool> ans;
void baap_ke_dost(long long int u) {
  if (vis[u]) return;
  vis[u] = 1;
  ans[u] = 1;
  for (long long int i = pos[u].first + 1; i < n; i++) {
    if (!vis[ranks[i].first])
      baap_ke_dost(ranks[i].first);
    else
      break;
  }
  for (long long int i = pos[u].second + 1; i < n; i++) {
    if (!vis[ranks[i].second])
      baap_ke_dost(ranks[i].second);
    else
      break;
  }
}
void order(long long int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (long long int i = pos[u].first - 1; i >= 0; i--) {
    if (!vis[ranks[i].first])
      order(ranks[i].first);
    else
      break;
  }
  for (long long int i = pos[u].second - 1; i >= 0; i--) {
    if (!vis[ranks[i].second])
      order(ranks[i].second);
    else
      break;
  }
  sabka_baap = u;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(__null), cout.tie(__null);
  long long int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<long long int, pair<long long int, long long int> > > arr(n);
    for (long long int i = 0; i < n; i++) arr[i].first = i;
    for (long long int i = 0; i < n; i++) cin >> arr[i].second.first;
    for (long long int i = 0; i < n; i++) cin >> arr[i].second.second;
    ranks.clear();
    ranks.resize(n);
    ans.clear();
    ans.resize(n, 0);
    vis.clear();
    vis.resize(n, 0);
    pos.clear();
    pos.resize(n);
    sort((arr).begin(), (arr).end(),
         [](pair<long long int, pair<long long int, long long int> > a,
            pair<long long int, pair<long long int, long long int> > b) {
           return a.second.first < b.second.first;
         });
    for (long long int i = 0; i < n; i++) pos[arr[i].first].first = i;
    for (long long int i = 0; i < n; i++) ranks[i].first = arr[i].first;
    sort((arr).begin(), (arr).end(),
         [](pair<long long int, pair<long long int, long long int> > a,
            pair<long long int, pair<long long int, long long int> > b) {
           return a.second.second < b.second.second;
         });
    for (long long int i = 0; i < n; i++) pos[arr[i].first].second = i;
    for (long long int i = 0; i < n; i++) ranks[i].second = arr[i].first;
    sabka_baap = ranks[n - 1].first;
    baap_ke_dost(sabka_baap);
    for (long long int i = 0; i < n; i++) cout << ans[i];
    cout << endl;
  }
  return 0;
}
