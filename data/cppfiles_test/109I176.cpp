#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, s = 0, a;
  cin >> t;
  vector<int> v(t);
  for (int i = 0; i < t; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> a;
      s += a;
    }
    v.push_back(s + n - 1);
    s = 0;
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
