#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long maxn = 3E5 + 5;
long long xc[4] = {-1, 1, 0, 0};
long long yc[4] = {0, 0, -1, 1};
void akkicpp() {
  long long n;
  cin >> n;
  long long coin1 = 1;
  long long coin2 = 2;
  long long m = n / 3;
  if (n % 3 == 0) {
    cout << n / 2 << " " << n / 2 << endl;
  } else
    cout << m + 1 << " " << m << endl;
}
int32_t main() {
  long long x;
  cin >> x;
  while (x--) {
    akkicpp();
  }
}
