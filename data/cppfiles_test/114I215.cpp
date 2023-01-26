#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      v.push_back(k);
    }
    sort(v.begin(), v.end());
    int temp = n / 2;
    int i = n - 1, j = 0;
    while (i > -1 && temp > 0) {
      int temp1 = v[i] % v[j];
      auto it = find(v.begin(), v.end(), temp1);
      if (it == v.end()) {
        cout << v[i] << " " << v[j] << endl;
        temp--;
      }
      if (j == n - 1) {
        i--;
        j = 0;
      }
      j++;
    }
  }
}
