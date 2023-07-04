#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string carp(const string&, const string&);
char intToChar(int);

int main()
{
    string int1,int2;
    cout<<"Int 1 giriniz : ";
    cin>>int1;
    cout<<"Int 2 giriniz : ";
    cin>>int2;

    string sonuc = carp(int1,int2);

    cout<<"Sonuc : "<<sonuc;
}

string carp(const string& int1, const string& int2)
{
    int len1 = int1.length();
    int len2 = int2.length();

    string product(len1+len2,'0');

    for(int i = len1-1 ; i>=0; --i)
    {
        int elde = 0;
        for(int j = len2-1; j>= 0;--j)
        {
            int hane1 = int1[i]-'0';
            int hane2 = int2[j]-'0';

            int toplam = (hane1*hane2)+elde +(product[i+j+1]-'0');
            product[i+j+1]=intToChar(toplam%10);
            elde = toplam/10;
        }
        product[i] = intToChar(elde);
    }

    product.erase(0,min(product.find_first_not_of('0'),product.size()-1));
    return product;
}
char intToChar(int digit)
{
    return static_cast<char>(digit + '0');
}
