#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, k;
    cin >> x >> k;
    long long int temp = k % 4;
    long long int i = 1;
    while (temp--) {
      if (x % 2) {
        x += ((k / 4) * 4) + i;
      } else {
        x -= ((k / 4) * 4) + i;
      }
      i++;
    }
    cout << x << endl;
  }
  return 0;
}
