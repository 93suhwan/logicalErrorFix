#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, f = 0;
    cin >> n;
    vector<char> v1, v2;
    for (int i = 0; i < n; i++) {
      char a;
      cin >> a;
      v1.push_back(a);
    }
    for (int i = 0; i < n; i++) {
      char b;
      cin >> b;
      v2.push_back(b);
    }
    for (int i = 0; i < n; i++) {
      if (v1[i] == '1' && v2[i] == '1') {
        f = 1;
        break;
      }
    }
    if (f == 1) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
