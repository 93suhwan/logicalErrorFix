#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 11;
int ans;
vector<vector<int>> bad;
set<vector<int>> used;
set<pair<int, vector<int>>> s;
vector<int> a[N];
void init() {}
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int sz;
    scanf("%d", &sz);
    a[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  bad.clear();
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    vector<int> cur(n);
    for (int j = 0; j < n; ++j) {
      scanf("%d", &cur[j]);
      --cur[j];
    }
    bad.push_back(std::move(cur));
  }
  sort((bad).begin(), (bad).end());
  vector<int> cur(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cur[i] = ((int)(a[i]).size()) - 1;
    sum += a[i][cur[i]];
  }
  used.insert(cur);
  s.insert(make_pair(-sum, cur));
  while (!s.empty()) {
    pair<int, vector<int>> v = *(s.begin());
    s.erase(s.begin());
    auto it = lower_bound((bad).begin(), (bad).end(), v.second);
    if (it == bad.end() || *it != v.second) {
      for (int i = 0; i < n; ++i) {
        printf("%d ", v.second[i] + 1);
      }
      puts("");
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (v.second[i] > 0) {
        --v.second[i];
        if (!used.count(v.second)) {
          bool good = true;
          if (!s.empty()) {
            auto it2 = s.end();
            --it2;
            if (v.first + a[i][v.second[i] + 1] - a[i][v.second[i]] >=
                it2->first) {
              good = false;
            }
          }
          if (good) {
            used.insert(v.second);
            s.insert(make_pair(
                v.first + a[i][v.second[i] + 1] - a[i][v.second[i]], v.second));
            if (((int)(s).size()) >= 1e6) {
              auto it2 = s.end();
              --it2;
              s.erase(it2);
            }
          }
        }
        ++v.second[i];
      }
    }
  }
  assert(false);
}
int main() {
  init();
  int t = 1;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
