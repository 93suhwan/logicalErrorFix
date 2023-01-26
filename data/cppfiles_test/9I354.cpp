#include <bits/stdc++.h>
using namespace std;
void func() {
  string s;
  cin >> s;
  if (s.length() == 1) {
    cout << "0\n";
    return;
  }
  set<char> st;
  for (char c : s) {
    st.insert(c);
  }
  cout << min(s.length() / 2, st.size()) << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    func();
  }
  return 0;
}
