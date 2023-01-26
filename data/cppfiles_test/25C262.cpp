#include <bits/stdc++.h>
using namespace std;
void task() {
  string s, t;
  cin >> s >> t;
  string opa = s;
  string aux = "";
  int tam = t.size();
  for (int i = 0; i < tam; i++) {
    aux += t[i];
    opa = s;
    while (true) {
      int a = opa.find(aux);
      if (a != -1) {
        opa[a] = '.';
        int fim = a + i - 1, o = i + 1;
        if (fim + 1 < tam - o) continue;
        bool ok = true;
        while (fim >= 0 && o < tam) {
          if (s[fim] == t[o]) {
            fim--, o++;
          } else {
            ok = false;
            break;
          }
        }
        if (ok) {
          printf("YES\n");
          return;
        }
      } else
        break;
    }
  }
  printf("NO\n");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    task();
  }
  return 0;
}
