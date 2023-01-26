#include <bits/stdc++.h>
using namespace std;
long long factorial(long long num) {
  long long ans = 1;
  for (long long i = 2; i <= num; i++) {
    ans = ans % 1000000007;
    ans = ans * i;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long num;
    cin >> num;
    cout << (factorial(num * 2) / 2) % 1000000007 << endl;
  }
}
