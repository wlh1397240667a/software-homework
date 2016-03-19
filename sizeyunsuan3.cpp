#include<iostream>
#include<ctime>
#include<stack>
#include<fstream>
#define length 10000//��Ŵ����鳤��
using namespace std;
typedef long long ll;
ofstream fout("equation.txt");
char Op[] = {'+', '-', '*', '/'};
int rights;//������Ŀ
int wrong;//������Ŀ

struct num{
    ll numerator, denominator;
    num(){numerator = 0; denominator = 1;}
    num(int n) {numerator = n; denominator = 1;}
    num(int n,int d) {numerator = n; denominator = d;}
    
    void operator = (num x)
    {
        numerator = x.numerator;
        denominator = x.denominator;
    }
};
#define maxl 1005
char nifix[maxl], post[maxl];
char ans[maxl];
int cnt_right, cnt_wrong;
bool error;
num res, rst;

//****������***//
	class fraction
	{
	 private:
		int above;         //����
		int below;         //��ĸ
		void reduction();            //Լ��
		fraction makeCommond(fraction); //ͨ��
 
	public:
		fraction()
		{             //���캯��
		}
	   fraction add(fraction);      //���������
	   fraction sub(fraction);      //���������
	   fraction mul(fraction);      //���������
	   fraction div(fraction);      //���������
	   int display(int,int);              //��ʾ����
	   void setvalue(int ,int);                //�洢����
	};

//***********������Լ��*********//

	  void fraction::reduction()
	  {
		int i,comdiv,small,max;
		if(above<below)
		{
		  small=above;
		  max=below;
		 }
		else
		{
		  small=below;
		  max=above;
		}
	   for(i=small;i>1;i--)
	   {
		  if((small%i==0 )&(max%i==0) )
		  break;
	   }
		 comdiv=i;            //���Լ��

		  if(i!=0)
		  {
			  above/=i;
			  below/=i;
		   }
	}

 //*************������ͨ��*************//

	fraction fraction::makeCommond(fraction frac)
	{
	   int b1=below,b2=frac.below, m,s;
	   if(b1>b2)
	   {
		m=b1%b2;
		s=b2;
	   }
		else
		{
		  m=b2%b1;
		  s=b1;
		}
	   while(m>0)
	   {
		 int res=s%m;
		  s=m,m=res;
	   }
	   int small=(b1*b2)/s;
	   above=above*(small/below);
	   frac.above=frac.above*(small/frac.below);
	   below=small;
	   frac.below=small;
	   return frac;
	}
   //***************���������*************//

	fraction fraction::add(fraction fr)
	{
		  fraction myFraction;
		  myFraction.above=above*fr.below+fr.above*below;
		  myFraction.below=below*fr.below;
		  myFraction.reduction();
		  return myFraction;
	}
//*********************���������***************//

	 fraction fraction::sub(fraction fr)
	 {
		   fraction myFraction;
		   myFraction.above=above*fr.below-fr.above*below;
		   myFraction.below=below*fr.below;
		   myFraction.reduction();
		   return myFraction;
	}

  //*******************���������****************//

	fraction fraction::mul(fraction fr)
	{ 
		  fraction myFraction;
		  myFraction.above=above*fr.above;
		  myFraction.below=below*fr.below;
		  myFraction.reduction();
		  return myFraction;
	} 
//******************���������***********//

	fraction fraction::div(fraction fr)
	{
		fraction myFraction; 
		myFraction.above=above*fr.below;
		myFraction.below=below*fr.above;
		myFraction.reduction();
		return myFraction;
	}

 //*********************�����𰸵������ж�*************//

	int fraction::display(int a,int b)
	{
    
		if((a==above)&&(b==below))
		{
			cout<<"��ȷ"<<endl;
			rights=rights+1;
		}
		else
		{
			cout<<"����"<<endl;
			wrong=wrong+1;
		}
		return rights,wrong;
	} 

  //*******************�����ĸ�ֵ****************//

	 void fraction::setvalue(int sj1,int sj3)           
	 { 
		above=sj1;
		below=sj3;
	}
