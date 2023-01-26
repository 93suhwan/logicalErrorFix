#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  cin >> testcases;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
void Hollwo_Pelw() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) cout << "(";
    for (int j = 0; j < i; j++) cout << ")";
    for (int j = 0; j < n - i; j++) cout << "()";
    cout << '\n';
  }
}
