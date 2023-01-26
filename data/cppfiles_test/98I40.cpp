#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string ke,s;
        cin>>ke>>s;
        int len=s.size();
        int arr[len]={0};
        int m=0;
       // int len=max(ke.size(),s.size());
        for(int j=0;j<s.size();j++)
        {
            for(int l=0;j<ke.size();l++)
            {
                if(s[j]==ke[l])
                {
                    arr[m]=l+1;
                    //cout<<m<<" "<<arr[m]<<endl;
                    m++;
                    break;
                }

            }
        }
        int sum=0;
        for(int i=1;i<m;i++)
        {
            sum=sum+abs(arr[i]-arr[i-1]);
           // cout<<arr[i]<<"-"<<arr[i-1]<<"="<<abs(arr[i]-arr[i-1])<<endl;
        }
        cout<<sum<<endl;
    }
        //cin>>arr[i];

}