//*************�޷��������������ж�****************//
	
	 int answer(int a[],int i)
	{
		int ans;
		
		cout<<"�������:"<<endl;
		cin>>ans;
	      if(ans==a[i]) 
          {
		      cout<<"��ȷ"<<endl;
			  rights=rights+1;
		    }
		  else
		  {
			  cout<<"����"<<endl;
			  wrong=wrong+1;
		  }
		  return rights,wrong;
     
	}
 //*************�޷��������������ж�****************//
	int answer_1(int a[],int i,int b[])
	{
		int ans,yushu;
		
		cout<<"��������:"<<endl;
		cin>>ans;
		cout<<"��������"<<endl;
		cin>>yushu;
	      if((ans==a[i])&&(yushu=b[i])) 
          {
		      cout<<"��ȷ"<<endl;
			   rights=rights+1;
		    }
		  else
		  {
			  cout<<"����"<<endl;
			  wrong=wrong+1;
		  }
		  return rights,wrong;
     
	}
 //*************����������ʽ��****************//
	void create(int maxn)
	{
		
		if(!fout)                        //�����ʧ�ܣ�outfile����ֵ
		{
          cerr << "open error!" << endl;
         exit(1);
        }

    //�������������ʽ�в������ĸ������������������1 
    int lengt;//ʽ�ӳ���
    do{
        lengt = rand()%8;
    }while(lengt < 2);
    bool div = false;                        //������ֹ���ֳ�0���� 
    int brack_cnt = 0;                        //��¼δƥ��������Ÿ��� 
    ll num, op;
    for (int i = 1; i < lengt; i++)        //ѭ��������ʽ 
    {
        if (div)                            //����ʱ��Ҫ���ɵ�����ǰ�ĸ�����'/'������Ҫ���д˴����ɵ����ֲ���Ϊ0 
        {
            div = false;
            do{
                num = rand()%maxn;
            }while(num == 0);
			cout<< num;
			fout<< num;
			
        }
        else
		{
			num= rand()%maxn;
			fout <<num;
			cout<<num;
		}//����ֱ������������� 
        int tmpcnt = brack_cnt;
        for (int j = 0; j < tmpcnt; j++)    //����ǰ��δƥ��������ţ����ÿһ��δƥ��������ţ�����һ������������Ӧ�����š�    
        {
            if ((rand()%5) > 2)                //���������Ÿ���Ϊ0.6
            {
                brack_cnt--;
				
				fout << ")";
				cout<<")";
            }
        }
        
        op = rand()%4;                        //��������� 
		fout << Op[op];
		cout << Op[op];
        if (op == 3)                        //�������˳��ţ�����Ҫ����Ӧ��־λ 
            div = true;
        
        if (!(rand()%3))                    //��һ���������������ţ�����Ϊ1/3 
        {
			fout << "(";
			cout<<"(";
            brack_cnt++;
			num= rand()%maxn;//���������ź��������һ�����ֺ����������Ȼ���ܳ���(15)�����Ĵ��� 
			fout <<num;
			cout<<num;
            op = rand()%4;
			fout << Op[op];
			cout<<Op[op];
            if (op == 3)
                div = true;
        }
    }
    if (div)                                //�������һ�����֣������ֺ���Ҫ������� 
    {
        div = false;
        do{
            num = rand()%maxn;
        }while(num == 0);
		fout << num;
		cout<< num;	
    }
    else
	{
		num=rand()%maxn;
	    fout << num;
		cout<<num;
		
	}
    while(brack_cnt--)              //��ȫ������ 
	{
		fout << ")";
		cout << ")";
	}
	    cout<<"=";
	    fout<< endl;
		cout<<endl;
		
}
	bool isNum(char x)            //�ж��Ƿ�������
{
    return (x >= '0' && x <= '9');
}

bool isOp(char x)             //�ж��Ƿ��ǲ�����
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')');
}

