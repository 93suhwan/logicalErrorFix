#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
char opo(char c) { return (c == 'L' ? 'R' : 'L'); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  VI V(n);
  for (int& x : V) cin >> x;
  string s;
  cin >> s;
  sort(V.begin(), V.end());
  int dre = 0;
  int i = 0;
  while (i < n) {
    int j = i;
    while (++j < n and s[j] == s[i])
      ;
    if ((j - i) % 2 == 0) ++dre;
    i = j;
  }
  char petit = opo(s[0]);
  int esq = dre - 1;
  i = 0;
  while (i < n) {
    int j = i;
    while (++j < n and s[j] == s[i])
      ;
    int q = j - i;
    int m = (q + 1) / 2;
    for (int k = 0; k < m; ++k) cout << V[dre + 2 * k] << ' ' << s[i] << '\n';
    if (q % 2) {
      for (int k = m; k < q; ++k)
        cout << V[dre + 1 + 2 * (k - m)] << ' ' << opo(s[i]) << '\n';
    } else {
      for (int k = m; k < q - 1; ++k)
        cout << V[dre + 1 + 2 * (k - m)] << ' ' << opo(s[i]) << '\n';
      cout << V[esq--] << ' ' << petit << endl;
      --dre;
      petit = opo(petit);
    }
    dre += q;
    i = j;
  }
}
