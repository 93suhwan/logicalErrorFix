#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int p;
  scanf("%lld", &p);
  while (p--) {
    string st;
    cin >> st;
    long long int n = st.size();
    long long int p = 0, j = 0;
    for (int i = 0; i < n; i++) {
      if (st[i] == '0')
        p = 1;
      else if (st[i] != '0' && p == 1) {
        j++;
        p = 0;
      }
    }
    if (st[n - 1] == '0') j++;
    if (j > 2)
      cout << "2\n";
    else
      cout << j << endl;
  }
}
