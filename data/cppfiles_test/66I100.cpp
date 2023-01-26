#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  for (int i = 1; i <= 1000; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      continue;
    }
    v.push_back(i);
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << v[n] << endl;
  }
  return 0;
}
