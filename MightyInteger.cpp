//
//  MightyInteger.cpp
//  MightyInteger
//
//  Created by Dilnur Yuldashev on 2/25/14.
//  Copyright (c) 2014 Dilnur Yuldashev. All rights reserved.
//

//MightyNumbers.h-MightyNumbers class implementation
//Written by D. Yuldashev

#include<iostream>
#include<string>
#include<ostream>
#include"MightyInteger.h"

using namespace std;

const int TEN=10;
const string STRING_ONE= "1";
const string STRING_ZERO= "0";
const char ZERO_TURN='z';
const char ZERO_CHAR='0';
const char ONE_CHAR='1';
const char NINE_CHAR='9';

MightyInteger::MightyInteger(){
	Size=0;
	Number="";
}

MightyInteger::MightyInteger(string number){
	Size=(long)number.length();
	Number=number;
}

int MightyInteger::GetSize() const{
	return Size;
}

string MightyInteger::ToString() const{
	return Number;
}

bool MightyInteger::isNegative() const{
	return (Number[0]=='-');
}

// Assignment operator to perform deep copy
MightyInteger& MightyInteger::operator = (const MightyInteger& source){
	Number=source.ToString();
	return *this;
}

MightyInteger MightyInteger::AbsoluteValue(){
	//string might be empty
	if(Number=="")
		return (*this);
	if(Number[0]=='-')
		//hardcoded one?
		Number=Number.substr(1);
	return *this;
}

MightyInteger MightyInteger::operator -(){
	Number="-"+Number;
	return *this;
}

//be sure that index is in bounds
int& MightyInteger::operator [] (int index) const{
	int toReturn=(Number[index]-ZERO_CHAR);
	return toReturn;
}

//note that + is not +=
MightyInteger MightyInteger::operator + (const MightyInteger& myInteger) const{
	string addition;
	//four cases
	//1- (+ +)---just add
	//2-(+ -)......subtract
	//3-(- -).......add and put minus
	//4-(- +).......subtract then put minus
	//case 4
	if((*this).isNegative() && !myInteger.isNegative()){
		MightyInteger absThis=(*this);
		return (myInteger-absThis.AbsoluteValue());
	}
	//case 2
	else if(!(*this).isNegative() && myInteger.isNegative()){
		MightyInteger absMyInt=myInteger;
		return (*this)-absMyInt.AbsoluteValue();
	}
	else{
		
		MightyInteger n1=(*this);
		MightyInteger n2=(myInteger);
		string number1=n1.AbsoluteValue().ToString();
		string number2=n2.AbsoluteValue().ToString();
		int rem=0;
		int add=0;
		
		if(number1.length()>number2.length()){
			//complement number2 with zeros
			for(long i=number2.length();i<number1.length();i++){
				number2=STRING_ZERO+number2;
			}
		}
		else if(number1.length()<number2.length()){
			//complement number1 with zeros
			for(long i=number1.length();i<number2.length();i++){
				number1=STRING_ZERO+number1;
			}
		}
		//so we have two strings of equal lengths
		//now it is easier to add them.
		bool largerThanTen=false;
		for(long i=number1.length()-1;i>=0;i--){
			if(add>=TEN)
				largerThanTen=true;
			else
				largerThanTen=false;
			add=(number1[i]-ZERO_CHAR)+(number2[i]-ZERO_CHAR);
			//for the next addition
			rem=add%TEN;
			if(i!=number1.length()-1 && largerThanTen==true)
				rem++;
			//there is a case when we add 0 and 9 and give 1
			//that would be 10, 0-current digit
			char digit=rem+ZERO_CHAR;
			if(rem==TEN){
				digit=ZERO_CHAR;
				add=TEN;
			}
			addition=digit+addition;
		}
		if(add>=TEN)
			addition=STRING_ONE+addition;
	}
	if((*this).isNegative() && myInteger.isNegative())
		return (-MightyInteger(addition));
	else
		return MightyInteger(addition);
}

