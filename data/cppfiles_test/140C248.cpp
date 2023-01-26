#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    unordered_set<int> s;
    for (int i = 1; (i * i) <= n; i++) {
      s.insert(i * i);
    }
    for (int i = 1; (i * i * i) <= n; i++) {
      s.insert(i * i * i);
    }
    cout << s.size() << "\n";
  }
  return 0;
}
