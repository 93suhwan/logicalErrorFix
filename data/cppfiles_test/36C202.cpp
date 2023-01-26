#include <bits/stdc++.h>
using namespace std;
using db = double;
using dbl = long double;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using gr = vector<vector<int> >;
using grl = vector<vector<ll> >;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
bool isPrime(ll _a) {
  if (_a < 2) {
    return false;
  }
  if (((_a & 1) == 0) && (_a != 2)) {
    return false;
  }
  for (int i = 3; i * i <= _a; i += 2) {
    if (_a % i == 0) {
      return false;
    }
  }
  return true;
}
void input();
void compute();
int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    input();
    compute();
  }
  return 0;
}
ll n;
ll tab[101];
ll s;
bool o;
void input() {
  cin >> n;
  for (int(i) = 0; (i) < (n); (i)++) cin >> tab[i];
}
void compute() {
  o = false;
  s = 0;
  for (int(i) = 0; (i) < (n); (i)++) s += tab[i];
  if (!isPrime(s)) {
    cout << n << "\n";
    for (int(i) = 0; (i) < (n); (i)++) cout << i + 1 << " ";
    cout << "\n";
  } else {
    cout << n - 1 << "\n";
    for (int(i) = 0; (i) < (n); (i)++) {
      if (!o && (tab[i] & 1)) {
        o = true;
        continue;
      }
      cout << i + 1 << " ";
    }
    cout << "\n";
  }
}
