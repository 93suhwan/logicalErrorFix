#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18 + 9;
const vector<long long> possible = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<long long> digits(long long n) {
  vector<long long> pom;
  pom.clear();
  while (n) {
    pom.push_back(n % 10);
    n /= 10;
  }
  reverse(pom.begin(), pom.end());
  return pom;
}
long long construct(vector<long long> pom) {
  long long ans = 0;
  for (auto it : pom) ans = (ans * 10) + it;
  return ans;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> num = digits(n);
  long long ans = inf;
  for (long long i = 0; i < (1 << (long long)possible.size()); i++) {
    long long mask = i;
    if (__builtin_popcountll(mask) != k) continue;
    vector<long long> akt;
    akt.clear();
    for (long long j = 0; j < (long long)possible.size(); j++) {
      if (mask & (1 << j)) akt.push_back(possible[j]);
    }
    vector<long long> probuj;
    probuj.clear();
    if ((long long)akt.size() == 0) continue;
    if ((long long)akt.size() == 1 && akt[0] == 0) continue;
    long long smallest = -1;
    for (long long j = 0; j < (long long)akt.size(); j++) {
      if (akt[j] != 0) {
        smallest = akt[j];
        break;
      }
    }
    assert(smallest > 0);
    for (long long j = 0; j <= (long long)num.size(); j++)
      probuj.push_back(smallest);
    ans = min(ans, construct(probuj));
    vector<long long> rak;
    rak.clear();
    long long last = -1;
    for (long long prefiks = 0; prefiks < (long long)num.size(); prefiks++) {
      long long aktcyfra = num[prefiks];
      long long wsk = -1;
      for (auto it : akt)
        if (it > aktcyfra) {
          wsk = it;
          break;
        }
      if (wsk != -1) {
        vector<long long> wynik = rak;
        wynik.push_back(wsk);
        while ((long long)wynik.size() < (long long)num.size())
          wynik.push_back(akt[0]);
        ans = min(ans, construct(wynik));
      }
      bool czy = false;
      for (auto it : akt)
        if (it == aktcyfra) czy = true;
      if (czy == false) break;
      rak.push_back(aktcyfra);
      if (prefiks == (long long)num.size() - 1) ans = min(ans, n);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long z = 0; z < t; z++) {
    solve();
  }
  return 0;
}
