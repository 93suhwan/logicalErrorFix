#include <bits/stdc++.h>
using namespace std;
long long fact(long long n) {
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    long long n;
    cin >> n;
    cout << (fact(n * 2) / 2) % 1000000007 << endl;
  }
}
