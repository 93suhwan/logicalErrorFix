#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    set<long long> s;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    long long l = s.size();
    if (n % 2 == 0)
      cout << "YES"
           << "\n";
    else {
      int c = 0;
      for (long long i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
          c = 1;
          break;
        }
      }
      if (c == 1)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
}
