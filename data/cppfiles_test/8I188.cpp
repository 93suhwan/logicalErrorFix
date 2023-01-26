#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long double b;
    long double a;
    a = ceil(n / 3);
    b = ceil((n - a) / 2);
    cout << b << " " << a << endl;
  }
}
