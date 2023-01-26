#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  for (int test = 0; test < t; test++) {
    string s;
    int n;
    cin >> s >> n;
    set<char> st;
    map<char, int> fst;
    int p = 0, lst = -1;
    while (p < int(s.size()) and int(st.size()) <= n) {
      if (st.count(s[p]) == 0) {
        fst[s[p]] = p;
        st.insert(s[p]);
        if (st.size() == n) {
          lst = p;
        }
      }
      p++;
    }
    if (int(st.size()) <= n) {
      cout << s << '\n';
    } else {
      p--;
      st.erase(s[p]);
      if ((*st.rbegin()) > s[p]) {
        s[p] = (*st.upper_bound(s[p]));
        for (p = p + 1; p < s.size(); p++) {
          s[p] = (*st.begin());
        }
      } else {
        int flag = 0;
        while (p > lst + 1) {
          p--;
          if ((*st.rbegin()) > s[p]) {
            s[p] = (*st.upper_bound(s[p]));
            for (int pp = p + 1; pp < s.size(); pp++) {
              s[pp] = (*st.begin());
            }
            flag = 1;
          }
        }
        if (flag == 0) {
          p = lst;
          st.erase(s[p]);
          if (s[p] != '9') {
            s[p] += 1;
            st.insert(s[p]);
            for (p = p + 1; p < s.size(); p++) {
              s[p] = (*st.begin());
            }
          } else {
            p--;
            if (fst[s[p]] == p) {
              st.erase(s[p]);
              st.insert('0');
            }
            s[p]++;
            for (p = p + 1; p < s.size(); p++) {
              s[p] = (*st.begin());
            }
          }
        }
      }
      cout << s << '\n';
    }
  }
  return 0;
}
