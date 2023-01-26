#include <bits/stdc++.h>
using namespace std;
long long int M = (long long int)(pow(10, 9) + 7);
void putar(vector<long long int> a) {
  long long int i;
  for (i = 0; i < (long long int)(a).size(); i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
  ;
}
long long int cse = 0;
vector<long long int> a;
void runtest() {
  long long int n, m, x = 0, y = 0, z = 0, c = 0, i, j, h, k = 0, ans = 0;
  ;
  a.clear();
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  };
  vector<long long int> v = a;
  sort(v.begin(), v.end());
  c = 0;
  for (i = 0; i < n; i++) {
    if (v[i] != a[i]) {
      c++;
    }
  }
  if (c == 0) {
    cout << "YES\n";
    ;
    return;
  }
  if (c < 3) {
    cout << "NO\n";
    ;
  } else {
    cout << "YES\n";
    ;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int _ = 1;
  cin >> _;
  while (_--) {
    runtest();
  };
  return 0;
}
