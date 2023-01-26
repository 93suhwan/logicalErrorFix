#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int n, a[N];
void solve() {
  cin >> n;
  map<int, int> M;
  for (int i = 0; i < n; i++) cin >> a[i], M[a[i]]++;
  long long sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];
  if ((2 * sum) % n) {
    cout << 0 << '\n';
    return;
  }
  long long k = (2 * sum) / n, ans1 = 0, ans2 = 0;
  for (auto it : M) {
    if (it.first * 2 == k) {
      ans2 = 1LL * it.second * (it.second - 1) / 2;
    } else {
      ans1 += 1LL * it.second * M[k - it.first];
    }
  }
  cout << ans1 / 2 + ans2 << '\n';
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) solve();
  return 0;
}
