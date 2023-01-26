#include <bits/stdc++.h>
using namespace std;
void solved_by_satyapsr13() {
  long long int n, k, ans = 0, l, count = 0, sum = 0, mn = INT_MAX,
                      mx = INT_MIN;
  long long int r;
  cin >> l >> r;
  long long int test = r / 2;
  if (test >= l) {
    r & 1 ? cout << test : cout << test - 1;
    cout << "\n";
    return;
  } else {
    cout << r % l;
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int Test_Cases;
  cin >> Test_Cases;
  while (Test_Cases--) {
    solved_by_satyapsr13();
  }
  return 0;
}
