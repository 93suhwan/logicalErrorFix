#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n;
  string a;
  int p;
  vector<int> v;
  string f;
  cin >> t;
  while (t--) {
    p = 0;
    int c[26] = {0};
    cin >> n;
    cin >> a;
    f = a;
    sort(f.begin(), f.end());
    for (int i = 0; i < n; i++) {
      if (f[i] != a[i]) {
      }
      p++;
    }
    v.push_back(p);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << "\n";
  }
  return 0;
}
