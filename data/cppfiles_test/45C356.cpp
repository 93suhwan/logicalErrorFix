#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t-- != 0) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int val = 1;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      if (val > 0) {
        if (a[i] == 0) {
          if (i > 0) {
            if (a[i - 1] == 0) {
              val = -1;
            } else {
            }
          } else {
          }
        } else {
          if (i > 0) {
            if (a[i - 1] == 1) {
              val += 5;
            } else {
              val++;
            }
          } else {
            val++;
          }
        }
      }
    }
    cout << val << endl;
  }
}
