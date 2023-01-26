#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt(1);
  vector<int> v;
  while (v.size() <= 1000) {
    if (cnt % 3 == 0 || cnt % 10 == 3) {
      cnt++;
      continue;
    } else {
      v.push_back(cnt);
      cnt++;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << v[--k] << endl;
  }
}
