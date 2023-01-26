#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int test, flag1, flag2, flag[maxn], ans, len, numr, numg;
string s;
void solve() {
  cin >> s;
  ans = flag1 = numg = numr = 0;
  flag2 = 1;
  memset(flag, 0, sizeof(flag));
  len = s.size();
  while (flag2) {
    flag2 = 0;
    for (int i = 0; i < len - 1; i++) {
      if (s[i] - '0' > s[i + 1] - '0') swap(s[i], s[i + 1]), flag2 = 1;
    }
  }
  for (int i = 0; i < len; i++) {
    flag[s[i] - '0']++;
    if (flag[s[i] - '0'] > 2)
      continue;
    else {
      if (!flag1)
        numr++, flag1 = 1;
      else
        numg++, flag1 = 0;
    }
  }
  cout << min(numg, numr) << '\n';
}
int main() {
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
