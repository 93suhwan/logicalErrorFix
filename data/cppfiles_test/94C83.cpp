#include <bits/stdc++.h>
using namespace std;
void Uchiha() {
  long long n;
  cin >> n;
  string s = to_string(n);
  n = s.size();
  long long n1 = 0, n2 = 0;
  for (long long i = 0; i < n; i++)
    (i % 2) ? n1 = 10 * n1 + s[i] - '0' : n2 = 10 * n2 + s[i] - '0';
  long long ans = (n1 + 1) * (n2 + 1);
  cout << ans - 2 << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) Uchiha();
}
