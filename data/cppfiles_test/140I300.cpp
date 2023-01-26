#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long int x = 1;
    for (int i = 2; i * i <= n; ++i) {
      x += 1;
    }
    for (int i = 2; (i * i * i) <= n; ++i) {
      x += 1;
    }
    cout << x << endl;
  }
  return 0;
}
