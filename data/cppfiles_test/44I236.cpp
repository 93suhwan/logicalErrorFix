#include <bits/stdc++.h>
using namespace std;
int fact(long long int n) {
  long long int p = 1;
  for (long long int i = 1; i <= 1; i = i + 1) {
    p = p * i;
  }
  return p;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a == b) {
      if (a == 0 && b == 0)
        cout << "0";
      else
        cout << "1";
    } else if ((a + b) % 2 != 0)
      cout << "-1";
    else
      cout << "2";
  }
}
