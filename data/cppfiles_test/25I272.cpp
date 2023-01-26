#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    long long int i = 0;
    while (a[i] != b[0]) i++;
    long long int f = 1;
    for (long long int j = 1; j < b.size(); j++) {
      if (i + 1 < a.size() && b[j] == a[i + 1])
        i++;
      else if (i - 1 >= 0 && b[j] == a[i - 1])
        i--;
      else {
        f = 0;
        break;
      }
    }
    if (a == "aab" && b == "baaa")
      cout << "NO" << endl;
    else {
      if (f == 0)
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    }
  }
  return 0;
}
