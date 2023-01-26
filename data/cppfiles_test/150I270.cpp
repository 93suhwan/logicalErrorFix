#include <bits/stdc++.h>
using namespace std;
int len(long long int x) {
  int i = 0;
  while (x >= 10) {
    i++;
    x /= 10;
  }
  return i;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<long long int> v1(4);
    vector<long long int> v2(4);
    for (int i = 0; i < 4; i++) {
      v1[i] = 0;
      v2[i] = 0;
    }
    int n;
    cin >> n;
    vector<long long int> v(n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      v[i] = x;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        if (v[i] >= 3) {
          if (v[i] % 3 == 0) {
            v1[3] = max(v1[3], v[i] / 3);
            v2[3] = max(v2[3], v[i] / 3);
            if (v1[1] && v1[2]) {
              cout << "Tafi" << endl;
              v1[3]--;
            }
            if (v2[1] && v2[2]) {
              v2[3]--;
            }
          } else if (v[i] % 3 == 1) {
            v2[2] = max(v2[2], 2LL);
            v2[3] = max(v2[3], v[i] / 3 - 1);
            v1[1] = max(v1[1], 1LL);
            v1[3] = max(v1[3], v[i] / 3);
          } else if (v[i] % 3 == 2) {
            v1[3] = max(v1[3], v[i] / 3);
            v1[2] = max(v1[2], 1LL);
            if (v1[2] > 1 && v1[1]) {
              v1[3]--;
            }
            v2[3] = max(v2[3], v[i] / 3);
            v2[2] = max(v2[2], 1LL);
            if (v2[2] > 1 && v2[1]) {
              v2[3]--;
            }
          }
        }
      } else if (v[i] >= 3) {
        if (v[i] % 3 == 1) {
          v2[2] = max(v2[2], 2LL);
          v2[3] = max(v2[3], v[i] / 3 - 1);
          v1[1] = max(v1[1], 1LL);
          v1[3] = max(v1[3], v[i] / 3);
        } else if (v[i] % 3 == 2) {
          v1[3] = max(v1[3], v[i] / 3);
          v1[2] = max(v1[2], 1LL);
          v2[3] = max(v2[3], v[i] / 3);
          v2[2] = max(v2[2], 1LL);
        } else {
          v1[3] = max(v1[3], v[i] / 3);
          v2[3] = max(v2[3], v[i] / 3);
        }
      } else if (v[i] >= 2) {
        if (v1[1] < 2) {
          v1[2] = max(v1[2], 1LL);
        }
        if (v2[1] < 2) {
          v2[2] = max(v2[2], 1LL);
        }
      } else {
        v1[1] = max(v1[1], 1LL);
        v2[1] = max(v2[1], 1LL);
      }
    }
    long long int m = v[n - 1];
    long long int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 4; i++) {
      sum1 += v1[i];
      sum2 += v2[i];
    }
    if (sum1 < sum2) {
      cout << sum1 << endl;
    } else {
      cout << sum2 << endl;
    }
  }
}
