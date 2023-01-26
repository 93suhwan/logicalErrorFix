#include <bits/stdc++.h>
using namespace std;
int ttt = 1;
int n, m, k;
int const BIG = 1e9;
template <class myType>
void print_arr(myType &arr, long long L, string sep) {
  for (int(i) = (0); (i) < (L); ++(i)) {
    cout << arr[i];
    if (i < L - 1) cout << sep;
  }
  cout << endl;
  return;
}
int query_(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int x;
  cin >> x;
  return x;
}
void solve() {
  int q1 = query_(1, BIG), q2 = query_(BIG, BIG);
  int ym = (BIG - 1 - q1);
  ym += q2;
  ym /= 2;
  int q3 = query_(BIG, ym), q4 = query_(1, ym);
  cout << "! " << 1 + q4 << " " << 1 + abs(q3 - q2) << " " << BIG - q3 << " "
       << BIG - abs(q4 - q1) << endl;
  return;
}
int main() {
  while (ttt--) solve();
  return 0;
}
