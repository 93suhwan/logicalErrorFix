#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
int modo[43]={999999937,999999929,999999893,999999883,999999797,999999761,999999757,999999751,999999739,999999733,999999677,999999667,999999613,999999607,999999599,999999587,999999541,999999527,999999503,999999491,999999487,999999433,999999391,999999353,999999337,999999323,999999229,999999223,999999197,999999193,999999191,999999181,999999163,999999151,999999137,999999131,999999113,999999107};
string s,t;
long long mod,hsht,bs,CS,invpw[500003],inv,hshs[500003],pw[500003],lcp[500003];
vector<int>ans[3][33];
long long mypow(long long x,int y){
	long long ret=1;
	while(y){
		if(y&1)ret=ret*x%mod;
		y>>=1;x=x*x%mod;
	}return ret;
}
int HSH(int x,int len){
	return (hshs[x+len]-hshs[x]*pw[len]%mod+mod)%mod;
}
void calc(int nwidx){
	bs=10;
	inv=mypow(bs,mod-2);
	invpw[0]=1;pw[0]=1;
	for(int i=1;i<500003;i++){
		invpw[i]=invpw[i-1]*inv%mod;
		pw[i]=pw[i-1]*bs%mod;
	}hsht=0;
	for(register int i=0;i<t.size();i++)
		hsht=(hsht*bs+t[i]-'0')%mod;
	hshs[0]=0;
	for(register int i=0;i<s.size();i++)
		hshs[i+1]=(hshs[i]*bs+s[i]-'0')%mod; 
	for(register int i=0;i<=s.size()-t.size()+1;i++)
		if(i>=t.size()&&i+t.size()-1<=s.size())
			if((HSH(i,t.size()-1)+HSH(i-t.size()+1,t.size()-1))%mod==hsht){
				ans[0][nwidx].push_back(i-t.size()+1);
				ans[1][nwidx].push_back(i);
				ans[2][nwidx].push_back(i+t.size()-2);
			}
	for(register int i=0;i<=s.size()-t.size();i++){
		int sz=t.size()-lcp[i];
		if(i>=sz&&i+t.size()<=s.size())
			if((HSH(i,t.size())+HSH(i-sz,sz))%mod==hsht){
				ans[0][nwidx].push_back(i-sz);
				ans[1][nwidx].push_back(i);
				ans[2][nwidx].push_back(i+t.size()-1);
			}
		if(i+t.size()+sz<=s.size())
			if((HSH(i,t.size())+HSH(i+t.size(),sz))%mod==hsht){
				ans[0][nwidx].push_back(i);
				ans[1][nwidx].push_back(i+t.size());
				ans[2][nwidx].push_back(i+t.size()+sz-1);
			}
		sz--;
		if(i>=sz&&i+t.size()<=s.size())
			if((HSH(i,t.size())+HSH(i-sz,sz))%mod==hsht){
				ans[0][nwidx].push_back(i-sz);
				ans[1][nwidx].push_back(i);
				ans[2][nwidx].push_back(i+t.size()-1);
			}
		if(i+t.size()+sz<=s.size())
			if((HSH(i,t.size())+HSH(i+t.size(),sz))%mod==hsht){
				ans[0][nwidx].push_back(i);
				ans[1][nwidx].push_back(i+t.size());
				ans[2][nwidx].push_back(i+t.size()+sz-1);
			}
	}
}
bool check(int x,int y,int z){
	int cnt=0;
	for(int i=0;i<17;i++){
		bool ok=0;
		for(int j=0;j<ans[0][i].size();j++)
			if(ans[0][i][j]==x&&ans[1][i][j]==y&&ans[2][i][j]==z)
				ok=1;
		cnt+=ok;
	}
	return cnt>=15;
}
long long MOD=998244353;
long long Hsht[200003];
bool Check(int x,int len){
	if(x+len>s.size())return 0;
	return (hshs[x+len]-hshs[x]*pw[len]%MOD+MOD)%MOD==Hsht[len];
}
int main(){srand(time(NULL));
	cin>>s>>t;
	pw[0]=1;
	for(register int i=1;i<500003;i++)
		pw[i]=pw[i-1]*13%MOD;
	for(register int i=0;i<s.size();i++)
		hshs[i+1]=(hshs[i]*13+s[i]-'0')%MOD;
	for(register int i=0;i<t.size();i++)
		Hsht[i+1]=(Hsht[i]*13+t[i]-'0')%MOD;
	for(register int i=0;i<s.size();i++){
		int l=0,r=t.size(),mid;
		while(l!=r){
			mid=(l+r+1)/2;
			if(Check(i,mid))
				l=mid;
			else
				r=mid-1;
		}
		lcp[i]=l;
	}
	for(int i=0;i<17;i++){
		mod=modo[i];
		calc(i);
	}
	for(int j=0;j<17;j++)
		for(int i=0;i<ans[0][j].size();i++)
			if(check(ans[0][j][i],ans[1][j][i],ans[2][j][i])){
				cout<<ans[0][j][i]+1<<' '<<ans[1][j][i]<<endl;
				cout<<ans[1][j][i]+1<<' '<<ans[2][j][i]+1<<endl;
				return 0;
			}
}
