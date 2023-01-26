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
        if (s[i] == 'a' && s[i + 1] == 'b') {
          cout << i + 1 << " " << i + 2 << endl;
          break;
        }
        if (s[i] == 'b' && s[i + 1] == 'a') {
          cout << i + 1 << " " << i + 2 << endl;
          break;
        }
      }
    }
  }
}
