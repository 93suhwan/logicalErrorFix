#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, posi, posj, di, dj;
  cin >> t;
  while (t--) {
    cin >> n >> m >> posi >> posj >> di >> dj;
    int dem = 0, addi = 1, addj = 1;
    while (posi != di && posj != dj) {
      if (posi + addi >= 1 && posi + addi <= n)
        posi += addi;
      else
        addi = -addi, posi += addi;
      if (posj + addj >= 1 && posj + addj <= m)
        posj += addj;
      else
        addj = -addj, posj += addj;
      dem++;
    }
    cout << dem << '\n';
  }
}
