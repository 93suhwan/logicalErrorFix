#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l[n], r[n];
    for (int i = 0; i < n; i++) {
      cin >> l[i] >> r[i];
    }
    int req[n];
    set<int> s;
    set<int>::iterator it;
    for (int j = n - 1; j >= 0; j--) {
      for (int k = l[j]; k <= r[j]; k++) {
        it = s.find(k);
        if (it == s.end()) {
          req[j] = k;
          s.insert(k);
          break;
        }
      }
    }
    for (int g = 0; g < n; g++) {
      cout << l[g] << " " << r[g] << " " << req[g] << '\n';
    }
    cout << '\n';
  }
  return 0;
}
