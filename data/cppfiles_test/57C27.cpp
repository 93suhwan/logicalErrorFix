#include <bits/stdc++.h>
using namespace std;
bool solve(int64_t s, int64_t n, int64_t k) {
  if (k > s) return false;
  if (k == s) return true;
  if (s >= ((n / k) * (2 * k) + n % k)) return false;
  return true;
}
void test_case() {
  int64_t s, n, k;
  cin >> s >> n >> k;
  cout << (solve(s, n, k) ? "YES\n" : "NO\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test_case();
  }
}
