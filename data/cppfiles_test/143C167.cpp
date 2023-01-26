#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> vec(n + 1);
    for (long long i = 0; i < n; i++) {
      long long a;
      cin >> a;
      vec[a]++;
    }
    stack<long long> st;
    if (vec[0] > 1) st.push(0);
    long long ans = 0;
    cout << vec[0] << ' ';
    for (long long i = 1; i <= n; i++) {
      if (ans == -1) {
        cout << -1 << ' ';
        continue;
      }
      if (vec[i - 1] == 0) {
        if (st.empty()) {
          ans = -1;
          cout << -1 << ' ';
          continue;
        }
        ans += i - 1 - st.top();
        vec[st.top()]--;
        vec[i - 1] = 1;
        if (vec[st.top()] == 1) st.pop();
      }
      cout << ans + vec[i] << ' ';
      if (vec[i] > 1) st.push(i);
    }
    cout << "\n";
  }
  return 0;
}
