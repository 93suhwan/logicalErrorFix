#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, m;
  long long int sum1, sum2, ans, temp, s;
  cin >> t;
  while (t--) {
    cin >> m;
    sum1 = 0;
    sum2 = 0;
    ans = 1e10;
    vector<int> v1(m);
    vector<int> v2(m);
    for (int i = 0; i < m; i++) {
      cin >> v1[i];
      sum1 += v1[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> v2[i];
      sum2 += v2[i];
    }
    temp = 0;
    for (int i = 0; i < m; i++) {
      sum1 -= v1[i];
      if (i > 0) temp += v2[i - 1];
      s = std::max(temp, sum1);
      if (s < ans) {
        ans = s;
      }
    }
    cout << ans << '\n';
  }
}
