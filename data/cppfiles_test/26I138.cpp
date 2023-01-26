#include <bits/stdc++.h>
using namespace std;
int check(string st) {
  int s1 = 0, s2 = 0;
  for (int i = 1; i < st.length(); i++) {
    if (st[i] == '1' && i % 2 == 1) s1++;
    if (st[i] == '1' && i % 2 == 0) s2++;
    if (s1 - s2 > 5 - i / 2 || (i % 2 == 1 && s2 - s1 >= 5 - i / 2)) return i;
  }
  return 10;
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    string st;
    cin >> st;
    st = " " + st;
    string sts = st;
    for (int i = 1; i < st.length(); i++)
      if (st[i] == '?')
        if (i % 2 == 1)
          st[i] = '1';
        else
          st[i] = '0';
    for (int i = 1; i < sts.length(); i++)
      if (sts[i] == '?')
        if (i % 2 == 0)
          sts[i] = '1';
        else
          sts[i] = '0';
    cout << min(check(st), check(sts)) << endl;
  }
  return 0;
}
