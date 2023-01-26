#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long calc(long long x) { return x * (x + 1) / 2; }
int mex(set<int> &st) {
  int ret = 0;
  while (st.count(ret)) ret++;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, k;
    cin >> n >> m >> k;
    int md = n % m;
    vector<vector<bool> > a(k, vector<bool>(n, false));
    int cur_block = 0;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < md; j++) {
        a[i][cur_block] = 1;
        cur_block = (cur_block + 1) % (n / m);
      }
    }
    for (int i = 0; i < k; i++) {
      int block = 0;
      for (int j = 1; j <= n; j += n / m, block++) {
        cout << n / m + a[i][block] << ' ';
        for (int k = j; k < j + n / m + a[i][block]; k++) cout << k << ' ';
        cout << '\n';
        j += a[i][block];
      }
    }
    cout << '\n';
  }
  return 0;
}
