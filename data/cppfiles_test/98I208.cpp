#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
using namespace std;
void jivan() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool flag = 0;
  long long x, y;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') {
      x = i + 1;
      y = i + 2;
      flag = 1;
    } else if (s[i] == 'a' && s[i + 1] == 'b') {
      x = i + 1;
      y = i + 2;
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    cout << x << " " << y << endl;
  else
    cout << -1 << " " << -1 << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) jivan();
  return 0;
}
