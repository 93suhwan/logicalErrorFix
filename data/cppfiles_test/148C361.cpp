#include <bits/stdc++.h>
using namespace std;
int codefo;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> codefo;
  while (codefo--) {
    long long w, h;
    cin >> w >> h;
    vector<vector<long long>> x(2), y(2);
    vector<long long> X, Y;
    long long ans = 0;
    for (int i = 0; i < 2; i++) {
      int k;
      cin >> k;
      x[i].resize(k);
      for (int j = 0; j < k; j++) cin >> x[i][j];
      ans = max(ans, h * (x[i][k - 1] - x[i][0]));
    }
    for (int i = 0; i < 2; i++) {
      int k;
      cin >> k;
      y[i].resize(k);
      for (int j = 0; j < k; j++) cin >> y[i][j];
      Y.push_back(y[i][0]);
      ans = max(ans, w * (y[i][k - 1] - y[i][0]));
    }
    cout << ans << endl;
  }
}
