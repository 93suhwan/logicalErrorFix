#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<long long> v(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % n == 0)
    cout << 0 << endl;
  else
    cout << 1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
