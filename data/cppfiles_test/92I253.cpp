#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int len = s.size();
  int ab = 0, ba = 0;
  stack<char> st;
  for (int i = 0; i < len; i++) {
    if (!st.empty()) {
      char top = st.top();
      if (s[i] == 'b' && top == 'a') {
        st.pop();
        ab++;
      } else if (s[i] == 'a' && top == 'b') {
        st.pop();
        ba++;
      } else
        st.push(s[i]);
    } else
      st.push(s[i]);
  }
  if (ab > ba) {
    for (int i = 0; i < len; i++) {
      if (s[i] == 'b' && i != 0) {
        s[i - 1] = 'b';
        break;
      }
    }
  } else if (ba > ab) {
    for (int i = 0; i < len; i++) {
      if (s[i] == 'a' && i != 0) {
        s[i - 1] = 'a';
        break;
      }
    }
  }
  cout << s << endl;
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    solve();
  }
}
