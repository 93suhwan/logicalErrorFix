#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i].first;
      A[i].second = i;
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (A[i].second + 1 != A[i + 1].second) {
        ans++;
      }
    }
    if (ans + 1 <= k) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
