#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x;
}
int main() {
  int t = read();
  while (t--) {
    int n = read();
    for (int i = 0; i < n / 2 - 1; ++i) {
      cout << 'a';
    }
    if (n & 1)
      cout << "bc";
    else
      cout << 'b';
    for (int i = 0; i < n / 2; ++i) cout << 'a';
    cout << endl;
  }
  return 0;
}
