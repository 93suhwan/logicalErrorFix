#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, m;
    cin >> n >> m >> k;
    vector<long long int> v(n);
    for (long long int i = 0; i < n; i++) v[i] = i;
    long long int big = n % m;
    long long int sizebig = ceil(float(n) / m);
    long long int sizesmall = n / m;
    for (long long int i = 0; i < k; i++) {
      long long int j = 0;
      for (long long int o = 0; o < big; o++) {
        cout << sizebig << ' ';
        long long int temp = j;
        for (; j < temp + sizebig; j++) cout << v[j] + 1 << ' ';
        cout << '\n';
      }
      for (long long int o = 0; o < m - big; o++) {
        cout << sizesmall << ' ';
        long long int temp = j;
        for (; j < temp + sizesmall; j++) cout << v[j] + 1 << " ";
        cout << "\n";
      }
      rotate(v.begin(), v.begin() + (big * sizebig), v.end());
    }
    cout << "\n\n";
  }
  return 0;
}
