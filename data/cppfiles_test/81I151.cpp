#include<bits/stdc++.h>

using namespace std;
#define ll long long
int isPrime(int n)
{	//返回1表示判断为质数，0为非质数，在此没有进行输入异常检测
    if(n==1)return false;
	float n_sqrt;
	if(n==2 || n==3) return 1;
	if(n%6!=1 && n%6!=5) return 0;
	n_sqrt=floor(sqrt((float)n));
	for(int i=5;i<=n_sqrt;i+=6)
	{
	    if(n%(i)==0 | n%(i+2)==0) return 0;
	}
        return 1;
}
int main()
{
int t;
cin>>t;
while(t--)
{
    int n,m;
    scanf("%d%d",&n,&m);
    char num[n+5];
    scanf("%s",num);
    int sum[n+5]={};
    sum[0]=0;
    for(int i=0;i<n;i++)
    {
        int k=-1;
        if(i%2==0)k=1;
        if(num[i]=='+')sum[i+1]=sum[i]+1*k;
        else sum[i+1]=sum[i]-1*k;
        printf("%d",sum[i+1]);
    }
    cout<<endl;
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=sum[r]-sum[l-1];
        if(ans<0)ans*=-1;
        if(ans!=0)
        {
            if(ans%2==0)ans=2;
            else ans=1;
        }
        printf("%d\n",ans);
    }
}
	return 0;
}
