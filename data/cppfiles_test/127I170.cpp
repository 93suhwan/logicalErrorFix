#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<time.h>
#include<set>
#include<cmath>
using namespace std;
#define rg register
#define ll long long
#define ull unsigned long long
#define lowbit(i) i&(-i)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define fr first
#define se second
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
const int maxn=8e6+10,mod=998244353;
int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
int del(int a,int b){return a-b<0?a-b+mod:a-b;}
int mul(int a,int b){return 1ll*a*b-1ll*a*b/mod*mod;}
int mi(int a,int b){
    int ans=1;
    while(b){
	if(b&1)ans=mul(ans,a);
	a=mul(a,a);b>>=1;
    }
    return ans;
}
int n,T,t[27];
char a[maxn],b[maxn];
int main(){
    read(T);
    while(T--){
	for(rg int i=0;i<26;i++)t[i]=0;
        scanf("%s",a+1),scanf("%s",b+1);
	n=strlen(a+1);
	for(rg int i=1;i<=n;i++)t[a[i]-'a']++;
	if(b[1]=='a'&&b[2]=='b'&&b[3]=='c'){
	    for(rg int i=1;i<=t[0];i++)printf("a");
	    for(rg int i=1;i<=t[2];i++)printf("c");
	    for(rg int i=1;i<=t[1];i++)printf("b");
	    for(rg int i=3;i<26;i++)
		for(rg int j=1;j<=t[i];j++)printf("%c",i+'a');
	}
	else {
	    for(rg int i=0;i<26;i++)
		for(rg int j=1;j<=t[i];j++)printf("%c",i+'a');
	}
	puts("");
    }
}
