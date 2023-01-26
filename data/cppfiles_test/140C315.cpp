#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int mi2(int x1) {
  long long sum = 0;
  int cnt = 1;
  while (sum <= x1) {
    cnt++;
    sum = cnt * cnt;
  }
  return cnt - 1;
}
int mi3(int x1) {
  long long sum = 0;
  int cnt = 1;
  while (sum <= x1) {
    cnt++;
    sum = cnt * cnt * cnt;
  }
  return cnt - 1;
}
int mi6(int x1) {
  long long sum = 0;
  int cnt = 1;
  while (sum <= x1) {
    cnt++;
    sum = cnt * cnt * cnt * cnt * cnt * cnt;
  }
  return cnt - 1;
}
int main(void) {
  int t;
  int n;
  int put;
  cin >> t;
  for (int i = 1; i <= (t); i++) {
    cin >> n;
    int x1, x2, x3;
    x1 = int(sqrt(n));
    x2 = int(cbrt(n));
    x3 = int(cbrt(sqrt(n)));
    put = mi2(n) + mi3(n) - mi6(n);
    cout << x1 + x2 - x3 << "\n";
  }
}
