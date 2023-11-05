#ifndef BIGDECIMALINT_H_INCLUDED
#define BIGDECIMALINT_H_INCLUDED

#include <vector>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h>

class BigDecimalInt
{
private:
    int Size;
    int sign;
    std::vector <int> Number;
    void SetNumber(int Data)//to use it in addition and subtraction
    {
        Number.push_back(Data);
    }
public:
    BigDecimalInt()
    {
        Size = 0;
    }
    std::vector<int> getNumber()
    {
        return this->Number;
    }
    BigDecimalInt(int decInt)
    {
        int counter=0;

	while(decInt!=0)//to divide number into digits
	{
		int division=decInt/10;
		Number.push_back(decInt%10);
		decInt=division;
		counter++;
	}
        reverse(Number.begin() , Number.end());
    }
    /////////////////////////////////////////////
    BigDecimalInt(std::string decStr)
    {
        int Num;
            if(decStr[0]=='-')
            {
                this->sign = 1;// 1 stands for negative
                decStr.erase(decStr.begin()+0);
          for(int i=0 ; i<decStr.size() ; i++)
            {
                    Num = decStr[i] - 48;
                  Number.push_back(Num);
            }
            Number[0] = Number[0] * (-1);
            }
            else{
            for(int i=0 ; i<decStr.size() ; i++)
            {
                    Num = decStr[i] - 48;
                  Number.push_back(Num);
            }
            }
            /*the previous operations to turn string into integer*/
    }
    ////////////////////////////////////////////////

    //////////////////////////////////////////////
    int GetSize()
    {
        return Number.size();
    }
    ///////////////////////////////////////////
    int get_sign()
    {
        return this->sign;
    }
    /////////////////////////////////////////////
    BigDecimalInt operator+(BigDecimalInt &obj)
    {
        reverse(Number.begin() , Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigDecimalInt NewObj;
        int sum = 0;
        int sum2 = 0;
        int Carry = 0;
      if(this->Size > obj.GetSize())
      {
        for(int i=0 ; i<GetSize() ; i++)
        {
            if(i<=obj.GetSize()-1)
            {
                sum = (this->Number[i] + obj.Number[i] + Carry);
                sum2 = sum % 10;
                NewObj.SetNumber(sum2);
            }
            else if(i>obj.GetSize()-1)
            {
                sum = this->Number[i] + Carry;
                NewObj.SetNumber(sum);
            }
                  Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.SetNumber(Carry);
        }
    }
     else if(this->Size < obj.GetSize())
     {
         for(int i=0 ; i<obj.GetSize() ; i++)
        {
            if(i<=this->Size-1)
            {
                sum = (this->Number[i] + obj.Number[i] + Carry);
                sum2 = sum % 10;
                NewObj.SetNumber(sum2);
            }
            else if(i>this->Size-1)
            {
                sum = obj.Number[i] + Carry;
                NewObj.SetNumber(sum);
            }
                  Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.SetNumber(Carry);
        }
     }
     else
     {
         for(int i=0 ; i<this->Size ; i++)
        {
            sum = this->Number[i] + obj.Number[i] + Carry;
            sum2 = sum % 10;
            NewObj.SetNumber(sum2);
            Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.SetNumber(Carry);
        }
     }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        return NewObj;
    }

    /////////////////////////////////////////////////
    BigDecimalInt operator-(BigDecimalInt obj)
    {
        reverse(this->Number.begin() , this->Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigDecimalInt NewObj;
        int sub = 0;
        int Carry = 0;
        if(this->Size > obj.GetSize()){
            for(int i=0 ; i<GetSize() ; i++)
            {
                if(i<=obj.GetSize()-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>obj.GetSize()-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else if(this->Size < obj.GetSize())
        {
            for(int i=0 ; i<obj.GetSize() ; i++)
            {
                if(i<=this->Size-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>this->Size-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->Size ; i++)
            {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.SetNumber(sub);
            }
        }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        return NewObj;
    }
    ////////////////////////////////////////////////////
    BigDecimalInt operator= (BigDecimalInt anotherDec)
    {
        BigDecimalInt NewObj;
        for(int i=0 ; i<anotherDec.GetSize() ; i++)
        {
            NewObj.SetNumber(anotherDec.Number[i]);
        }
    }
    ////////////////////////////////////////////////////
    bool operator< (BigDecimalInt obj)
    {
        if(this->sign == 1 && obj.sign == 0)
            return true;
        else if(this->sign == 0 && obj.sign == 1)
            return false;
        else if(this->Number.size() > obj.GetSize())
            return false;
        else if(this->Number.size() < obj.GetSize())
            return true;

        reverse(this->Number.begin() , this->Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigDecimalInt NewObj;
        int sub = 0;
        int Carry = 0;
        if(this->Size > obj.GetSize()){
            for(int i=0 ; i<GetSize() ; i++)
            {
                if(i<=obj.GetSize()-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>obj.GetSize()-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else if(this->Size < obj.GetSize())
        {
            for(int i=0 ; i<obj.GetSize() ; i++)
            {
                if(i<=this->Size-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>this->Size-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->Size ; i++)
            {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.SetNumber(sub);
            }
        }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        if(NewObj.sign == 0)
            return false;
        return true;
    }
    //////////////////////////////////////////////////////

    bool operator> (BigDecimalInt obj)
    {
        if(this->sign == 1 && obj.sign == 0)
            return false;
        else if(this->sign == 0 && obj.sign == 1)
            return true;
        else if(this->Number.size() > obj.GetSize())
            return true;
        else if(this->Number.size() < obj.GetSize())
            return false;

        reverse(this->Number.begin() , this->Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigDecimalInt NewObj;
        int sub = 0;
        int Carry = 0;
        if(this->Size > obj.GetSize()){
            for(int i=0 ; i<GetSize() ; i++)
            {
                if(i<=obj.GetSize()-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>obj.GetSize()-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else if(this->Size < obj.GetSize())
        {
            for(int i=0 ; i<obj.GetSize() ; i++)
            {
                if(i<=this->Size-1)
                {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.SetNumber(sub);
                }
                else if(i>this->Size-1)
                {
                    NewObj.SetNumber(this->Number[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->Size ; i++)
            {
                    sub = (this->Number[i] - obj.Number[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.SetNumber(sub);
            }
        }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        if(NewObj.sign == 0)
            return true;
        return false;
    }

    ///////////////////////////////////////////////////////
    friend std::ostream& operator << (std::ostream& out , const BigDecimalInt &obj)
    {
        for(int i = 0 ; i<obj.Number.size() ; i++)
        {
            out<<obj.Number[i];
        }
        out<<std::endl;
    }
};

#endif // BIGDECIMALINT_H_INCLUDED
