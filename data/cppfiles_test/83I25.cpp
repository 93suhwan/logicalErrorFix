#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int N = 300010, P1 = 131, P2 = 101, mod1 = 1e9 + 9, mod2 = 1e9 + 7;
ll h1[N], h2[N], px1[N], px2[N], d[N];
bool eql(int l, int r, int a, int b) {
  if ((h1[r] - h1[l - 1] * px1[(r - l + 1)]) % mod1 ==
      (h1[b] - h1[a - 1] * px1[(b - a + 1)]) % mod1)
    return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    px1[0] = px2[0] = 1;
    for (int i = 1; i <= n; i++) {
      d[i] = n - i + 1;
      h1[i] = (h1[i - 1] * P1 + s[i - 1]) % mod1;
      h2[i] = (h2[i - 1] * P2 + s[i - 1]) % mod2;
      px1[i] = px1[i - 1] * P1 % mod1;
      px2[i] = px2[i - 1] * P2 % mod2;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (s[i - 1] > s[j - 1]) {
          d[i] = max(d[i], d[j] + n - i + 1);
        } else if (s[i - 1] == s[j - 1]) {
          int l = 1, r = n - i + 1;
          while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (eql(i, i + mid - 1, j, j + mid - 1))
              l = mid;
            else
              r = mid - 1;
          }
          if (s[i + r - 1] > s[j + r - 1])
            d[i] = max(d[i], d[j] + n - i + 1 - r);
        }
      }
      res = max(res, d[i]);
    }
    cout << res << '\n';
  }
  return 0;
}
