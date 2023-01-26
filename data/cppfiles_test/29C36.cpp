#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &ai : a) cin >> ai;
  int64_t ans = 0, tmp = 1;
  for (auto ai : a) {
    if (ai == 1)
      ++ans;
    else if (ai == 0)
      tmp <<= 1;
  }
  cout << ans * tmp << '\n';
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Case = 1;
  cin >> Case;
  for (int i = 1; i <= Case; i++) {
    test_case();
  }
  return 0;
}
