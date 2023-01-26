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
int multiply(long long x, long long res[], long long ressize) {
  long long carry = 0;
  for (int i = 0; i < ressize; i++) {
    int product = res[i] * x + carry;
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
  for (int i = 2; i <= n; i++) {
    ressize = multiply(i, res, ressize);
  }
  for (int i = ressize - 1; i >= 0; i--) {
    cout << res[i];
  }
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
bool issafe(vector<vector<int>> board, int row, int col) {
  for (int i = 0; i < col; i++) {
    if (board[row][i]) return false;
  }
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j] == 1) return false;
  }
  for (int i = row, j = col; i < n && j < n; i++, j++) {
    if (board[i][j] == 1) return false;
  }
  return true;
}
void display(vector<vector<int>> &board) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
bool solvenqueen(vector<vector<int>> &board, int col) {
  if (col >= n) {
    return true;
  }
  for (int i = 0; i < n; i++) {
    if (issafe(board, i, col)) {
      board[i][col] = 1;
      if (solvenqueen(board, col + 1)) return true;
      board[i][col] = 0;
    }
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  long long a[n];
  int b[n];
  int k;
  cin >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  if (n <= k) {
    cout << "YES" << endl;
  } else {
    vector<pair<long long, int>> v(n);
    for (int i = 0; i < n; i++) {
      v[i].first = a[i];
      v[i].second = i;
    }
    sort(v.begin(), v.end());
    long long count = 0;
    for (int i = 0; i < n - 1; i++) {
      if (v[i + 1].second != v[i].second + 1) {
        if (i == 0) {
          count++;
        } else {
          if (v[i - 1].second + 1 != v[i].second) {
            count++;
          }
        }
      }
    }
    if (v[n - 1].second != v[n - 2].second + 1) {
      count++;
    }
    if (count + 1 <= k) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
}
