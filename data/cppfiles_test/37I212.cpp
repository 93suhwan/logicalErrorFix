#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> st;
int visited[1000000];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
      int x, y;
      int o;
      cin >> x;
      cin >> y >> o;
      if (x != 1 && y != 1) {
        st.insert({1, x});
        st.insert({1, y});
      } else {
        st.insert({x, y});
      }
      if (o == 1) {
        st.insert({x, o});
      } else {
        st.insert({1, o});
      }
      visited[x] = 1;
      visited[y] = 1;
    }
    if (st.size() < n - 1) {
      while (st.size() < n - 1) {
        for (int i = 1; i <= n; i++) {
          if (visited[i] == 0) {
            st.insert({1, i});
          }
        }
      }
    }
    int count = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
      pair<int, int> kk = *it;
      cout << kk.first << " " << kk.second << endl;
      count++;
      if (count == n - 1) break;
    }
  }
  return 0;
}
