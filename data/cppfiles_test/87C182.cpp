#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<int> v;
  int res = 0;
  for (int i = 0; i < n; i++) {
    v.push_back(0);
    cin >> v[i];
  }
  long long pos = 1;
  for (int i = 0; i < n; i++) {
    if (pos < v[i]) {
      res += (v[i] - pos);
      pos = v[i];
    }
    pos++;
  }
  cout << res << "\n";
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
