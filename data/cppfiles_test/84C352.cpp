#include <bits/stdc++.h>
using namespace std;
bool checkbalanced(string s) {
  int n = s.size();
  stack<int> st;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(s[i]);
    } else {
      if (st.empty()) {
        return false;
      }
      if (st.top() == '(') {
        st.pop();
      } else {
        return false;
      }
    }
  }
  return st.empty();
}
void help(int s, int e, string op) {
  if (s == 0 && e == 0) {
    if (checkbalanced(op)) {
      cout << op << endl;
    }
    return;
  }
  if (s >= 1) {
    help(s - 1, e, op + '(');
  }
  if (e >= 1) {
    help(s, e - 1, op + ')');
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s;
    cin >> n >> s;
    cout << s / ((n / 2) + 1) << endl;
  }
}
