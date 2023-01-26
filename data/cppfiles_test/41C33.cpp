#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string u = "abc";
  long long cnt = 0;
  vector<vector<long long>> pool(6, vector<long long>(n + 1));
  do {
    for (int i = 0; i < n; i++) {
      pool[cnt][i + 1] = pool[cnt][i] + (s[i] != u[i % 3]);
    }
    ++cnt;
  } while (next_permutation(u.begin(), u.end()));
  while (m--) {
    long long l, r;
    cin >> l >> r;
    long long ans = n;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, pool[i][r] - pool[i][l - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
