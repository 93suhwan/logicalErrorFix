#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  int height = 1;
  int flag = 0;
  bool die = false;
  for (int i = 0; i < n; i++) {
    if (vec[i] == 0)
      flag++;
    else {
      flag = 0;
      height++;
      if (i >= 1 && vec[i - 1]) {
        height--;
        height += 5;
      }
    }
    if (flag == 2) {
      die = true;
      break;
    }
  }
  if (die)
    cout << "-1"
         << "\n";
  else
    cout << height << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
