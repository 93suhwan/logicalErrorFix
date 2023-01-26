#include <bits/stdc++.h>
using namespace std;
int daj(int a, int b) {
  if (!b) return a;
  return daj(b, a % b);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tt = 0; tt < (t); tt++) {
    int n;
    cin >> n;
    vector<int> bitovi(35, 0);
    int a;
    for (int i = 0; i < (n); i++) {
      cin >> a;
      for (int j = 0; j < (31); j++) {
        if (a & (1 << j)) bitovi[j]++;
      }
    }
    int gcd = -1;
    for (int i = 0; i < (35); i++) {
      if (bitovi[i] == 0)
        continue;
      else if (gcd == -1)
        gcd = bitovi[i];
      else {
        gcd = daj(gcd, bitovi[i]);
      }
    }
    if (gcd == -1) {
      for (int i = 0; i < (n); i++) cout << i + 1 << " ";
      cout << "\n";
    } else {
      for (int i = 0; i < (n); i++) {
        if (gcd % (i + 1) == 0) cout << i + 1 << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
