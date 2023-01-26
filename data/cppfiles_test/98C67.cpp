#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
string s;
ll n, t;
bool check;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    check = true;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        cout << i << " " << i + 1 << endl;
        check = false;
        break;
      }
    }
    if (check) cout << -1 << " " << -1 << endl;
  }
  return 0;
}
