#include <bits/stdc++.h>
using namespace std;
long long n, k, s;
void read() { cin >> s >> n >> k; }
void solve() {
  if (s == k) {
    cout << "YES"
         << "\n";
    ;
    return;
  }
  if (s < k) {
    cout << "NO"
         << "\n";
    ;
    return;
  }
  long long posa = s + k;
  long long l = s - k + 1;
  long long r = s;
  long long siz = r - l + 1;
  long long a = 0, b = 0;
  long long num = (s / k) * k;
  b = r - num + 1;
  a = siz - b;
  if ((s / k) % 2 == 1)
    posa -= b;
  else
    posa -= a;
  if ((2 * n + 1) > posa) {
    cout << "YES"
         << "\n";
    ;
  } else
    cout << "NO"
         << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    read();
    solve();
  }
  return 0;
}
