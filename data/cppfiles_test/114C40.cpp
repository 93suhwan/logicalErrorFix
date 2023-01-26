#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n / 2; ++i) {
    cout << a[i + 1] << ' ' << a[0] << '\n';
  }
}
bool multitest = true;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  size_t number_of_tests = 1;
  if (multitest) {
    cin >> number_of_tests;
  }
  for (size_t _ = 0; _ < number_of_tests; ++_) {
    solve();
  }
}
