#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int64_t ans = 0, power = 0;
    vector<tuple<int, int>> B(n);
    vector<vector<int>> A(n);
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      A[i].resize(m);
      for (int j = 0; j < m; j++) {
        cin >> A[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int)A[i].size(); j++) {
        A[i][j] -= j;
      }
    }
    for (int i = 0; i < n; i++) {
      B[i] = make_tuple(*max_element(A[i].begin(), A[i].end()) + 1,
                        (int)A[i].size());
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < n; i++) {
      int64_t start, end;
      tie(start, end) = B[i];
      ans += max((int64_t)0, start - power);
      power = max(power + end, start + end);
    }
    cout << ans << endl;
  }
  return 0;
}
