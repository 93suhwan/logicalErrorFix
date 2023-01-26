#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    string s;
    cin >> s;
    set<char> st;
    for (int i = 0; i < s.size(); i++) {
      st.insert(s[i]);
    }
    if (st.size() == 1) {
      cout << -1 << " " << -1 << endl;
    } else {
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[i + 1]) {
          cout << i + 1 << " " << i + 2 << endl;
          break;
        }
      }
    }
  }
}
