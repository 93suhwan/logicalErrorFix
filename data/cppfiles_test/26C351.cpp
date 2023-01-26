#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7, inf = 1e18;
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
int main() {
  setIO();
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll m = 1;
    for (int i = 3; i <= 2 * n; i++) m = m * i % 1000000007;
    cout << m << endl;
  }
  return 0;
}
