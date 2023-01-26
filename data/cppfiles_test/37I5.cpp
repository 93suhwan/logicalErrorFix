#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long int n, m;
    cin >> n >> m;
    vector<int> v;
    while (m--) {
      int a, b, c;
      cin >> a >> b >> c;
      v.push_back(b);
      sort(v.begin(), v.end());
    }
    long long int t;
    for (int i = 0; i < n; i++) {
      if (v[i] != (i + 1)) {
        t = i + 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == t) {
        continue;
      }
      cout << t << " " << i << endl;
    }
  }
  return 0;
}
