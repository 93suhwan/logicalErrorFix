#include <bits/stdc++.h>
using namespace std;
const long double pi = atan2l(0, -1);
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long double EPS = 1e-7;
long long a[200001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, m, k;
    string s;
    cin >> s;
    long long b[3];
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    for (int i = 0; i < s.size(); i++) {
      b[s[i] - 'A']++;
    }
    if (b[1] == b[0] + b[2]) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  cout << "";
  ;
}
