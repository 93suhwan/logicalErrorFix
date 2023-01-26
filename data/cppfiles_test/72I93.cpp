#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int a, b, c, d;
  cout << "? " << 1 << " " << 1 << endl;
  cin >> a;
  cout << "? " << (int)1e9 << " " << 1 << endl;
  cin >> c;
  cout << "? " << 1 << " " << (int)1e9 << endl;
  cin >> b;
  cout << "? " << (int)1e9 << " " << (int)1e9 << endl;
  cin >> d;
  int l = 1, h = 1e9;
  int mhdist_l = a, mhdist_h = b;
  int mid;
  int w1, w2, l1, l2;
  while (l < h) {
    mid = (l + h) / 2;
    cout << "? " << 1 << " " << mid << endl;
    cin >> w1;
    if (w1 < mhdist_l) {
      l = mid + 1;
      mhdist_l = w1;
    } else if (w1 < mhdist_h) {
      h = mid - 1;
      mhdist_h = w1;
    } else
      break;
  }
  l1 = a - w1;
  w2 = c - l1;
  l2 = d - w2;
  cout << "! " << w1 + 1 << " " << l1 + 1 << " " << (int)1e9 - w2 << " "
       << (int)1e9 - l2 << endl;
}
