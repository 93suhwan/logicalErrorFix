#include <bits/stdc++.h>
using namespace std;
void solve() {
  int ab = 0, ba = 0, len;
  string stn;
  cin >> stn;
  len = stn.size();
  for (int i = 1; i < len; i++) {
    if (stn[i - 1] == 'a' && stn[i] == 'b') ab++;
    if (stn[i - 1] == 'b' && stn[i] == 'a') ba++;
  }
  if (ab == ba)
    cout << stn;
  else {
    if (ab > ba) {
      if (stn[0] == 'a')
        stn[0] = 'b';
      else if (stn[len - 1] == 'b')
        stn[len - 1] = 'a';
    } else {
      if (stn[0] == 'b')
        stn[0] = 'a';
      else if (stn[len - 1] == 'a')
        stn[len - 1] = 'b';
    }
    cout << stn;
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
    cout << endl;
  }
  return 0;
}
