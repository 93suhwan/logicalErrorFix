#include <bits/stdc++.h>
using namespace std;
int t, n;
char a[105];
vector<int> st;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    a[0] = 'B';
    st.clear();
    for (int i = 1; i <= n; i++) {
      char x;
      cin >> x;
      if (x == '?') {
        st.push_back(i);
        continue;
      }
      a[i] = x;
      while (!st.empty()) {
        if (x == 'B') {
          a[st.back()] = 'R';
          x = 'R';
        } else {
          a[st.back()] = 'B';
          x = 'B';
        }
        st.pop_back();
      }
    }
    if (!st.empty()) {
      char x = a[st.front() - 1];
      for (int i = st.front(); i <= st.back(); i++) {
        if (x == 'B') {
          a[i] = 'R';
          x = 'R';
        } else {
          a[i] = 'B';
          x = 'B';
        }
      }
    }
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
  }
}
