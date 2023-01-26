#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1000;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
vector<long long> cal(long long x) {
  long long sum = 0;
  bool flag = false;
  vector<long long> v;
  while (x > 0) {
    sum = x % 10;
    x /= 10;
    if (!flag) {
      flag = true;
      continue;
    } else if (flag) {
      v.push_back(sum);
    }
  }
  return v;
}
long long w(long long x) {
  long long sum = 0;
  while (x) {
    sum++;
    x /= 10;
  }
  return sum;
}
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n % 10 == 9) n++;
    vector<long long> ans = cal(n);
    if (ans.size() == 0) {
      cout << "0" << endl;
    } else {
      for (long long i = ans.size() - 1; i >= 0; i--) cout << ans[i];
      cout << endl;
    }
  }
  return 0;
}
