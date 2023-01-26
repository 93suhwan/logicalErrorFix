#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<int> v(n);
  map<long long, set<long long>> m;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]].insert(i);
  }
  vector<int> ans(n), t;
  for (auto it : m) {
    int c = 0;
    set<long long> cur = it.second;
    for (auto i : cur) {
      if (c < k) t.push_back(i);
      c++;
    }
  }
  long long N = t.size() % k;
  while (N--) t.pop_back();
  long long c = 0;
  for (int i = 0; i < t.size(); i++) {
    ans[i] = c + 1;
    c++;
    c = c % k;
  }
  for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
