#include<iostream>
using namespace std;
#define NUM 100
 int find(int arr[], int n)//找水王函数
 {
    int sw = 0; //
    int count=0;  //标记
    for(int i=0;i<n;i++)
    { 
        if(count == 0)//初始时，把数组第一个元素赋给sw
        { 
            sw = arr[i]; 
            count = 1; 
        } 
        else
        { 
            if(sw == arr[i]) //相等不消除
                count ++; 
            else  
                count --; 
        } 
    }

         return sw;
    }
int main()
{
	  int length=0;
      while (length==NULL||length == 0)//如果数组长度为空或零则请重新输入
      {
        cout<<"请输入ID数量：";
        cin>>length;
       }
       int arr[NUM];
       cout<<"输入作者id(不为0)："<<endl;
	   for(int i=0;i<=(length-1);i++)
	   {
		   cin>>arr[i];
		   if(arr[i]==0)
		   {
			   cout<<"id不为0，请重新输入：";
		   cin>>arr[i];
		   }

	   }

	   int ID=find(arr,length);
		cout<<"水军的ID是"<<ID<<endl;
		return 0;
}