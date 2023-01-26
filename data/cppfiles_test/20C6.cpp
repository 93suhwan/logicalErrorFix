#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  vector<vector<long long>> all(n);
  for (long long i = 0; i < k * n; i++) {
    long long a;
    cin >> a, a--;
    all[a].push_back(i);
  }
  long long tk = (n - 1) / (k - 1) + 1;
  vector<bool> used(n);
  vector<pair<long long, long long>> ans(n);
  for (long long j = 1; j < k; j++) {
    vector<pair<long long, long long>> to_sort;
    for (long long i = 0; i < n; i++)
      if (!used[i]) to_sort.emplace_back(all[i][j], i);
    sort(to_sort.begin(), to_sort.end());
    long long m = to_sort.size();
    for (long long i = 0; i < min(tk, m); i++) {
      used[to_sort[i].second] = true;
      ans[to_sort[i].second] = {all[to_sort[i].second][j - 1] + 1,
                                to_sort[i].first + 1};
    }
  }
  for (auto an : ans) cout << an.first << " " << an.second << '\n';
  return 0;
}
