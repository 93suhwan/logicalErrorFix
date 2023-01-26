#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    queue<bool> q;
    long long two_degree = 2;
    while (k) {
      if (k % two_degree != 0)
        q.push(true);
      else
        q.push(false);
      k -= k % two_degree;
      two_degree <<= 1;
    }
    long long result = 0;
    long long n_degree = 1;
    while (!q.empty()) {
      if (q.front()) result += n_degree;
      n_degree *= n;
      n_degree %= 1000000007;
      result %= 1000000007;
      q.pop();
    }
    cout << result << endl;
  }
}
