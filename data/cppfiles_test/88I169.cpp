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
      vector<int> b;
      for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] < v[i + 1]) {
          b.push_back(2);
          e++;
          i++;
        } else {
          b.push_back(1);
        }
      }
      if (e >= 2) {
        for (int i = b.size() - 1; i >= 0; i--) {
          if (b[i] == 2) {
            if (i != b.size() - 1) {
              cout << "YES" << endl;
              break;
            } else {
              cout << "NO" << endl;
              break;
            }
          }
        }
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
