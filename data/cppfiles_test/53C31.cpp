#include <bits/stdc++.h>
using namespace std;
void Uchiha() {
  long long n;
  char c;
  cin >> n >> c;
  string s;
  cin >> s;
  long long idx = 0, cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == c)
      idx = i + 1;
    else
      cnt++;
  }
  if (cnt == 0)
    cout << 0 << '\n';
  else if (idx * 2 <= n)
    cout << 2 << '\n' << n - 1 << " " << n << '\n';
  else
    cout << 1 << '\n' << idx << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) Uchiha();
}
