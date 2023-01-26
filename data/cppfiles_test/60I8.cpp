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
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int num = a[1];
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) num = min(num, a[i] & a[j]);
    }
    cout << num << endl;
  }
  return 0;
}
