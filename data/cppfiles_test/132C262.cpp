#include <bits/stdc++.h>
using namespace std;
void slv() {
  vector<int> a(7);
  for (int& i : a) cin >> i;
  for (int i = 0; i < 7; i++) {
    for (int j = i + 1; j < 7; j++) {
      for (int k = j + 1; k < 7; k++) {
        if (a[i] + a[j] + a[k] == a[6]) {
          cout << a[i] << " " << a[j] << " " << a[k] << '\n';
          return;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) slv();
}
