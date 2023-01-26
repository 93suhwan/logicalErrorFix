#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 17;
const int INF = 1e9 + 7;
const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;
const long double EPS = 1e-8;
const long double PI = acos(-1);
vector<string> pot;
void generate() {
  long long curr = 1;
  while (curr <= 1e18) {
    pot.push_back(to_string(curr));
    curr *= 2;
  }
}
int dif(string n, string p) {
  int tam = (int)n.size();
  int it = 0;
  for (auto e : n) {
    if (e == p[it]) it++;
  }
  return (tam - it) + ((int)p.size() - it);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  generate();
  int t;
  cin >> t;
  while (t--) {
    string n;
    cin >> n;
    int ans = INF;
    for (auto e : pot) ans = min(ans, dif(n, e));
    cout << ans << '\n';
  }
  return 0;
}
