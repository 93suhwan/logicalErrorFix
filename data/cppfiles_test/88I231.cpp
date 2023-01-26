#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]]++;
    }
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      if (mp[a[i]] > 1) {
        c++;
        break;
      }
    }
    if (c == 1) {
      cout << "YES" << endl;
    } else {
      if (n % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
