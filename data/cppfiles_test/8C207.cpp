#include <bits/stdc++.h>
using namespace std;
void BoostIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long const maxn = 100005;
double pi = 3.1415926535897932;
double eps = 1e-7;
long long Pow(long long b) {
  if (b == 0) {
    return 1;
  }
  long long v = Pow(b / 2);
  if (b % 2 == 0) {
    return v * v;
  } else {
    return v * v * 2;
  }
}
int32_t main() {
  BoostIO();
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long a = n / 3;
    long long b = a;
    if (n % 3 == 1) {
      ++a;
    }
    if (n % 3 == 2) {
      ++b;
    }
    cout << a << ' ' << b << endl;
  }
}
