#include <bits/stdc++.h>
using namespace std;
void solve() {
  string second;
  cin >> second;
  int ab = 0, ba = 0;
  for (int i = 1; i < second.size(); i++) {
    if (second[i] == 'a' && second[i - 1] == 'b') ba++;
    if (second[i] == 'b' && second[i - 1] == 'a') ab++;
  }
  if (ab == ba) {
    cout << second;
    return;
  }
  if (ba > ab) {
    string aux = second, aux1 = second;
    int cont = 0, cont1 = 0;
    for (int i = 0; second[i] == 'b'; i++) {
      aux[i] = 'a';
      cont++;
    }
    for (int i = second.size() - 1; second[i] == 'a'; i--) {
      aux1[i] = 'b';
      cont1++;
    }
    if (cont < cont1) {
      cout << aux;
    } else
      cout << aux1;
  }
  if (ab > ba) {
    string aux = second, aux1 = second;
    int cont = 0, cont1 = 0;
    for (int i = 0; second[i] == 'a'; i++) {
      aux[i] = 'b';
      cont++;
    }
    for (int i = second.size() - 1; second[i] == 'b'; i--) {
      aux1[i] = 'a';
      cont1++;
    }
    if (cont < cont1) {
      cout << aux;
    } else
      cout << aux1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t5;
  cin >> t5;
  while (t5--) {
    solve();
    cout << '\n';
  }
  return 0;
}
