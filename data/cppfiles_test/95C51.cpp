#include <bits/stdc++.h>
using namespace std;
template <typename T>
int smin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
int smax(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
mt19937_64 rng;
const int MX = 2e5 + 10;
const char nl = '\n';
void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> pre_max(n, vector<int>(m));
  vector<vector<int>> pre_min(n, vector<int>(m));
  vector<vector<int>> suf_max(n, vector<int>(m));
  vector<vector<int>> suf_min(n, vector<int>(m));
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      pre_max[i][j] = a[i][j];
      pre_min[i][j] = a[i][j];
      if (j > 0) {
        pre_max[i][j] = max(pre_max[i][j], pre_max[i][j - 1]);
        pre_min[i][j] = min(pre_min[i][j], pre_min[i][j - 1]);
      }
    }
  }
  for (int j = m - 1; j >= 0; --j) {
    for (int i = 0; i < n; i++) {
      suf_max[i][j] = a[i][j];
      suf_min[i][j] = a[i][j];
      if (j + 1 < m) {
        suf_max[i][j] = max(suf_max[i][j], suf_max[i][j + 1]);
        suf_min[i][j] = min(suf_min[i][j], suf_min[i][j + 1]);
      }
    }
  }
  for (int j = 0; j + 1 < m; j++) {
    vector<array<int, 2>> left;
    for (int i = 0; i < n; i++) {
      left.push_back({pre_max[i][j], i});
    }
    sort(left.rbegin(), left.rend());
    multiset<int> left_blue, right_blue;
    for (int i = 0; i < n; i++) {
      left_blue.insert(pre_max[i][j]);
      right_blue.insert(suf_min[i][j + 1]);
    }
    string answer(n, 'B');
    int left_red = 1e9 + 10, right_red = -1;
    for (const auto& [_, i] : left) {
      answer[i] = 'R';
      left_blue.erase(left_blue.find(pre_max[i][j]));
      right_blue.erase(right_blue.find(suf_min[i][j + 1]));
      left_red = min(left_red, pre_min[i][j]);
      right_red = max(right_red, suf_max[i][j + 1]);
      if (((int)(left_blue.size())) == 0) break;
      if (left_red > *left_blue.rbegin() && *right_blue.begin() > right_red) {
        cout << "YES\n";
        cout << answer << " " << j + 1 << nl;
        return;
      }
    }
  }
  cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te = 1;
  cin >> te;
  while (te--) {
    solve();
  }
  return 0;
}
