#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7, MAX = 1e6 + 5;
const long long INF = 1e18 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    vector<vector<int> > A(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
      cin >> A[i][0] >> A[i][1];
      ans += A[i][0] - A[i][1];
    }
    ans += (long long)n * m;
    int cansub = 0;
    long long maxans = ans, minans = ans;
    vector<pair<int, int> > V;
    for (int i = 0; i < n; i++) {
      int low = max(0, m - A[i][1]);
      int high = min(A[i][0], m);
      maxans -= 2 * low;
      minans -= 2 * high;
      V.push_back({low, high});
    }
    if (minans > 0) {
      cout << minans << endl;
      for (int i = 0; i < n; i++) {
        int high = V[i].second;
        cout << high << " " << m - high << endl;
      }
    } else if (maxans < 0) {
      cout << abs(maxans) << endl;
      for (int i = 0; i < n; i++) {
        int low = V[i].first;
        cout << low << " " << m - low << endl;
      }
    } else {
      cout << ans % 2 << endl;
      vector<vector<int> > Ans(n, vector<int>(2));
      for (int i = 0; i < n; i++) {
        Ans[i][0] = V[i].first;
        Ans[i][1] = m - V[i].first;
      }
      for (int i = 0; i < n; i++) {
        if (maxans > 1) {
          int caninc = min(maxans / 2, (long long)V[i].second - V[i].first);
          maxans -= 2 * caninc;
          Ans[i][0] += caninc;
          Ans[i][1] -= caninc;
        }
      }
      for (int i = 0; i < n; i++) {
        cout << Ans[i][0] << " " << Ans[i][1] << endl;
      }
    }
  }
}
