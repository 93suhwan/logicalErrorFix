#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
const long long SZ = 1010, INF = 1e9, LG = 61;
long long n, k;
long long cols[SZ][SZ];
vector<vector<long long>> sts;
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  cin >> n >> k;
  long long curr = 1;
  sts.resize(n);
  for (int i = 0; i < sts.size(); i++) {
    sts[i].push_back(i);
  }
  while (sts.size() > 1) {
    vector<vector<long long>> svd;
    while (sts.size() > 0) {
      vector<long long> pr;
      for (int i = 0; i < k; i++) {
        if (sts.size() > 0) {
          vector<long long> cur = sts.back();
          sts.pop_back();
          for (auto c : cur) {
            for (auto t : pr) {
              cols[c][t] = curr;
            }
          }
          for (auto c : cur) pr.push_back(c);
        }
      }
      svd.push_back(pr);
    }
    reverse(svd.begin(), svd.end());
    sts = svd;
    curr++;
  }
  cout << curr - 1 << "\n";
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << cols[i][j] << " ";
    }
  }
  return 0;
}
