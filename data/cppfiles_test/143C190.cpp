#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n;
  cin >> n;
  vector<int> ima(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++ima[x];
  }
  ll treba = 0;
  vector<ll> ans(n + 1, -1);
  int tren = 0;
  stack<int> st;
  for (int mex = 0; mex <= n; ++mex) {
    if (tren >= mex) {
      ans[mex] = treba + ima[mex];
    }
    tren += ima[mex];
    if (ima[mex] == 0) {
      while (!st.empty() && ima[st.top()] <= 1) st.pop();
      if (st.empty()) {
        break;
      }
      --ima[st.top()];
      ++ima[mex];
      treba += mex - st.top();
    } else if (ima[mex] > 1) {
      st.push(mex);
    }
  }
  for (auto z : ans) cout << z << " ";
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
