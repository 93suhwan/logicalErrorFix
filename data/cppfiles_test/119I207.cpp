#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  long long p = v[0];
  long long count = 0;
  for (int i = 1; i < v.size(); i++) {
    count += v[i] - p;
  }
  if (count % 2 == 0) {
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
