#include <bits/stdc++.h>
using namespace std;
long long setbit(long long num, long long nth) { return num |= (1LL << nth); }
long long clearbit(long long num, long long nth) {
  return num &= ~(1LL << nth);
}
long long toggle(long long num, long long nth) { return num ^= (1LL << nth); }
long long check(long long num, long long nth) { return (num >> nth) & 1LL; }
long long change(long long num, long long nth, long long val) {
  return num ^= (-val ^ num) & (1LL << nth);
}
int fx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int fy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
long long dx[4] = {+1, -1, +0, -0};
long long dy[4] = {+0, -0, +1, -1};
long long n, k;
string str, s;
long long a[5000003];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1, cas = 0;
  cin >> tt;
  while (tt--) {
    for (int i = 1; i <= 7; i++) cin >> a[i];
    sort(a + 1, a + 7 + 1);
    cout << a[1] << " " << a[2] << " " << a[7] - a[2] - a[1] << endl;
  }
  return 0;
}
