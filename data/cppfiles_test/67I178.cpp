#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    int flag = 0, ans;
    cin >> a >> b >> c;
    if (abs(b - a) < 2) {
      flag = 1;
    }
    long long int ele = (abs(b - a));
    long long int cir_sz = (ele * 2);
    if (c > cir_sz || cir_sz < a || cir_sz < b) {
      flag = 1;
    }
    if (c < cir_sz) {
      ans = c - ele;
      if (ans <= 0) {
        ans = c + ele;
      }
      if (ans > cir_sz) {
        flag = 1;
      }
    }
    if (flag == 1)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
