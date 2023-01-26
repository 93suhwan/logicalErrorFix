#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q, init_poz, nr_jumps;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    long long ans;
    cin >> init_poz >> nr_jumps;
    if (init_poz % 2 == 0) {
      long long rest = nr_jumps % 4;
      if (rest == 1) {
        ans = init_poz - nr_jumps;
      } else {
        if (rest == 2)
          ans = init_poz + 1;
        else if (rest == 3)
          ans = nr_jumps + 1 + init_poz;
        else
          ans = init_poz;
      }
    } else {
      long long rest = nr_jumps % 4;
      if (rest == 3)
        ans = init_poz - nr_jumps + 1;
      else if (rest == 0)
        ans = init_poz;
      else if (rest == 1)
        ans = init_poz + nr_jumps;
      else
        ans = init_poz - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
