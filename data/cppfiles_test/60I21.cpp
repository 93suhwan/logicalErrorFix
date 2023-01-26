#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    cout << (v[0] & v[n - 1]) << endl;
  }
}
