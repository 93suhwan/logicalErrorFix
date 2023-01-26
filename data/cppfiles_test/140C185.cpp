#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    long long int n;
    cin >> n;
    long long int k = sqrt(n);
    long long int l = cbrt(n);
    long long int h = cbrt(k);
    cout << k + l - h << endl;
    t--;
  }
}
