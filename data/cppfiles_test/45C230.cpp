#include <bits/stdc++.h>
using namespace std;
long long int mod = 10000007;
long long int a[100005];
vector<long long int> o, e;
vector<char> fin, fin2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int c, r, i, j, t, l, ii, jj, m, k, q;
  cin >> t;
  while (t--) {
    fin.clear();
    fin2.clear();
    o.clear();
    e.clear();
    long long int n;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        e.push_back(i);
      else
        o.push_back(i);
    }
    long long int oo, ee;
    oo = o.size();
    ee = e.size();
    if (abs(ee - oo) > 1) {
      cout << -1 << "\n";
      continue;
    }
    fin.push_back('z');
    fin2.push_back('z');
    if (ee > oo)
      for (i = 1; i <= n; i++) {
        if (i % 2 != 0)
          fin.push_back('e');
        else
          fin.push_back('o');
      }
    else if (oo > ee)
      for (i = 1; i <= n; i++) {
        if (i % 2 != 0)
          fin.push_back('o');
        else
          fin.push_back('e');
      }
    else if (e[0] == 1)
      for (i = 1; i <= n; i++) {
        if (i % 2 != 0) {
          fin.push_back('e');
          fin2.push_back('o');
        } else {
          fin.push_back('o');
          fin2.push_back('e');
        }
      }
    else
      for (i = 1; i <= n; i++) {
        if (i % 2 != 0) {
          fin.push_back('o');
          fin2.push_back('e');
        } else {
          fin.push_back('e');
          fin2.push_back('o');
        }
      }
    long long int indx = 0;
    long long int swaps = 0;
    long long int j = 0;
    for (i = 1; i <= n; i++) {
      if (fin[i] == 'e') {
        long long int oldd = e[indx];
        long long int neww = i;
        if (oldd > neww) swaps += oldd - neww;
      } else {
        long long int oldd = o[indx];
        long long int neww = i;
        if (oldd > neww) swaps += oldd - neww;
      }
      j++;
      if (j % 2 == 0) indx++;
    }
    if (ee == oo) {
      indx = 0;
      long long int swaps2 = 0;
      j = 0;
      for (i = 1; i <= n; i++) {
        if (fin2[i] == 'e') {
          long long int oldd = e[indx];
          long long int neww = i;
          if (oldd > neww) swaps2 += oldd - neww;
        } else {
          long long int oldd = o[indx];
          long long int neww = i;
          if (oldd > neww) swaps2 += oldd - neww;
        }
        j++;
        if (j % 2 == 0) indx++;
      }
      swaps = min(swaps, swaps2);
    }
    cout << swaps << "\n";
  }
  return 0;
}
