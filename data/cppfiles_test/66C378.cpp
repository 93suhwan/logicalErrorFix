#include <bits/stdc++.h>
using namespace std;
int s = 1e7;
int main() {
  vector<int> v;
  for (int i = 1; i <= s; i++) {
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
    cout << v[n - 1] << endl;
  }
  return 0;
}
