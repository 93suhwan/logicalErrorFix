#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    if (v.size() % 2 == 0) {
      cout << "YES" << endl;
    } else {
      bool flag = false;
      for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
          flag = true;
          break;
        }
      }
      if (flag)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