int priority(char x)          //����һ�������������ȼ�
{
    if (x == '-' || x == '+')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '(')
        return 0;
    else
        return -1;
}
bool nifix_to_post()
{
    memset(post, 0, sizeof(post));
    stack<char> s;                                //������ջ������ѹ������ 
/*    ************************************************************************************************
#    ���ڲ������Ƕ�λ�ģ�����������λ��һ���ۼ��ݴ�Ĺ�����������������ʱ������˲�����ǰ�����ݴ���ϣ� 
#    ��Ҫ������ջ����Ҳ�������в�����ǰ���в���������'*('�ȣ�����������Ҫһ����־λ����ʾĳ��������ǰ
#    �Ƿ���й��ݴ�������Ĵ��� 
*///************************************************************************************************** 
    bool havenum = false;                        
    int tmp = 0, pos = 0;                        //tmpΪ�ݴ��λ���ı�����posΪ��׺����洢λ�� 
    for (int i = 0; nifix[i] != '\0'; i++)        //ѭ��������׺���� 
    {
        if (isNum(nifix[i]))                     //����ǰ�ַ������֣�������ݴ����������ʶ���в����� 
        {
            havenum = true;
            tmp = tmp*10 + (nifix[i]-'0');
        }
        else if (isOp(nifix[i]))                //����ǰ�ַ��ǲ�������������²��� 
        {
            //��׺���ʽ�Ϸ����жϣ��ж��Ƿ������������ַ������������������� 
            if (isOp(nifix[i-1]) && nifix[i-1] != ')' && nifix[i] != '(') 
                return true; 
            //���������ǰ�в��������򽫵õ��Ĳ������������׺���ʽ 
            if (havenum)
            {
                havenum = false;
                post[pos++] = tmp + '0';
                tmp = 0;
            }
            //���������Ϊ�����ţ��򰴹�����г�ջ���׺���ʽ�Ȳ��� 
            if (nifix[i] == ')')
            {
                if (s.empty())                    //��׺���ʽ�Ϸ����жϣ��ж�����ƥ�� 
                    return true;
                while(s.top() != '(')
                {
                    post[pos++] = s.top();
                    s.pop();
                    if (s.empty())                //��׺���ʽ�Ϸ����жϣ��ж�����ƥ�� 
                        return true;
                }
                s.pop();
            }
            else if (nifix[i] == '(')            //�������������ֱ����ջ 
                s.push(nifix[i]);
            else                                //�����+-*/�򰴹������ 
            {
                while (!s.empty() && priority(nifix[i]) <= priority(s.top()))
                {
                    post[pos++] = s.top();
                    s.pop();
                }
                s.push(nifix[i]);
            }
        }
        else                                    //��׺���ʽ�Ϸ����жϣ��ж��Ƿ񺬷Ƿ����� 
            return true;
	}
    //���в������������������׺���ʽ 
    if (havenum)
    {
        havenum = false;
        post[pos++] = tmp + '0';
        tmp = 0;
    }
    //��ջ�в�����һ���������׺���ʽ�� 
    while(!s.empty())
    {
        if (s.top() == '(')                        //��׺���ʽ�Ϸ����жϣ��ж�����ƥ�� 
            return true;
        post[pos++] = s.top();
        s.pop(); 
    }
    return false;
}
ll gcd(ll m, ll n)
{
    ll    tmp;
    tmp = m % n;
    while(tmp)
    {
        m = n;
        n = tmp;
        tmp = m % n;
    }
    return n;
}
bool cal_result()
{
    stack<num> s;                                //������Ų�������ջ 
    for (int i = 0; i < (strlen(post)); i++)        //ѭ��������׺���ʽ 
    {
        if (!isOp(post[i]))                        //�����������ֱ����ջ 
        {
            num tmp(post[i]-'0', 1);
            s.push(tmp);
        }
        else
        {
            //ȡ������������������������������������������ 
            if (s.empty())
                return true;
            num b = s.top(); s.pop();
            if (s.empty())
                return true;
            num a = s.top(); s.pop();
            num c;

            if (post[i] == '+')                    //��������'+'������������������ 
            {
                c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
                c.denominator = a.denominator * b.denominator;
            }
            else if (post[i] == '-')            //��������'-'������������������
            {
                c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
                c.denominator = a.denominator * b.denominator;
            }
            else if (post[i] == '*')            //��������'*'������������������ 
            {
                c.numerator = a.numerator * b.numerator;
                c.denominator = a.denominator * b.denominator;
            }
            else if (post[i] == '/')            //��������'/'������������������ 
            {
                if (b.numerator == 0)            //���������0������ֳ������󣬷��� 
                    return true;
                c.numerator = a.numerator * b.denominator;
                c.denominator = a.denominator * b.numerator;
            }
            else                                //������������ 
                return true;
            if (c.numerator != 0)                //�������Ϊ0����Է��ӷ�ĸԼ�� 
            {
                ll div = gcd(c.denominator, c.numerator);
                c.denominator /= div;
                c.numerator /= div;
            }
            s.push(c);                            //��Լ�ֺ�����ջ 
        }
    }
    if (s.size() > 1)                            //������в�������������Ӧ��������ջ�ڻ��ж��Ԫ�أ���˵���������� 
        return true;
    res = s.top();                                //������ 
    s.pop();
    if (res.denominator < 0)                    //������������ĸ�ĸ����Ƶ������� 
    {
        res.numerator = -res.numerator;
        res.denominator = -res.denominator;
    }
    return false;    
}

