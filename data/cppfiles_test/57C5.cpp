#include <bits/stdc++.h>
using namespace std;
bool calc() {
  int64_t s, n, k;
  cin >> s >> n >> k;
  if (k == s) return true;
  if (k > s) return false;
  int64_t q = n / k;
  int64_t r = n % k;
  if (s >= q * (2 * k) + r) return false;
  return true;
}
void solve() { cout << (calc() ? "YES" : "NO") << '\n'; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
