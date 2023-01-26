#include <bits/stdc++.h>
using namespace std;
int compare(int a, int b) { return a > b; }
using namespace std;
long long a[1000010], b[1000010], s2[1000010];
int main() {
  long long T, P;
  cin >> T;
  while (T--) {
    long long a, b, c, d;
    cin >> P;
    if (P % 2 != 0) {
      b = P - 1;
      a = b / 2;
    } else {
      b = P / 2;
      a = b / 2;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
