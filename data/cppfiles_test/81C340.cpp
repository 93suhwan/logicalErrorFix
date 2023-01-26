#include <bits/stdc++.h>
using namespace std;
void File() {
  char output[100] = "C:\\Users\\Emiya\\Desktop\\out.txt";
  freopen(output, "w", stdout);
}
const int maxn = 3e5 + 10;
char s[maxn];
int v[maxn];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m >> s + 1;
    for (int i = 1; i <= n; ++i) {
      if (s[i] == '+')
        v[i] = 1;
      else
        v[i] = -1;
      if ((i - 1) & 1) v[i] *= -1;
      v[i] += v[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
      int lf, rt;
      cin >> lf >> rt;
      if (v[lf - 1] == v[rt])
        cout << "0\n";
      else if ((rt - lf + 1) & 1)
        cout << "1\n";
      else
        cout << "2\n";
    }
  }
  return 0;
}
