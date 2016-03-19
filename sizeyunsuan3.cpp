#include<iostream>
#include<ctime>
#include<stack>
#include<fstream>
#define length 10000//存放答案数组长度
using namespace std;
typedef long long ll;
ofstream fout("equation.txt");
char Op[] = {'+', '-', '*', '/'};
int rights;//对题数目
int wrong;//错题数目

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

//****分数类***//
	class fraction
	{
	 private:
		int above;         //分子
		int below;         //分母
		void reduction();            //约分
		fraction makeCommond(fraction); //通分
 
	public:
		fraction()
		{             //构造函数
		}
	   fraction add(fraction);      //两分数相加
	   fraction sub(fraction);      //两分数相减
	   fraction mul(fraction);      //两分数相乘
	   fraction div(fraction);      //两分数相除
	   int display(int,int);              //显示分数
	   void setvalue(int ,int);                //存储分数
	};

//***********分数的约分*********//

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
		 comdiv=i;            //最大公约数

		  if(i!=0)
		  {
			  above/=i;
			  below/=i;
		   }
	}

 //*************分数的通分*************//

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
   //***************分数的相加*************//

	fraction fraction::add(fraction fr)
	{
		  fraction myFraction;
		  myFraction.above=above*fr.below+fr.above*below;
		  myFraction.below=below*fr.below;
		  myFraction.reduction();
		  return myFraction;
	}
//*********************分数的相减***************//

	 fraction fraction::sub(fraction fr)
	 {
		   fraction myFraction;
		   myFraction.above=above*fr.below-fr.above*below;
		   myFraction.below=below*fr.below;
		   myFraction.reduction();
		   return myFraction;
	}

  //*******************分数的相乘****************//

	fraction fraction::mul(fraction fr)
	{ 
		  fraction myFraction;
		  myFraction.above=above*fr.above;
		  myFraction.below=below*fr.below;
		  myFraction.reduction();
		  return myFraction;
	} 
//******************分数的相除***********//

	fraction fraction::div(fraction fr)
	{
		fraction myFraction; 
		myFraction.above=above*fr.below;
		myFraction.below=below*fr.above;
		myFraction.reduction();
		return myFraction;
	}

 //*********************分数答案的输入判断*************//

	int fraction::display(int a,int b)
	{
    
		if((a==above)&&(b==below))
		{
			cout<<"正确"<<endl;
			rights=rights+1;
		}
		else
		{
			cout<<"错误"<<endl;
			wrong=wrong+1;
		}
		return rights,wrong;
	} 

  //*******************分数的赋值****************//

	 void fraction::setvalue(int sj1,int sj3)           
	 { 
		above=sj1;
		below=sj3;
	}
//*************无分数，无余数答案判断****************//
	
	 int answer(int a[],int i)
	{
		int ans;
		
		cout<<"请输入答案:"<<endl;
		cin>>ans;
	      if(ans==a[i]) 
          {
		      cout<<"正确"<<endl;
			  rights=rights+1;
		    }
		  else
		  {
			  cout<<"错误"<<endl;
			  wrong=wrong+1;
		  }
		  return rights,wrong;
     
	}
 //*************无分数，有余数答案判断****************//
	int answer_1(int a[],int i,int b[])
	{
		int ans,yushu;
		
		cout<<"请输入商:"<<endl;
		cin>>ans;
		cout<<"输入余数"<<endl;
		cin>>yushu;
	      if((ans==a[i])&&(yushu=b[i])) 
          {
		      cout<<"正确"<<endl;
			   rights=rights+1;
		    }
		  else
		  {
			  cout<<"错误"<<endl;
			  wrong=wrong+1;
		  }
		  return rights,wrong;
     
	}
 //*************产生带括号式子****************//
	void create(int maxn)
	{
		
		if(!fout)                        //如果打开失败，outfile返回值
		{
          cerr << "open error!" << endl;
         exit(1);
        }

    //首先随机生成算式中操作数的个数，其数量必须大于1 
    int lengt;//式子长度
    do{
        lengt = rand()%8;
    }while(lengt < 2);
    bool div = false;                        //用来防止出现除0错误 
    int brack_cnt = 0;                        //记录未匹配的左括号个数 
    ll num, op;
    for (int i = 1; i < lengt; i++)        //循环生成算式 
    {
        if (div)                            //若此时需要生成的数字前的负号是'/'，则需要特判此次生成的数字不能为0 
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
		}//否则直接生成数字输出 
        int tmpcnt = brack_cnt;
        for (int j = 0; j < tmpcnt; j++)    //若当前有未匹配的左括号，则对每一个未匹配的左括号，都有一定概率生成相应右括号。    
        {
            if ((rand()%5) > 2)                //生成右括号概率为0.6
            {
                brack_cnt--;
				
				fout << ")";
				cout<<")";
            }
        }
        
        op = rand()%4;                        //生成运算符 
		fout << Op[op];
		cout << Op[op];
        if (op == 3)                        //若生成了除号，则需要置相应标志位 
            div = true;
        
        if (!(rand()%3))                    //以一定概率生成左括号，概率为1/3 
        {
			fout << "(";
			cout<<"(";
            brack_cnt++;
			num= rand()%maxn;//生成左括号后必须生成一个数字和运算符，不然可能出现(15)这样的错误 
			fout <<num;
			cout<<num;
            op = rand()%4;
			fout << Op[op];
			cout<<Op[op];
            if (op == 3)
                div = true;
        }
    }
    if (div)                                //生成最后一个数字，该数字后不需要跟运算符 
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
    while(brack_cnt--)              //补全右括号 
	{
		fout << ")";
		cout << ")";
	}
	    cout<<"=";
	    fout<< endl;
		cout<<endl;
		
}
	bool isNum(char x)            //判断是否是数字
{
    return (x >= '0' && x <= '9');
}

