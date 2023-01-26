#include <bits/stdc++.h>
using namespace std;
void solution() {
  long long int n, m, a, b, c, d, p, q, cnt = 0, ct = 0, sum = 0, ans = 0;
  cin >> n >> a;
  cin >> m >> b;
  string s1, s2;
  s1 = to_string(n);
  s2 = to_string(m);
  long long int sz1, sz2;
  sz1 = s1.size();
  sz2 = s2.size();
  sz1 += a;
  sz2 += b;
  if (sz2 > sz1)
    cout << "< " << endl;
  else if (sz1 > sz2)
    cout << ">" << endl;
  else {
    if (n > m)
      cout << ">" << endl;
    else if (n < m)
      cout << "<" << endl;
    else
      cout << "=" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solution();
  return 0;
}
