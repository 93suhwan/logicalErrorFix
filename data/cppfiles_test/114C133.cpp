#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n / 2; i++) {
      cout << v[i] << " " << v[0] << endl;
    }
  }
}
