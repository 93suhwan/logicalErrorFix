#include <bits/stdc++.h>
using namespace std;
int main() {
  long long test;
  cin >> test;
  while (test--) {
    long long x;
    long long y;
    cin >> x >> y;
    long long out = 0;
    long long num = x - 1;
    long long sum = y - 1;
    if (num % 4 == 0) {
      out = num;
      sum = sum + out;
    } else if (num % 4 == 1) {
      out = 1;
      sum = 1;
    } else if (num % 4 == 2) {
      out = num + 1;
      sum++;
    } else {
      out = 0;
      sum = sum / out;
    }
    sum++;
    if (out != y) {
      sum++;
      long long t = out ^ y;
      if (t < 0 || t == x) {
        sum += x;
        x++;
      }
      x++;
      sum--;
    }
    sum = x;
    cout << sum << endl;
  }
  return 0;
}
