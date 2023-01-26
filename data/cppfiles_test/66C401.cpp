#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int i = 1;
    vector<int> v;
    for (i; i <= 1666; i++) {
      if (((i % 3) == 0) || (i % 10 == 3)) continue;
      v.push_back(i);
    }
    cout << v[k - 1] << endl;
  }
  return 0;
}
