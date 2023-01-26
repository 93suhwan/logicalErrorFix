#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<long long> v(n), v1(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    v1 = v;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if (v.size() % 2 == 0) {
      cout << "YES" << endl;
    } else {
      if (v.size() == v1.size()) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    }
  }
  return 0;
}
