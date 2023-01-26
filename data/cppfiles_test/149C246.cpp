#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int a, long long int b) {
  long long int ans = 0;
  while (b) {
    if (b & 1) {
      ans += a;
    }
    b = b >> 1;
    a += a;
    if (a > 1e18) {
      a = 1e18;
    }
    if (ans > 1e18) {
      ans = 1e18;
    }
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int i, j, k, l, m, n, a, b, c, d, u, v, w, t = 1, x;
  cin >> t;
  while (t--) {
    string str;
    cin >> n >> k >> x;
    x--;
    cin >> str;
    vector<long long int> v1;
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      if (str[i] == 'a')
        v1.push_back(cnt), cnt = 0;
      else
        cnt++;
    }
    v1.push_back(cnt);
    vector<long long int> v2(v1.size(), 1);
    for (long long int i = v1.size() - 2; i >= 0; i--) {
      v2[i] = mul(v2[i + 1], (k * v1[i + 1] + 1));
    }
    for (long long int i = 0; i < v2.size(); i++) {
      long long int u = x / v2[i];
      while (u) cout << 'b', u--;
      if (i + 1 != v1.size()) cout << 'a';
      x %= v2[i];
    }
    cout << endl;
  }
}
