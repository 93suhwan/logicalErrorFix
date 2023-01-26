#include <bits/stdc++.h>
using namespace std;
bool comp(long long int x, long long int y) { return x > y; }
bool is_square(long long int n) {
  if (pow((long long int)sqrt(n), 2) == n) return true;
  return false;
}
long long int logd(long long int x, long long int y) {
  return ceil((long double)log(x) / (long double)log(y));
}
struct mone {
  int value = -1;
};
const int N = 2e5 + 5;
void solve() {
  long long int n, s;
  cin >> n >> s;
  if (n > s) {
    cout << 0 << endl;
    return;
  }
  long long int ans = 0;
  if (n & 1) {
    s -= n / 2;
    long long int remain = n / 2 + 1;
    long long int ans = ceil((long double)s / remain);
    cout << ans << endl;
  } else {
    s -= n / 2 - 1;
    long long int remain = n / 2 + 1;
    cout << s / remain << endl;
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
