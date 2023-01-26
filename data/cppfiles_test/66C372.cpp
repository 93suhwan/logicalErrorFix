#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<int> v(1000, 0);
  int j = 0;
  for (int i = 1; i <= 1666, j < 1000; i++) {
    if (i % 3 != 0 && i % 10 != 3) v[j++] = i;
  }
  while (t--) {
    int k;
    cin >> k;
    cout << v[k - 1] << endl;
  }
  return 0;
}
