#include "conversion.h"

void main(){
	
	clear
	while(1){
	welcome_stuff();
	conversion_code();
	sleep(5);
	clear
	}
}

int binary_number1(int num){

	int d,res;
	for(d=1,res=0;num;num=num/10,d=d*2)
		res=res+(num%10)*d;
	printf("Decimal Number:%d\n",res);
	return res;
}


int hexa_deci_number(char *s){
	int l;
	for(l=0;s[l];l++);

	int d,res,n;
	for(--l,d=1,res=0;s[l];l--,d=d*16){
		if(s[l]>=48 && s[l]<=57){
			n=s[l]-48;
			res=res+(n*d);}
		else
		{
			n=s[l]-87;
			res=res+(n*d);
		}
	}
	printf("Decimal Number :%d\n",res);
	return res;
}


int octal_deci_number(int n)
{        int ar[32],index,t;
	for(index=0;n;n=n/10){
		t=n%10;
		while(t>=2){
			ar[index++]=t%2;
			t=t/2;
		}
		ar[index++]=t;
	}

	int res=0;
	for(n=index,index=0,t=1;index<n;index++,t=t*2)
		res=res+(ar[index]*t);
	printf("Decimal Number:%d\n",res);
	return res;

}

//Binary converter fn takes decimal
void binary_number(int num){
	printf("Binary Number:");
	int binary[32],index=0;
	
	while(num>=2){
		binary[index++]=num%2;
		num=num/2;
	}

	binary[index]=num;

	for(;index>=0;index--)
		printf("%d",binary[index]);
	Line


}



//Hexa converter fn takes decimal
void hexa_number(int num){
	printf("Hexa Number:");
	int hex[8],index=0;
	while(num>=16){
		hex[index++]=num%16;
		num=num/16;
	}
	hex[index]=num;

	for(;index>=0;index--){
		if(hex[index]>=10)
			printf("%c",hex[index]+87);
		else
			printf("%d",hex[index]);
	}
	Line

}
//octa converter fn takes decimal
void oct_number(int num){
	printf("Octal Number:");
	int oct[6],index=0;
	while(num>=8)
	{
		oct[index++]=num%8;
		num=num/8;
	}
	oct[index]=num;
	for(;index>=0;index--)
		printf("%d",oct[index]);
	Line
}
void welcome_stuff(){
	for(int i=0;i<8;i++)
		printf("-----");
	printf("\n>>>WELCOME TO NUMBER SYSTEM CONVERTER<<<\n");
	for(int i=0;i<8;i++)
		printf("-----");
	printf("\n->->Select Conversion Type:\n1.Decimal Conversion\n");
	printf("2.Octal Conversion\n3.Hexadecimal Conversion\n");
	printf("4.Binary Conversion\n5.Exit the Program\n");
	printf("Enter the option & hit Enter:\n");
}

void conversion_code(){
	int op;
	scanf("%d",&op);
	switch(op){
		case 1:{
			int num;
			printf("Enter Decimal Number:");
			scanf("%d",&num);
			oct_number(num);
			hexa_number(num);
			binary_number(num);
			break;
		}
		case 2:{
			int num;
			printf("Enter Octal Number:");
			scanf("%d",&num);
			int dnum=octal_deci_number(num);
			hexa_number(dnum);
			binary_number(dnum);
			break;
		}
		case 3:{
			char num[8];
			printf("Enter Hexa Number:");
			scanf("%s",num);
			int dnum=hexa_deci_number(num);
			oct_number(dnum);
			binary_number(dnum);
			break;

		}
		case 4:{
			int num;
			printf("Enter Binary Number:");
			scanf("%d",&num);
			int dnum=binary_number1(num);
			oct_number(dnum);
			hexa_number(dnum);
			break;
		}
		case 5:
		{
			system("clear");
			exit(0);
		}
	}
}
/*	clear
	//char one='y';
	while(1){
	welcome_stuff();
	conversion_code();
	//printf("\n\nOne More Conversion Type y/n:");
	//scanf(" %c",&one); */
