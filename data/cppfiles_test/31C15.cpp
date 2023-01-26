#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> arr;
    for (long long i = 0; i < n; i++) {
      long long num;
      cin >> num;
      arr.push_back(num);
    }
    vector<long long> b(n, 0);
    if (n % 2 == 0) {
      for (long long i = 0; i < n; i += 2) {
        b[i] = arr[i + 1];
        b[i + 1] = -arr[i];
      }
    } else {
      for (long long i = 3; i < n; i += 2) {
        b[i] = arr[i + 1];
        b[i + 1] = -arr[i];
      }
      vector<long long> s({arr[0], arr[1], arr[2]});
      sort((s).begin(), (s).end());
      long long sum = 0;
      if (s[1] > 0) {
        for (long long i = 0; i < 3; i++) {
          if (s[0] == arr[i]) {
            b[i] = s[2] + s[1];
            ;
            b[(i + 1) % 3] = -s[0];
            b[(i + 2) % 3] = -s[0];
            break;
          }
        }
      } else {
        for (long long i = 0; i < 3; i++) {
          if (s[2] == arr[i]) {
            b[i] = s[0] + s[1];
            ;
            b[(i + 1) % 3] = -s[2];
            b[(i + 2) % 3] = -s[2];
            break;
          }
        }
      }
    }
    for (auto i : b) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
