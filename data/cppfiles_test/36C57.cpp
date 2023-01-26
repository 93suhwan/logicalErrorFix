#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &n) {
  n = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    n = (n << 3) + (n << 1) + (ch & 15);
    ch = getchar();
  }
  n *= f;
}
const int N = 1e5 + 10;
long long a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  read(T);
  while (T--) {
    int n;
    read(n);
    if (n == 1) {
      cout << "a" << endl;
      continue;
    }
    if (n & 1) {
      n = n - 1;
      int q = n / 2 - 1, h = n / 2;
      for (int i = 1; i <= q; i++) cout << "a";
      cout << "b";
      for (int i = 1; i <= h; i++) cout << "a";
      cout << "c";
      cout << endl;
    } else {
      int q = n / 2 - 1, h = n / 2;
      for (int i = 1; i <= q; i++) cout << "a";
      cout << "b";
      for (int i = 1; i <= h; i++) cout << "a";
      cout << endl;
    }
  }
  return 0;
}
