#include <bits/stdc++.h>
const int N = int(1e5) + 5;
const int oo = int(1e6);
const int MOD = (int)1e9 + 7;
const double EPS = 1e-7;
long long gcd(long long a, long long b) { return (a) ? gcd(b % a, a) : b; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
using namespace std;
void RUN() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool getBit(long long num, int idx) { return ((num >> idx) & 1); }
long long Fpow(long long x, long long y, long long mod) {
  return (!y ? 1
             : (((y & 1) ? x : 1) % mod *
                Fpow((x % mod) * (x % mod) % mod, y >> 1, mod) % mod) %
                   mod);
}
map<char, int> mp;
int main() {
  RUN();
  int ts;
  cin >> ts;
  while (ts--) {
    char ch;
    for (int i = 0; i < 26; i++) {
      cin >> ch;
      mp[ch] = i;
    }
    string s;
    cin >> s;
    long long cost = 0;
    for (int i = 1; i < (int)(s.size()); i++) {
      cost += abs(mp[s[i]] - mp[s[i - 1]]);
    }
    cout << cost << '\n';
    mp.clear();
  }
}
