#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void compute() {
  long long n;
  cin >> n;
  string s, temp;
  cin >> temp;
  s = temp;
  for (long long i = 0; i < n - 3; i++) {
    string var;
    cin >> var;
    if (var[0] == s[1])
      s += var[1];
    else
      s += var;
  }
  if (s.size() == n)
    cout << s << endl;
  else {
    for (long long i = s.size(); s.size() < n; i++) s.push_back('a');
    cout << s << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    compute();
  }
  return 0;
}
