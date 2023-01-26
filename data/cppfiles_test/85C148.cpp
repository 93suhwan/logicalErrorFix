#include <bits/stdc++.h>
using namespace std;
int main() {
  int DER;
  scanf("%d", &DER);
  while (DER--) {
    string kmjolp;
    cin >> kmjolp;
    int dcvfg = 0, awsxzc = 0, bnhjmk = 2, opkm = kmjolp.length();
    for (int sdwer = 0; sdwer < opkm; sdwer++) {
      if (kmjolp[sdwer] != bnhjmk) {
        if (kmjolp[sdwer] == '0')
          dcvfg++;
        else
          awsxzc++;
        bnhjmk = kmjolp[sdwer];
      }
    }
    if (dcvfg == 0)
      printf("0\n");
    else if (awsxzc == 0)
      printf("1\n");
    else if (dcvfg <= 2)
      printf("%d\n", dcvfg);
    else
      printf("2\n");
  }
}
