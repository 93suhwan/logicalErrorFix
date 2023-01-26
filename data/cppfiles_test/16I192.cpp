#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  set<pair<long long, long long>> s1;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    s1.insert({x, i + 1});
  }
  vector<pair<long long, long long>> ans;
  while (s1.size() > 1) {
    auto p1 = *s1.rbegin();
    s1.erase(p1);
    auto p2 = *s1.rbegin();
    s1.erase(p2);
    if (p1.first > p2.first) {
      for (long long i = 0; i < p2.first; i++)
        ans.push_back({p1.second, p2.second});
      p1.first -= p2.first;
      s1.insert(p1);
    } else {
      for (long long i = 0; i < p1.first; i++)
        ans.push_back({p1.second, p2.second});
      p2.first -= p1.first;
      if (p2.first != 0) s1.insert(p2);
    }
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
