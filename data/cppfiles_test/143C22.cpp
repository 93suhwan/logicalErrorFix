#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void debm(T&&... args) {
  ((cout << args << ", "), ...);
  cout << "\n";
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long val;
    cin >> val;
    v.push_back(val);
  };
  vector<long long> cnt(n + 1, 0);
  for (auto x : v) cnt[x]++;
  sort((v).begin(), (v).end());
  vector<long long> ans(n + 1, 0);
  long long i = 0;
  stack<long long> st;
  while (i < n && v[i] == 0) {
    st.push(0);
    i++;
    ans[0]++;
  }
  bool f = 0;
  for (long long num = 1; num <= n; num++) {
    if (st.empty()) {
      ans[num] = -1;
      continue;
    }
    long long top = st.top();
    st.pop();
    if (f) ans[num] += ans[num - 1] - cnt[num - 1];
    if (top != num - 1) {
      ans[num] += (num - 1 - top);
      f = 1;
    }
    while (i < n && v[i] == num) {
      i++;
      ans[num]++;
      st.push(num);
    }
  }
  for (auto x : ans) cout << x << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