bool isOp(char x)             //判断是否是操作符
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')');
}

int priority(char x)          //返回一个操作符的优先级
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
    stack<char> s;                                //操作符栈，用来压操作符 
/*    ************************************************************************************************
#    由于操作数是多位的，所以我们逐位做一个累加暂存的工作，当遇到操作符时，代表此操作符前的数暂存完毕， 
#    需要将其入栈，但也不是所有操作符前都有操作数，如'*('等，所以我们需要一个标志位来表示某个操作符前
#    是否进行过暂存操作数的处理。 
*///************************************************************************************************** 
    bool havenum = false;                        
    int tmp = 0, pos = 0;                        //tmp为暂存多位数的变量，pos为后缀数组存储位置 
    for (int i = 0; nifix[i] != '\0'; i++)        //循环遍历中缀数组 
    {
        if (isNum(nifix[i]))                     //若当前字符是数字，则进行暂存操作。并标识已有操作数 
        {
            havenum = true;
            tmp = tmp*10 + (nifix[i]-'0');
        }
        else if (isOp(nifix[i]))                //若当前字符是操作符则进行如下操作 
        {
            //中缀表达式合法性判断，判断是否有连续两个字符相连，若有则代表出错 
            if (isOp(nifix[i-1]) && nifix[i-1] != ')' && nifix[i] != '(') 
                return true; 
            //如果操作符前有操作数，则将得到的操作数输出至后缀表达式 
            if (havenum)
            {
                havenum = false;
                post[pos++] = tmp + '0';
                tmp = 0;
            }
            //如果操作符为右括号，则按规则进行出栈如后缀表达式等操作 
            if (nifix[i] == ')')
            {
                if (s.empty())                    //中缀表达式合法性判断，判断括号匹配 
                    return true;
                while(s.top() != '(')
                {
                    post[pos++] = s.top();
                    s.pop();
                    if (s.empty())                //中缀表达式合法性判断，判断括号匹配 
                        return true;
                }
                s.pop();
            }
            else if (nifix[i] == '(')            //如果是左括号则直接入栈 
                s.push(nifix[i]);
            else                                //如果是+-*/则按规则操作 
            {
                while (!s.empty() && priority(nifix[i]) <= priority(s.top()))
                {
                    post[pos++] = s.top();
                    s.pop();
                }
                s.push(nifix[i]);
            }
        }
        else                                    //中缀表达式合法性判断，判断是否含非法符号 
            return true;
	}
    //若有操作数，则将其输出至后缀表达式 
    if (havenum)
    {
        havenum = false;
        post[pos++] = tmp + '0';
        tmp = 0;
    }
    //将栈中操作符一次输出到后缀表达式中 
    while(!s.empty())
    {
        if (s.top() == '(')                        //中缀表达式合法性判断，判断括号匹配 
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
    stack<num> s;                                //用来存放操作数的栈 
    for (int i = 0; i < (strlen(post)); i++)        //循环遍历后缀表达式 
    {
        if (!isOp(post[i]))                        //如果是数字则直接入栈 
        {
            num tmp(post[i]-'0', 1);
            s.push(tmp);
        }
        else
        {
            //取出两个操作数，如果操作数数量不够，则出错，返回 
            if (s.empty())
                return true;
            num b = s.top(); s.pop();
            if (s.empty())
                return true;
            num a = s.top(); s.pop();
            num c;

            if (post[i] == '+')                    //操作符是'+'，进行上述规则运算 
            {
                c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
                c.denominator = a.denominator * b.denominator;
            }
            else if (post[i] == '-')            //操作符是'-'，进行上述规则运算
            {
                c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
                c.denominator = a.denominator * b.denominator;
            }
            else if (post[i] == '*')            //操作符是'*'，进行上述规则运算 
            {
                c.numerator = a.numerator * b.numerator;
                c.denominator = a.denominator * b.denominator;
            }
            else if (post[i] == '/')            //操作符是'/'，进行上述规则运算 
            {
                if (b.numerator == 0)            //如果除的是0，则出现除法错误，返回 
                    return true;
                c.numerator = a.numerator * b.denominator;
                c.denominator = a.denominator * b.numerator;
            }
            else                                //其他情况则出错 
                return true;
            if (c.numerator != 0)                //若结果不为0，则对分子分母约分 
            {
                ll div = gcd(c.denominator, c.numerator);
                c.denominator /= div;
                c.numerator /= div;
            }
            s.push(c);                            //将约分后结果入栈 
        }
    }
    if (s.size() > 1)                            //如果所有操作符都进行相应操作数后栈内还有多个元素，则说明出错，返回 
        return true;
    res = s.top();                                //保存结果 
    s.pop();
    if (res.denominator < 0)                    //化简结果，将分母的负号移到分子上 
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
    //两个标志位分别标志用户输入的分子分母是否为负数 
    bool num_flag = false, deno_flag = false;
    //先判断分子是否为负 
    if (ans[i] == '-')
    {
        num_flag = true;
        i++;
    }
    //接收第一个数字 
    while(isNum(ans[i]))
    {
        tmp = tmp * 10 + (ans[i] - '0');
        i++;
    }
    //若第一个数为负数，则将转化过来的整数取负 
    if (num_flag)
        tmp = -tmp;
    //保存分子 
    rst.numerator = tmp;
    //分母赋初值为1 
    rst.denominator = 1;
    tmp = 0;
    //判断是否是分数 
    if (ans[i] == '/')
    {
        //判断分母是否为负数 
        if (ans[++i] == '-')
        {
            deno_flag = true;
            i++;
        }
        //接收第二个数 
        while(isNum(ans[i]))
        {
            tmp = tmp * 10 + (ans[i] - '0');
            i++;
        }
        //若第二个数为负数，则将转化过来的整数取负
        if (deno_flag)
            tmp = -tmp;
        //保存分母 
        rst.denominator = tmp;
    }
    //若分母为0，则用户输入的结果是非法的 
    if (rst.denominator == 0)
        return true;
    //若此时没有遍历所有的字符，则说明输入是非法的 
    if (i != strlen(ans))
        return true;
    //化简分母的负号，将其移至分子 
    if (rst.denominator < 0)
    {
        rst.numerator = -rst.numerator;
        rst.denominator = -rst.denominator;
    }
    //若用户输入的分子分母都是负数，则用户输入不符合规范，我们取分母为0（因为计算结果不可能出现分母为0的状况）标志这种情况的发生 
    if (num_flag && deno_flag)
        rst.denominator = 0;
    return false;
}


