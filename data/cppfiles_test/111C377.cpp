#include <bits/stdc++.h>
using namespace std;
vector<char> v;
void print(int n) {
  for (int i = 0; i < n; i++) {
    cout << v[i];
  }
  cout << endl;
}
void solve() {
  int n;
  cin >> n;
  int tot = 2 * n;
  int lo = tot / 2 - 1;
  int hi = tot / 2;
  for (int i = 0; i < n; i++) v.push_back('(');
  for (int i = 0; i < n; i++) v.push_back(')');
  print(tot);
  for (int i = 1; i < n; i++) {
    for (int k = lo; k <= hi; k = k + 2) {
      swap(v[k], v[k + 1]);
    }
    print(tot);
    lo--;
    hi++;
  }
  v.clear();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
