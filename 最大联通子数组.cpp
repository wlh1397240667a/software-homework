#include<iostream>
#include<fstream>
using namespace std;

long Max(long n,long a[],long *smark,long *mmark)
{
    long b[100]={0};
    long sum1=0,max1=0,i;
    for(i=0;i<n;i++)
    {
        if(sum1<0)
        {
            sum1=a[i];
        }
        else
        {
            sum1=sum1+a[i];
        }
        b[i]=sum1;
    }
    max1=b[0];
    for(i=0;i<n;i++)
    {
        if (max1<b[i]) 
         {
             max1= b[i];
             *mmark = i;
         }
    }
     for (i = *mmark;i >= 0;i--) 
    {
        if (b[i] == a[i]) 
        {
             *smark = i;
             break;
        }
    }
     return max1;
}

int main()
{
    long m,n,i,j,t2,c[2];
    long sum,smark,mmark;
    long up[100],down[100],t[100];
    long a[100][100],b[100];
	ifstream infile;
    infile.open("input.txt", ios::in);
	  if(infile.is_open() == false)
	  {
         cerr << "open error!" << endl;
         exit(1);
	  }
    
    cout<<"二维数组的行数和列数：";
     for(i=0;i<2;i++) 
     {
	 infile >> c[i];
     
     }          //在显示器上顺序显示个数
	 m=c[0];
	 n=c[1];
	 cout<<m<<" "<<n<<endl;
    cout<<"数组为"<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            infile>>a[i][j];
			cout<<a[i][j]<<"   ";
        }
		if(j%n==0)
		{
			cout<<endl;
		}
    }
    //把二维数组按行分解为几个一维数组
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j]=a[i][j];
        }
        sum=Max(n,b,&smark,&mmark);
        up[i]=smark;                                    
        down[i]=mmark;
        t[i]=sum;

    }
    t2=t[0];
    for(i=0;i+1<m;i++)
    {
        if(up[i]<=down[i+1] && down[i]>=up[i+1])
        {
            t2+=t[i+1];
        }
         for(j=up[i];j<up[i+1];j++)
        {
            if(a[i+1][j]>0) t2+=a[i+1][j];                   //判别独立正数
        }

    }
	 cout<<"最大联通子数组和为";
     cout<<t2<<endl;
	 return 0;

}