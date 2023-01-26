#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  pair<string, int> solve(vector<vector<int>>& M) {
    int n = M.size();
    int m = M[0].size();
    vector<multiset<int>> S(n);
    for (int i = 0; i < n; ++i) {
      for (auto x : M[i]) {
        S[i].insert(x);
      }
    }
    const int INF = 1 << 24;
    vector<int> mins(n, INF);
    vector<int> maxs(n, -INF);
    vector<int> ord(n, 0);
    iota(ord.begin(), ord.end(), 0);
    auto cmp = [&](int l, int r) { return maxs[l] < maxs[r]; };
    for (int k = 0; k < m - 1; ++k) {
      for (int i = 0; i < n; ++i) {
        mins[i] = min(mins[i], M[i][k]);
        maxs[i] = max(maxs[i], M[i][k]);
        S[i].erase(S[i].find(M[i][k]));
      }
      multiset<int> MIN;
      for (int i = 0; i < n; ++i) {
        MIN.insert(mins[i]);
      }
      sort(ord.begin(), ord.end(), cmp);
      multiset<int> RB;
      multiset<int> RR;
      for (int i = 0; i < n; ++i) {
        RR.insert(*S[i].rbegin());
      }
      string res(n, 'R');
      for (int i = 0; i < n; ++i) {
        int l = i;
        int mx = maxs[ord[i]];
        while (i + 1 < n && maxs[ord[i + 1]] == mx) {
          ++i;
        }
        int r = i;
        for (int j = l; j <= r; ++j) {
          MIN.erase(MIN.find(mins[ord[j]]));
          auto x = *S[ord[j]].rbegin();
          RR.erase(RR.find(x));
          x = *S[ord[j]].begin();
          RB.insert(x);
          res[ord[j]] = 'B';
        }
        if (MIN.empty()) {
          break;
        }
        int mn = *MIN.begin();
        if (mn > mx) {
          if (*RR.rbegin() < *RB.begin()) {
            return {res, k + 1};
          }
        }
      }
    }
    return {"", 0};
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> M[i][j];
      }
    }
    auto res = sol.solve(M);
    if (res.second == 0 || res.first.empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << res.first << ' ' << res.second << '\n';
    }
  }
  return 0;
}
