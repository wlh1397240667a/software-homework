/*2016.3.22 weilihua fengyutong*/
#include<iostream>
#include<iostream>
#include<time.h>
using namespace std;
#define NUM 100000
int DTGH_Sum(int a[],int n) //��̬�滮�����Ӷκͺ���
{
	int sum = 0;
	int *b = (int *) malloc(n * sizeof(int));	//��̬Ϊ�������ռ�
	b[0] = a[0];
	for(int i = 1; i < n; i++)
	{
		if(b[i-1] > 0)
			b[i] = b[i - 1] + a[i];
		else
			b[i] = a[i];
	}
	for(int j = 0; j < n; j++)
	{
		if(b[j] > sum)
			sum = b[j];
	}
	delete []b;		//�ͷ��ڴ�
	return sum;
}
int main()
{
	int length=0;
	 while (length==NULL||length == 0)//������鳤��Ϊ�ջ���������������
     {
	  cout<<"���������鳤�ȣ�";
      cin>>length;
     }
	int a[NUM];
	cout<<"��������Ԫ�أ�"<<endl;
	for(int i=0;i<=(length-1);i++)
	{
		cin>>a[i];
	}
	cout<<"����Ӷκͣ�";
	cout<<DTGH_Sum(a,length)<<endl;
	return 0;
	
}