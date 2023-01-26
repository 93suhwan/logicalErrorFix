#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> t;
  set<int> s;
  while (t--) {
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
      s.insert(i * i);
    }
    for (int i = 1; i * i * i <= n; i++) {
      s.insert(i * i * i);
    }
    cout << s.size() << "\n";
    s.clear();
  }
  return 0;
}
