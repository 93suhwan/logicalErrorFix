#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long ans = 0;
    set<long long> s;
    for (long long i = 1; i * i <= n; i++) {
      if (i * i <= n) {
        s.insert(i * i);
      }
    }
    for (long long i = 1; i * i * i <= n; i++) {
      if (i * i * i <= n) {
        s.insert(i * i * i);
      }
    }
    cout << s.size() << "\n";
  }
  return 0;
}
