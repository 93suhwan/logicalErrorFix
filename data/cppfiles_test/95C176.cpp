#include <bits/stdc++.h>
using namespace std;
const long long large = 1e10;
const long long remi = 1000000007;
const long long remi2 = 998244353;
const long long inf = 1e18 + 1e17 + 1e16 + 1e15 + 1e14;
vector<vector<int> > g;
vector<int> vis;
long long PowI(long long a, long long b, long long m) {
  long long ans = 1 % m;
  while (b > 0) {
    if (b % 2) ans = (((ans % m) * (a % m)) % m);
    a = (((a % m) * (a % m)) % m);
    b = (long long)(b / ((long long)2));
  }
  return ans;
}
vector<long long> sepdig(long long n) {
  vector<long long> ans;
  while (n) {
    long long r = n % 10;
    n /= 10;
    ans.push_back(r);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k;
  int T = 1;
  cin >> T;
  while (T--) {
    long long n, ele;
    cin >> n >> ele;
    vector<long long> digs = sepdig(n);
    long long dig = digs.size();
    multiset<long long> spes;
    for (i = 0; i < digs.size(); i++) {
      long long num = digs[i];
      long long num2 = PowI(10, dig - 1 - i, inf);
      for (j = 0; j < num; j++) {
        spes.insert(num2);
      }
    }
    long long sz = spes.size();
    vector<long long> ans;
    if (sz < ele) {
      while (sz < ele) {
        for (auto x = spes.begin(); x != spes.end(); x++) {
          long long num = *x;
          if (num != 1) {
            long long numins = num / 10;
            spes.erase(spes.find(num));
            for (j = 0; j < 10; j++) spes.insert(numins);
            break;
          }
        }
        sz = spes.size();
      }
    }
    long long sum = n;
    i = 0;
    for (auto x = spes.begin(); x != spes.end(); x++) {
      if (i >= ele - 1) break;
      long long num = *x;
      ans.push_back(num);
      sum -= num;
      i++;
      if (i >= ele - 1) break;
    }
    ans.push_back(sum);
    sort(ans.begin(), ans.end(), greater<long long>());
    for (i = 0; i < ele; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
