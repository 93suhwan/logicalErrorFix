#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  int a, b, c;
  string second;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> second;
    a = 0;
    b = 0;
    c = 0;
    for (int j = 0; j < second.length(); j++) {
      if (second[j] == 'A')
        a++;
      else if (second[j] == 'B')
        b++;
      else if (second[j] == 'C')
        c++;
    }
    if (b == a + c)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