bool trans_ans()
{
    int i = 0;
    ll tmp = 0;
    //������־λ�ֱ��־�û�����ķ��ӷ�ĸ�Ƿ�Ϊ���� 
    bool num_flag = false, deno_flag = false;
    //���жϷ����Ƿ�Ϊ�� 
    if (ans[i] == '-')
    {
        num_flag = true;
        i++;
    }
    //���յ�һ������ 
    while(isNum(ans[i]))
    {
        tmp = tmp * 10 + (ans[i] - '0');
        i++;
    }
    //����һ����Ϊ��������ת������������ȡ�� 
    if (num_flag)
        tmp = -tmp;
    //������� 
    rst.numerator = tmp;
    //��ĸ����ֵΪ1 
    rst.denominator = 1;
    tmp = 0;
    //�ж��Ƿ��Ƿ��� 
    if (ans[i] == '/')
    {
        //�жϷ�ĸ�Ƿ�Ϊ���� 
        if (ans[++i] == '-')
        {
            deno_flag = true;
            i++;
        }
        //���յڶ����� 
        while(isNum(ans[i]))
        {
            tmp = tmp * 10 + (ans[i] - '0');
            i++;
        }
        //���ڶ�����Ϊ��������ת������������ȡ��
        if (deno_flag)
            tmp = -tmp;
        //�����ĸ 
        rst.denominator = tmp;
    }
    //����ĸΪ0�����û�����Ľ���ǷǷ��� 
    if (rst.denominator == 0)
        return true;
    //����ʱû�б������е��ַ�����˵�������ǷǷ��� 
    if (i != strlen(ans))
        return true;
    //�����ĸ�ĸ��ţ������������� 
    if (rst.denominator < 0)
    {
        rst.numerator = -rst.numerator;
        rst.denominator = -rst.denominator;
    }
    //���û�����ķ��ӷ�ĸ���Ǹ��������û����벻���Ϲ淶������ȡ��ĸΪ0����Ϊ�����������ܳ��ַ�ĸΪ0��״������־��������ķ��� 
    if (num_flag && deno_flag)
        rst.denominator = 0;
    return false;
}


