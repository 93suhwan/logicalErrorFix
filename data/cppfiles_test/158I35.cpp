#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }
    vector<string> s(n);
    mt19937 gen(time(NULL));
    uniform_int_distribution<int> uid(0, 1);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    vector<vector<int>> gr(1 << n);
    for (int j = 0; j < m; ++j) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        sum = (sum << 1) + s[i][j] - '0';
      }
      gr[sum].push_back(j);
    }
    vector<vector<int>> srt;
    for (int i = 0; i < (1 << n); ++i) {
      if ((int)gr[i].size()) {
        srt.push_back(gr[i]);
      }
    }
    vector<int> col(m);
    for (int i = 0; i < (int)srt.size(); ++i) {
      for (auto& j : srt[i]) {
        col[j] = i;
      }
    }
    vector<vector<int>> uses(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '1') {
          uses[i].push_back(col[j]);
        }
      }
      sort(uses[i].begin(), uses[i].end());
      uses[i].erase(unique(uses[i].begin(), uses[i].end()), uses[i].end());
    }
    int ans = 0;
    vector<int> vans;
    for (int i = 0; i < (1 << n); ++i) {
      int sum = 0;
      vector<int> gcnt((int)srt.size());
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          sum += x[i];
          for (auto& x : uses[j]) {
            --gcnt[x];
          }
        } else {
          sum -= x[i];
          for (auto& x : uses[j]) {
            ++gcnt[x];
          }
        }
      }
      vector<vector<int>> gsrt;
      for (int i = 0; i < (int)srt.size(); ++i) {
        gsrt.push_back({gcnt[i], (int)srt[i].size(), i});
      }
      sort(gsrt.begin(), gsrt.end());
      int l = 1;
      for (int i = 0; i < (int)srt.size(); ++i) {
        int r = l + (int)gsrt[i][1] - 1;
        sum += (r + l) * (r - l + 1) / 2 * gsrt[i][0];
        l = r + 1;
      }
      if (sum > ans) {
        ans = sum;
        vans.clear();
        for (int i = (int)srt.size() - 1; i >= 0; --i) {
          vans.push_back(gsrt[i][2]);
        }
      }
    }
    vector<int> out(m);
    int l = 1;
    for (auto& i : vans) {
      for (auto& j : srt[i]) {
        out[j] = l++;
      }
    }
    for (int i = 0; i < m; ++i) {
      cout << out[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
