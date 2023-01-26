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
    bool flag = true;
    cin >> P;
    if (P % 2 != 0) {
      a = P - 1;
      b = a / 2;
    } else {
      a = P / 2;
      b = a / 2;
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
