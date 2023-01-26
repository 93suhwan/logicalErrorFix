#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int n, h[N], hp[N], mx[N];
bool is_valid(int L) {
  for (int i = 0; i < n; i++) h[i] = hp[i];
  for (int i = 2; i < n; i++) mx[i] = h[i] / 3;
  for (int i = n - 1; i >= 2; i--) {
    int l = max(0, min((h[i] - L) / 3, mx[i]));
    h[i - 1] += l, h[i - 2] += 2 * l;
    h[i] -= l * 3;
  }
  for (int i = 0; i < n; i++)
    if (h[i] < L) return false;
  return true;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> hp[i];
  int l = 0, r = 1e9 + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (is_valid(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) solve();
  return 0;
}
