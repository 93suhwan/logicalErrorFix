#include <bits/stdc++.h>
using namespace std;
bool compare(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first > p2.first;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long m, n;
    cin >> m >> n;
    vector<vector<long long>> v(m, vector<long long>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> v[i][j];
      }
    }
    long long ans = 0;
    long long low = 0;
    long long high = 2e18;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      bool n1 = false, n2 = false;
      set<long long> st;
      for (int i = 0; i < n; i++) {
        n1 = false;
        for (int j = 0; j < m; j++) {
          if (v[j][i] >= mid) {
            n1 = true;
            if (st.count(j)) {
              n2 = true;
            }
            st.insert(j);
          }
        }
        if (n1 == false) {
          break;
        }
      }
      if (n1 && n2) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
