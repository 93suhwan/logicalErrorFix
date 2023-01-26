#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    unordered_set<long long int> s;
    for (long long int i = 1; i * i <= n; i++) {
      if (i * i * i <= n) {
        s.insert(i * i * i);
      } else {
        s.insert(i * i);
      }
    }
    cout << s.size() << "\n";
  }
}
