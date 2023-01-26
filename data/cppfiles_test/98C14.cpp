#include <bits/stdc++.h>
using namespace std;
char st[1009], sr[1009];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> st + 1 >> sr + 1;
    int len_st = strlen(st + 1);
    int len_sr = strlen(sr + 1);
    int pos1, pos2;
    int ans = 0;
    for (int i = 1; i < len_sr; i++) {
      for (int j = 1; j <= len_st; j++) {
        if (sr[i] == st[j]) pos1 = j;
        if (sr[i + 1] == st[j]) pos2 = j;
      }
      ans += abs(pos2 - pos1);
    }
    cout << ans << endl;
  }
  return 0;
}
