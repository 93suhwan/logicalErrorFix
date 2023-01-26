#include <bits/stdc++.h>
using namespace std;
map<long long int, long long int> mp;
long long int ara[200009];
set<long long int> adj[200009];
vector<pair<long long int, long long int> > vec;
map<long long int, long long int> vis;
map<long long int, long long int> pos;
vector<long long int> prime;
long long int ax[200009], ys[200009];
vector<pair<long long int, long long int> > x_cor;
vector<pair<long long int, long long int> > y_cor;
vector<long long int> aq;
vector<long long int> bq;
struct abc {
  long long int k;
  long long int powr;
};
abc arr[200009];
long long int cmp(abc a, abc b) { return a.powr < b.powr; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, m, n, a, b, i, j = 2, tn = 10, ans = 0, k = 1, q;
  long long int par1[4009], par2[4009], rank1[4009], rank2[4009];
  string ab = "Hello,World!";
  cin >> t;
  while (t--) {
    cin >> n;
    string str;
    cin >> str;
    vector<long long int> primss;
    a = -1;
    for (i = 0; i < n; i++) {
      if (a != -1) continue;
      if (str[i] == '1' || str[i] == '4' || str[i] == '6' || str[i] == '8' ||
          str[i] == '9') {
        a = str[i] - '0';
      }
    }
    if (a != -1) {
      cout << "1" << '\n';
      cout << a << '\n';
      continue;
    }
    for (i = 0; i < n - 1; i++) {
      a = str[i] - '0';
      for (j = i + 1; j < n; j++) {
        b = str[j] - '0';
        long long int c = tn * a + b;
        primss.push_back(c);
      }
    }
    long long int sz = primss.size();
    for (i = 0; i < sz; i++) {
      long long int x = primss[i];
      long long int ck = -1;
      for (j = 2; j * j <= x + 12; j++) {
        if (x % j == 0) {
          ck = 0;
          break;
        }
      }
      if (ck == 0) {
        a = x;
      }
    }
    cout << "2" << '\n';
    cout << a << '\n';
  }
}
