#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
const int max_n = 100011, inf = 1000111222;
const int mod = 1000000007;
int n, m, fenv[333][333];
map<int, vector<pair<int, int>>> mp;
pair<int, int> a[max_n];
int sum(int tt[], int r) {
  int result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += tt[r];
  return result;
}
void inc(int t[], int i, int delta) {
  for (; i < m; i = (i | (i + 1))) t[i] += delta;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first > b.first;
  }
  return a.second < b.second;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    mp.clear();
    for (int i = 0; i < n; ++i) {
      for (int q = 0; q < m; ++q) {
        fenv[i][q] = 0;
      }
    }
    for (int i = 0; i < n * m; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a, a + n * m);
    int pos = 0;
    for (int i = 0; i < n * m; ++i) {
      mp[a[i].first].push_back({pos % m, pos / m});
      ++pos;
      swap(a[i].first, a[i].second);
    }
    for (auto& a : mp) {
      sort(a.second.begin(), a.second.end(), cmp);
      reverse(a.second.begin(), a.second.end());
    }
    sort(a, a + n * m);
    int ans = 0;
    for (int i = 0; i < n * m; ++i) {
      int x = mp[a[i].second].back().second;
      int y = mp[a[i].second].back().first;
      mp[a[i].second].pop_back();
      ans += sum(fenv[x], y);
      inc(fenv[x], y, 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
