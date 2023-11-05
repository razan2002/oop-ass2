#ifndef BIGREAL_H_INCLUDED
#define BIGREAL_H_INCLUDED


#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h>
#include "BigDecimalInt.h"

using namespace std;


class BigReal
{
private:
    int Size;
    int sign;
    std::string number;
    std::vector <int> Number;
    std::vector<int> floats;// for fraction

public:
    BigReal()
    {
        Size = 0;
    }
    int GetSize()
    {
        return Number.size();
    }

    BigReal(const BigReal& bigInteger)
    {
        for(int i=0 ; i<this->Number.size() ; i++)
        {
            this->Number.push_back(bigInteger.Number[i]);
        }

        for(int i=0 ; i<this->floats.size() ; i++)
        {
            this->floats.push_back(bigInteger.floats[i]);
        }

    }

    void SetNumber(int Data)//to use it in addition and subtraction
    {
        Number.push_back(Data);
    }
    void set_float_number(int data)
    {
        floats.push_back(data);
    }

    BigReal(int decInt)
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
    BigReal(std::string decStr)
    {
        int Num;
        int stop = 0;
            if(decStr[0]=='-')
            {
                this->sign = 1;// 1 stands for negative
                decStr.erase(decStr.begin()+0);
          for(int i=0 ; i<decStr.size() ; i++)
            {
                    if(decStr[i] != '.')
                    {
                        Num = decStr[i] - 48;
                  Number.push_back(Num);
                    }
                    else
                    {
                        stop = i;
                        break;
                    }
            }
            for(int i=stop+1 ; i<decStr.size() ; i++)
            {
                    if(decStr[i] != '.')
                    {
                        Num = decStr[i] - 48;
                    floats.push_back(Num);
                    }
            }
            Number[0] = Number[0] * (-1);
            }
            else{
            for(int i=0 ; i<decStr.size() ; i++)
            {
                    if(decStr[i] != '.')
                    {
                        Num = decStr[i] - 48;
                  Number.push_back(Num);
                    }
                    else
                    {
                        stop = i;
                        break;
                    }
            }
            for(int i=stop+1 ; i<decStr.size() ; i++)
            {
                    if(decStr[i] != '.')
                    {
                        Num = decStr[i] - 48;
                    floats.push_back(Num);
                    }
            }
            }
            /*the previous operations to turn string into integer*/
    }

    int get_floats_size()
    {
        return this->floats.size();
    }
    ///////////////////////////////////////////
    int get_sign()
    {
        return this->sign;
    }

