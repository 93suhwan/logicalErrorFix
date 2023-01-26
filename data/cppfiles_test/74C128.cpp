#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int tot = a + b;
    int f = tot / 2;
    int s = tot - f;
    set<int> st;
    for (int i = 0; i <= min(a, f); i++) {
      if (a - i <= s) st.insert(a - i + f - i);
    }
    for (int i = 0; i <= min(a, s); i++)
      if (a - i <= f) st.insert(a - i + s - i);
    cout << st.size() << endl;
    for (auto i : st) cout << i << " ";
    cout << endl;
  }
  return 0;
}
