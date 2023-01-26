#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
const long long maxn = 3E5 + 5;
long long xc[4] = {-1, 1, 0, 0};
long long yc[4] = {0, 0, -1, 1};
long long n;
void akkicpp() {
  cin >> n;
  long long m = floor(n / 3);
  long long coin1 = m;
  long long coin2 = m;
  if (n % 3 == 1) {
    ++coin1;
  } else if (n % 3 == 2) {
    ++coin2;
  }
  cout << coin1 << " " << coin2 << endl;
}
int32_t main() {
  long long x;
  cin >> x;
  while (x--) {
    akkicpp();
  }
}
