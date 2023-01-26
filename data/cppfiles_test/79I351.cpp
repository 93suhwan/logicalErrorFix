#include <bits/stdc++.h>
using namespace std;
void input() {
  int k;
  string n;
  scanf("%d", &k);
  cin >> n;
  int is77 = 0, is33 = 0;
  bool b = 0;
  for (int i = 0; i < k; i++) {
    if (n[i] != '2' and n[i] != '3' and n[i] != '5' and n[i] != '7') {
      printf("%d\n", 1);
      cout << n[i] << endl;
      b = true;
      break;
    }
  }
  if (!b) {
    for (int i = 0; i < k; i++) {
      if ((n[i] == '2' or n[i] == '5') and i > 0) {
        printf("%d\n", 2);
        cout << n[i - 1] << n[i] << endl;
        break;
      }
      if (n[i] == '7' or n[i] == '3') {
        is77++;
        is33++;
        if (is77 > 1 or is33 > 1) {
          printf("%d\n", 2);
          if (is77 > 1)
            cout << 77 << endl;
          else
            cout << 33 << endl;
          break;
        }
        if ((n[0] == '2' or n[0] == '5') and is77) {
          printf("%d\n", 2);
          cout << n[0] << 7 << endl;
          break;
        }
      }
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) input();
  return 0;
}