int main()
{
	fraction frac,frac2;
	int sj1,sj2,sf=1,sj3,sj4,r,j=1;//��������������
	int above,below;
	int Num;//�������
	int numchose;//������ѡ��
	char sfchose;//���ѡ��
	char yschose;//����ѡ��
	char jf;//�������ѡ��
	int qznum;//ȡֵ��Χ
	int ans_2[length];//�����ȷ�Ĵ�
	int ans_4[length]={0};//�����ȷ������
	srand((unsigned)time(NULL)); //srand������������ϵͳʱ����Ϊʱ�����Ӳ��������
	cout<<"*****��ӭʹ���Զ�����ϵͳ*****"<<endl;
	cout<<"����������ݽ��г�ʼ�����ã�"<<endl;
	cout<<"��ѡ����������1.���������� 2.�����������"<<endl;
	cin>>numchose;
	if(numchose==1)
	{
		cout<<"�������ӡ������"<<endl;
	cin>>Num;
	cout<<"��ѡ���Ƿ��г˳���?��y/n��"<<endl;
	cin>>sfchose;
	cout<<"������һ��ֵȷ����ʽ����ֵȡֵ��Χ��"<<endl;
    cin>>qznum;
	cout<<"��������г��ָ����𣿣�y/n��";
    cin>>jf;

	if(sfchose=='y')
	{
		cout<<"��ѡ�������������?��y/n��"<<endl;
		cin>>yschose;
	}
		cout<<"********************************"<<endl;

	for(int i=0;i<Num;i++)
	{
            sj1=rand()%qznum;
			sj2=rand()%qznum;
			sj3=rand()%qznum;
			sj4=rand()%qznum;
			if(sfchose=='n')//�޳˳���
			{
			     sf=rand()%4; 		
			}
			if(sfchose=='y')//�г˳���
			{
				  sf=rand()%8; 
			}
			switch(sf)
				{		
					 case 0:
                       cout<<sj1<<"+"<<sj2<<"=     "<<endl;
					   ans_2[i]=sj1+sj2;
					   answer(ans_2,i);

                     break;
                    case 1:
                       if(jf=='n')//�޸���
					   {
						   if(sj1<sj2)
						   {
							  cout<<sj2<<"-"<<sj1<<"=    "<<endl;
							  ans_2[i]=sj2-sj1;
							  answer(ans_2,i);
						
						   }
						   else
						   {
							   cout<<sj1<<"-"<<sj2<<"=    "<<endl;
							   ans_2[i]=sj1-sj2;
							   answer(ans_2,i);
						   }
					    }
					   else
					   {
						    cout<<sj1<<"-"<<sj2<<"=    "<<endl;
							ans_2[i]=sj1-sj2;
							answer(ans_2,i);
						
					   } 
					   break;
				  case 2:
					   if(sj1>sj3)
					   {
						   r=sj1;
						   sj1=sj3;
						   sj3=r;
					   }
                       if(sj2>sj4)
					   {
						   r=sj2;
						   sj2=sj4;
						   sj4=r;
					   }
                     cout<<"("<<sj1<<"/"<<sj3<<")"<<"+"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
					 frac.setvalue(sj1,sj3);
					 frac2.setvalue(sj2,sj4);
					 cout<<"������Ӻͷ�ĸ���ÿո����������������";
					 cin>>above>>below;
					 frac.add(frac2).display(above,below); 

					break;
				  case 3:
					    if(sj1>sj3)
						{
							r=sj1;
							sj1=sj3;
							sj3=r;
						}
                        if(sj2>sj4)
						{
							r=sj2;
							sj2=sj4;
							sj4=r;
						}
						if(jf=='n')//��������޸���
						{
							if((sj1/sj3)<(sj2/sj4))
							{ 
								cout<<"("<<sj2<<"/"<<sj4<<")"<<"-"<<"("<<sj1<<"/"<<sj3<<")=     "<<endl;
								frac.setvalue(sj2,sj4);
					            frac2.setvalue(sj1,sj3);
					            cout<<"������Ӻͷ�ĸ���ÿո����������������";
					            cin>>above>>below;
					            frac.sub(frac2).display(above,below); 

							}
							else
							{
								cout<<"("<<sj1<<"/"<<sj3<<")"<<"-"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
								frac.setvalue(sj1,sj3);
					            frac2.setvalue(sj2,sj4);
					            cout<<"������Ӻͷ�ĸ���ÿո����������������";
					            cin>>above>>below;
					            frac.sub(frac2).display(above,below); 
							}
						}
						 else
						 {
							    cout<<"("<<sj1<<"/"<<sj3<<")"<<"-"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
							    frac.setvalue(sj1,sj3);
					            frac2.setvalue(sj2,sj4);
					            cout<<"������Ӻͷ�ĸ���ÿո����������������";
					            cin>>above>>below;
					            frac.sub(frac2).display(above,below); 
						 }
					   break;
                   case 4:
                      cout<<sj1<<"*"<<sj2<<"="<<endl;
					  ans_2[i]=sj1*sj2;
					  answer(ans_2,i);
                    break;
                   case 5:
					   if(sj2==0)//��ĸΪ���򲻼�������
					   {
						   i=i-1;
						
					   }
					   else if(yschose=='n')//����û������
					   {
						   if(sj1%sj2==0)
						   {
							   cout<<sj1<<"/"<<sj2<<"="<<endl;
							   ans_2[i]=sj1/sj2;
							   answer(ans_2,i);

						
						   }
						   else 
						   {
							   i=i-1;
							 
						   }
					   }
					   else if(yschose=='y')//����������
					   {
						     if(sj1%sj2!=0)
						   {
							   cout<<sj1<<"/"<<sj2<<"="<<endl;
							   ans_2[i]=sj1/sj2;
							   ans_4[i]=sj1-sj2*ans_2[i];
							   answer_1(ans_2,i,ans_4);
					
						   }
						   else 
						   {
							   i=i-1;
						
						   }

					   }
					   break;
				   case 6:
					if(sj1>sj3)
					{
						r=sj1;
						sj1=sj3;
						sj3=r;
					}
                    if(sj2>sj4)
					{
						r=sj2;
						sj2=sj4;
						sj4=r;
					}
                     cout<<"("<<sj1<<"/"<<sj3<<")"<<"*"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
					 frac.setvalue(sj1,sj3);
					 frac2.setvalue(sj2,sj4);
					 cout<<"������Ӻͷ�ĸ���ÿո����������������";
					 cin>>above>>below;
					 frac.mul(frac2).display(above,below); 
					   break;
				   case 7:
					   if(sj1>sj3)
					   {
						   r=sj1;
						   sj1=sj3;
						   sj3=r;
					   }
                     if(sj2>sj4)
					 {
						r=sj2;
						sj2=sj4;
						sj4=r;
					 }
					   cout<<"("<<sj1<<"/"<<sj3<<")"<<"/"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
					   frac.setvalue(sj1,sj3);
					   frac2.setvalue(sj2,sj4);
					   cout<<"������Ӻͷ�ĸ���ÿո����������������";
					   cin>>above>>below;
					   frac.div(frac2).display(above,below); 
					   break;
                   default:
                   break;
				}
	}
	 cout<<"������  "<<rights<<"  ����"<<endl;
     cout<<"������  "<<wrong<<"  ����"<<endl;
	}
	else
	{
		
		cout<<"�����������Ŀ��";
        cin >>Num ;
		cout<<"������һ��ֵȷ����ʽ����ֵȡֵ��Χ��"<<endl;
        cin>>qznum;
		cout<<"******************************************"<<endl;
        while(Num--)
		{
			create(qznum);
		}
		//��������0 
    cnt_right = cnt_wrong = 0;
	ifstream infile;
    infile.open("equation.txt", ios::in);
	  if(infile.is_open() == false)
	  {
         cerr << "open error!" << endl;
         exit(1);
	  }
		
    while( infile >> nifix)
    {
        error = nifix_to_post();            //��׺ת��׺�������ܴ�����Ϣ 
        if (error)                            //�����̳��������������Ϣ 
        { 
            cout << "��ȡʽ�ӳ���!" << endl;
            return 0; 
        }
        
        //test_post();
        
        error = cal_result();                //��׺���ʽ���㣬�����ܴ�����Ϣ 
        if (error)                            //�����̳��������������Ϣ
        { 
            cout << "�����г���..." << endl;
            return 0; 
        }
        
        cout << "�������: ";
        cin >> ans;                            //�����û��� 
        error = trans_ans();                //�𰸷��룬 �����ܴ�����Ϣ
        if (error)                            //�����̳��������������Ϣ
        { 
            cout << "���벻�Ϸ���!" << endl;
            return 0; 
        }
        //���û�����ͳ�������𰸵ķ��ӷ�ĸ��Ȼ���Ӿ�Ϊ0����˵���û��������ȷ 
        if ((rst.denominator == res.denominator && rst.numerator == res.numerator) || (rst.numerator == res.numerator && rst.numerator == 0))
        {
            cnt_right++;
            cout << "��ȷ!" << endl;
        }
        //����𰸴��󣬳��������ȷ�� 
        else
        {
            cnt_wrong++;
            cout << "����. ���� ";
            if (res.denominator == 1)
                cout << res.numerator << "." << endl;
            else
                cout << res.numerator << "/" << res.denominator << "." << endl;
        }
    }
    cout << "ͳ�ƽ��..." << endl;
    //���ͳ�ƽ�� 
    cout << "�����" << cnt_right+cnt_wrong << " ���� ";
    cout << "��ȷ����" << cnt_right << "   �������� " << cnt_wrong << " ��" << endl;
	infile.close();
 
	}
	  
	 return 0;
}

