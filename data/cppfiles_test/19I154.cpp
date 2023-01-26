#include <bits/stdc++.h>
using namespace std;
int tc, cs = 1;
int n, a[30];
bool check(int m) {
  int sum1 = 0;
  for (int i = 0; i < n; ++i) {
    if (m & (1 << i)) sum1 += a[i];
  }
  for (int msk = 1; msk < (1 << n); ++msk) {
    if ((msk & m)) continue;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (msk & (1 << i)) sum += a[i];
    }
    if (sum == sum1) return true;
  }
  return false;
}
void test_cases() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      cout << "YES" << '\n';
      return;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      cout << "YES" << '\n';
      return;
    }
  }
  for (int msk = 1; msk < (1 << n); ++msk) {
    if (check(msk)) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    test_cases();
  }
}
