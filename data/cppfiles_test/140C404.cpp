#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (cin >> n)
    cout << (int)sqrt(n) + (int)cbrt(n) - (int)sqrt(cbrt(n)) << endl;
}
