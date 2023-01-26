#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
resume:
  while (t--) {
    int n;
    cin >> n;
    vector<array<int, 5>> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    int ind = 0;
    auto sup = [&](int i) -> bool {
      int cnt = 0;
      for (int j = 0; j < 5; j++) {
        cnt += (a[ind][j] < a[i][j]);
      }
      return cnt >= 3;
    };
    for (int i = 1; i < n; i++) {
      if (!sup(i)) {
        ind = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == ind) continue;
      if (!sup(i)) {
        cout << -1 << "\n";
        goto resume;
      }
    }
    cout << ind + 1 << "\n";
  }
  return 0;
}
