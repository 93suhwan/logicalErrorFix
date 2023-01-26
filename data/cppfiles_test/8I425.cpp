#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    double b;
    double a;
    a = ceil(n / 3);
    b = ceil((n - a) / 2);
    cout << b << " " << a << endl;
  }
}
