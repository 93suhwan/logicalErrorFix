#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
template <typename T>
inline void read(T& X) {
  X = 0;
  int w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  if (w) X = -X;
}
long long a[20];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  long long n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long k, q, p;
    for (int i = 1; i < n; i++) {
      p = m - pow(10, a[i + 1] - a[i]) + 1;
      if (p < 0) {
        k = m;
        q = a[i];
        break;
      } else
        m = p;
    }
    if (p > 0) {
      printf("%lld", (p + 1));
      for (int i = 1; i <= a[n]; i++) cout << "9";
      cout << endl;
    } else {
      cout << (long long)(k + 1);
      for (int i = 1; i <= q; i++) cout << "9";
      cout << endl;
    }
  }
  return 0;
}
