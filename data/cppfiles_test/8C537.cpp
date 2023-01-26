#include <bits/stdc++.h>
using namespace std;
void test() {
  int x;
  cin >> x;
  int jedinice = x / 3;
  int dvojke = jedinice;
  int ostalo = x - jedinice - dvojke - dvojke;
  if (ostalo == 1) jedinice++;
  if (ostalo == 2) dvojke++;
  cout << jedinice << " " << dvojke << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    test();
  }
  return 0;
}
