#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    set<char> st;
    cin >> s;
    for (int i = 0; i < n; i++) {
      st.insert(s[i]);
    }
    if (st.size() % 2 == 0) {
      cout << st.size() << endl;
      continue;
    } else {
      cout << st.size() - 1 << endl;
      continue;
    }
  }
}
