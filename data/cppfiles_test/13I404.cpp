#include <bits/stdc++.h>
using namespace std;
const long long int infLL = 9222372036854775103;
const int inf = 2117483645;
const long long int mod = 1000000007;
long long int ceil(long long int a, long long int b) { return (a + b - 1) / b; }
long long int min(long long int a, long long int b) {
  if (a > b)
    return b;
  else
    return a;
}
bool bit_check(long long int a, int i) {
  if ((a & (1LL << i))) return 1;
  return 0;
}
long long int bit_toggle(long long int a, int i) { return (a ^ (1LL << i)); }
long long int bit_sum(long long int a, int i) { return a + (1LL << i); }
long long int bit_sub(long long int a, int i) { return a - (1LL << i); }
long long int mod_power(long long int x, long long int y) {
  long long int p = mod;
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int power_of(long long int a, int b) {
  if (a == 0) return -1;
  return 1 + power_of(a / b, b);
}
long long power(long long int a, long long int b) {
  if (a == 1) return 1;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void mycode();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  mycode();
  cerr << "Ended\n";
  return 0;
}
int arr[300][300];
int tryout(int i, int j) {
  int r = rand() % 26;
  while (!(r != arr[i][j - 1] && r != arr[i - 1][j] && r != arr[i + 1][j] &&
           r != arr[i + 1][j + 1] && r != arr[i - 1][j + 1] &&
           r != arr[i][j + 2])) {
    r = rand() % 26;
  }
  return r;
}
void mycode() {
  srand(time(0));
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, x, cnt;
    cin >> a >> b >> c;
    for (int i = 0; i <= a + 4; i++) {
      for (int j = 0; j <= b + 4; j++) {
        arr[i][j] = -1;
      }
    }
    if (a % 2 == 0) {
      if (c % 2 == 0 && c <= (b / 2) * a) {
        cout << "YES\n";
        cnt = 0;
        for (int i = 1; i <= a; i += 2) {
          if (cnt == c) break;
          for (int j = 1; j + 1 <= b; j += 2) {
            x = tryout(i, j);
            arr[i][j] = x;
            arr[i][j + 1] = x;
            x = tryout(i + 1, j);
            arr[i + 1][j] = x;
            arr[i + 1][j + 1] = x;
            cnt += 2;
            if (cnt == c) break;
          }
        }
        for (int i = 1; i <= a; i++) {
          for (int j = 1; j <= b; j++) {
            if (arr[i][j] == -1) {
              x = tryout(i, j);
              arr[i][j] = x;
              arr[i + 1][j] = x;
            }
          }
        }
        for (int i = 1; i <= a; i++) {
          for (int j = 1; j <= b; j++) {
            cout << char(arr[i][j] + 'a');
          }
          cout << '\n';
        }
      } else
        cout << "NO\n";
    } else {
      if (c >= b / 2 && (b / 2) % 2 == c % 2) {
        cout << "YES\n";
        cnt = b / 2;
        for (int i = 1; i + 1 <= b; i += 2) {
          x = tryout(1, i);
          arr[1][i] = x;
          arr[1][i + 1] = x;
        }
        for (int i = 2; i <= a; i += 2) {
          if (cnt == c) break;
          for (int j = 1; j + 1 <= b; j += 2) {
            x = tryout(i, j);
            arr[i][j] = x;
            arr[i][j + 1] = x;
            x = tryout(i + 1, j);
            arr[i + 1][j] = x;
            arr[i + 1][j + 1] = x;
            cnt += 2;
            if (cnt == c) break;
          }
        }
        for (int i = 1; i <= a; i++) {
          for (int j = 1; j <= b; j++) {
            if (arr[i][j] == -1) {
              x = tryout(i, j);
              arr[i][j] = x;
              arr[i + 1][j] = x;
            }
          }
        }
        for (int i = 1; i <= a; i++) {
          for (int j = 1; j <= b; j++) {
            cout << char(arr[i][j] + 'a');
          }
          cout << '\n';
        }
      } else
        cout << "NO\n";
    }
  }
}