//note that this function is const
//so the original class string Number
//should not be given in here
void MightyInteger::minusOperatorInMind(string &a, long index, int &subtract) const{
	//we start from the back and go to the front
	//because we do not have to deal with the numbers after index
	//look at the number next to it
	//if it's not equal to zero
	long i=index-1;
	while(a[i]==ZERO_CHAR){
		i--;
	}
	//So while loop ends when we encounter
	//a number!=0
	////subtract one from it
	//and add 10 to the number[index]
	//if the number is zero-----different story
	//in here we must also run another loop
	//from i to index(zeros might be there)
	//and add 9 to each of zeros
	//for sure a[i]!=0 and not touching a[index](for we add 10 to it)
	//subtracting one from it
	if(i==0){
		if(a[i]!=ONE_CHAR){
			a[i]=a[i]-1;
		}
		else{
			a[i]=ZERO_TURN;
		}
	}
	else{
		a[i]=a[i]-1;
	}
	for(long j=i+1;j<index;j++){
		if(a[j]==ZERO_CHAR){
			a[j]=NINE_CHAR;
		}
	}
	subtract=(a[index]-ZERO_CHAR)+TEN;
}

MightyInteger MightyInteger::operator - (const MightyInteger& myInteger) const{
	string result;
	//four cases
	//1- (+ +)---just subtract=---n1-n2
	//2-(+ -)......add their absValue
	//3-(- -).......n2.abs-n1.abs---n2-n1
	//4-(- +).......add and put minus
	//write a function for calc carry
	//case 4
	if((*this).isNegative() && !myInteger.isNegative()){
		MightyInteger absThis=(*this);
		return (-(myInteger+absThis.AbsoluteValue()));
	}
	//case 2
	else if(!(*this).isNegative() && myInteger.isNegative()){
		MightyInteger absMyInt=myInteger;
		return (*this)+absMyInt.AbsoluteValue();
	}
	else{
		int subtract=0;
		MightyInteger n1=(*this);
		MightyInteger n2=(myInteger);
		n1=n1.AbsoluteValue();
		n2=n2.AbsoluteValue();
		string number1=n1.ToString();
		string number2=n2.ToString();
		if(number1.length()>number2.length()){
			//complement number2 with zeros
			for(long i=number2.length();i<number1.length();i++){
				number2=STRING_ZERO+number2;
			}
		}
		else if(number1.length()<number2.length()){
			//complement number1 with zeros
			for(long i=number1.length();i<number2.length();i++){
				number1=STRING_ZERO+number1;
			}
		}
		//so we have two strings of equal lengths
		//now it is easier to subtract them.
		//be sure to subtract the smaller from the larger
		if(n1==n2){
			return MightyInteger(STRING_ZERO);
		}
		else if(n1>n2){
			//DO NOT FORGET TO ACCOUNT for 'z'--zero char in front
			for(long i=number1.length()-1;i>=0;i--){
				if(number1[i]==ZERO_TURN){
					//modify result, get rid of zeros in front
					result=result.substr(result.find_first_not_of(ZERO_CHAR));
					return MightyInteger(result);
				}
				if(number1[i]>=number2[i]){
					//do nothing-easy
					subtract=number1[i]-number2[i];
				}
				else{
					minusOperatorInMind(number1, i, subtract);
					subtract=subtract-(number2[i]-ZERO_CHAR);
				}
				//add subtract to thy string
				char digit=subtract+ZERO_CHAR;
				result=digit+result;
			}
			//modify result, get rid of zeros in front
			//modify result, get rid of zeros in front
			result=result.substr(result.find_first_not_of(ZERO_CHAR));
			if((*this).isNegative() && myInteger.isNegative())
				return (-MightyInteger(result));
			else
				return (MightyInteger(result));
		}
		else{
			//DO NOT FORGET TO ACCOUNT for 'z'--zero char in front
			for(long i=number2.length()-1;i>=0;i--){
				if(number2[i]==ZERO_TURN){
					//modify result, get rid of zeros in front
					result=result.substr(result.find_first_not_of(ZERO_CHAR));
					return (-MightyInteger(result));
				}
				if(number2[i]>=number1[i]){
					//do nothing-easy
					subtract=number2[i]-number1[i];
				}
				else{
					minusOperatorInMind(number2, i, subtract);
					subtract=subtract-(number1[i]-ZERO_CHAR);
				}
				//add subtract to thy string
				char digit=subtract+ZERO_CHAR;
				result=digit+result;
			}
		}
		//just put minus in front
		//modify result, get rid of zeros in front
		//modify result, get rid of zeros in front
		result=result.substr(result.find_first_not_of(ZERO_CHAR));
		if((*this).isNegative() && myInteger.isNegative())
			return (MightyInteger(result));
		else
			return (-MightyInteger(result));
		//return (-MightyInteger(result));
	}
}

