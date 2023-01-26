#include <bits/stdc++.h>
const int N = 1e7 + 5;
long long a[N];
using namespace std;
int main() {
  int t;
  a[0] = 1;
  for (int i = 1; i < 1000000; i++) {
    a[i] = a[i - 1] * (2 * i - 1) * (2 * i) % 2000000014;
    a[i] %= 2000000014;
  }
  cin >> t;
  while (t > 0) {
    long long n, ans = 1, flag;
    cin >> n;
    flag = a[n] % 2000000014;
    flag /= 2;
    cout << flag << endl;
    t--;
  }
  return 0;
}
