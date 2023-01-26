#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    string s, t;
    cin >> s >> t;
    string ss = s;
    sort(ss.begin(), ss.end());
    if (t == "abc") {
      int x, y, z, num1 = 0, num2 = 0, num3 = 0;
      bool ins1 = 0, ins2 = 0, ins3 = 0;
      for (int i = 0; i <= ss.size() - 1; i++) {
        if (ss[i] == 'a') num1++;
        if (ss[i] == 'b') num2++;
        if (ss[i] == 'c') num3++;
        if (!ins1 && ss[i] == 'a') ins1 = 1, x = i;
        if (!ins2 && ss[i] == 'b') ins2 = 1, y = i;
        if (!ins3 && ss[i] == 'c') ins3 = 1, z = i;
      }
      if (ins1 && ins2 && ins3) {
        for (int i = 0; i < num1; i++) printf("a");
        for (int i = 0; i < num3; i++) printf("c");
        for (int i = 0; i < num2; i++) printf("b");
        for (int i = 0; i < ss.size(); i++) {
          if (ss[i] != 'a' && ss[i] != 'b' && ss[i] != 'c') printf("%c", ss[i]);
        }
        printf("\n");
        continue;
      }
    }
    cout << ss << endl;
  }
  return 0;
}
