#include <bits/stdc++.h>
using namespace std;
int la, lb, lap;
long long a, ap, b;
string stra = "", strap = "", reva = "", strb = "";
bool flag = 1, imp1 = 1, imp2 = 1, imp3 = 1;
int main() {
  scanf("%lld%lld", &a, &b);
  if (a == b) {
    printf("YES");
    return 0;
  }
  if (b % 2 == 0) {
    printf("NO");
    return 0;
  }
  ap = a;
  while (a % 2 == 0) a /= 2;
  while (ap) {
    if (ap % 2 == 1)
      strap += "1";
    else
      strap += "0";
    ap /= 2;
  }
  strap = "1" + strap;
  while (a) {
    if (a % 2 == 1)
      stra += "1";
    else
      stra += "0";
    a /= 2;
  }
  while (b) {
    if (b % 2 == 1)
      strb += "1";
    else
      strb += "0";
    b /= 2;
  }
  la = stra.length();
  lap = strap.length();
  for (int i = 0; i < la; i++) reva = stra[i] + reva;
  lb = strb.length();
  for (int i = 0; i < lb && flag && imp1; i++)
    for (int j = 0; j < la; j++) {
      if (stra[j] != strb[i + j])
        break;
      else if (j == la - 1) {
        for (int k = 0; k <= i; k++)
          if (strb[k] == '0') imp1 = 0;
        for (int k = i + la; k < lb; k++)
          if (strb[k] == '0') imp1 = 0;
        if (imp1) flag = 0;
      }
    }
  for (int i = 0; i < lb && flag && imp3; i++)
    for (int j = 0; j < la; j++) {
      if (reva[j] != strb[i + j])
        break;
      else if (j == la - 1) {
        for (int k = 0; k <= i; k++)
          if (strb[k] == '0') imp3 = 0;
        for (int k = i + la; k < lb; k++)
          if (strb[k] == '0') imp3 = 0;
        if (imp3) flag = 0;
      }
    }
  for (int i = 0; i < lb && flag && imp2; i++)
    for (int j = 0; j < lap; j++) {
      if (strap[j] != strb[i + j])
        break;
      else if (j == lap - 1) {
        for (int k = 0; k <= i; k++)
          if (strb[k] == '0') imp2 = 0;
        for (int k = i + lap; k < lb; k++)
          if (strb[k] == '0') imp2 = 0;
        if (imp2) flag = 0;
      }
    }
  if (flag)
    printf("NO");
  else
    printf("YES");
  return 0;
}
