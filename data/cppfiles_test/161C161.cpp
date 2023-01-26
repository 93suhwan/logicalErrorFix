#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a.push_back({x, y});
  }
  sort(a.begin(), a.end(), cmp);
  set<int> st;
  for (int i = 1; i <= n; i++) st.insert(i);
  for (int i = 0; i < n; i++) {
    int x = a[i].first;
    int y = a[i].second;
    auto it = st.lower_bound(x);
    if (it == st.end()) it--;
    int z = (*it);
    st.erase(it);
    cout << x << " " << y << " " << z << endl;
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
