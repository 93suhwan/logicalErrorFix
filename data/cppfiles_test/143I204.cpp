#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    map<long long int, long long int> m;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    long long int d[n + 1];
    long long int k;
    for (long long int i = 0; i <= n; i++) {
      if (!m.count(i)) {
        k = i;
        break;
      }
    }
    stack<long long int> s;
    long long int sum = 0;
    for (long long int i = 0; i <= n; i++) {
      if (i < k) {
        d[i] = m[i];
        long long int kk = m[i];
        while (kk > 1) {
          s.push(i);
          kk--;
        }
      } else if (i == k) {
        d[i] = 0;
      } else {
        if (m.count(i)) {
          if (m.count(i - 1)) {
            d[i] = m[i] + sum;
          } else {
            if (s.size() > 0) {
              long long int it = s.top();
              s.pop();
              long long int dd = i - 1 - it;
              sum += dd;
              d[i] = sum;
              d[i] += m[i];
              long long int kk = m[i];
              while (kk > 1) {
                s.push(i);
                kk--;
              }
            } else {
              for (long long int j = i; j <= n; j++) {
                d[j] = -1;
              }
              break;
            }
          }
        } else {
          if (m.count(i - 1)) {
            d[i] = sum;
          } else {
            if (s.size() > 0) {
              long long int it = s.top();
              s.pop();
              long long int dd = i - 1 - it;
              sum += dd;
              d[i] = sum;
            } else {
              for (long long int j = i; j <= n; j++) {
                d[j] = -1;
              }
              break;
            }
          }
        }
      }
    }
    for (long long int i = 0; i <= n; i++) cout << d[i] << " ";
    cout << endl;
  }
}
