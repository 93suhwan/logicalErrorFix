#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int i, tc, sq, cb, tmp, count;
  cin >> tc;
  int inp[tc];
  for (i = 0; i < tc; i++) {
    cin >> inp[i];
  }
  for (i = 0; i < tc; i++) {
    sq = int(sqrt(inp[i]));
    cb = int(cbrt(inp[i]));
    tmp = int(sqrt(cb));
    count = sq + cb - tmp;
    cout << count << "\n";
    count = 0;
  }
  return 0;
}
