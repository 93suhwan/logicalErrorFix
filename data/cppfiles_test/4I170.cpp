#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    long long int n;
    cin >> n;
    int a = 0;
    for (int i = 2; i <= 9; i++) {
      for (int j = i + 1; j <= 9; j++) {
        if (n % i == n % j) {
          cout << i << " " << j << endl;
          a = 1;
          break;
        }
      }
      if (a == 1) {
        break;
      }
    }
    t--;
  }
}
