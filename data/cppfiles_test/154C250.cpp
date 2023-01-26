#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void fun();
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int testCase{0};
  cin >> testCase;
  while (testCase--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (((2 * max(a, max(b, c))) == a + b + c && a != 0 && b != 0 && c != 0) ||
        ((a == b && c % 2 == 0) || (b == c && a % 2 == 0) ||
         (a == c && b % 2 == 0)))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
void fun() {}
