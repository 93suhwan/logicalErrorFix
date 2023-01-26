#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool is_prm(int x) {
  if (x == 2) return 1;
  if (x == 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (!is_prm((s[i] - '0'))) {
        cout << "1" << endl << s[i] << endl;
        goto f;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int x = ((s[i] - '0')) * 10 + ((s[j] - '0'));
        if (!is_prm(x)) {
          cout << "2" << endl << x << endl;
          ;
          goto f;
        }
      }
    }
  f:;
  }
  return 0;
}
