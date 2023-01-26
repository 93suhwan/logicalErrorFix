#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    set<int> st;
    vector<int> v;
    for (int i = 0; i < 7; i++) {
      int x;
      cin >> x;
      if (i < 2) v.push_back(x);
      st.insert(x);
    }
    auto third = st.begin();
    for (int i = 0; i < 2; i++) {
      auto it = st.begin();
      it++;
      if (i == 1) it++;
      auto last = st.rbegin();
      for (; it != st.end(); it++) {
        long long x = v[i] + (*it);
        if (st.find(x) != st.end() && v[0] + v[1] + *it == *last) {
          third = it;
          break;
        }
      }
    }
    cout << v[0] << " " << v[1] << " " << *third << "\n";
  }
}
