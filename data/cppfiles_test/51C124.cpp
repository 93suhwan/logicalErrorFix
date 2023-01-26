#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, l, r;
    cin >> n;
    l = -(n - 1);
    r = n;
    cout << l << " " << r << endl;
  }
  return 0;
}
