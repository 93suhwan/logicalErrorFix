#include <bits/stdc++.h>
using namespace std;
void TombStonePiledrider(void) {
  long long int gh;
  cin >> gh;
  string ff;
  cin >> ff;
  string gg;
  cin >> gg;
  long long int hoga = 0;
  for (long long int i = 0; i < gh; ++i) {
    if (gg[i] == '0') {
      continue;
    }
    bool ok = ff[i] == '0';
    if (i - 1 >= 0) {
      if (!ok && ff[i - 1] == '1') {
        ok = true;
        ff[i - 1] == '0';
      }
    }
    if (i + 1 < gh) {
      if (!ok && ff[i + 1] == '1') {
        ok = true;
        ff[i + 1] == '0';
      }
      ok = ok || (ff[i + 1] == '1');
    }
    if (ok) {
      gg[i] = '0';
    }
    hoga += ok;
  }
  for (long long int i = 0; i < gh; ++i) {
    if (gg[i] == '0') {
      continue;
    }
    hoga += (ff[i] == '0');
  }
  cout << hoga << '\n';
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  long long int TotalTestCase = 1;
  std::cin >> TotalTestCase;
  while (TotalTestCase--) {
    TombStonePiledrider();
  }
  return 0;
}
