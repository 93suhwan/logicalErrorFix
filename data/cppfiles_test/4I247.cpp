#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int p;
    cin >> p;
    --p;
    for (long long i = 2; i * i <= p; i++) {
      if (p % i == 0) {
        cout << i << ' ' << p / i << endl;
        break;
      }
    }
  }
}
