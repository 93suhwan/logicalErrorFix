#include <bits/stdc++.h>
using namespace std;
int sum(int n) {}
int main() {
  int t;
  cin >> t;
  vector<int> v;
  while (t--) {
    int k;
    cin >> k;
    for (int i = 1; i < 2 * k; i++) {
      if (i % 3 == 0) {
        continue;
      }
      if (i % 10 == 3) {
        continue;
      }
      v.push_back(i);
    }
    cout << v[k] << "\n";
  }
  return 0;
}
