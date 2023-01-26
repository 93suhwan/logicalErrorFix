#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int smallest = *min_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    smallest = a[i] & smallest;
  }
  cout << smallest << endl;
}
int32_t main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) test_case();
  return 0;
}
