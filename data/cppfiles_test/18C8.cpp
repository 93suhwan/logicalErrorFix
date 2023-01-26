#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n, k;
set<int> st;
void pre() {
  for (int i = 0; i < 2 * n; ++i) st.insert(i);
}
void run() {
  cin >> n >> k;
  pre();
  vector<pair<long long, long long>> vec;
  for (int i = 0; i < k; ++i) {
    long long x, y;
    cin >> x >> y;
    --x;
    --y;
    if (x > y) swap(x, y);
    vec.push_back({x, y});
    st.erase(x);
    st.erase(y);
  }
  vector<long long> a;
  int ans = 0;
  set<int>::iterator it = st.begin();
  for (; it != st.end(); ++it) {
    a.push_back(*it * 1ll);
  }
  int sz = (int((a).size()));
  for (int i = 0; i < sz / 2; ++i) {
    vec.push_back({a[i], a[sz / 2 + i]});
  }
  for (int i = 0; i < n; ++i) {
    long long l1 = vec[i].first;
    long long r1 = vec[i].second;
    for (int j = i + 1; j < n; ++j) {
      long long l2 = vec[j].first;
      long long r2 = vec[j].second;
      if ((l1 < l2 && l2 < r1 && r1 < r2) || (l2 < l1 && l1 < r2 && r2 < r1))
        ans++;
    }
  }
  cout << ans << '\n';
  st.clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  tt = 1;
  cin >> tt;
  while (tt--) run();
}
