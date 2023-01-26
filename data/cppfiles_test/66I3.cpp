#include <bits/stdc++.h>
using namespace std;
int T, n, A, B, rt;
string sA, sB;
int main() {
  cin >> T;
  while (T--) {
    cin >> n >> A >> B >> sA >> sB, A++, B++;
    if (A == B)
      rt = A;
    else if (sA == "left" && sB == "left")
      rt = (abs(A - B) + 3) / 2;
    else if (sA == "left" && sB == "right")
      rt = (2 * n - abs(A - B) + 1) / 2;
    else if (sA == "right" && sB == "left")
      rt = (A + B + 1) / 2;
    else
      rt = (2 * n - A - B + 3) / 2;
    if (rt == 1)
      cout << n - 1 << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
