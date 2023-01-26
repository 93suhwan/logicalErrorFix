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
    long long int n, k, x;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    vector<long long int> cnt;
    long long int c = 0;
    for (long long int i = 0; i < n; ++i) {
      if (s[i] == 'a') {
        cnt.push_back(c);
        c = 0;
      } else {
        c++;
      }
    }
    cnt.push_back(c);
    vector<long long int> m(cnt.size());
    m[cnt.size() - 1] = 1;
    for (long long int i = cnt.size() - 2; i >= 0; --i) {
      m[i] = mul(m[i + 1], (k * cnt[i + 1] + 1));
    }
    vector<long long int> ans(cnt.size());
    for (long long int i = 0; i < cnt.size(); ++i) {
      ans[i] = x / m[i];
      x %= m[i];
    }
    for (long long int i = 0; i < cnt.size(); ++i) {
      for (long long int j = 0; j < ans[i]; ++j) {
        cout << 'b';
      }
      if (i + 1 != cnt.size()) {
        cout << 'a';
      }
    }
    cout << endl;
  }
}
