#include <bits/stdc++.h>
using namespace std;
long long mod = 10e9 + 7;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    long long n, second;
    cin >> n >> second;
    long long m = n / 2 + 1;
    cout << (long long)(floor(second / m)) << endl;
  }
  return 0;
}
