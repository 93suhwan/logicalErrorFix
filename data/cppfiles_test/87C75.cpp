#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    ;
    cin >> n;
    n++;
    vector<long long> a(n);
    long long diff = 0;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
      if (diff < (a[i] - i)) {
        diff = abs(a[i] - i);
      }
    }
    cout << diff << '\n';
  }
}
