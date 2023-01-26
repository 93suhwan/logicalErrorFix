#include <bits/stdc++.h>
inline long long int GCD(long long int a, long long int b) {
  return b == 0 ? a : GCD(b, a % b);
}
inline long long int LCM(long long int a, long long int b) {
  return a * b / GCD(a, b);
}
inline long long int ceil(long long int a, long long int b) {
  return (a % b == 0) ? a / b : a / b + 1;
}
const long long int mod = 1e9 + 7;
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  long long int g1 = (a + b) / 2;
  long long int g2 = ceil(a + b, 2);
  set<long long int> st;
  if (a >= g1 && b <= g2) {
    long long int res = (a - g1);
    for (long long int i = 0; i <= g1; i++) {
      if ((res + i) <= g2)
        st.insert(res + 2 * i);
      else
        break;
    }
  }
  if (a >= g2 && b <= g1) {
    long long int res = (a - g2);
    for (long long int i = 0; i <= g2; i++) {
      if ((res + i) <= g1)
        st.insert(res + 2 * i);
      else
        break;
    }
  }
  if (b >= g1 && a <= g2) {
    long long int res = (b - g1);
    for (long long int i = 0; i <= g1; i++) {
      if ((res + i) <= g2)
        st.insert(res + 2 * i);
      else
        break;
    }
  }
  if (b >= g2 && a <= g1) {
    long long int res = (b - g2);
    for (long long int i = 0; i <= g2; i++) {
      if ((res + i) <= g1)
        st.insert(res + 2 * i);
      else
        break;
    }
  }
  cout << st.size() << "\n";
  for (auto &it : st) cout << it << " ";
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
