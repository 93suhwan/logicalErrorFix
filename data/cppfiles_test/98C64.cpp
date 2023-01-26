#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, j;
  string s, s1;
  cin >> s >> s1;
  long long sum = 0;
  for (i = 1; i <= s1.length() - 1; i++) {
    char aa, bb;
    aa = s1[i];
    bb = s1[i - 1];
    long long a, b;
    a = s.find(aa);
    b = s.find(bb);
    sum += abs(a - b);
  }
  cout << sum << endl;
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