MightyInteger MightyInteger::operator * (const MightyInteger& myInteger) const{
	MightyInteger multiplication;
	MightyInteger n1=(*this);
	MightyInteger n2=(myInteger);
	n1=n1.AbsoluteValue();
	n2=n2.AbsoluteValue();
	string number1=n1.ToString();
	string number2=n2.ToString();
	//these ifs are for efficiency
	//we find the shorter one of number1 and number2
	//and we use that one for multiplication
	string zeros;
	if(Number==STRING_ZERO || number2==STRING_ZERO)
		return MightyInteger(STRING_ZERO);
	for(long i=number1.length()-1;i>=0;i--){
		MightyInteger temp;
		int digit=number1[i]-ZERO_CHAR;
		for(int j=0;j<digit;j++){
			temp=temp+n2;
		}
		//now we must add zeros
		temp=MightyInteger(temp.ToString()+zeros);
		//increment zeros
		zeros=zeros+STRING_ZERO;
		multiplication=multiplication+temp;
	}
	if(((*this).isNegative() && myInteger.isNegative()) || (!(*this).isNegative() && !myInteger.isNegative()))
		return multiplication;
	else
		return -multiplication;
}

MightyInteger MightyInteger::operator / (const MightyInteger& myInteger) const{
	string quotient;
	MightyInteger powerOfTen("10");
	MightyInteger n1=(*this);
	MightyInteger n2=(myInteger);
	n1=n1.AbsoluteValue();
	n2=n2.AbsoluteValue();
	string number1=n1.ToString();
	string number2=n2.ToString();
	MightyInteger copyOfThis(number1);
	if(n1==n2)
		return MightyInteger(STRING_ONE);
	else if(n1<n2){
		return MightyInteger(STRING_ZERO);
	}
	//(*this)<myInteger
	else{
		string numberTwoComplemented=number2;
		//all the problem starts here
		//now numberTwoComplemented and number1 has equal length
		//kind of paper long-division
		//going from back of two strings
		//finding each digit in quotient
		//quotient[k]*number2*10^k <= number1--loop is needed
		//then move to k--, till k=0
		for(long i=number1.length()-1;i>=0;i--){
			//find i such that quotient[i]*number2*10^i <= number1--loop is needed
			int j;
			//bool found=false;
			for(j=0;j<TEN;j++){
				string temp;
				temp+=(j+ZERO_CHAR);
				MightyInteger a(temp);
				if(((a*n2)*powerOfTen.Power(i))>(copyOfThis)){
					break;
				}
			}
			j--;
			//cout<<"int k= "<<i<<" c[k]="<<j<<endl;
			//j is found
			quotient+=(j+ZERO_CHAR);
			string temp;
			temp+=(j+ZERO_CHAR);
			MightyInteger a(temp);
			MightyInteger result=(a*n2)*powerOfTen.Power(i);
			copyOfThis=copyOfThis-result;
			number1=copyOfThis.ToString();
			//complement with zeros
			for(long k=number1.length();k<Number.length();k++){
				number1=STRING_ZERO+number1;
			}
		}
	}
	quotient=quotient.substr(quotient.find_first_not_of(ZERO_CHAR));
	if(((*this).isNegative() && myInteger.isNegative()) || (!(*this).isNegative() && !myInteger.isNegative()))
		return MightyInteger(quotient);
	else
		return (-MightyInteger(quotient));
}

