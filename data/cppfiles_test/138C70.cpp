#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
int __FAST_IO__ = []() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  return 0;
}();
int main() {
  int n, m, q;
  long long sum = 0;
  cin >> n >> m >> q;
  vector<long long> ans(q), pre, ca;
  vector<pair<int, int>> diff;
  vector<vector<int>> v, query(q);
  for (int i = 0; i < (n); ++i) {
    int a;
    cin >> a;
    v.push_back({a, 0});
    sum += a;
  }
  for (int i = 0; i < (m); ++i) {
    int b;
    cin >> b;
    v.push_back({b, 1});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < (v.size() - 1); ++i)
    diff.push_back({v[i + 1][0] - v[i][0], i + 1});
  sort(diff.begin(), diff.end());
  pre.resize(v.size());
  ca.resize(v.size());
  for (int i = 0; i < (v.size()); ++i) {
    pre[i] = v[i][0] + (i == 0 ? 0 : pre[i - 1]);
    ca[i] = (v[i][1] == 0) + (i == 0 ? 0 : ca[i - 1]);
  }
  for (int i = 0; i < (q); ++i) {
    int t;
    cin >> t;
    query[i] = {t, i};
  }
  sort(query.begin(), query.end());
  auto cal = [&](int l, int r) {
    int count = ca[r] - (l == 0 ? 0 : ca[l - 1]), left = r - count + 1;
    long long ret = pre[r] - (left == 0 ? 0 : pre[left - 1]);
    return ret;
  };
  vector<int> left, right;
  for (int i = 0; i < (v.size()); ++i) left.push_back(i), right.push_back(i);
  int j = 0;
  for (int i = 0; i < (q); ++i) {
    while (j < diff.size() && diff[j].first <= query[i][0]) {
      int t = diff[j++].second;
      int l = left[t - 1], r = right[t];
      long long leftcost = cal(l, t - 1), rightcost = cal(t, r);
      sum -= leftcost + rightcost;
      right[l] = r, left[r] = l;
      sum += cal(l, r);
    }
    ans[query[i][1]] = sum;
  }
  for (int i = 0; i < (q); ++i) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}
