#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long w, h;
  cin >> w >> h;
  long long x1, y1, x2, y2;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  long long Tw, Th;
  cin >> Tw >> Th;
  bool chi = false;
  long long answ = 99999999999;
  if ((x2 - x1) + Tw <= w) {
    long long one = max((long long)0, Tw - x1);
    long long two = max((long long)0, Tw - (w - x2));
    answ = min(one, two);
  }
  if ((y2 - y1) + Th <= h) {
    long long one = max((long long)0, Th - y1);
    long long two = max((long long)0, Th - (h - y2));
    answ = min(one, answ);
    answ = min(two, answ);
  }
  if (answ == 99999999999) {
    cout << "-1" << endl;
    return;
  } else {
    cout << answ << endl;
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n = 1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
