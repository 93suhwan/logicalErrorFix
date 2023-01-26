#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &B, int &M, vector<vector<int>> &S, vector<int> &X,
         vector<int> &Y, vector<int> &C, int CS, int p) {
  int N = B.size();
  if (p == N) {
    if (C.size() == M) {
      if (S[CS].empty()) {
        S[CS] = C;
      } else {
        X = C;
        Y = S[CS];
      }
    }
  } else {
    dfs(B, M, S, X, Y, C, CS, p + 1);
    if (!X.empty()) {
      return;
    }
    C.push_back(p);
    dfs(B, M, S, X, Y, C, CS + B[p], p + 1);
    C.pop_back();
  }
}
int main() {
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  if (N == 2) {
    if (B[0] == B[1]) {
      cout << "YES" << endl;
      cout << B[0] << ' ' << 0 << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (N == 3) {
    if (B[0] == B[1]) {
      cout << "YES" << endl;
      cout << 0 << ' ' << B[0] << ' ' << B[2] << endl;
    } else if (B[1] == B[2]) {
      cout << "YES" << endl;
      cout << 0 << ' ' << B[1] << ' ' << B[0] << endl;
    } else if (B[2] == B[0]) {
      cout << "YES" << endl;
      cout << 0 << ' ' << B[2] << ' ' << B[1] << endl;
    } else if ((B[0] + B[1] + B[2]) % 2 == 0) {
      int S = (B[0] + B[1] + B[2]) / 2;
      cout << "YES" << endl;
      cout << S - B[0] << ' ' << S - B[1] << ' ' << S - B[2] << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    int p = -1;
    for (int i = 0; i < N; i++) {
      if (B[i] % 2 == 0) {
        p = i;
      }
    }
    if (p != -1) {
      vector<int> X;
      for (int i = 0; i < N; i++) {
        if (i != p) {
          X.push_back(i);
          if (X.size() == 3) {
            break;
          }
        }
      }
      int a = -1, b = -1;
      for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
          if (B[X[i]] % 2 == B[X[j]] % 2) {
            a = X[i];
            b = X[j];
          }
        }
      }
      int S = (B[p] + B[a] + B[b]) / 2;
      vector<int> A;
      A.push_back(S - B[p]);
      A.push_back(S - B[a]);
      A.push_back(S - B[b]);
      for (int i = 0; i < N; i++) {
        if (i != p && i != a && i != b) {
          A.push_back(B[i] - (S - B[p]));
        }
      }
      cout << "YES" << endl;
      for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i < N - 1) {
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      if (N <= 26) {
        vector<int> X, Y;
        int M = min(N / 2, 13);
        vector<vector<int>> S(M * 1000000 + 1);
        vector<int> C;
        dfs(B, M, S, X, Y, C, 0, 0);
        if (X.empty() && Y.empty()) {
          cout << "NO" << endl;
        } else {
          set<int> stX, stY;
          for (int i = 0; i < M; i++) {
            stX.insert(X[i]);
            stY.insert(Y[i]);
          }
          vector<int> X2, Y2;
          for (int i = 0; i < M; i++) {
            if (stY.count(X[i]) == 0) {
              X2.push_back(X[i]);
            }
            if (stX.count(Y[i]) == 0) {
              Y2.push_back(Y[i]);
            }
          }
          int cnt = X2.size();
          vector<int> B2;
          for (int i = 0; i < cnt; i++) {
            B2.push_back(B[X2[i]]);
            B2.push_back(B[Y2[i]]);
          }
          vector<int> A;
          A.push_back(0);
          for (int i = 0; i < cnt * 2 - 1; i++) {
            A.push_back(B2[i] - A.back());
          }
          vector<bool> used(N, false);
          for (int i = 0; i < cnt; i++) {
            used[X2[i]] = true;
            used[Y2[i]] = true;
          }
          for (int i = 0; i < N; i++) {
            if (!used[i]) {
              A.push_back(B[i]);
            }
          }
          cout << "YES" << endl;
          for (int i = 0; i < N; i++) {
            cout << A[i];
            if (i < N - 1) {
              cout << ' ';
            }
          }
          cout << endl;
        }
      }
    }
  }
}
