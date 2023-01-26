#include <bits/stdc++.h>
using namespace std;
const long long maxn = 3e5 + 5;
const long long max_val = 2e5 + 10;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long co = 0;
    for (long long i = n - 1; i >= 0; i--) {
      co += (s[i] - '0');
    }
    for (long long i = 0; i < n; i++) {
      if (s[i] != '0') co++;
    }
    if (s[n - 1] != '0') co--;
    cout << co << "\n";
  }
  return 0;
}
