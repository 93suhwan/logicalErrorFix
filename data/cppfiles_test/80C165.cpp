#include <bits/stdc++.h>
using namespace std;
void solve(long long tc) {
  string s;
  long long n;
  cin >> n >> s;
  long long req = n / 2;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0' and n - i >= req and n - i - 1 >= req) {
      i++;
      cout << i << " " << n << " " << i + 1 << " " << n << endl;
      return;
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (s[i] == '0' and i + 1 >= req and i >= req) {
      i++;
      cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
      return;
    }
  }
  cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t = 1;
  long long tc = 1;
  cin >> t;
  while (t--) {
    solve(tc);
    tc++;
  }
  return 0;
}
