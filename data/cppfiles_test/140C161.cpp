#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int s = (long long)sqrt(n);
    long long int cb = (long long)cbrt(n);
    long long int six = (long long)sqrt(cb);
    cout << (s + cb - six) << endl;
  }
  return 0;
}
