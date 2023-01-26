#include <bits/stdc++.h>
using namespace std;
const int max_size = 2e5 + 100;
map<int, int> mp;
vector<pair<int, int> > v;
int ans[max_size];
int main() {
  int t, n, k, x;
  cin >> t;
  while (t--) {
    mp.clear();
    v.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      ans[i] = 0;
      cin >> x;
      mp[x]++;
      if (mp[x] <= k) v.push_back(make_pair(x, i));
    }
    int sum = v.size() - v.size() % k;
    sort(v.begin(), v.end());
    for (int i = 0; i < sum; i++) {
      ans[v[i].second] = i % k + 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
