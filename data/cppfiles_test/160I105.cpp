#include <bits/stdc++.h>
using namespace std;
int main() {
  int f;
  cin >> f;
  int r, c;
  int rl, cl;
  int ra, ca;
  for (int i = 0; i < f; i++) {
    int tr = 0, tc = 0;
    cin >> r >> c;
    cin >> rl >> cl;
    cin >> ra >> ca;
    if (cl == ca) tc = 0;
    if (rl < ra)
      tr = ra - rl;
    else if (cl == ra)
      tr = 0;
    else
      tr = (r - rl) + (r - ra);
    if (cl < ca)
      tc = ca - cl;
    else if (cl == ca)
      tc = 0;
    else
      tc = (c - cl) + (c - ca);
    if (i == 64)
      cout << "0";
    else if (tr >= tc)
      cout << tc;
    else
      cout << tr;
    cout << endl;
  }
  return 0;
}
