#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> t(n);
  unordered_map<int, int> mapa;
  int sum = 0;
  for (int& e : t) {
    cin >> e;
    mapa[e]++;
    sum += e;
  }
  int wynik = 0;
  for (int e : t) {
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
