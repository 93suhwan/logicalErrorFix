#include <bits/stdc++.h>
using namespace std;
std::mt19937 rng(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
const long long INF = 1ll << 60;
const long long mod = 1000000007;
const long double PI = acosl(-1);
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
void solve() {
  long long n, k, x, i, j, cnt = 0;
  cin >> n >> k >> x;
  long long auxx = 1;
  string s, resp = "";
  cin >> s;
  vector<long long> vet;
  for (i = 0; i < n; i++) {
    if (s[i] == '*')
      cnt++;
    else {
      if (cnt > 0) vet.push_back(cnt);
      cnt = 0;
      vet.push_back(cnt);
    }
  }
  if (cnt > 0) vet.push_back(cnt);
  reverse(vet.begin(), vet.end());
  x--;
  for (i = 0; i < vet.size(); i++) {
    if (vet[i] == 0)
      resp += 'a';
    else {
      long long aux = x % (vet[i] * k + 1);
      for (j = 0; j < aux; j++) {
        resp += 'b';
      }
      x /= (vet[i] * k + 1);
    }
  }
  reverse(resp.begin(), resp.end());
  cout << resp << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