int main()
{
	fraction frac,frac2;
	int sj1,sj2,sf=1,sj3,sj4,r,j=1;//定义随机数及算符
	int above,below;
	int Num;//题的数量
	int numchose;//运算数选择
	char sfchose;//算符选择
	char yschose;//余数选择
	char jf;//减法结果选择
	int qznum;//取值范围
	int ans_2[length];//存放正确的答案
	int ans_4[length]={0};//存放正确的余数
	srand((unsigned)time(NULL)); //srand函数是以现在系统时间作为时间种子产生随机数
	cout<<"*****欢迎使用自动出题系统*****"<<endl;
	cout<<"请对以下内容进行初始化设置："<<endl;
	cout<<"请选择运算数（1.二个运算数 2.多个运算数）"<<endl;
	cin>>numchose;
	if(numchose==1)
	{
		cout<<"请输入打印题数："<<endl;
	cin>>Num;
	cout<<"请选择是否有乘除法?（y/n）"<<endl;
	cin>>sfchose;
	cout<<"请输入一个值确定算式中数值取值范围："<<endl;
    cin>>qznum;
	cout<<"减法结果中出现负数吗？（y/n）";
    cin>>jf;

	if(sfchose=='y')
	{
		cout<<"请选择除法有无余数?（y/n）"<<endl;
		cin>>yschose;
	}
		cout<<"********************************"<<endl;

	for(int i=0;i<Num;i++)
	{
            sj1=rand()%qznum;
			sj2=rand()%qznum;
			sj3=rand()%qznum;
			sj4=rand()%qznum;
			if(sfchose=='n')//无乘除法
			{
			     sf=rand()%4; 		
			}
			if(sfchose=='y')//有乘除法
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
                       if(jf=='n')//无负数
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
					 cout<<"输入分子和分母（用空格隔开，结果化到最简）";
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
						if(jf=='n')//减法结果无负数
						{
							if((sj1/sj3)<(sj2/sj4))
							{ 
								cout<<"("<<sj2<<"/"<<sj4<<")"<<"-"<<"("<<sj1<<"/"<<sj3<<")=     "<<endl;
								frac.setvalue(sj2,sj4);
					            frac2.setvalue(sj1,sj3);
					            cout<<"输入分子和分母（用空格隔开，结果化到最简）";
					            cin>>above>>below;
					            frac.sub(frac2).display(above,below); 

							}
							else
							{
								cout<<"("<<sj1<<"/"<<sj3<<")"<<"-"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
								frac.setvalue(sj1,sj3);
					            frac2.setvalue(sj2,sj4);
					            cout<<"输入分子和分母（用空格隔开，结果化到最简）";
					            cin>>above>>below;
					            frac.sub(frac2).display(above,below); 
							}
						}
						 else
						 {
							    cout<<"("<<sj1<<"/"<<sj3<<")"<<"-"<<"("<<sj2<<"/"<<sj4<<")=     "<<endl;
							    frac.setvalue(sj1,sj3);
					            frac2.setvalue(sj2,sj4);
					            cout<<"输入分子和分母（用空格隔开，结果化到最简）";
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
					   if(sj2==0)//分母为零则不计入总数
					   {
						   i=i-1;
						
					   }
					   else if(yschose=='n')//除法没有余数
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
					   else if(yschose=='y')//除法有余数
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
					 cout<<"输入分子和分母（用空格隔开，结果化到最简）";
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
					   cout<<"输入分子和分母（用空格隔开，结果化到最简）";
					   cin>>above>>below;
					   frac.div(frac2).display(above,below); 
					   break;
                   default:
                   break;
				}
	}
	 cout<<"共做对  "<<rights<<"  道题"<<endl;
     cout<<"共做错  "<<wrong<<"  道题"<<endl;
	}
	else
	{
		
		cout<<"请输入出题数目：";
        cin >>Num ;
		cout<<"请输入一个值确定算式中数值取值范围："<<endl;
        cin>>qznum;
		cout<<"******************************************"<<endl;
        while(Num--)
		{
			create(qznum);
		}
		//计数器请0 
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
        error = nifix_to_post();            //中缀转后缀，并接受错误信息 
        if (error)                            //若过程出错，则输出错误信息 
        { 
            cout << "读取式子出错!" << endl;
            return 0; 
        }
        
        //test_post();
        
        error = cal_result();                //后缀表达式计算，并接受错误信息 
        if (error)                            //若过程出错，则输出错误信息
        { 
            cout << "计算中出错..." << endl;
            return 0; 
        }
        
        cout << "请输入答案: ";
        cin >> ans;                            //接受用户答案 
        error = trans_ans();                //答案翻译， 并接受错误信息
        if (error)                            //若过程出错，则输出错误信息
        { 
            cout << "输入不合法答案!" << endl;
            return 0; 
        }
        //若用户输入和城西计算答案的分子分母相等或分子均为0，则说明用户输入答案正确 
        if ((rst.denominator == res.denominator && rst.numerator == res.numerator) || (rst.numerator == res.numerator && rst.numerator == 0))
        {
            cnt_right++;
            cout << "正确!" << endl;
        }
        //否则答案错误，程序输出正确答案 
        else
        {
            cnt_wrong++;
            cout << "错误. 答案是 ";
            if (res.denominator == 1)
                cout << res.numerator << "." << endl;
            else
                cout << res.numerator << "/" << res.denominator << "." << endl;
        }
    }
    cout << "统计结果..." << endl;
    //输出统计结果 
    cout << "你答了" << cnt_right+cnt_wrong << " 道题 ";
    cout << "正确数：" << cnt_right << "   错误数： " << cnt_wrong << " 。" << endl;
	infile.close();
 
	}
	  
	 return 0;
}

