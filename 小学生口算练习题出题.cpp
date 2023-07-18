//核心出题模块，可直接使用
#include <bits/stdc++.h>
using namespace std;
void numcraet(double t);
void title(char s1,char s2,int t1,int t2,int t3,int t4);
char pcreat();
void numscreat(double t);

int p=0;
int m;
int main()
{
	int z,M,N;
	char a;
	srand(time(0));
	printf("请输入页数\n");
	cin>>M;
	printf("请输入每页题目数\n");
	cin>>N;
	int t;
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{   
		    z=1+rand()%2;//z==1or2 
			t=rand()%2;//t==0or1 
			if(t==1)//t 用来随机决定生成哪种类型 
	        title('(',a,z,z,0,0);//
	        else if(t==0)//
	        title(a,a,z,z,1,0);//
	        cout<<'='<<' '<<' '<<' '<<' ';//
		}
		cout<<endl;
	}
	return 0;
}
void titlecreat() 
{
	char a;
	int z,t;
	z=1+rand()%3;//决定生成几个括号 
	t=rand()%2;//决定首先是否生成括号 
	if(t==1) title('(',a,z,z,0,0);
	else if(t==0) title(a,a,z,z,1,0);//z是括号个数 
	cout<<'=';
} 


int numcreat()//生成数字
{
    return 1+rand()%100;
}


char pcreat()//生成运算符
{
	int t;
	t=rand()%4;
	if(t==0) return '+';
	if(t==1) return '-';
	if(t==2) return '*';
	if(t==3) return '/';
}


void numscreat()//生成单个运算
{
	int num;
	char s;
	num=numcreat();
	cout<<num;
	s=pcreat();
	cout<<s;
	num=numcreat();
	cout<<num;
}


void title(char s1,char s2,int t1,int t2,int t3,int t4) //t3,t4是现存左右括号 
{
    int m;
    m=0;
	int num;
	char s;
	int ta=rand()%2;//[0,1] 
    int tb=rand()%2;//随机 
    int tc=rand()%2;
    int td=rand()%2;
	char a;
	if(s1=='('&&t1>0)//如果s1==(,输出(,t1--。进入下一个函数 
	{
		p++;
		cout<<'(';
		t1--;
		title(a,a,t1,t2,1,0);
	}
	else if(s1==a)//s1不为(有两种情况. 
	{
		if(t3==1)//t3==1
		{
			numscreat();//生成一对运算 
			if(tb==1&&p>0)//决定 是否生成右括号 
			{
		    p--;
			title(a,')',t1,t2,0,0);
		    }
			else title(a,a,t1,t2,0,1);
		}
		else if(t4==1)//t4==1
		{
		    s=pcreat();
		    cout<<s;
		    if(s=='/') m=1;
		    if(tc==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//决定是否生成左括号 
		    else title(a,a,t1,t2,1,0);
		}
	}
	if(s2==')')
	{
		t2--;
		cout<<')';
		if(t2==0)
		{
			s=pcreat();
			cout<<s;
    	    num=numcreat();
    	    cout<<num;
    	    return;
		}
		else
		{
			s=pcreat();
			cout<<s;
			if(s=='/') m=1;
			if(td==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//决定是否生成左括号 
		    else title(a,a,t1,t2,1,0);
		}
	}
}
