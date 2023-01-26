#include <bits/stdc++.h>
const long long mod = 998244353;
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  vector<int> ans(n + 1, 0), cnt(n + 1, 0), cur;
  for (auto c : v) cnt[c]++;
  cur = cnt;
  ans[0] = (cnt[0] == 0 ? -1 : cnt[0]);
  multiset<int> st;
  for (int i = 0; i < cnt[0] - 1; i++) st.insert(0);
  for (int i = 1; i < n + 1; i++) {
    if (ans[i - 1] == -1) {
      ans[i] = -1;
      continue;
    }
    if (cnt[i - 1] > 0) {
      ans[i] = cnt[i] + ans[i - 1] - cnt[i - 1];
    } else {
      if (st.empty()) {
        ans[i] = -1;
        continue;
      }
      ans[i] = cnt[i] + ans[i - 1] + i - *(--st.end()) - 1;
      st.erase(--st.end());
    }
    for (int j = 0; j < cnt[i] - 1; j++) st.insert(i);
  }
  for (auto c : ans) cout << c << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  int test;
  cin >> test;
  while (test--) solve();
}
