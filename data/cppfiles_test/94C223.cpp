#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int maxN = 1e5 + 10;
int n, a[maxN];
long long k, pw[19];
void solve() {
  cin >> n >> k;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> a[i];
  }
  pw[0] = 1;
  for (int i = 1; i <= (int)(18); ++i) {
    pw[i] = pw[i - 1] * 10;
  }
  k++;
  string ans;
  for (int i = 1; i <= (int)(n - 1); ++i) {
    int d = a[i] - a[i - 1];
    if (pw[d] - 1 < k) {
      ans += string(d, '9');
      k -= pw[d] - 1;
    } else {
      string t = to_string(k);
      reverse((t).begin(), (t).end());
      ans += t;
      k = 0;
      break;
    }
  }
  if (k) {
    string t = to_string(k);
    reverse((t).begin(), (t).end());
    ans += t;
  }
  reverse((ans).begin(), (ans).end());
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
