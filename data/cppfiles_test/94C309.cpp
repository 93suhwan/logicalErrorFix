#include <bits/stdc++.h>
using namespace std;
void Fast() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void File() {}
using ll = long long;
using ull = unsigned long long;
int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int N = 1e6 + 5;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto& a : v) cin >> a;
  string ans;
  int bit = 0;
  ll num = 9;
  k++;
  for (int i = 0; k && i < n - 1; i++, num = 9, bit++) {
    while (v[i + 1] != bit + 1) {
      num = num * 10 + 9;
      bit++;
    }
    if (i == n) break;
    if (k <= num) {
      ans = to_string(k) + ans;
      k = 0;
      break;
    } else {
      ans = to_string(num) + ans;
      k -= num;
    }
  }
  if (k) cout << k;
  cout << ans << "\n";
}
int main() {
  Fast();
  File();
  int t$$t$;
  cin >> t$$t$;
  while (t$$t$--) solve();
}
