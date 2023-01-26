#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    if (n % 2 == 0) {
      cout << "YES" << endl;
      continue;
    }
    int cnt = 0, num = -1;
    for (int i = 0; i < n; i++) {
      if (num < vec[i]) {
        num = vec[i];
        cnt++;
      }
    }
    if (cnt == n) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
