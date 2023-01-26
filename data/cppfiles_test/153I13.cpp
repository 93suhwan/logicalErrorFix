#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      A[i][c - 'a']++;
    }
  }
  vector<vector<int>> intersections(1 << n, vector<int>(26));
  vector<int> counts(1 << n);
  long long ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int u = (i & (1 - i));
    int count = 1;
    if (!u) {
      intersections[i] = A[31 - __builtin_clz(i)];
      for (int val : intersections[i]) {
        count = 1LL * count * (val + 1) % MOD;
      }
      counts[i] = count;
    } else {
      for (int j = 0; j < 26; j++) {
        intersections[i][j] = min(intersections[u][j], intersections[i - u][j]);
      }
      for (int val : intersections[i]) {
        count = 1LL * count * (val + 1) % MOD;
      }
      count = ((long long)counts[u] + counts[i - u] + MOD - count) % MOD;
      counts[i] = count;
    }
    int s = 0;
    int k = 0;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        s += j + 1;
        k++;
      }
    }
    ans ^= (1LL * s * k * count);
  }
  cout << ans << endl;
}
