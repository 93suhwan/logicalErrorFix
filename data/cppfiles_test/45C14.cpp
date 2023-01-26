#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int b[n];
    long long int o = 0, e = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] % 2 == 0) {
        b[i] = 0;
        e++;
      }
      if (arr[i] % 2 != 0) {
        b[i] = 1;
        o++;
      }
    }
    vector<long long int> v1, v2, v3, v4;
    if (n % 2 != 0) {
      if (abs(o - e) > 1) {
        cout << -1 << endl;
      } else {
        long long int ans = 0;
        if (o > e) {
          for (long long int i = 0; i < n; i++) {
            if (i % 2 == 0 && b[i] != 1) {
              v1.push_back(i);
            }
            if (i % 2 != 0 && b[i] != 0) {
              v2.push_back(i);
            }
          }
          for (long long int i = 0; i < v1.size(); i++) {
            ans += abs(v1[i] - v2[i]);
          }
          cout << ans << endl;
        }
        if (o < e) {
          for (long long int i = 0; i < n; i++) {
            if (i % 2 == 0 && b[i] != 0) {
              v1.push_back(i);
            }
            if (i % 2 != 0 && b[i] != 1) {
              v2.push_back(i);
            }
          }
          for (long long int i = 0; i < v1.size(); i++) {
            ans += abs(v1[i] - v2[i]);
          }
          cout << ans << endl;
        }
      }
    }
    if (n % 2 == 0) {
      if (o - e != 0) {
        cout << -1 << endl;
      } else {
        long long int ans1 = 0, ans2 = 0;
        for (long long int i = 0; i < n; i++) {
          if (i % 2 == 0 && b[i] != 0) {
            v1.push_back(i);
          }
          if (i % 2 != 0 && b[i] != 1) {
            v2.push_back(i);
          }
        }
        for (long long int i = 0; i < v1.size(); i++) {
          ans1 += abs(v1[i] - v2[i]);
        }
        for (long long int i = 0; i < n; i++) {
          if (i % 2 == 0 && b[i] != 1) {
            v3.push_back(i);
          }
          if (i % 2 != 0 && b[i] != 0) {
            v4.push_back(i);
          }
        }
        for (long long int i = 0; i < v3.size(); i++) {
          ans2 += abs(v3[i] - v4[i]);
        }
        cout << min(ans1, ans2) << endl;
      }
    }
  }
}
