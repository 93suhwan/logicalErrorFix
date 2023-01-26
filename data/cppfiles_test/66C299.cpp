#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  while (a--) {
    int b;
    cin >> b;
    int k = 0, ans = 0, num = 1;
    while (k < b) {
      if (num % 3 != 0 && num % 10 != 3) {
        ans = num;
        k++;
      }
      num++;
    }
    cout << ans << endl;
  }
}
