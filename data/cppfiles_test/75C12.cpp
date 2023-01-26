#include <bits/stdc++.h>
using namespace std;
int kacBuyuk(int *dizi, int bas, int son) {
  int cevap = 0;
  if (bas < son) {
    cevap = bas + 1;
    while (cevap <= son && dizi[cevap] > dizi[cevap - 1]) cevap++;
    cevap -= bas + 1;
  } else if (son < bas) {
    cevap = bas - 1;
    while (cevap >= son && dizi[cevap] > dizi[cevap + 1]) cevap--;
    cevap = bas - 1 - cevap;
  }
  return cevap;
}
void coz(int *dizi, int bas, int son, int bastan, int sondan, bool kim,
         int enbuyuk) {
  if (bas == son || (dizi[bas] <= enbuyuk && dizi[son] <= enbuyuk)) {
    if (kim)
      cout << "Alice";
    else
      cout << "Bob";
    return;
  }
  if (dizi[bas] == dizi[son]) {
    if ((bastan % 2) && (sondan % 2)) kim = !kim;
    if (kim)
      cout << "Alice";
    else
      cout << "Bob";
    return;
  }
  if (dizi[bas] > dizi[son]) {
    if (!(bastan % 2)) {
      if (kim)
        cout << "Alice";
      else
        cout << "Bob";
      return;
    }
    if (dizi[son] <= enbuyuk) {
      if (kim)
        cout << "Bob";
      else
        cout << "Alice";
    } else {
      coz(dizi, bas, son - 1, bastan, sondan - 1, !kim, dizi[son]);
    }
  } else {
    if (!(sondan % 2)) {
      if (kim)
        cout << "Alice";
      else
        cout << "Bob";
      return;
    }
    if (dizi[bas] <= enbuyuk) {
      if (kim)
        cout << "Bob";
      else
        cout << "Alice";
    } else {
      coz(dizi, bas + 1, son, bastan - 1, sondan, !kim, dizi[bas]);
    }
  }
  return;
}
int main() {
  int n;
  cin >> n;
  int dizi[n];
  for (int i = 0; i < n; i++) cin >> dizi[i];
  int bastan = kacBuyuk(dizi, 0, n - 1);
  int sondan = kacBuyuk(dizi, n - 1, 0);
  coz(dizi, 0, n - 1, bastan, sondan, 1, -1);
  return 0;
}
