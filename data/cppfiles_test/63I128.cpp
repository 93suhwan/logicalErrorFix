#include <bits/stdc++.h>
using namespace std;
string S[20];
vector<pair<pair<int, int>, int> > psList[20];
int ps[(1 << 20)], dp[(1 << 20)];
int Process(string &s, vector<pair<pair<int, int>, int> > &psList) {
  int ps = 0;
  for (int i = 0, n = s.size(); i < n; ++i) {
    ps += (s[i] == '(' ? 1 : -1);
    psList.push_back({{ps, i}, i});
  }
  sort(psList.begin(), psList.end());
  int x = INT_MAX;
  for (auto &p : psList) {
    x = min(x, p.second);
    p.second = x;
  }
  return ps;
}
int Calculate(int i, int ps, int c) {
  ps = -ps;
  auto &v = psList[i];
  int k = lower_bound(v.begin(), v.end(), make_pair(make_pair(ps, 0), 0)) -
          v.begin();
  if (k >= v.size() || v[k].first.first != ps) {
    return c;
  }
  int n = k != 0 ? v[k - 1].second : INT_MAX;
  return c +
         (lower_bound(v.begin() + k, v.end(), make_pair(make_pair(ps, n), n)) -
          (v.begin() + k));
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> S[i];
  }
  for (int i = 0; i < n; ++i) {
    int mask = (1 << i);
    ps[mask] = Process(S[i], psList[i]);
  }
  int m = (1 << n);
  for (int mask = 1; mask < m; ++mask) {
    int i = __builtin_ctz(mask);
    int imask = (1 << i);
    ps[mask] = ps[(mask ^ imask)] + ps[imask];
  }
  for (int mask = 1; mask < m; ++mask) {
    bool isPossible = false;
    int tmask = mask, ans = INT_MIN;
    while (tmask != 0) {
      int i = __builtin_ctz(tmask);
      int rmask = mask ^ (1 << i);
      ans = max(ans, dp[rmask]);
      if (ps[rmask] >= 0) {
        isPossible = true;
        ans = max(ans, Calculate(i, ps[rmask], dp[rmask]));
      }
      tmask ^= (1 << i);
    }
    if (!isPossible) {
      ps[mask] = INT_MIN;
    }
    dp[mask] = ans;
  }
  cout << dp[m - 1] << '\n';
  return 0;
}
