/*2016.5.23 weilihua ��ˮ��(��)*/
#include<iostream>
using namespace std;
#define NUM 100
int main()
{
	  int length=0;
      while (length==NULL||length == 0)//������鳤��Ϊ�ջ���������������
      {
        cout<<"������ID������";
        cin>>length;
       }
       int arr[NUM];
       cout<<"��������id(��Ϊ0)��"<<endl;
	   for(int i=0;i<=(length-1);i++)
	   {
		   cin>>arr[i];
		   if(arr[i]==0)
		   {
			   cout<<"id��Ϊ0�����������룺";
		   cin>>arr[i];
		   }

	   }

    int sw [3]={0}; 
    int count[3] = {0};  //��Ǳ�Ϊ3��
	 bool flag = false;
    for(int i=0;i<length;i++)
    { 
			if(arr[i]==sw[0])  
            {  
                 count[0]++;  
            }  
            else if(arr[i]==sw[1])  
            {  
                 count[1]++;  
            }  
            else if(arr[i]==sw[2])  
            {  
                 count[2]++;  
            }  
            else if(count[0]==0)  
            {  
                 count[0]=1;  
                 sw[0]=arr[i];  
            }  
            else if(count[1]==0)  
            {  
                 count[1]=1;  
                 sw[1]=arr[i];  
            }  
            else if(count[2]==0)  
            {  
                 count[2]=1;  
                 sw[2]=arr[i];  
            }  
            else  
            {  
                 count[0]--;  
                 count[1]--;  
                 count[2]--;  
             }  

	}
	
		cout<<"ˮ��id��"<<endl;
		for(int i=0;i<3;i++)
		{
			cout<<sw[i]<<" ";
		}
    
		cout<<endl;
		return 0;
}