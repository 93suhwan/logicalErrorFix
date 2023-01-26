#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> t(n);
  map<long long, long long> mapa;
  long long sum = 0;
  for (long long& e : t) {
    cin >> e;
    mapa[e]++;
    sum += e;
  }
  long long wynik = 0;
  for (long long e : t) {
    if ((2 * sum) % n == 0) {
      wynik += mapa[(2 * sum) / n - e];
      if ((2 * sum) / n - e == e) wynik--;
    }
  }
  wynik /= 2;
  cout << wynik << "\n";
}
int main() {
  int Q;
  cin >> Q;
  while (Q--) solve();
}
