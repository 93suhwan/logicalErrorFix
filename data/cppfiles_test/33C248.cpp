#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      a.push_back(x);
    }
    long long m = 0;
    for (int i = 0; i < (n - 1); i++) {
      long long x = a[i] * a[i + 1];
      if (x > m) m = x;
    }
    cout << m << endl;
  }
}
