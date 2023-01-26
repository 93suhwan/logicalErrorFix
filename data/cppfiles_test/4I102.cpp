#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long p, temp[2], j = 0;
    cin >> p;
    temp[0] = 0;
    temp[1] = 0;
    p -= 1;
    for (int i = 2; i <= p; i++) {
      if (p % i == 0) {
        temp[j++] = i;
      }
      if (j == 1) {
        break;
      }
    }
    cout << temp[0] << ' ' << temp[0] * 2 << endl;
  }
}
