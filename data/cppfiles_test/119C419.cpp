#include <bits/stdc++.h>
using namespace std;
void init(int& n, vector<int>& a) {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}
void solve(int n, vector<int>& a) {
  int sum = accumulate(a.begin(), a.end(), 0);
  if (sum % n) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    vector<int> a;
    init(n, a);
    solve(n, a);
  }
  return 0;
}
