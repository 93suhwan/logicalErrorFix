#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int N = 1e5 + 5;
const long long int mod = 1e9 + 7;
const long long int inf = 1e17;
const long double PI = (acos(-1));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (char ch : s) {
      ans += ch - '0';
    }
    cout << ans << endl;
  }
}
