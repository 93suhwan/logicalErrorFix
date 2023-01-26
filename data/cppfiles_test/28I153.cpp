#include <bits/stdc++.h>
using namespace std;
vector<long> ve;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    while (n--) {
      int a;
      cin >> a;
      ve.push_back(a);
    }
    int k1 = 0;
    int k0 = 0;
    for (int i = 0; i < ve.size(); i++) {
      if (ve[i] == 0) k0++;
      if (ve[i] == 1) k1++;
    }
    cout << k1 * pow(2, k0) << endl;
    ve.clear();
  }
}
