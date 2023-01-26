#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int i = 0; i < 7; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    cout << v[0] << " " << v[1] << " " << v[6] - v[1] - v[0] << endl;
  }
  return 0;
}
