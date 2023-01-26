#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int n, m, d, f, outp = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int tab[n];
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  m = max(tab[0], tab[n - 1]);
  m--;
  d = 0;
  f = n - 1;
  while (f >= d) {
    if (tab[d] > m && tab[f] > m) {
      if (tab[d] >= tab[f]) {
        m = tab[d];
        d++;
        outp++;
      } else {
        m = tab[f];
        outp++;
        f--;
      }
    } else if (tab[d] > m) {
      m = tab[d];
      d++;
      outp++;
    } else if (tab[f] > m) {
      m = tab[f];
      f--;
      outp++;
    } else
      break;
  }
  if (outp % 2 == 0)
    cout << "Bob";
  else
    cout << "Alice";
  return 0;
}
