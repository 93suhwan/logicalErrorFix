#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int f = (a + b) / 2;
    int s = (a + b) - f;
    set<int> st;
    int i;
    for (i = 0; i <= min(a, f); i++) {
      if (a - i <= s) {
        st.insert(a - i + f - i);
      }
    }
    for (i = 0; i <= min(a, s); i++) {
      if (a - i <= f) {
        st.insert(a - i + s - i);
      }
    }
    cout << st.size() << "\n";
    for (auto ans : st) {
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}
