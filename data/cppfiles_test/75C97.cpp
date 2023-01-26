#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int n, m, d, f, outp1 = 0, outp2 = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int tab[n];
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
  }
  d = 0;
  f = n - 1;
  while (f - 1 > d && tab[f] < tab[f - 1]) {
    outp1++;
    f--;
  }
  while (d + 1 < n - 1 && tab[d] < tab[d + 1]) {
    outp2++;
    d++;
  }
  outp1++;
  outp2++;
  if (outp1 % 2 || outp2 % 2)
    cout << "Alice";
  else
    cout << "Bob";
  return 0;
}
