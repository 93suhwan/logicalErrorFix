
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
	#define _GLIBCXX_DEBUG
	#include "../../../debug.cpp"
#endif


int32_t main(){
	int n;
	cin >> n;
	int a[n], b[n][2];
	for(int i=0; i<n; i++)
		cin >> a[i];

	for(int i=0; i<n; i++){
		cin >> b[i][0];
		b[i][1] = b[i][0];
		b[i][0] += i;
	}

	int ans[n] = {0};

	int maxdist = n-1 - a[n-1];
	int prev = n-1;

	if(maxdist < 0){
		cout << "1\n";
		return 0;
	}

	int step = 1;
	ans[n-1] = -1;

	vector<int> aa;
	while(true){
		if(maxdist < 0){
			cout << step << "\n";
			aa.push_back(0);
			for(auto x: aa){
				cout << x << " ";
			}
			cout << "\n";
			return 0;
		}

		vector<pair<int, int>> v;
		for(int i=maxdist; i<prev; i++){
			v.push_back({b[i][0], i});
		}

		prev = maxdist;
		int p = -1;
		for(auto ind: v){
			if(ind.first-a[ind.first] < maxdist){
				p = ind.second + 1;
				maxdist = ind.first-a[ind.first];
			}
		}

		aa.push_back(p);

		if(prev == maxdist){
			cout << "-1\n";
			return 0;
		}
		step++;
	}
}
