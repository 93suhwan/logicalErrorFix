#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long num, a = 0, l = 0;
    cin >> num;
    for (int i = 2;; i++) {
      if ((2 * num - i * i + i) % (2 * i) == 0) {
        a = (2 * num - i * i + i) / (2 * i);
        l = a + i - 1;
        break;
      }
    }
    cout << a << " " << l << "\n";
  }
}
