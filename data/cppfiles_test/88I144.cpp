#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    vector<long long int> v;
    for (int i = 0; i < x; i++) {
      long long int q;
      cin >> q;
      v.push_back(q);
    }
    if (x % 2 == 0) {
      cout << "YES" << endl;
    } else {
      long long int e = 0;
      for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] < v[i + 1]) {
          e++;
          i++;
        }
      }
      if (e >= 2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
