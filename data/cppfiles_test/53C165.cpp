#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  set<int> st;
  for (int i = 0; i < n; ++i) cin >> arr[i], st.insert(arr[i]);
  int v = 1;
  for (int i = 0; i < n - 1; ++i) {
    auto it = st.find(arr[i]);
    it++;
    if (it == st.end() || arr[i + 1] != (*it)) v++;
  }
  if (v <= k)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
