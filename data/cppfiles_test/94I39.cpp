#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996).
int arrSize = 0;
void solve(long long n, long long& num1, long long& num2, int ind = 0,
           long long p = 1) {
  if (n <= 0) return;
  if (ind % 2 == 0 && ind > 1) p *= 10;
  if (ind & 1)
    num1 = num1 * 10 + n % 10;
  else
    num2 = num2 + (n % 10) * p;
  solve(n / 10, num1, num2, ind + 1, p);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long num1 = 0;
    long long num2 = 0;
    solve(n, num1, num2);
    cout << (num1 + 1LL) * (num2 + 1LL) - 2LL << endl;
  }
}
