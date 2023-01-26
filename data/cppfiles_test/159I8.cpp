#include <bits/stdc++.h>
using namespace std;
bool is_perfect_square(unsigned long long int n) {
  if (pow((long int)(sqrt(n)), 2) == n) {
    return true;
  }
  return false;
}
void solve() {
  unsigned long int n;
  cin >> n;
  vector<unsigned long int> arr = {};
  unsigned long int halfi = (long int)n / 2;
  unsigned long long int asdf =
      (unsigned long long int)2 * (halfi) * (halfi - 1);
  if ((n % 4) == 0) {
    arr = {halfi};
  } else if (n == 1) {
    arr = {};
  } else if (n % 4 == 1) {
    arr = {halfi, n};
  } else if ((n % 4) == 2) {
    if (is_perfect_square((unsigned long long int)(n + 2)))
      arr = {halfi + 1};
    else if (is_perfect_square((unsigned long long int)(n * (halfi - 1))))
      arr = {halfi - 2};
    else
      arr = {halfi, 2};
  } else {
    if (is_perfect_square((unsigned long long int)(n + 1)))
      arr = {halfi + 1, n};
    else if (is_perfect_square(asdf))
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
