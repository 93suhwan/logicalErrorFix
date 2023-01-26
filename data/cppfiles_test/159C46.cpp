#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
vector<T> make_unique(vector<T> a) {
  sort((a).begin(), (a).end());
  a.erase(unique((a).begin(), (a).end()), a.end());
  return a;
}
using ull = unsigned long long;
const int N = 1e6 + 10;
bool prime[N];
ull h[N], fact[N];
int n;
map<ull, int> seen;
string bin(ull x, int width = 5) {
  string ans;
  for (int bit = (int)(width)-1; bit >= ((int)0); bit--)
    ans += char('0' + ((x >> bit) & 1));
  return ans;
}
bool zero() { return fact[n] == 0; }
bool one(vector<int> &ans) {
  if (seen.count(fact[n])) {
    ans[seen[fact[n]]] = 0;
    return true;
  }
  return false;
}
bool two(vector<int> &ans) {
  auto H = fact[n];
  for (int i = 1; i <= n; i++) {
    auto need = H ^ h[i];
    if (seen.count(need)) {
      auto j = seen[need];
      ans[i] = ans[j] = 0;
      return true;
    }
  }
  return false;
}
vector<int> solve(int n) {
  ::n = n;
  vector<int> ans(n + 1, 1);
  if (zero())
    ;
  else if (one(ans))
    ;
  else if (two(ans))
    ;
  else
    ans[n] = ans[n / 2] = ans[2] = 0;
  vector<int> ret;
  for (int i = 1; i <= n; i++)
    if (ans[i]) ret.push_back(i);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(prime + 2, prime + n + 1, true);
  int sz = 0;
  for (int i = 2; i <= n; i++)
    if (prime[i]) {
      ull x = rng();
      for (long long int p = i; p <= n; p *= i) {
        for (int j = p; j <= n; j += p) {
          prime[j] = false;
          h[j] ^= x;
        }
      }
    }
  for (int i = 1; i < n; i++) {
    h[i + 1] ^= h[i];
    fact[i + 1] = fact[i] ^ h[i + 1];
  }
  for (int i = (int)(1); i < ((int)n + 1); i++) seen[h[i]] = i;
  auto ans = solve(n);
  cout << ((int)(ans).size()) << endl;
  for (auto x : ans) cout << x << ' ';
  cout << endl;
  return 0;
}
