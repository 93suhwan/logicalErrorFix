#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
  long long sum = 0;
  for (int i = 0; i < v.size(); i++) {
    sum += v[i];
  }
  if (sum % n == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
