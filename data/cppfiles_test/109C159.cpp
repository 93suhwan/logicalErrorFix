#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m = 0, t, z = -1, sum = 0, mx = 0, x;
  cin >> t;
  while (t--) {
    cin >> n;
    string s, p;
    cin >> s;
    x = count(s.begin(), s.end(), '0');
    p = s;
    sort(p.begin(), p.end());
    mx = 0, sum = 0, z = -1;
    for (int i = 0; i < n; i++) {
      sum += (s[i] - '0');
      if (s[i] != '0' && i != n - 1) sum++;
    }
    cout << sum << endl;
  }
}
