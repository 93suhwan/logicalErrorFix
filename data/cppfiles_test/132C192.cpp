#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
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
int a[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i = 1; i <= 7; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 8);
    for (int i = 1; i <= 2; i++) {
      cout << a[i] << " ";
    }
    if ((a[1] + a[2] == a[3] && a[3] == a[4]) || a[1] + a[2] != a[3]) {
      cout << a[3] << "\n";
    } else
      cout << a[4] << "\n";
  }
  return 0;
}
