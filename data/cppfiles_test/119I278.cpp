#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    int k;
    for (int i = 0; i < n; i++) {
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    while (v[0] != v[v.size() - 1]) {
      if ((v[0] + v[n - 1]) % 2 == 0) {
        v[0] = (v[0] + v[n - 1]) / 2;
        v[n - 1] = (v[0] + v[n - 1]) / 2;
        sort(v.begin(), v.end());
      } else {
        break;
      }
    }
    if ((v[0] + v[n - 1]) % 2 != 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
}
