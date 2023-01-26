#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, c, d;
  long long arr[1000000];
  vector<long long> v;
  cin >> t;
  for (int a = 1; a <= t; a++) {
    cin >> c >> d;
    if ((c + d) % 2 == 1) {
      cout << -1 << endl;
    } else {
      if (c == 0 && d == 0) {
        cout << 0 << endl;
      } else if (c == d) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}
