#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int soma = 0;
    map<char, int> teste;
    string a, b;
    cin >> a >> b;
    for (int z = 0; z < 26; z++) {
      teste[a[z]] = z + 1;
    }
    for (int k = 0; k < b.length() - 1; k++) {
      soma += abs(teste[b[k + 1]] - teste[b[k]]);
    }
    cout << soma << endl;
  }
  return 0;
}
