#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int tt = 1, c = 1;
  vector<int> v;
  while (c <= 1000) {
    if (!(tt % 10 == 3 || tt % 3 == 0)) {
      v.push_back(tt);
      ++c;
    }
    ++tt;
  }
  while (t--) {
    int k;
    cin >> k;
    cout << v[k - 1] << "\n";
  }
  return 0;
}
