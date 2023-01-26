#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int main() {
  int t, l1, l2, l3;
  cin >> t;
  while (t--) {
    cin >> l1 >> l2 >> l3;
    if (l1 > l3) swap(l1, l3);
    if (l2 > l3) swap(l2, l3);
    if (l1 > l2) swap(l1, l2);
    bool can = false;
    if (l1 == l2 && l3 % 2 == 0) {
      can = true;
    } else if (l2 == l3 && l1 % 2 == 0) {
      can = true;
    } else if (l1 + l2 == l3) {
      can = true;
    }
    cout << (can ? "YES" : "NO") << "\n";
  }
}
