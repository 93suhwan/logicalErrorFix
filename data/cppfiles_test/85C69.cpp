#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chkmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int num = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num *= 10;
    num += ch - '0';
    ch = getchar();
  }
  return num * f;
}
long long read1() {
  long long num = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    num *= 10;
    num += ch - '0';
    ch = getchar();
  }
  return num * f;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int idx(char x) { return x - 'a'; }
long long n, k;
int a[300010];
int b[10000];
int ans[100][100];
map<int, int> id;
int main() {
  int t;
  t = read();
  while (t--) {
    string s;
    getline(cin, s);
    long long ans = 0;
    bool flag = false;
    for (int i = 0; i <= s.size(); i++) {
      if (s[i] == '1') {
        ans += flag;
        flag = false;
      } else if (s[i] == '0')
        flag = true;
    }
    if (flag) ans++;
    if (ans > 2) ans = 2;
    cout << ans << endl;
  }
  return 0;
}
