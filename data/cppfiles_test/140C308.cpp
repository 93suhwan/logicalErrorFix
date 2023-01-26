#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    set<long long int> s;
    cin >> n;
    for (long long int i = 1; (i * i <= n); i++) {
      s.insert(i * i);
    }
    for (long long int i = 1; i * i * i <= n; i++) {
      s.insert(i * i * i);
    }
    cout << s.size() << "\n";
  }
  return 0;
}
