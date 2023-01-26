#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VL = vector<LL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
void dout() { cerr << endl; }
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
  cerr << H << ' ';
  dout(T...);
}
const int MAX = 447;
string s[MAX];
int a[MAX], b[MAX];
int sum[MAX];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = (0); i < (n); ++i) cin >> s[i];
    int ans = n * m;
    for (int i1 = (0); i1 < (n); ++i1) {
      for (int j = (0); j < (m); ++j) a[j] = b[j] = 0;
      for (int i2 = (i1); i2 < (n); ++i2) {
        for (int j = (0); j < (m); ++j) {
          if (i2 - 1 > i1) {
            a[j] += s[i2 - 1][j] == '0';
            b[j] += s[i2 - 1][j] == '1';
          }
        }
        if (i2 - i1 > 3) {
          int mn = 1e9;
          for (int j = (0); j < (m); ++j) {
            if (j >= 3) {
              mn = min(mn, a[j - 3] - sum[j - 3]);
              ans = min(ans, a[j] + sum[j - 1] + mn);
            }
            sum[j] = (j ? sum[j - 1] : 0) + b[j] + (s[i1][j] == '0') +
                     (s[i2][j] == '0');
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
