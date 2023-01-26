#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long squareLength = (long long)sqrt(k);
    long long squareSize = squareLength * squareLength;
    if (k == squareSize)
      cout << squareLength << " " << 1 << endl;
    else if (squareSize == 1)
      cout << k - 1 << " " << 2 << endl;
    else if (k <= squareSize + squareLength + 1)
      cout << k % squareSize << " " << squareLength + 1 << endl;
    else
      cout << squareLength + 1 << " "
           << (squareLength + 1) * (squareLength + 1) - k + 1 << endl;
  }
}
