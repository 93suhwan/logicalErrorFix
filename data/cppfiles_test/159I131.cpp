#include <bits/stdc++.h>
using namespace std;
bool is_perfect_square(long int n) {
  if (pow((int)(sqrt(n)), 2) == n) {
    return true;
  }
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<long int> arr = {};
  int halfi = (int)n / 2;
  if (remainderf(n, 4) == 0)
    arr = {halfi};
  else if (n == 1)
    arr = {};
  else if (remainderf(n, 4) == 1)
    arr = {halfi, n};
  else if (remainderf(n, 4) == 2) {
    if (is_perfect_square(n + 2))
      arr = {halfi + 1};
    else if (is_perfect_square(n * (halfi - 1)))
      arr = {halfi - 2};
    else
      arr = {2, halfi, n};
  } else {
    if (is_perfect_square(n + 1))
      arr = {halfi + 1, n};
    else if (is_perfect_square(2 * (halfi) * (halfi - 1)))
      arr = {n, halfi - 2};
    else if (is_perfect_square((halfi - 1) * n))
      arr = {halfi - 2, n - 2};
    else
      arr = {2, halfi, n};
  }
  vector<int> ans = {};
  for (int i = 1; i < n + 1; i++) {
    if (find(arr.begin(), arr.end(), i) == arr.end()) ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int el = 0; el < ans.size(); el++) {
    cout << ans[el] << ' ';
  }
  cout << endl;
}
int main() {
  solve();
  return 0;
}
