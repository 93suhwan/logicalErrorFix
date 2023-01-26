#include <bits/stdc++.h>
using namespace std;
void test_case() {
  string st;
  cin >> st;
  int la, lb;
  long long a = 0, b = 0;
  long long cur1 = 1, cur2 = 1;
  for (lb = 0, la = (int)st.length() - 1; la >= 0; la--, lb++) {
    if (lb % 2 == 0) {
      a += (cur1 * (st[la] - '0'));
      cur1 *= 10;
    } else {
      b += (cur2 * (st[la] - '0'));
      cur2 *= 10;
    }
  }
  long long ans = (a + 1) * (b + 1);
  ans -= 2;
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    test_case();
  }
  return 0;
}
