#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    string n, k;
    cin >> n >> k;
    string A, B, C, other;
    for (int i = 0; i < n.size(); i++) {
      if (n[i] == 'a')
        A.push_back('a');
      else if (n[i] == 'b')
        B.push_back('b');
      else if (n[i] == 'c')
        C.push_back('c');
      else
        other.push_back(n[i]);
    }
    sort(n.begin(), n.end());
    sort(other.begin(), other.end());
    if (A.size() == 0 || B.size() == 0 || C.size() == 0)
      cout << n;
    else {
      cout << A;
      for (int i = 0; i < 3; i++) {
        if (k[i] == 'b')
          cout << C;
        else if (k[i] == 'c')
          cout << B;
      }
      if (other.size() != 0) cout << other;
    }
    cout << "\n";
  }
  return 0;
}
