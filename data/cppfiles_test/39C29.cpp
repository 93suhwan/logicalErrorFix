#include <bits/stdc++.h>
using namespace std;
int n;
int a, b, c, d;
set<int> posicoes;
int resp[107];
vector<int> espera;
int main() {
  int pos = 1;
  cin >> n;
  assert(true);
  for (int i = 1; i <= n; i++) {
    posicoes.insert(i);
  }
  while (((int)(posicoes).size())) {
    int last = *prev(posicoes.end());
    espera.push_back(last);
    posicoes.erase(last);
    while (1) {
      vector<int> def(n + 1, 1);
      for (int i = 1; i <= n; i++) {
        if (resp[i]) {
          def[i] = 1;
        } else if (i == espera[0]) {
          def[i] = 1;
        } else {
          def[i] = ((int)(espera).size()) + 1;
        }
      }
      cout << "?";
      for (int i = 1; i <= n; i++) {
        cout << " " << def[i];
      }
      cout << endl;
      int res;
      cin >> res;
      if (res != 0) {
        espera.push_back(res);
        posicoes.erase(res);
      } else {
        break;
      }
      if (posicoes.empty()) break;
    }
    while (!espera.empty()) {
      resp[espera.back()] = pos++;
      espera.pop_back();
    }
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
    cout << " " << resp[i];
  }
  cout << endl;
  return 0;
}
