#include <bits/stdc++.h>
using namespace std;
const int MX = 200005, mod = 998244353;
int n;
long long a[MX], dp[MX];
stack<vector<long long> > st;
void main_() {
  cin >> n;
  for (int i = 0; i < int(n); i++) cin >> a[i];
  long long acu = 0;
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    long long s = i % 2 ? -dp[i + 1] : dp[i + 1];
    while (st.size() && st.top()[0] >= a[i]) {
      (acu -= st.top()[0] * st.top()[1]) %= mod;
      (s += st.top()[1]) %= mod;
      st.pop();
    }
    (acu += a[i] * s) %= mod;
    st.push({a[i], s});
    dp[i] = i % 2 ? -acu : acu;
  }
  cout << ((((dp[0]) % (mod)) + (mod)) % (mod)) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) main_();
  return 0;
}
