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
	printf("������ҳ��\n");
	cin>>M;
	printf("������ÿҳ��Ŀ��\n");
	cin>>N;
	int t;
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{   
		    z=1+rand()%2;//z==1or2 
			t=rand()%2;//t==0or1 
			if(t==1)//t ����������������������� 
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
	z=1+rand()%3;//�������ɼ������� 
	t=rand()%2;//���������Ƿ��������� 
	if(t==1) title('(',a,z,z,0,0);
	else if(t==0) title(a,a,z,z,1,0);//z�����Ÿ��� 
	cout<<'=';
} 


int numcreat()//��������
{
    return 1+rand()%100;
}


char pcreat()//���������
{
	int t;
	t=rand()%4;
	if(t==0) return '+';
	if(t==1) return '-';
	if(t==2) return '*';
	if(t==3) return '/';
}


void numscreat()//���ɵ�������
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


void title(char s1,char s2,int t1,int t2,int t3,int t4) //t3,t4���ִ��������� 
{
    int m;
    m=0;
	int num;
	char s;
	int ta=rand()%2;//[0,1] 
    int tb=rand()%2;//��� 
    int tc=rand()%2;
    int td=rand()%2;
	char a;
	if(s1=='('&&t1>0)//���s1==(,���(,t1--��������һ������ 
	{
		p++;
		cout<<'(';
		t1--;
		title(a,a,t1,t2,1,0);
	}
	else if(s1==a)//s1��Ϊ(���������. 
	{
		if(t3==1)//t3==1
		{
			numscreat();//����һ������ 
			if(tb==1&&p>0)//���� �Ƿ����������� 
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
		    if(tc==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//�����Ƿ����������� 
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
			if(td==0&&t1>0&&m==0) title('(',a,t1,t2,0,0);//�����Ƿ����������� 
		    else title(a,a,t1,t2,1,0);
		}
	}
}
