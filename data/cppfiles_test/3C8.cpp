#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N, M, F, i, j, k, f, s, MI, MX, a, b, c, x, y, z, K, Z;
  string P, Q;
  cin >> P;
  N = P.length();
  a = N - 2;
  b = N - 1;
  s = 0;
  if (P[a] == 'X' && P[b] == 'X') {
    s = 0;
    if (P[0] != 'X') {
      s = 1;
    }
  } else if (P[a] == 'X') {
    s = 0;
    if (P[b] == '5') {
      s += 2;
    } else if (P[b] == '0') {
      s = 1;
      if (P[0] != 'X') {
        s++;
      }
    } else if (P[b] == '_') {
      s = 4;
      if (P[0] == 'X') {
        s--;
      }
    }
  } else if (P[b] == 'X') {
    s = 0;
    if (P[a] == '0' && P[0] != 'X') {
      s++;
    } else if (P[a] == '5' && P[0] != 'X') {
      s++;
    } else if (P[a] == '2') {
      s++;
    } else if (P[a] == '7') {
      s++;
    } else if (P[a] == '_') {
      s = 4;
      if (P[0] == 'X') {
        s -= 2;
      }
      if (a == 0) {
        s -= 1;
      }
    }
  } else if (P[a] == '_' && P[b] == '_') {
    s = 4;
    if (a == 0) {
      s--;
    }
  } else if (P[a] == '_') {
    s = 0;
    if (P[b] == '5') {
      s = 2;
    } else if (P[b] == '0') {
      s = 2;
      if (a == 0) {
        s--;
      }
    }
  } else if (P[b] == '_') {
    s = 0;
    if (P[a] == '5') {
      s = 1;
    } else if (P[a] == '0') {
      s = 1;
    } else if (P[a] == '2') {
      s = 1;
    } else if (P[a] == '7') {
      s = 1;
    }
  } else if ((P[a] == '0' && P[b] == '0') || (P[a] == '5' && P[b] == '0') ||
             (P[a] == '2' && P[b] == '5') || (P[a] == '7' && P[b] == '5')) {
    s = 1;
  }
  Z = 1;
  x = 0;
  for (i = 0; i < (N - 2); i++) {
    if (i == 0 && P[i] == '_') {
      Z = Z * 9;
    } else if (P[i] == '_') {
      Z = Z * 10;
    }
    if (P[i] == 'X') {
      x = 1;
    }
  }
  for (i = (N - 2); i < N; i++) {
    if (P[i] == 'X') {
      x = 2;
    }
  }
  if (x == 1) {
    if (P[0] != 'X') {
      Z = Z * 10;
    } else {
      Z = Z * 9;
    }
  }
  Z = Z * s;
  if (P == "0") {
    Z = 1;
  } else if (P[0] == '0') {
    Z = 0;
  } else if (P == "_" || P == "X")
    Z = 1;
  cout << Z << endl;
  return 0;
}
