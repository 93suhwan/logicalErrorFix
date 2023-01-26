#include <bits/stdc++.h>
using namespace std;
template <class X>
void temfunc(const X a) {
  for (auto it = a.begin(); it != a.end(); it++) cout << *it << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t, l, r;
  cin >> t;
  while (t--) {
    cin >> l >> r;
    if (l == r)
      cout << 0 << "\n";
    else {
      int temp;
      if (r & 1) {
        int temp = r / 2;
        if (temp >= l)
          cout << temp << "\n";
        else {
          cout << r % l << "\n";
        }
      } else {
        temp = r / 2;
        if (temp >= l)
          cout << temp - 1 << "\n";
        else
          cout << r % l << "\n";
      }
    }
  }
  return 0;
}
