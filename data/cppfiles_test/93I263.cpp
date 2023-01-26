#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, count = 0, i = 0;
    cin >> n >> k;
    while (n > 0 || pow(2, i) < k) {
      n -= pow(2, i);
      count++;
      i++;
    }
    while (n > 0) {
      n -= k;
      count++;
    }
    cout << count << endl;
  }
}
