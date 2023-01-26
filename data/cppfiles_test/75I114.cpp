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
void coz(int *dizi, int bas, int son, int bastan, int sondan, bool kim) {
  if (bas == son) {
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
    } else {
      int yedek = son - 1;
      while (dizi[yedek] < dizi[bas] && son - 1 - yedek <= sondan) yedek--;
      yedek = son - 1 - yedek;
      if (sondan < yedek) {
        if ((sondan + bastan + 1) % 2) kim = !kim;
        if (kim)
          cout << "Alice";
        else
          cout << "Bob";
        return;
      } else {
        if (!(yedek % 2)) kim = !kim;
        coz(dizi, bas, son - yedek - 1, bastan, son - yedek - 1, kim);
      }
    }
  } else {
    if (!(sondan % 2)) {
      if (kim)
        cout << "Alice";
      else
        cout << "Bob";
      return;
    } else {
      int yedek = bas + 1;
      while (dizi[yedek] < dizi[son] && yedek - bas - 1 <= bastan) yedek++;
      yedek -= bas + 1;
      if (bastan < yedek) {
        if ((sondan + bastan + 1) % 2) kim = !kim;
        if (kim)
          cout << "Alice";
        else
          cout << "Bob";
        return;
      } else {
        if (!(yedek % 2)) kim = !kim;
        coz(dizi, bas + yedek + 1, son, bastan - yedek - 1, sondan, kim);
      }
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
  coz(dizi, 0, n - 1, bastan, sondan, 1);
  return 0;
}
