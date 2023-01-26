#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
      cout << 0 << "\n";
    else {
      long long sum = a * 1 + b * 2 + c * 3;
      long long first_concert = sum / 2;
      long long second_concert = sum - first_concert;
      cout << abs(first_concert - second_concert) << "\n";
    }
  }
  return 0;
}
