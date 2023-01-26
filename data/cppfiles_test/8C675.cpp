#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x;
    cin >> x;
    long long int a = x / 3;
    long long int b = x % 3;
    long long int m, n;
    m = n = a;
    if (b == 1) m++;
    if (b == 2) n++;
    cout << m << " " << n << endl;
  }
}
