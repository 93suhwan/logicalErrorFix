#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e17;
long long ask(long long x, long long y) {
  cout << "? " << x << " " << y << endl;
  long long k;
  cin >> k;
  return k;
}
signed main(signed argc, char** argv) {
  long long start = 2, end = 1e9 - 1, mid;
  long long x, y, p, q;
  long long g1 = ask(1, 1);
  long long g2 = ask(1, 1e9);
  long long g;
  while (start <= end) {
    mid = (start + end) / 2;
    g = ask(1, mid);
    if (g1 - (mid - 1) >= g && g2 - (1e9 - mid) >= g) {
      break;
    }
    if (g1 - (mid - 1) < g) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  long long h = ask(1e9, mid);
  long long l = ask(g + 1, 1);
  long long m = ask(g + 1, 1e9);
  x = g + 1;
  y = l + 1;
  p = 1e9 - h;
  q = 1e9 - m;
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
  if (argc > 1) {
    string __ = argv[1];
    if (__ == "IN") {
      cout << "\n\n\nProgram Ended." << endl;
      long long _;
      cin >> _;
    }
  }
}
