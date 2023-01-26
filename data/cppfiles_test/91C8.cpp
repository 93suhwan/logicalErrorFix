#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int PR = 998244353;
int T, n;
int a[MAXN], f[2][MAXN];
vector<int> vec[2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    vec[0].clear();
    vec[1].clear();
    memset(f, 0, sizeof f);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
      int k = i % 2;
      vec[k].push_back(a[i]);
      f[k][a[i]] = 1;
      int lst = a[i];
      for (int j = 0; j < vec[k ^ 1].size(); j++) {
        int tmp = f[k ^ 1][vec[k ^ 1][j]], tmp2 = vec[k ^ 1][j];
        int val = (a[i] + tmp2 - 1) / tmp2;
        int val2 = a[i] / val;
        ans += 1ll * (val - 1) * tmp * i;
        ans %= PR;
        f[k][val2] += tmp;
        if (lst != val2) {
          vec[k].push_back(val2);
          lst = val2;
        }
      }
      for (int j = 0; j < vec[k ^ 1].size(); j++) {
        int x = vec[k ^ 1][j];
        f[k ^ 1][x] = 0;
      }
      vec[k ^ 1].clear();
    }
    cout << ans << endl;
  }
  return 0;
}
