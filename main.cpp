#include <iostream>
using namespace std;
class Rational{
public:
    Rational(){
        numerator = 0 ;
        denominator = 1 ;
        cout<<"------Constructor called------"<<endl;
    }
    Rational(int n,int d){
        numerator =   n ;
        denominator = (d!=0) ? d : 1;
        simplify();
        cout<<"Constructor called"<<endl;
    }
    void print(){
        cout<<numerator<<" / "<<denominator<<endl;
    }
    int setNumerator(int n){
        numerator = n;
    }
    int getNumerator(){
        return numerator;
    }
    int setDenominator(int d){
        denominator = (d!=0) ? d : 1 ;
    }
    int getDenominator(){
        return denominator;
    }
    Rational add(Rational r){
        int lcm = this->denominator * r.denominator;
        int n1 = (this ->numerator * lcm) / this-> denominator;
        int n2 =  (r.numerator * lcm) / r.denominator;
        return Rational(n1+n2,lcm);
    }
    Rational sub(Rational r){
        int lcm = this->denominator * r.denominator;
        int n1 = (this ->numerator * lcm) / this-> denominator;
        int n2 =  (r.numerator * lcm) / r.denominator;
        return Rational(n1-n2,lcm);
    }
    Rational mul(Rational r){
        int n = (this ->numerator * r.numerator) ;
        int d =  denominator * r.denominator;
        return Rational(n,d);
    }
    Rational div(Rational r){
        int n = this ->numerator * r.denominator ;
        int d =  denominator * r.numerator;
        return Rational(n,d);
    }


private:
    int numerator;
    int denominator;
    //utility function because it is in private section of class
    void simplify(){
        int min = (numerator< denominator)?numerator:denominator;
        int div = 2;
        while(div<=min){
            if(numerator%div ==0 && denominator%div==0){
                numerator=numerator/div;
                denominator=denominator/div;
            }else{
                div++;
            }
        }
    }
};

int main() {
    Rational r1(1,2);
    Rational r2(3,4);
    r1.print();
    r2.print();
    Rational r3 = r1.add(r2);
    cout<<"rational addition"<<endl;
    r3.print();
    Rational r4 = r1.sub(r2);
    cout<<"rational subtraction"<<endl;
    r4.print();
    Rational r5 = r1.mul(r2);
    cout<<"rational multiplication"<<endl;
    r5.print();
    Rational r6 = r1.div(r2);
    cout<<"rational division"<<endl;
    r6.print();


    return 0;
}
