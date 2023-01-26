#include <bits/stdc++.h>
using namespace std;
int n;
unordered_set<int> st;
int solve() {
  st.clear();
  for (int i = 1; i <= n / i; ++i) {
    st.insert(i * i);
    if (i * i <= n / i) st.insert(i * i * i);
  }
  return st.size();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << endl;
  }
  return 0;
}
