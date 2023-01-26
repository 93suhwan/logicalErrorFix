#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int K = 3;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long int mx = INT_MIN;
    long long int ind = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] > mx) {
        mx = a[i];
        ind = i + 1;
      }
    }
    cout << mx - ind << endl;
  }
  return 0;
}
