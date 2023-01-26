#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int testcases;
  cin >> testcases;
  while (testcases--) {
    int arrlength;
    cin >> arrlength;
    vector<long long> tharr(arrlength);
    bool strictsorted = true;
    for (int i = 0; i < arrlength; i++) {
      cin >> tharr[i];
      if (i > 0 && tharr[i - 1] >= tharr[i]) {
        strictsorted = false;
      }
    }
    if (arrlength % 2 == 0 || !strictsorted) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
