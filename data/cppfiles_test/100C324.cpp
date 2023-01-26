#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long m = 0, mx = -1e18;
  vector<long long> st(n);
  for (int i = 0; i < n; i++) {
    cin >> st[i];
  }
  sort(st.begin(), st.end());
  for (int i = 0; i < n; i++) {
    long long temp = st[i] - m;
    mx = max(temp, mx);
    m += temp;
  }
  cout << mx << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
