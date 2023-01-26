#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], k = 0;
    vector<int> b;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (a[i] <= i) {
        b.push_back(a[i]);
      } else {
        k = a[i] - (i + k);
        for (int j = 0; j < k; j++) {
          b.push_back(1);
        }
        b.push_back(a[i]);
      }
    }
    cout << b.size() - n << endl;
  }
}
