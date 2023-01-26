#include<bits/stdc++.h>
typedef unsigned long long u64;
using namespace std;
int n,m;
u64 e[64];
void chk1(){
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			if(e[i]>>j&1)
				for(int k=j+1;k<n;++k)
					if((e[i]>>k&1)&&(e[j]>>k&1))
						for(int l=k+1;l<n;++l)
							if((e[i]>>l&1)&&(e[j]>>l&1)&&(e[k]>>l&1)){
								u64 S=e[i]&e[j]&e[k]&e[l];
								if(S){
									cout<<i+1<<' '<<j+1<<' '<<k+1<<' '<<l+1<<' '<<__lg(S)+1<<'\n';
									exit(0);
								}
							}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m,n=min(n,64);
	for(int u,v;m--;){
		cin>>u>>v,--u,--v;
		if(u>=64||v>=64)continue;
		e[u]|=1uLL<<v;
		e[v]|=1uLL<<u;
	}
	chk1();
	for(int i=0;i<n;++i)
		e[i]^=(1<<n)-1;
	chk1();
	cout<<"-1\n";
	return 0;
}