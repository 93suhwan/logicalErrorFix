#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    set<int> k;
    int sa = (a + b) / 2;
    int sb = a + b - sa;
    int abr = max(0, a - sa);
    int bbr = max(0, b - sb);
    while (abr <= a && bbr <= b) {
      k.insert(abr + bbr);
      abr++;
      bbr++;
    }
    if ((a + b) % 2) {
      int sb = (a + b) / 2;
      int sa = a + b - sb;
      int abr = max(0, a - sa);
      int bbr = max(0, b - sb);
      while (abr <= a && bbr <= b) {
        k.insert(abr + bbr);
        abr++;
        bbr++;
      }
    }
    cout << k.size() << '\n';
    for (auto it = k.begin(); it != k.end(); it++) cout << *it << ' ';
    cout << '\n';
  }
}
