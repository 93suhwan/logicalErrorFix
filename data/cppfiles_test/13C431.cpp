#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int test;
  cin >> test;
  while (test > 0) {
    string str_cas;
    cin >> str_cas;
    long long int a_count = 0, b_count = 0, c_count = 0;
    for (long long int counter = 0; counter < str_cas.length(); counter++) {
      if (str_cas[counter] == 'A') a_count++;
      if (str_cas[counter] == 'B') b_count++;
      if (str_cas[counter] == 'C') c_count++;
    }
    if (b_count == a_count + c_count)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
    test--;
  }
  return 0;
}
