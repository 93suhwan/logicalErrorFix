#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n + 1];
    int k;
    int kk = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      if (a[i] > kk) {
        kk = a[i];
        k = i;
      }
    }
    int count = 1;
    int flag = 0;
    int pp = a[n - 1];
    for (int i = n - 1; i >= k; i--) {
      if (a[i] > pp) {
        pp = a[i];
        count++;
        flag = 1;
      }
    }
    cout << count - 1 << endl;
  }
  return 0;
}
