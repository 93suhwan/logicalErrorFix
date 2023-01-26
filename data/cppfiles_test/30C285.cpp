#include <bits/stdc++.h>
using namespace std;
void solved() {
  long long int n, flag = 0;
  cin >> n;
  string s;
  char a[2];
  cin >> s;
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    if (s[i] != s[j]) {
      a[0] = s[i];
      a[1] = s[j];
      flag = 1;
      break;
    }
  }
  long long int c1 = 0, c2 = 0;
  for (int i = 0, j = n - 1; i < j && flag == 1;) {
    if (s[i] != s[j]) {
      if (s[i] == a[0])
        c1++, i++;
      else if (s[j] == a[0])
        c1++, j--;
      else {
        c1 = -1;
        break;
      }
    } else
      i++, j--;
  }
  for (int i = 0, j = n - 1; i < j && flag == 1;) {
    if (s[i] != s[j]) {
      if (s[i] == a[1])
        c2++, i++;
      else if (s[j] == a[1])
        c2++, j--;
      else {
        c2 = -1;
        break;
      }
    } else
      i++, j--;
  }
  long long int ans = -1;
  if (c1 > 0 && c2 > 0)
    ans = min(c1, c2);
  else if (c1 >= 0 || c2 >= 0)
    ans = max(c1, c2);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) solved();
  return 0;
}
