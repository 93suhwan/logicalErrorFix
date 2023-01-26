#include <bits/stdc++.h>
using namespace std;
bool chkmin(int &a, int b) { return b < a ? a = b, 1 : 0; }
bool chkmax(int &a, int b) { return b > a ? a = b, 1 : 0; }
inline int read() {
  int x = 0, fh = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fh = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
  return x * fh;
}
int n;
double p;
int main() {
  cin >> n >> p;
  int l = 0, r = n, now = n;
  int npo3 = n * (n - 1) * (n - 2) / 6;
  while (l <= r) {
    int mid = (l + r) >> 1;
    double p2 = (n - mid) * mid * (mid - 1) / 2. / npo3;
    double p1 = (n - mid) * (n - mid - 1) * mid / 2. / npo3;
    double p3 = mid * (mid - 1) * (mid - 2) / 6. / npo3;
    double p0 = (n - mid) * (n - mid - 1) * (n - mid - 2) / 6. / npo3;
    double win = p3 + p2 + p1 / 2;
    if (win >= p - 1e-9) {
      now = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << now << endl;
  return 0;
}
