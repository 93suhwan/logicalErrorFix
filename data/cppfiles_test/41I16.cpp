#include <bits/stdc++.h>
using namespace std;
int sum[10][200005];
int n;
string strl;
string str;
void work(int l) {
  if (str[0] != strl[0]) sum[l][1] = 1;
  if (str[1] != strl[1])
    sum[l][2] = sum[l][1] + 1;
  else
    sum[l][2] = sum[l][1];
  for (int i = 2; i < n; i++) {
    for (char j = 'a'; j <= 'c'; j++) {
      if (strl[i - 1] != j && strl[i - 2] != j) {
        strl[i] = j;
        break;
      }
    }
    if (strl[i] != str[i - 1])
      sum[l][i + 1] = sum[l][i] + 1;
    else
      sum[l][i + 1] = sum[l][i];
  }
}
int main() {
  cin >> n;
  int T;
  cin >> T;
  cin >> str;
  strl[0] = 'a';
  strl[1] = 'b';
  work(1);
  strl[1] = 'c';
  work(2);
  strl[0] = 'b';
  work(3);
  strl[1] = 'a';
  work(4);
  strl[0] = 'c';
  work(5);
  strl[1] = 'b';
  work(6);
  while (T--) {
    int l, r, ans = 0x7fffffff;
    cin >> l >> r;
    for (int i = 1; i <= 6; i++) {
      ans = min(ans, sum[i][r] - sum[i][l - 1]);
    }
    cout << ans << endl;
  }
}
