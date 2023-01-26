#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) cin >> a[i];
    long long int co = 0;
    for (long long int i = 0; i < n; i++) {
      long long int idx = i + co + 1;
      if (a[i] <= idx)
        ;
      else {
        long long int o = a[i] - idx;
        co += o;
      }
    }
    cout << co << endl;
  }
}
