#include <bits/stdc++.h>
const long long int mx = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int rem[] = {5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0};
    string s, s1 = "??????????", s2 = "??????????";
    cin >> s;
    int st = 0, nd = 0;
    for (int i = 0; i < 10; i++) {
      s1[i] = s[i], s2[i] = s[i];
      if (s[i] == '?' && i % 2 == 0) s1[i] = '1', s2[i] = '0';
      if (s[i] == '?' && i % 2 == 1) s2[i] = '1', s1[i] = '0';
    }
    int in = 10, mn1 = 10, mn2 = 10, mn3 = 10, mn4 = 10;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (s1[i] == '1') st++;
      } else {
        if (s1[i] == '1') nd++;
      }
      if (nd > (st + rem[i + 1])) {
        mn1 = i + 1;
        break;
      }
      if (st > (nd + rem[i + 1])) {
        mn1 = i + 1;
        break;
      }
    }
    st = 0, nd = 0;
    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0) {
        if (s2[i] == '1') st++;
      } else {
        if (s2[i] == '1') nd++;
      }
      if (nd > (st + rem[i + 1])) {
        mn2 = i + 1;
        break;
      }
      if (st > (nd + rem[i + 1])) {
        mn2 = i + 1;
        break;
      }
    }
    st = 0, nd = 0;
    for (int i = 0; i < 10; i++) {
      in = i;
      if (i % 2 == 0) {
        if (s1[i] == '1') st++;
      } else {
        if (s1[i] == '1') nd++;
      }
      if (nd > st) {
        if (i % 2 == 0) in = i + 1;
        if (nd > (st + rem[in + 1])) {
          mn3 = i + 1;
          break;
        }
      }
      if (st > nd) {
        if (i % 2 == 1) in = i + 1;
        if (st > (nd + rem[in + 1])) {
          mn3 = i + 1;
          break;
        }
      }
    }
    st = 0, nd = 0;
    for (int i = 0; i < 10; i++) {
      in = i;
      if (i % 2 == 0) {
        if (s2[i] == '1') st++;
      } else {
        if (s2[i] == '1') nd++;
      }
      if (nd > st) {
        if (i % 2 == 0) in = i + 1;
        if (nd > (st + rem[in + 1])) {
          mn4 = i + 1;
          break;
        }
      }
      if (st > nd) {
        if (i % 2 == 1) in = i + 1;
        if (st > (nd + rem[in + 1])) {
          mn4 = i + 1;
          break;
        }
      }
    }
    cout << min(mn1, min(mn2, min(mn3, mn4))) << endl;
  }
  return 0;
}
