#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
constexpr int M = sqrt(N);
int n, m, k;
int sum[M + 10][M + 10];
int x[N], y[N], t[N];
int del[N], sdel;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= m; i++){
		int op, k, val;
		cin >> op >> k;
		if(op == 1) val = 1, t[k] = i;
		else val = -1;
		int xy = x[k] + y[k];
		if(xy > M){
			for(int j = t[k]; ; j += x[k] + y[k]){
				if(j + x[k] > n) break;
				del[j + x[k]] += val;
				if(j + x[k] + y[k] > n) break;
				del[j + x[k] + y[k]] -= val;
			}
		}
		else{
			for(int j = x[k]; j < xy; j++){
				sum[xy][(j + t[k]) % xy] += val;
			}
		}
		sdel += del[i];
		int ans = sdel;
		for(int V = 1; V <= M; V++){
			ans += sum[V][i % V];
		}
		cout << ans << "\n";
	}
	return 0;
}