MightyInteger MightyInteger::operator % (const MightyInteger& myInteger) const{
	MightyInteger div=(*this)/myInteger;
	return ((*this)-div*myInteger);
}

MightyInteger MightyInteger::Power(int exponent) const{
	//be sure take abs of *this
	MightyInteger absThis=(*this);
	absThis=absThis.AbsoluteValue();
	MightyInteger one(STRING_ONE);
	for(int i=1;i<=exponent;i++){
		one=absThis*one;
	}
	if((*this).isNegative() && exponent%2==1)
		return -one;
	else
		return one;
}

MightyInteger MightyInteger::Factorial() const{
	MightyInteger one(STRING_ONE);
	MightyInteger factorial(STRING_ONE);
	while(one<(*this) || one==(*this)){
		factorial=factorial*one;
		//incrementing by ONE(1)
		one=one+MightyInteger(STRING_ONE);
	}
	return factorial;
}

MightyInteger MightyInteger::Sqrt() const{
	//source for algorithm: acmp.ru---Dlinniy Koren(razdel Dlinnaya arifmetika)
	//the source states: if number is of N digits--->sqrt(number) (N+1)/2
	string squareRoot;
	for(int i=0;i<(Number.length()+1)/2;i++)
		squareRoot+=STRING_ZERO;
	//assume that k numbers of squareRoot are found
	//to find (k+1)'th digit--first set it to '9'
	//then decrease to find max digit that makes squareRoot^2<=number
	//assuming that number after k+1' th digit are zeros
	for(int i=0;i<squareRoot.length();i++){
		//set squareRoot[i]='9', then follow the guidelines
		squareRoot[i]=NINE_CHAR;
		while(!(MightyInteger(squareRoot).Power(2)<(*this) || MightyInteger(squareRoot).Power(2)==(*this))){
			squareRoot[i]--;
		}
	}
	return MightyInteger(squareRoot);
}

int MightyInteger::Log(const MightyInteger& myInteger) const{
	int log=0;
	MightyInteger number1=(*this);
	MightyInteger number2=myInteger;
	MightyInteger zero(STRING_ZERO);
	while(number1!=zero){
		number1=number1/number2;
		log++;
	}
	return (log-1);
}

bool MightyInteger::operator == (const MightyInteger& compareTo) const{
	return Number==compareTo.ToString();
}

bool MightyInteger::operator != (const MightyInteger& compareTo) const{
	return Number!=compareTo.ToString();
}

bool MightyInteger::operator > (const MightyInteger& compareTo) const{
	MightyInteger n1=(*this);
	MightyInteger n2=(compareTo);
	n1=n1.AbsoluteValue();
	n2=n2.AbsoluteValue();
	string number1=n1.ToString();
	string number2=n2.ToString();
	//these are a bit different
	//you cannot just compare
	//- +
	if((*this).isNegative() && !compareTo.isNegative()){
		return false;
	}
	else if(!(*this).isNegative() && compareTo.isNegative()){
		return true;
	}
	else if((*this).isNegative() && compareTo.isNegative()){
		if(number1.length()==number2.length())
			return (number1<number2);
		else
			return number1.length()<number2.length();
	}
	else{
		string second=compareTo.ToString();
		if(Number.length()==second.length())
			return Number>compareTo.ToString();
		else
			return Number.length()>second.length();
	}
}

bool MightyInteger::operator < (const MightyInteger& compareTo) const{
	return !((*this)>compareTo) && !(*this==compareTo);
}

// Stream output operator to print BigInteger
ostream& operator << (ostream& out, const MightyInteger& myInteger){
	return out<<myInteger.ToString();
}
