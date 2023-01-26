#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, ar[45], i, j, x = 0, tmp = 0;
  string s, ss;
  cin >> a;
  cin >> s;
  ss = s;
  for (i = 0; i < a; i++) ar[i] = s[i];
  for (i = 0; i < a; i++) {
    for (j = i + 1; j < a; j++) {
      if (ar[i] > ar[j]) {
        tmp = ar[j];
        ar[j] = ar[i];
        ar[i] = tmp;
      }
    }
  }
  for (i = 0; i < a; i++) ss[i] = ar[i];
  cout << ss << endl;
  for (i = 0; i < a; i++)
    if (s[i] != ss[i]) x++;
  cout << x << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
