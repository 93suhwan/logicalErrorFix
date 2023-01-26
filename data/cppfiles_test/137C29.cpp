#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
bool check(vb a, vb b) {
  if (((int)(a).size()) > ((int)(b).size())) return false;
  int za = -1, zb = -1;
  for (int i = 0; i < (((int)(a).size())); i++)
    if (!a[i]) {
      za = i;
      break;
    }
  for (int i = 0; i < (((int)(b).size())); i++)
    if (!b[i]) {
      zb = i;
      break;
    }
  if (za == -1 && zb == -1) return true;
  if (za == -1 || zb == -1) return false;
  if (za > zb) return false;
  reverse((a).begin(), (a).end());
  while (za < zb) {
    a.push_back(true);
    za++;
  }
  reverse((a).begin(), (a).end());
  while (((int)(a).size()) < ((int)(b).size())) a.push_back(true);
  for (int i = 0; i < (((int)(a).size())); i++)
    if (a[i] != b[i]) return false;
  return true;
}
bool getRes(vb a, vb b) {
  if (check(a, b)) return true;
  reverse((a).begin(), (a).end());
  return check(a, b);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES"
         << "\n";
    return 0;
  }
  if (!(y & 1LL)) {
    cout << "NO"
         << "\n";
    return 0;
  }
  vb b;
  while (y) {
    b.push_back(y & 1LL);
    y >>= 1;
  }
  reverse((b).begin(), (b).end());
  vb a;
  long long temp = x;
  while (!(temp & 1LL)) temp >>= 1;
  while (temp) {
    a.push_back(temp & 1LL);
    temp >>= 1;
  }
  if (getRes(a, b)) {
    cout << "YES"
         << "\n";
    return 0;
  }
  if (!(x & 1LL)) {
    temp = (x << 1) | 1LL;
    a.clear();
    while (temp) {
      a.push_back(temp & 1LL);
      temp >>= 1;
    }
    if (getRes(a, b)) {
      cout << "YES"
           << "\n";
      return 0;
    }
  }
  cout << "NO"
       << "\n";
}
