#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  auto it = max_element(v.begin(), v.end());
  if (it > v.begin() and it < v.end() - 1)
    return (*it) * (max(*(it - 1), *(it + 1)));
  if (it > v.begin()) return (*it) * (*(it - 1));
  if (it < v.end() - 1) return (*it) * (*(it + 1));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  bool multiple_testcases = 1;
  if (multiple_testcases) cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
  return 0;
}
