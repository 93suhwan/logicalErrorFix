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
  ca = 0;
  cc = 0;
  cb = 0;
  cin >> n;
  for (j = 1; j <= n; j++) {
    cin >> s;
  }
  for (j = 0; j < n; j++) {
    for (i = 0; i <= s.size(); i++) {
      if (s[i] == 'A') ca++;
      if (s[i] == 'B') cb++;
      if (s[i] == 'C') cc++;
    }
    if ((cc + cb) == s.size() || (cb + cc) == s.size())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
