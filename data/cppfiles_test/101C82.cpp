#include <bits/stdc++.h>
using namespace std;
long long M = 1000000007;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
class Adu {
 public:
  multiset<long long> vec;
  long long delta;
  long long get() { return (*vec.begin()) + delta; }
  void badha(long long x) { delta -= x; }
  void ghata(long long x) { vec.insert(x - delta); }
  void bacha() { vec.erase(vec.begin()); }
};
long long vec[200002], huehue[200002], adi[200002];
void bkchodcf() {
  long long n, numR = 0, numB = 0;
  ;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> vec[i];
  }
  string s;
  cin >> s;
  for (long long i = 1; i <= n; ++i) {
    if (s[i - 1] == 'R') {
      numR++;
      huehue[numR] = vec[i];
    } else {
      numB++;
      adi[numB] = vec[i];
    }
  }
  sort(adi + 1, adi + 1 + numB);
  sort(huehue + 1, huehue + 1 + numR);
  long long indR = 1, indB = 1;
  bool flag = true;
  for (long long i = 1; i <= n; ++i) {
    bool flag1 = false, flag2 = false;
    while (indB <= numB) {
      if (adi[indB] >= i) {
        flag1 = true;
      }
      indB++;
      if (flag1) {
        break;
      }
    }
    if (!flag1) {
      while (indR <= numR) {
        if (huehue[indR] <= i) {
          flag2 = true;
        }
        indR++;
        if (flag2) {
          break;
        }
      }
    }
    if (!flag1 && !flag2) {
      flag = false;
      break;
    }
  }
  if (!flag) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    bkchodcf();
  }
  return 0;
}
