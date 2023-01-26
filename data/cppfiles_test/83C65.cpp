#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}
const int N = 5010, P1 = 131;
ull h1[N], px1[N];
ll d[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    px1[0] = 1;
    for (int i = 1; i <= n; i++) {
      d[i] = n - i + 1;
      h1[i] = (h1[i - 1] * P1 + s[i - 1]);
      px1[i] = px1[i - 1] * P1;
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
            if (h1[i + mid - 1] - h1[i - 1] * px1[mid] ==
                h1[j + mid - 1] - h1[j - 1] * px1[mid])
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
