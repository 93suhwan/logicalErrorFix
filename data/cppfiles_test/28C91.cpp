#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long sum = a + 2 * b + 3 * c;
    if (sum & 1)
      cout << "1" << endl;
    else
      cout << "0" << endl;
  }
  return 0;
}
