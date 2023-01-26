#include <bits/stdc++.h>
using namespace std;
const long long DIM = 107;
char ch;
long long i, j, n;
long long a[DIM], x[DIM], y[DIM];
long long c, k, cnt, cc, ca, cb;
long double res;
vector<int> v;
priority_queue<long long> q;
string s, s1, s2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int j = 1; j <= n; j++) {
    cin >> s;
    ca = 0;
    cc = 0;
    cb = 0;
    for (auto i : s) {
      if (i == 'A')
        ca++;
      else if (i == 'B')
        cb++;
      else if (i == 'C')
        cc++;
    }
    {
      if (cb == cc + ca)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    }
  }
  return 0;
}
