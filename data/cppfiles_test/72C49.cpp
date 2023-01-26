#include <bits/stdc++.h>
using namespace std;
int ttt = 1;
int n, m, k;
long long const BIG = 1e9;
template <class myType>
void print_arr(myType &arr, long long L, string sep) {
  for (int(i) = (0); (i) < (L); ++(i)) {
    cout << arr[i];
    if (i < L - 1) cout << sep;
  }
  cout << endl;
  return;
}
long long query_(long long i, long long j) {
  cout << "? " << i << " " << j << endl;
  long long x;
  cin >> x;
  return x;
}
void solve() {
  long long q1 = query_(1, BIG), q2 = query_(BIG, BIG);
  long long ym = 1 + (BIG - 1 + q1 - q2) / 2;
  long long q3 = query_(ym, BIG), q4 = query_(ym, 1);
  cout << "! " << 1 + abs(q3 - q1) << " " << 1 + q4 << " " << BIG - abs(q3 - q2)
       << " " << BIG - q3 << endl;
  return;
}
int main() {
  while (ttt--) solve();
  return 0;
}