    BigReal operator+(BigReal &obj)
    {
        reverse(Number.begin() , Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigReal NewObj;
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

     ///////////////////////////////////////////////////////////
     //add the fraction
     reverse(floats.begin() , floats.end());
        reverse(obj.floats.begin() , obj.floats.end());
        sum = 0;
        sum2 = 0;
        Carry = 0;
      if(this->get_floats_size() > obj.get_floats_size())
      {
        for(int i=0 ; i<get_floats_size() ; i++)
        {
            if(i<=obj.get_floats_size()-1)
            {
                sum = (this->floats[i] + obj.floats[i] + Carry);
                sum2 = sum % 10;
                NewObj.set_float_number(sum2);
            }
            else if(i>obj.get_floats_size()-1)
            {
                sum = this->Number[i] + Carry;
                NewObj.set_float_number(sum);
            }
                  Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.set_float_number(Carry);
        }
    }
     else if(this->floats.size() < obj.get_floats_size())
     {
         for(int i=0 ; i<obj.get_floats_size() ; i++)
        {
            if(i<=this->floats.size()-1)
            {
                sum = (this->floats[i] + obj.floats[i] + Carry);
                sum2 = sum % 10;
                NewObj.set_float_number(sum2);
            }
            else if(i>this->floats.size()-1)
            {
                sum = obj.floats[i] + Carry;
                NewObj.set_float_number(sum);
            }
                  Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.set_float_number(Carry);
        }
     }
     else
     {
         for(int i=0 ; i<this->floats.size() ; i++)
        {
            sum = this->floats[i] + obj.floats[i] + Carry;
            sum2 = sum % 10;
            NewObj.set_float_number(sum2);
            Carry = sum / 10;
        }
      if(Carry)
        {
            NewObj.set_float_number(Carry);
        }
     }
        reverse(NewObj.Number.begin() , NewObj.Number.end());
        reverse(NewObj.floats.begin() , NewObj.floats.end());
        return NewObj;
    }

    /////////////////////////////////////////////////
    BigReal operator-(BigReal obj)
    {
        reverse(this->Number.begin() , this->Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigReal NewObj;
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

        //////////////////////////////////////////////////////////

        reverse(this->floats.begin() , this->floats.end());
        reverse(obj.floats.begin() , obj.floats.end());
        sub = 0;
        Carry = 0;
        if(this->floats.size() > obj.get_floats_size()){
            for(int i=0 ; i<get_floats_size() ; i++)
            {
                if(i<=obj.get_floats_size()-1)
                {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.set_float_number(sub);
                }
                else if(i>obj.get_floats_size()-1)
                {
                    NewObj.set_float_number(this->Number[i]);
                }
            }
        }
        else if(this->floats.size() < obj.get_floats_size())
        {
            for(int i=0 ; i<obj.get_floats_size() ; i++)
            {
                if(i<=this->floats.size()-1)
                {
                    sub = (this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.set_float_number(sub);
                }
                else if(i>this->Size-1)
                {
                    NewObj.set_float_number(this->Number[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->floats.size() ; i++)
            {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.set_float_number(sub);
            }
        }


        reverse(NewObj.Number.begin() , NewObj.Number.end());
        reverse(NewObj.floats.begin() , NewObj.floats.end());
        return NewObj;
    }


    bool operator< (BigReal obj)
    {
        if(this->sign == 1 && obj.sign == 0)
            return true;
        else if(this->sign == 0 && obj.sign == 1)
            return false;
        else if(this->Number.size() > obj.GetSize())
            return false;
        else if(this->Number.size() < obj.GetSize())
            return true;

        else if(this->Number.size() == obj.Number.size()
                && this->floats.size() > obj.floats.size())
                    return false;
        else if(this->Number.size() == obj.Number.size()
                && this->floats.size() < obj.floats.size())
                    return true;

        std::reverse(this->Number.begin() , this->Number.end());
        std::reverse(obj.Number.begin() , obj.Number.end());

        std::reverse(this->floats.begin() , this->floats.end());
        std::reverse(obj.floats.begin() , obj.floats.end());

        BigReal NewObj;
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

        sub = 0;
        Carry = 0;
        if(this->floats.size() > obj.get_floats_size()){
            for(int i=0 ; i<this->floats.size() ; i++)
            {
                if(i<=obj.GetSize()-1)
                {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.set_float_number(sub);
                }
                else if(i>obj.get_floats_size()-1)
                {
                    NewObj.set_float_number(this->floats[i]);
                }
            }
        }
        else if(this->floats.size() < obj.get_floats_size())
        {
            for(int i=0 ; i<obj.get_floats_size() ; i++)
            {
                if(i<=this->floats.size()-1)
                {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.set_float_number(sub);
                }
                else if(i>this->floats.size()-1)
                {
                    NewObj.set_float_number(this->floats[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->floats.size() ; i++)
            {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.set_float_number(sub);
            }
        }

        std::reverse(NewObj.Number.begin() , NewObj.Number.end());
        std::reverse(NewObj.floats.begin() , NewObj.floats.end());
        if(NewObj.sign == 0)
            return false;
        return true;
    }
    //////////////////////////////////////////////////////

    bool operator> (BigReal obj)
    {
        if(this->sign == 1 && obj.get_sign() == 0)
            return false;
        else if(this->sign == 0 && obj.get_sign() == 1)
            return true;
        else if(this->Number.size() > obj.GetSize())
            return true;
        else if(this->Number.size() < obj.GetSize())
            return false;

        reverse(this->Number.begin() , this->Number.end());
        reverse(obj.Number.begin() , obj.Number.end());
        BigReal NewObj;
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
        sub = 0;
        Carry = 0;
        if(this->floats.size() > obj.get_floats_size()){
            for(int i=0 ; i<this->floats.size() ; i++)
            {
                if(i<=obj.GetSize()-1)
                {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.set_float_number(sub);
                }
                else if(i>obj.get_floats_size()-1)
                {
                    NewObj.set_float_number(this->floats[i]);
                }
            }
        }
        else if(this->floats.size() < obj.get_floats_size())
        {
            for(int i=0 ; i<obj.get_floats_size() ; i++)
            {
                if(i<=this->floats.size()-1)
                {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else
                        Carry = 0;
                    NewObj.set_float_number(sub);
                }
                else if(i>this->floats.size()-1)
                {
                    NewObj.set_float_number(this->floats[i]);
                }
            }
        }
        else
        {
            for(int i=0 ; i<this->floats.size() ; i++)
            {
                    sub = abs(this->floats[i] - obj.floats[i] - Carry);
                    if(sub<0)
                    {
                        sub+=10;
                        Carry = 1;
                    }
                    else{
                        Carry = 0;
                        }
                    NewObj.set_float_number(sub);
            }
        }

        reverse(NewObj.Number.begin() , NewObj.Number.end());
        reverse(NewObj.floats.begin() , NewObj.floats.end());
        if(NewObj.sign == 0)
            return true;
        return false;
    }

    bool operator== (BigReal anotherDec)
    {
        if(this->Number.size() != anotherDec.Number.size() ||
           this->floats.size() != anotherDec.floats.size())
            return false;
        for(int i=0 ; i<anotherDec.GetSize() ; i++)
        {
            if(this->Number[i] != anotherDec.Number[i])
                return false;
        }
        for(int i=0 ; i<this->floats.size() ; i++)
        {
            if(this->floats[i] != anotherDec.floats[i])
                return false;
        }
        return true;
    }


    friend std::ostream& operator << (std::ostream& out , const BigReal &obj)
    {
        for(int i = 0 ; i<obj.Number.size() ; i++)
        {
            out<<obj.Number[i];
        }
        std::cout<<'.';
        for(int i = 0 ; i<obj.floats.size() ; i++)
        {
            out<<obj.floats[i];
        }
        out<<std::endl;
    }

    friend std::istream& operator >> (std::istream& in , BigReal &obj)
    {
        in>>obj.number;
        return in;
    }

};




#endif // BIGREAL_H_INCLUDED
