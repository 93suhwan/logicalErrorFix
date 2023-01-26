#include <bits/stdc++.h>
using namespace std;
const long long N = 22;
const long long M = 1e6 + 11;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 1e9 + 7;
const double EPS = 1e-9;
const long long block = 1e14;
const long long shift = 2e3;
const double pi = acos(-1.0);
mt19937 bruh(chrono::steady_clock::now().time_since_epoch().count());
long long t;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    long long d[3] = {0};
    for (auto u : a) d[u - 'A']++;
    cout << (d[0] + d[2] == d[1] ? "YES\n" : "No\n");
  }
}
