#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int p;
  scanf("%lld", &p);
  while (p--) {
    string s;
    cin >> s;
    long long int n = s.size();
    long long int c = 0, c1 = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        c++;
      } else
        c1++;
    }
    if (c == c1)
      cout << "1\n";
    else if (c == n)
      cout << "1\n";
    else if (c1 == n)
      cout << "0\n";
    else
      cout << min(c1, c) << endl;
  }
}
