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
      if (s[i] == '0') c1++;
    }
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0' && s[i + 1] == '1' || (s[i] == '1' && s[i + 1] == '0')) {
        c++;
        i++;
      }
    }
    if (c1 == n)
      cout << "1\n";
    else
      cout << c << endl;
  }
}
