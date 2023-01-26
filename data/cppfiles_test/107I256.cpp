#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    if ((abs(a - b)) > 1 || a + b > n - 2) {
      cout << -1 << endl;
      continue;
    }
    vector<long long> v(n, -1);
    if (a < b) {
      long long no = 1;
      for (long long i = 1; i < n; i += 2) {
        v[i] = no++;
        if (no > b) break;
      }
      for (long long i = 0; i < n; i++) {
        if (v[i] == -1) {
          v[i] = no++;
        }
      }
    } else if (a > b) {
      long long no = n;
      for (long long i = 1; i < n; i += 2) {
        v[i] = no--;
        if (n - no == a) break;
      }
      for (long long i = 0; i < n; i++) {
        if (v[i] == -1) {
          v[i] = no--;
        }
      }
    } else {
      long long no = n;
      for (long long i = 1; i < n; i += 2) {
        v[i] = no--;
        if (n - no == a) break;
      }
      for (long long i = 0; i < n; i++) {
        if (v[i] == -1) {
          v[i] = no--;
        }
      }
      swap(v[n - 1], v[n - 2]);
    }
    for (auto a : v) {
      cout << a << " ";
    }
    cout << endl;
  }
  return 0;
}
