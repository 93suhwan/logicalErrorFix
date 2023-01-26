#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long t, n, s;
void solve(long long sum, long long num, stack<long long> &st) {
  if (num == 1) {
    st.push(sum);
    return;
  }
  long long x = 1;
  long long cur = sum;
  for (; cur > 0; cur /= 10, x *= 10)
    ;
  x /= 10;
  for (; sum - x <= num - 2; x /= 10)
    ;
  st.push(x);
  solve(sum - x, num - 1, st);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> s >> n;
    stack<long long> st;
    solve(s, n, st);
    while (!st.empty()) {
      cout << st.top() << " ";
      st.pop();
    }
    cout << '\n';
  }
  return 0;
}
