#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long MOD = (long long)1e9 + 7LL;
const int MAXN = (int)1e3 + 5;
long long c[MAXN];
void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i += 2) {
    long long begin = c[i], sum = 0;
    bool flag = false;
    for (int j = i + 1; j < n; ++j) {
      if (j % 2 == 0) {
        sum += c[j];
      } else {
        sum -= c[j];
        if (sum <= 0) {
          ans += min(begin, -sum) + (int)flag;
          begin += sum;
          sum = 0;
        }
        if (begin < 0) break;
        flag = true;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    Solve();
  }
  return 0;
}
