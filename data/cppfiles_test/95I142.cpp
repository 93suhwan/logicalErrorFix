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
  int n, k;
  cin >> n >> k;
  int b = n / k;
  for (int i = 1; i <= k; i++) ans[i] = b;
  n %= k;
  for (int i = 1; i <= n; i++) ans[i]++;
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
