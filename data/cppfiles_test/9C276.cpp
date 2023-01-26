#include <bits/stdc++.h>
using namespace std;
int n;
string k;
int let[27];
int tong, kq;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int i = 1; i <= 26; i++) let[i] = 0;
    tong = 0, kq = 0;
    cin >> k;
    for (int i = 0; i < k.length(); i++) let[k[i] - 96]++;
    for (int i = 1; i <= 26; i++)
      if (let[i] >= 3)
        kq++;
      else
        tong += let[i];
    kq += tong / 2;
    cout << kq << endl;
  }
  return 0;
}
