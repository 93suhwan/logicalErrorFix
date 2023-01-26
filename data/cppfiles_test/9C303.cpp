#include <bits/stdc++.h>
using namespace std;
long long int M = 1000000007;
long long int mod(long long int x) { return ((x % M + M) % M); }
long long int add(long long int a, long long int b) {
  return mod(mod(a) + mod(b));
}
long long int mul(long long int a, long long int b) {
  return mod(mod(a) * mod(b));
}
long long int powr(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    b /= 2;
    a = mul(a, a);
  }
  return res;
}
bool cmp(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  return a.second < b.second;
}
long long int is[1000000];
vector<long long int> primes;
void primegen() {
  long long int n, i, j, k, x, mx = 1000000;
  primes.push_back(2);
  for (long long int i = 3; i <= mx; i += 2) {
    if (is[i] == 0) {
      for (long long int j = i * i; j <= mx; j += 2 * i) {
        is[j] = 1;
      }
    }
  }
  for (long long int i = 3; i <= mx; i += 2) {
    if (is[i] == 0) primes.push_back(i);
  }
}
long long int ncr(long long int x, long long int y) {
  long long int ans = 1, s = 1;
  while (s <= y) {
    ans *= (x - s + 1);
    ans /= s;
    s++;
  }
  return ans;
}
void solve() {
  long long int n;
  string s1;
  cin >> s1;
  long long int l = s1.size();
  if (l == 1) {
    cout << "0" << endl;
    return;
  }
  map<char, long long int> make_pair;
  for (long long int i = 0; i < l; i++) {
    make_pair[s1[i]]++;
  }
  long long int sum = 0;
  for (auto it : make_pair) {
    if (it.second >= 2)
      sum += 2;
    else
      sum++;
  }
  cout << sum / 2 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
