#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  vector<int> a;
  for (int i = 1; i <= 1666; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      continue;
    } else {
      a.push_back(i);
    }
  }
  cout << endl;
  cin >> t;
  for (int i = 0; i < t; i++) {
    a.clear();
    cin >> n;
    cout << a[n - 1] << endl;
  }
}
