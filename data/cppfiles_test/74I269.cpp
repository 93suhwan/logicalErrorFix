#include <bits/stdc++.h>
using namespace std;
void debugs() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long multiply(long long x, long long res[], long long ressize) {
  long long carry = 0;
  for (long long i = 0; i < ressize; i++) {
    long long product = res[i] * x + carry;
    res[i] = product % 10;
    carry = product / 10;
  }
  while (carry) {
    res[ressize] = carry % 10;
    carry = carry / 10;
    ressize++;
  }
  return ressize;
}
void bigfactorial(long long n) {
  long long ressize = 1;
  long long res[10000];
  res[0] = 1;
  for (long long i = 2; i <= n; i++) {
    ressize = multiply(i, res, ressize);
  }
  for (long long i = ressize - 1; i >= 0; i--) {
    cout << res[i];
  }
}
bool substring(string s1, string s2) {
  int M = s1.length();
  int N = s2.length();
  for (int i = 0; i <= N - M; i++) {
    int j;
    for (j = 0; j < M; j++)
      if (s2[i + j] != s1[j]) break;
    if (j == M) return true;
    ;
  }
  return false;
  ;
}
long long n;
bool palindrome(string s) {
  string t;
  t = s;
  reverse(t.begin(), t.end());
  if (s == t) {
    return true;
  }
  return false;
}
bool issafe(vector<vector<long long>> board, long long row, long long col) {
  for (long long i = 0; i < col; i++) {
    if (board[row][i]) return false;
  }
  for (long long i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 1) return false;
  }
  for (long long i = row, j = col; i < n && j < n; i++, j++) {
    if (board[i][j] == 1) return false;
  }
  return true;
}
void display(vector<vector<long long>> &board) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
bool solvenqueen(vector<vector<long long>> &board, long long col) {
  if (col >= n) {
    return true;
  }
  for (long long i = 0; i < n; i++) {
    if (issafe(board, i, col)) {
      board[i][col] = 1;
      if (solvenqueen(board, col + 1)) return true;
      board[i][col] = 0;
    }
  }
  return false;
}
int convertstring(string s) {
  stringstream geek(s);
  int x = 0;
  geek >> x;
  return x;
}
bool binary(long long k, long long a[]) {
  long long l = 1;
  long long r = 1e4;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (a[mid] == (k)) {
      return true;
    } else if (a[mid] > (k)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return false;
}
bool notprime(int n) {
  if (n == 2 || n == 3 || n == 5 || n == 7) {
    return false;
  }
  return true;
}
int bin(string n) {
  int num = convertstring(n);
  int dec_value = 0;
  int base = 1;
  int temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;
    dec_value += last_digit * base;
    base = base * 2;
  }
  return dec_value;
}
bool sorted(int a[], int n) {
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] > a[i + 1]) {
      return false;
    }
  }
  return true;
}
int main() {
  long long a, b;
  cin >> a >> b;
  string s = "";
  string t = "";
  for (int i = 0; i < a + b; i++) {
    if (i % 2 == 0) {
      s += 'A';
    } else {
      s += 'B';
    }
  }
  for (int i = 0; i < a + b; i++) {
    if (i % 2 == 0) {
      t += 'B';
    } else {
      t += 'A';
    }
  }
  string f = "";
  int x = 0;
  int c = 0;
  if (b > a) {
    int h = a + b;
    for (int i = 0; i < h; i++) {
      if (a > 0 && i % 2 == 0) {
        f += 'A';
      } else {
        f += 'B';
      }
    }
    for (int i = 0; i < h; i++) {
      if (s[i] != f[i]) c++;
    }
    for (int i = 0; i < h; i++) {
      if (t[i] != f[i]) x++;
    }
    int g = min(x, c);
    int z = max(x, c);
    if (h % 2 == 0) {
      for (int i = g; i <= z; i += 2) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      for (int i = g; i <= z; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
  } else {
    int h = a + b;
    for (int i = 0; i < h; i++) {
      if (a > 0 && i % 2 == 0) {
        f += 'B';
      } else {
        f += 'A';
      }
    }
    for (int i = 0; i < h; i++) {
      if (s[i] != f[i]) c++;
    }
    for (int i = 0; i < h; i++) {
      if (t[i] != f[i]) x++;
    }
    int g = min(x, c);
    int z = max(x, c);
    if (h % 2 == 0) {
      for (int i = g; i <= z; i += 2) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      for (int i = g; i <= z; i++) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
}
}
