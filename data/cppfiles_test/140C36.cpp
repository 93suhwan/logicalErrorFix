#include <bits/stdc++.h>
using namespace std;
int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    long long x;
    cin >> x;
    set<long long> st;
    for (long long i = 1; i * i <= x; i++) {
      long long g = i * i;
      st.insert(g);
      if (g * i <= x) st.insert(g * i);
    }
    cout << st.size() << endl;
    st.clear();
  }
  return 0;
}
