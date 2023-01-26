#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> v(n, 0);
    for (long long i = 0; i < n; i++) {
      long long k = i + 1;
      if (a[i] > k) {
        k = a[i] - k;
        v.push_back(k);
      }
    }
    sort((v).begin(), (v).end(), greater<int>());
    cout << v[0] << '\n';
  }
}
