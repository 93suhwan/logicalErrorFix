#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000000 + 7;
const long long int MAX = 1e15;
long long int b, t, al, ba, k, bas, m, son;
long long int a, e;
long long int d, q;
long long int n, r;
string s;
long long int x1, x2, p1, p2, w, h, x;
string y;
vector<long long int> v;
vector<long long int> v2;
long long int c;
long long int visited[2000037];
long long int cvp, yer;
long long int dizi[200037];
int main() {
  cin >> t;
  while (t--) {
    memset(dizi, 0, sizeof dizi);
    cin >> n;
    cvp = 0;
    v.clear();
    v2.clear();
    for (int i = 0; i < n; ++i) {
      cin >> a;
      if (a > n or dizi[a] != 0) {
        cvp++;
        v.push_back(a);
      } else {
        dizi[a] = 1;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (dizi[i] == 0) {
        v2.push_back(i);
      }
    }
    sort(v.begin(), v.end());
    long long int f = 1;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] <= v2[i] * 2) {
        f = 0;
      }
    }
    if (f)
      cout << cvp << endl;
    else
      cout << -1 << endl;
  }
}
