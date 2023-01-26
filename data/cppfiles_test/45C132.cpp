#include <bits/stdc++.h>
using namespace std;
const long long DOM = 100;
long long n, m, t, k;
bool p[DOM] = {1, 1};
string s;
char c;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  for (long long i = 2; i <= sqrt(DOM); ++i) {
    for (int j = i + i; j <= DOM; j += i) {
      p[j] = 1;
    }
  }
  cin >> t;
  for (int ca = 1; ca <= t; ++ca) {
    cin >> n;
    long long ans = 1;
    int la = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> k;
      if (i == 1) {
        if (k) {
          ++ans;
        }
      } else {
        if (k) {
          if (la) {
            ans += 5;
          } else {
            ans += 1;
          }
        } else {
          if (la == 0) {
            ans -= 1000000;
          }
        }
      }
      la = k;
    }
    if (ans < 0) {
      cout << "-1\n";
    } else {
      cout << ans << "\n";
    }
  }
}
