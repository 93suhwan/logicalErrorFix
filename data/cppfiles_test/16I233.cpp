#include <bits/stdc++.h>
using namespace std;
void print(vector<pair<int, int>> a) {
  for (auto x : a) {
    cout << x.first << " ";
  }
  cout << "\n";
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> aa(n);
  set<pair<int, int>> sp;
  for (int i = 0; i < n; i++) {
    cin >> aa[i].first;
    aa[i].second = i;
    if (aa[i].first > 0) sp.insert(aa[i]);
  }
  vector<pair<int, int>> ans;
  while (sp.size() > 1) {
    pair<int, int> a = *sp.begin();
    pair<int, int> b = *sp.rbegin();
    sp.erase(a);
    sp.erase(b);
    ans.push_back({a.second, b.second});
    a.first--;
    b.first--;
    if (a.first > 0) sp.insert(a);
    if (b.first > 0)
      ;
    sp.insert(b);
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
