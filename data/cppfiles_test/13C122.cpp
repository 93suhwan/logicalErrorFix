#include <bits/stdc++.h>
using namespace std;
bool GOOGLE = 0;
void Shrimad_Bhagavad_Gita() {
  long long int M = 0, N = 0, K = 0;
  cin >> N >> M >> K;
  vector<vector<char>> v(N, vector<char>(M, 'a'));
  long long int a = 0;
  for (long long int i = N - 1; i > 0; i -= 2) {
    for (long long int j = M - 1; j >= 0; j--) {
      if ((j + a) % 2 == 0) {
        v[i][j] = 'a';
        v[i - 1][j] = 'a';
      } else {
        v[i][j] = 'b';
        v[i - 1][j] = 'b';
      }
    }
    a++;
  }
  long long int b = K;
  if (N % 2 == 0 && M % 2 == 0) {
    if (K % 2 != 0) {
      cout << "NO\n";
    } else {
      for (long long int i = 0; i < N - 1 && b > 0; i += 2) {
        a = 0;
        for (long long int j = 0; j < M - 1 && b > 0; j += 2) {
          if ((a) % 2 == 0) {
            v[i][j] = 'c';
            v[i][j + 1] = 'c';
            v[i + 1][j] = 'd';
            v[i + 1][j + 1] = 'd';
          } else {
            v[i][j] = 'd';
            v[i][j + 1] = 'd';
            v[i + 1][j] = 'c';
            v[i + 1][j + 1] = 'c';
          }
          b -= 2;
          a++;
        }
      }
      cout << "YES\n";
      for (long long int i = 0; i < (long long int)N; i++) {
        for (long long int j = 0; j < (long long int)M; j++) {
          cout << v[i][j];
        }
        cout << "\n";
      }
    }
  } else if (M % 2 == 0) {
    if (K < M / 2 || (K - M / 2) % 2 != 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      a = 0;
      for (long long int j = 0; j < M - 1; j += 2) {
        if ((a + 1) % 2 != 0) {
          v[0][j] = v[0][j + 1] = 'c';
        } else {
          v[0][j] = v[0][j + 1] = 'd';
        }
        b--;
        a++;
      }
      for (long long int i = 1; i < N - 1 && b > 0; i += 2) {
        a = 0;
        for (long long int j = 0; j < M - 1 && b > 0; j += 2) {
          if ((a) % 2 != 0) {
            v[i][j] = 'c';
            v[i][j + 1] = 'c';
            v[i + 1][j] = 'd';
            v[i + 1][j + 1] = 'd';
          } else {
            v[i][j] = 'd';
            v[i][j + 1] = 'd';
            v[i + 1][j] = 'c';
            v[i + 1][j + 1] = 'c';
          }
          b -= 2;
          a++;
        }
      }
      for (long long int i = 0; i < (long long int)N; i++) {
        for (long long int j = 0; j < (long long int)M; j++) {
          cout << v[i][j];
        }
        cout << "\n";
      }
    }
  } else {
    if (K > (N * M) / 2 - N / 2 || K % 2 != 0) {
      cout << "NO\n";
    } else {
      for (long long int i = 0; i < N - 1 && b > 0; i += 2) {
        a = 0;
        for (long long int j = 0; j < M - 1 && b > 0; j += 2) {
          if ((a) % 2 == 0) {
            v[i][j] = 'c';
            v[i][j + 1] = 'c';
            v[i + 1][j] = 'd';
            v[i + 1][j + 1] = 'd';
          } else {
            v[i][j] = 'd';
            v[i][j + 1] = 'd';
            v[i + 1][j] = 'c';
            v[i + 1][j + 1] = 'c';
          }
          b -= 2;
          a++;
        }
      }
      cout << "YES\n";
      for (long long int i = 0; i < (long long int)N; i++) {
        for (long long int j = 0; j < (long long int)M; j++) {
          cout << v[i][j];
        }
        cout << "\n";
      }
    }
  }
}
int main() {
  if (!GOOGLE) {
  }
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int problem = 1;
  cin >> problem;
  while (problem--) {
    Shrimad_Bhagavad_Gita();
  }
  return 0;
}
