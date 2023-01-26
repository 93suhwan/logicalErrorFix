#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    if (n == 1) {
      cout << v[0] + 1 << endl;
      continue;
    }
    int pos = 1;
    long long ht = 1;
    long long i = 0;
    while (i < n - 1) {
      if (v[i] == 0 && v[i + 1] == 0) {
        pos = 0;
        break;
      }
      if (v[i] == 1) {
        ht++;
        i++;
        if (v[i] == 1) {
          ht += 5;
          i++;
        }
      } else if (v[i] == 0) {
        if (i == n - 2 && v[i + 1] == 1) ht++;
        i++;
      }
    }
    if (pos == 0) {
      cout << -1 << endl;
      continue;
    }
    cout << ht << endl;
  }
  return 0;
}
