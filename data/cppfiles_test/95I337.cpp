#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int d4x[4] = {1, 0, -1, 0};
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long oo = 1e18;
const long long maxN = 1e6;
void maximize(int &a, int b) { a = max(a, b); }
void minimize(int &a, int b) { a = min(a, b); }
int ans[maxN];
void solve() {
  long long n, k;
  cin >> n >> k;
  int cnt = 0;
  long long temp = 10;
  for (int i = 1; i <= k; i++) ans[i] = 0;
  while (n && cnt < k) {
    long long x = n % temp;
    x = x * 10 / temp;
    for (int i = 1; i <= x; i++) {
      cnt++;
      ans[cnt] = temp / 10;
      n -= temp / 10;
      if (cnt == k) break;
    }
    temp *= 10;
  }
  if (cnt == k) {
    ans[1] += n;
    for (int i = 1; i <= k; i++) cout << ans[i] << " ";
    cout << '\n';
    return;
  }
  while (cnt < k) {
    sort(ans + 1, ans + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
      if (ans[i] > 1) {
        cnt++;
        ans[cnt] = (ans[i] + 1) / 2;
        ans[i] /= 2;
        break;
      }
    }
  }
  for (int i = 1; i <= k; i++) cout << ans[i] << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1, ddd = 0;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
