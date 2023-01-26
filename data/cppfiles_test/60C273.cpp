#include <bits/stdc++.h>
using namespace std;
void code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
signed main() {
  code();
  long long testCases = 1;
  cin >> testCases;
  while (testCases--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long maxx = a[0];
    for (long long i = 1; i < n; ++i) {
      maxx &= a[i];
    }
    cout << maxx;
    cout << '\n';
  }
}
