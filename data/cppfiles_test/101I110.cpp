#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& i : vec) {
      cin >> i;
    }
    string s;
    cin >> s;
    set<int> st;
    deque<int> deq;
    for (int i = 1; i <= n; i++) deq.push_back(i);
    for (int i = 0; i < n; i++) {
      if (st.count(vec[i]) == 0) {
        st.insert(vec[i]);
      } else {
        if (s[i] == 'R') {
          while (st.count(deq.back()) && deq.size()) {
            deq.pop_back();
          }
          if (vec[i] <= deq.back()) {
            st.insert(deq.back());
            deq.pop_back();
          }
        } else if (s[i] == 'B') {
          while (st.count(deq.front()) && deq.size()) {
            deq.pop_front();
          }
          if (vec[i] >= deq.front()) {
            st.insert(deq.front());
            deq.pop_front();
          }
        }
      }
    }
    if (st.size() == n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
