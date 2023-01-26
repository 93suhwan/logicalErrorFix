#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    vector<int> v;
    int res = 0;
    for (int i = 0; i < a; i++) {
      res ^= i;
      v.push_back(i);
    }
    if (res == 0 && b > 0) {
      cout << v.size() + 2 << "\n";
    }
    if (res > 0) {
      if (res == b) {
        cout << v.size() << "\n";
      } else {
        cout << v.size() + 1 << "\n";
      }
    }
  }
}
