#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a >> b;
  long long d = abs(a - b) / 2;
  vector<long long> v;
  if ((a + b) % 2) {
    for (long long i = d; i <= a + b - d; i++) v.push_back(i);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
  } else {
    for (long long i = d; i <= a + b - d; i += 2) v.push_back(i);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
