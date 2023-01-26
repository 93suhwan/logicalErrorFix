#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    bool state = true;
    long long a[n], sum = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long x = ((n + 1) * (n)) / 2;
    if (sum % x != 0) {
      state = false;
    } else {
      if (x == 0) {
        state = false;
      } else {
        sum = sum / x;
      }
    }
    long long zz = sum - (a[0] - a[n - 1]);
    if (zz % n != 0) {
      state = false;
    } else {
      zz = zz / n;
      v.push_back(zz);
      if (zz <= 0) {
        state = false;
      }
    }
    for (int i = 1; i < n; i++) {
      long long z = sum - (a[i] - a[i - 1]);
      if (z % n != 0) {
        state = false;
      } else {
        z = z / n;
        v.push_back(z);
        if (z <= 0) {
          state = false;
        }
      }
    }
    if (state) {
      long long newsum = 0;
      for (int i = 0; i < n; i++) {
        newsum += v[i];
      }
      if (newsum == sum) {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n; i++) {
          cout << v[i] << " ";
        }
      } else {
        cout << "NO";
      }
      cout << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
