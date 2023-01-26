#include <bits/stdc++.h>
using namespace std;
set<int> st;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    st.clear();
    int tot = a + b;
    int f = tot / 2;
    int s = tot - f;
    set<int>::iterator it;
    for (int i = 0; i <= min(a, f); i++) {
      if (a - i <= s) {
        st.insert(a - i + f - i);
      }
    }
    for (int i = 0; i <= min(a, s); i++) {
      if (a - i <= f) {
        st.insert(a - i + s - i);
      }
    }
    cout << (int)st.size() << endl;
    for (it = st.begin(); it != st.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }
  return 0;
}
