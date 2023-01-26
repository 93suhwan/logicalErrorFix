#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T &x, const T &y) {
  return (x < y) ? (x = y, true) : false;
};
template <typename T>
bool chmin(T &x, const T &y) {
  return (x > y) ? (x = y, true) : false;
};
constexpr long long int MOD = 10;
constexpr long long int INF = 2e18;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<long long int> p(n);
    for (long long int i = 0; i < (n); i++) cin >> p[i], p[i]--;
    vector<long long int> cnt(n, 0);
    for (long long int i = 0; i < (n); i++) {
      cnt[(p[i] - i + n) % n]++;
    }
    vector<long long int> ans;
    for (long long int i = 0; i < (n); i++) {
      if (n - cnt[i] <= m) {
        ans.push_back((-i + n) % n);
      } else if (n - cnt[i] <= m * 2) {
        int x = 0;
        vector<long long int> q(n);
        for (long long int j = 0; j < (n); j++) q[j] = p[(j - i + n) % n];
        vector<long long int> f(n, 0);
        for (long long int j = 0; j < (n); j++) {
          if (f[j] == 0) {
            int now = j;
            while (f[now] == 0) {
              f[now] = 1;
              now = q[now];
              x++;
            }
            x--;
          }
        }
        if (x <= m) ans.push_back((-i + n) % n);
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size();
    for (auto i : ans) cout << " " << i;
    cout << endl;
  }
  return 0;
}
