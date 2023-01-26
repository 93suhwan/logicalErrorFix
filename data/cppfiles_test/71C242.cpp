#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string str;
    int k;
    cin >> str >> k;
    while (true) {
      set<char> st;
      for (int i = 0; i < str.size(); i++) st.insert(str[i]);
      if (st.size() <= k) break;
      st.clear();
      for (int i = 0; i < str.size(); i++) {
        st.insert(str[i]);
        if (st.size() > k) {
          int pos = i;
          while (str[pos] == '9') pos--;
          str[pos] += 1;
          for (int j = pos + 1; j < str.size(); j++) {
            str[j] = '0';
          }
          break;
        }
      }
    }
    cout << str << endl;
  }
  return 0;
}
