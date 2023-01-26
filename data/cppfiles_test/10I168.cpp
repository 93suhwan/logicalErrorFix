#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
int ans[MAX];
void solve() {
  int n, k, tmp;
  map<int, vector<int> > make_pair;
  cin >> n >> k;
  for (int i = 0; i < MAX; ++i) ans[i] = 0;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    if (make_pair[tmp].size() < k) make_pair[tmp].push_back(i);
  }
  int all = 0;
  for (auto i : make_pair) {
    all += i.second.size();
  }
  all -= all % k;
  tmp = 1;
  for (auto i : make_pair) {
    for (auto i1 : i.second) {
      ans[i1] = tmp;
      tmp++;
      tmp %= (k + 1);
      all--;
      if (all == 0) break;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
