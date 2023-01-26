#include <bits/stdc++.h>
using namespace std;
int lg2(const int &x) { return 31 - __builtin_clz(x); }
long long int lg2(const long long int &x) { return 63 - __builtin_clzll(x); }
char alpha[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;
int t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    a = a - 2 * (a / 2);
    b = b - 2 * (b / 2);
    c = c - 2 * (c / 2);
    if (c) {
      cout << 3 * c - (a + 2 * b) << '\n';
    } else if (b) {
      cout << 2 * b - a << '\n';
    } else if (a) {
      cout << a << '\n';
    } else
      cout << 0 << '\n';
  }
}
