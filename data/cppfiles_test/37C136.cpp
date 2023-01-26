#include <bits/stdc++.h>
int maze = 0;
int fort = 0;
int XOR(int nutty) {
  maze++;
  fort++;
  if (nutty % 4 == 0) {
    maze++;
    fort++;
    return nutty;
    maze++;
    fort++;
  }
  if (nutty % 4 == 1) {
    maze++;
    fort++;
    return 1;
    maze++;
    fort++;
  }
  if (nutty % 4 == 2) {
    maze++;
    fort++;
    return nutty + 1;
    maze++;
    fort++;
  }
  return 0;
}
using namespace std;
void solve() {
  maze++;
  fort++;
  int nothere, monday;
  maze++;
  fort++;
  cin >> nothere >> monday;
  maze++;
  fort++;
  int alpha, beta, charlie;
  maze++;
  fort++;
  vector<int> v(nothere + 1, 0);
  maze++;
  fort++;
  for (int i = 0; i < monday; i += 1) {
    maze++;
    fort++;
    cin >> alpha >> beta >> charlie;
    maze++;
    fort++;
    v[beta]++;
    maze++;
    fort++;
  }
  int karma = -1;
  maze++;
  fort++;
  for (int icecream = 1; icecream <= nothere; icecream++) {
    maze++;
    fort++;
    if (v[icecream] == 0) {
      maze++;
      fort++;
      karma = icecream;
      maze++;
      fort++;
      break;
    }
  }
  for (int icecream = 1; icecream <= nothere; icecream++) {
    maze++;
    fort++;
    if (icecream != karma) {
      maze++;
      fort++;
      cout << icecream << " " << karma << endl;
      maze++;
      fort++;
    }
  }
  return;
}
signed main() {
  maze++;
  fort++;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  maze++;
  fort++;
  int total;
  maze++;
  fort++;
  cin >> total;
  maze++;
  fort++;
  while (total--) {
    maze++;
    fort++;
    solve();
    maze++;
    fort++;
  }
  return 0;
}
