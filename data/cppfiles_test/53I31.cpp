#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long a[100007];
const long long maxn = 1e6 + 7;
vector<long long> q;
bool vis[maxn];
void get_Prime() {
  for (long long i = 2; i < maxn; ++i) {
    if (!vis[i]) q.push_back(i);
    for (long long j = 0; j < q.size(); ++j) {
      if (i * q[j] >= maxn) break;
      vis[i * q[j]] = true;
      if (i % q[j] == 0) break;
    }
  }
}
bool vis1[100007];
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    string s;
    cin >> n >> s;
    string s1;
    cin >> s1;
    long long flag = 0;
    for (long long i = 0; i < s1.size(); i++) {
      if (s1[i] != s[0]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      cout << 0 << endl;
      continue;
    }
    if (s1[s1.size() - 1] == s[0]) {
      cout << 1 << endl << n << endl;
      continue;
    }
    cout << 2 << endl << n - 1 << " " << n << endl;
  }
}
