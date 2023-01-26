#include <bits/stdc++.h>
using namespace std;
long long n, m, k, q, x;
vector<pair<long long, long long>> matched;
set<long long> freex;
void solve() {
  cin >> n >> k;
  vector<pair<long long, long long>>().swap(matched);
  freex.clear();
  for (long long i = 0; i < 2 * n; ++i) freex.insert(i);
  for (long long i = 0; i < k; ++i) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    if (b < a) swap(a, b);
    matched.push_back({a, b});
    freex.erase(a);
    freex.erase(b);
  }
  vector<long long> nums;
  for (auto e : freex) nums.push_back(e);
  long long offset = nums.size() / 2;
  for (long long i = 0; i < offset; ++i) {
    matched.push_back({nums[i], nums[i + offset]});
  }
  sort(matched.begin(), matched.end());
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = i + 1; j < n; ++j) {
      long long a = matched[i].first;
      long long b = matched[i].second;
      long long aa = matched[j].first;
      long long bb = matched[j].second;
      if (a < aa and b < bb and aa < b) {
        sum++;
      }
    }
  }
  cout << sum << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  long long z = 0;
  cin >> z;
  while (z--) {
    solve();
  }
}
