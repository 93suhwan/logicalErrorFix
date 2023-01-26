#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int>& a, vector<int>& b) { return a[1] - a[0] < b[1] - b[0]; }
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> v;
    int l, r;
    for (int i = 0; i < n; i++) {
      cin >> l >> r;
      v.push_back({l, r});
    }
    sort(v.begin(), v.end(), comp);
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
      if (v[i][1] - v[i][0] == 0) {
        cout << v[i][0] << " " << v[i][1] << " " << v[i][0];
        st.insert(v[i][0]);
      } else {
        int nw = 0;
        for (int j = v[i][0]; j <= v[i][1]; j++) {
          if (st.find(j) == st.end()) {
            nw = j;
            break;
          }
        }
        cout << v[i][0] << " " << v[i][1] << " " << nw;
        st.insert(nw);
      }
      cout << endl;
    }
  }
  return 0;
}
