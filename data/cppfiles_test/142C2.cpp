#include <bits/stdc++.h>
using lli = long long int;
using li = long int;
using namespace std;
const lli MOD{998244353};
const lli INF{(false ? (INT_MAX - 1) / 2 : (lli)1e18 + 5)};
const lli N{200005};
int main() {
  cout << setprecision(15);
  cin.tie(nullptr)->sync_with_stdio(false);
  li T{1};
  cin >> T;
  while (T--) {
    lli n{}, m{};
    cin >> m >> n;
    vector<vector<lli>> arr(m, vector<lli>(n));
    map<lli, vector<lli>> pre;
    vector<lli> mx(n);
    for (lli i{}; i < m; ++i) {
      for (lli j{}; j < n; ++j) {
        cin >> arr[i][j];
        mx[j] = max(mx[j], arr[i][j]);
      }
    }
    int flag{};
    vector<lli> done(m);
    for (lli i{}; i < n; ++i) {
      for (lli j{}; j < m; ++j) {
        if (arr[j][i] == mx[i]) {
          if (done[j]) {
            flag++;
            break;
          }
          done[j] = 1;
        }
      }
      if (flag) break;
    }
    lli ans{};
    for (lli i{}; i < m; ++i) {
      lli mx1{}, mx2{};
      for (lli j{}; j < n; ++j) {
        if (arr[i][j] >= mx1) {
          mx2 = mx1;
          mx1 = arr[i][j];
        } else if (arr[i][j] >= mx2)
          mx2 = arr[i][j];
      }
      ans = max(ans, min(mx1, mx2));
    }
    cout << min(ans, *(min_element((mx).begin(), (mx).end()))) << '\n';
  }
  return 0;
}
