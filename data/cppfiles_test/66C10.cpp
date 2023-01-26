#include <bits/stdc++.h>
using namespace std;
long long T, n, A, B, rt;
string sA, sB;
bool op, opt;
signed main() {
  cin >> T;
  while (T--) {
    cin >> n >> A >> B >> sA >> sB, A++, B++, op = 1;
    if (A > B) swap(A, B), swap(sA, sB), op = 0;
    if (A == B)
      rt = A;
    else if (sA == "left" && sB == "left")
      rt = (abs(A - B) + 2 + op) / 2;
    else if (sA == "left" && sB == "right")
      rt = (2 * n - abs(A - B) + op) / 2;
    else if (sA == "right" && sB == "left")
      rt = (A + B + op) / 2;
    else
      rt = (2 * n - A - B + 2 + op) / 2;
    opt = ((A & 1) == (B & 1)) ^ op;
    if (opt) {
      if (rt == 1)
        cout << n - 1 << endl;
      else
        cout << 0 << endl;
    } else {
      if (rt == n)
        cout << 0 << endl;
      else
        cout << n - 1 << endl;
    }
  }
  return 0;
}
