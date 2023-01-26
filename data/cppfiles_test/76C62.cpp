#include <bits/stdc++.h>
using namespace std;
mt19937 ran(time(0));
int mod = 1e9 + 7;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long Bpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int n, m;
vector<map<int, int>> g(2e5 + 7);
vector<vector<int>> h(5000, vector<int>(5000));
void F(vector<int>& v, int last = 0) {
  if (v.size() == 5) {
    for (auto& u : v) cout << u << " ";
    exit(0);
  }
  for (int i = last + 1; i < min(n + 1, 51); i++) {
    bool f = true;
    for (auto& u : v) f &= h[i][u];
    if (!f) continue;
    v.push_back(i);
    F(v, i);
    v.pop_back();
  }
}
void F1(vector<int>& v, int last = 0) {
  if (v.size() == 5) {
    for (auto& u : v) cout << u << " ";
    exit(0);
  }
  for (int i = last + 1; i < min(n + 1, 51); i++) {
    bool f = true;
    for (auto& u : v) f &= h[i][u] == 0;
    if (!f) continue;
    v.push_back(i);
    F1(v, i);
    v.pop_back();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > 50 || b > 50) continue;
    h[a][b]++;
    h[b][a]++;
  }
  vector<int> v;
  F(v);
  F1(v);
  cout << "-1";
}
