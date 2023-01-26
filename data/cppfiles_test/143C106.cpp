#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, S_INF = 1e7;
void solve() {
  int n;
  cin >> n;
  vector<long long int> freq(n + 1);
  int x;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    freq[x]++;
  }
  vector<long long int> ans(n + 1, -1);
  stack<int> st;
  long long int adj = 0;
  for (int i = 0; i <= n; ++i) {
    if (freq[i]) {
      ans[i] = adj + freq[i];
      if (freq[i] > 1) st.push(i);
    } else {
      ans[i] = adj;
      if (st.empty()) break;
      int j = st.top();
      freq[i]++, freq[j]--;
      if (freq[j] == 1) st.pop();
      adj += (long long int)(i - j);
    }
  }
  for (const long long int& val : ans) cout << val << ' ';
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(ios::badbit | ios::failbit);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
