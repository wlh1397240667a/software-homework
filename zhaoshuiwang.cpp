#include<iostream>
using namespace std;
#define NUM 100
 int find(int arr[], int n)//��ˮ������
 {
    int sw = 0; //
    int count=0;  //���
    for(int i=0;i<n;i++)
    { 
        if(count == 0)//��ʼʱ���������һ��Ԫ�ظ���sw
        { 
            sw = arr[i]; 
            count = 1; 
        } 
        else
        { 
            if(sw == arr[i]) //��Ȳ�����
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

	   int ID=find(arr,length);
		cout<<"ˮ����ID��"<<ID<<endl;
		return 0;
}