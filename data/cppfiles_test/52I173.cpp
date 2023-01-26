#include <bits/stdc++.h>
using namespace std;
const int MS = 1000001;
const long long int INF = 1e9 + 7;
void usaco(string filename) {
  string in = filename + ".in", out = filename + ".out";
  freopen(in.c_str(), "r", stdin);
  freopen(out.c_str(), "w", stdout);
}
template <class T>
bool comp(T a, T b) {
  if (a < b) return true;
  return false;
}
long long int po(long long int b, long long int p) {
  long long int ans = 1;
  while (p) {
    if (p % 2 == 0) {
      b = (b * b) % INF;
      p = p / 2;
    } else {
      ans = (ans * b) % INF;
      p--;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    int cnt = 0, her = log2(k);
    while (cnt <= 32) {
      if (k & (1 << cnt)) ans += po(n, cnt);
      cnt++;
      ans %= INF;
    }
    cout << ans << "\n";
  }
}
