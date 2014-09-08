//
//  main.cpp
//  MightyInteger
//
//  Created by Dilnur Yuldashev on 2/25/14.
//  Copyright (c) 2014 Dilnur Yuldashev. All rights reserved.
//

#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include "MightyInteger.h"
using namespace std;

#define NUMBER_OF_COMPARISONS 4

int main(int argc, const char * argv[])
{
    MightyInteger a("9238823832023983290328329032093");
	cout<<"ASCII of (:): "<<int('0')<<endl;
	cout<<a<<endl;
	cout<<"-a: "<<(-a)<<endl;
	cout<<a<<endl;
	MightyInteger b=a.AbsoluteValue();
	cout<<"b=a.absolute: "<<b<<endl;
	string temp;
	cout<<"Enter MightyInteger number1: "<<endl;
	cin>>temp;
	MightyInteger n1(temp);
	//cout<<"sqrt(n1): "<<n1.Sqrt()<<endl;
	cout<<"Enter MightyInteger number2: "<<endl;
	cin>>temp;
	MightyInteger n2(temp);
	cout<<"n1+n2: "<<(n1+n2)<<endl;
	cout<<"n1-n2= "<<n1-n2<<endl;
	cout<<"n1*n2: "<<(n1*n2)<<endl;
	cout<<"n1/n2: "<<(n1/n2)<<endl;
	cout<<endl<<"testing power function: "<<endl;
	int exp=1;
	cout<<"Enter MightyInteger base: "<<endl;
	cin>>temp;
	MightyInteger s(temp);
	cout<<"Enter exponent of type int: "<<endl;
	cin>>exp;
	cout<<"Power("<<temp<<", "<<exp<<")= "<<s.Power(exp)<<endl;
	cout<<endl<<"WARNING: The functions below(log, sqrt..) work only with positive MightyIntegers!!!!"<<endl;
	cout<<endl<<"Testing % operator "<<endl<<endl;
	cout<<"Enter MightyInteger number1: "<<endl;
	cin>>temp;
	MightyInteger t1(temp);
	//cout<<"sqrt(n1): "<<n1.Sqrt()<<endl;
	cout<<"Enter MightyInteger number2: "<<endl;
	cin>>temp;
	MightyInteger t2(temp);
	cout<<"t1%t2: "<<(t1%t2)<<endl;
	cout<<endl<<"Testing factorial function: "<<endl<<endl;
	cout<<"WARNING!!!"<<endl;
	cout<<"Note that this process takes a long time, for there many multiplications and additions invlolved"<<endl;
	cout<<"factorial(100) takes 4-5 seconds and it's about 160 digits long"<<endl;
	cout<<"So do not enter numbers more than 100!!!!!"<<endl;
	cout<<"Enter MightInteger base: "<<endl;
	cin>>temp;
	MightyInteger f(temp);
	cout<<"factorial("<<f<<")= "<<f.Factorial()<<endl;
	cout<<endl<<"Testing logarithm function: "<<endl<<endl;
	cout<<"Enter MightInteger base: "<<endl;
	cin>>temp;
	MightyInteger k(temp);
	cout<<"Enter log base:"<<endl;
	cin>>temp;
	MightyInteger p(temp);
	cout<<"log("<<k<<", "<<p<<")= "<<k.Log(p)<<endl;
	cout<<endl<<"Testing sqrt function: "<<endl<<endl;
	cout<<"Enter a MightyInteger: "<<endl;
	cin>>temp;
	cout<<"sqrt("<<temp<<")= "<<MightyInteger(temp).Sqrt()<<endl;
	cout<<"Testing comparison operators:"<<endl;
	for(int i=0;i<NUMBER_OF_COMPARISONS;i++){
		cout<<"Enter MightyInteger number1: "<<endl;
		cin>>temp;
		MightyInteger c1(temp);
		cout<<"Enter MightyInteger number2: "<<endl;
		cin>>temp;
		MightyInteger c2(temp);
		cout<<c1<<" "<<c2<<endl;
		cout<<"c1>c2: "<<(c1>c2)<<endl;
		cout<<"c1<c2: "<<(c1<c2)<<endl;
		cout<<"c1==c2: "<<(c1==c2)<<endl;
		cout<<"c1!=c2: "<<(c1!=c2)<<endl;
	}
    return 0;
}

