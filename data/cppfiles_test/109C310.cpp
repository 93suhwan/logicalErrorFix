#include <bits/stdc++.h>
using namespace std;
void init_code() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }
bool prime[102];
long long int xorarray[300002] = {0};
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  prime[1] = false;
}
void xorcal() {
  for (long long int i = 1; i < 300000; i++) {
    xorarray[i] = xorarray[i - 1] ^ i;
  }
}
bool comp(int a, int b) { return (a < b); }
int main() {
  init_code();
  xorcal();
  map<long long int, long long int> m1, m2;
  set<long long int> s1;
  vector<long long int> v1, v2;
  long long int i, n, ans = 0, digit = 0, y, b, r, m, j, pos, a, p, q, t;
  string s;
  char ch;
  cin >> q;
  while (q--) {
    cin >> n >> s;
    for (i = 0; i < s.length(); i++) {
      ans = ans + (s[i] - '0');
      if (s[i] != '0') {
        digit++;
      }
    }
    if (s[s.length() - 1] != '0') {
      cout << ans + (digit - 1) << endl;
    } else {
      cout << ans + digit << endl;
    }
    digit = 0;
    ans = 0;
  }
}
