#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a = 0, b = 0;
    while (n--) {
      int x;
      cin >> x;
      a = max(a, b * x);
      b = x;
    }
    cout << a << endl;
  }
}
