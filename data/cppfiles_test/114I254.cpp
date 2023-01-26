#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    set<int> s;
    int ma = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
      s.insert(x);
      ma = max(ma, v[i]);
    }
    int pairCount = 0;
    int i = 0;
    while (pairCount < n / 2) {
      if (s.count(ma % v[i]) == 0) {
        cout << ma << ' ' << v[i] << '\n';
        pairCount++;
      }
      i++;
    }
  }
}
