#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const long long h_mod = 10007;
const long long h_base = 265;
const long long mod = 1e9 + 7;
const long long N = 110;
int t, n, x, y;
set<int> st;
int main() {
  cin >> t;
  while (t--) {
    st.clear();
    cin >> x >> y;
    int ans = 0, sum = 0;
    sum = min(x, y);
    ans = (x + y + 1) / 2 + sum;
    st.insert(ans);
    while (sum--) {
      ans -= 2;
      st.insert(ans);
    }
    sum = max(x, y);
    ans = sum - (x + y + 1) / 2;
    st.insert(ans);
    sum = min(x, y);
    while (sum--) {
      ans += 2;
      st.insert(ans);
    }
    cout << st.size() << endl;
    for (auto v : st) {
      cout << v << " ";
    }
    cout << endl;
  }
  return 0;
}
