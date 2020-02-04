/********
 Author: Lydarius Tutt
 Program: Money class - program assignment #1
 Due Date:2/3/2020
 Purpose:
 ********/
#include "money.h"
#include <math.h>
#include <iomanip>

// convert current currency values to a string
string Money::toString() {
  stringstream ss;

  ss << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << " ones " << quarters
     << " quarters " << dimes << " dimes " << nickels << " nickels " << cents << " pennies " ;

    return ss.str();
}

// format amount as a local currency and return

string Money::toCurrency(double amount) {

    stringstream stream;
    stream << "$" << std::fixed << std::setprecision(2) << amount;
    string s = stream.str();


    //stringstream ss;

    //ss << "$" << left << setfill('0') << setw(4) << amount;
    return s;


}

// convert currency to float
// read currency values from stdin and compute value
// return results
string Money::processChange() {
    stringstream ss;
  cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
  total=static_cast<double>(hundreds)*100+static_cast<double>(tens)*10+(static_cast<double>(fives)*5)+
  (static_cast<double>(ones)*1)+(static_cast<double>(quarters)*.25)+(static_cast<double>(dimes)*.10)+
  (static_cast<double>(nickels)*.05)+(static_cast<double>(cents)*.01);
  ss << toString()+" = "+toCurrency(total);
  return ss.str();
}

// read from stdin and process float command
// convert float to change
// return results
string Money::processFloat() {
    cin>>total;
    double fp=total;
    hundreds=total/100;
    total-=hundreds*100;
    tens=total/10;
    total-=tens*10;
    fives=total/5;
    total-=fives*5;
    ones=total/1;
    total-=ones;
    total*=100;
    quarters=total/25;
    total-=quarters*25;
    dimes=total/10;
    total-=dimes*10;
    nickels=total/5;
    total-=nickels*5;
    cents=(int)round(total);
    return toCurrency(fp)+" = "+toString();
}

// read from stdin and process check command
// convert float to dollar words & cents
// return results
string Money::processCheck() {
    cin>>total;
    stringstream ss;
    int dollars=total;
    double cent=total-dollars;
    cent=cent*100;
    ss<< "check for "<< toCurrency(total)<<" = "<< dollars<<" dollars and "<<cent<<" cents";
  return ss.str() ;
}

// read from stdin and process change-float command
// read float of customer payment
// read float of transaction cost
// calculate difference and compute change values
// return the results
string Money::processChangeFloat() {
    double purchase,change;
    cin >> total >>purchase;


    change=total-purchase;
    double fp=change;
    hundreds=fp/100;
    fp-=hundreds*100;
    tens=fp/10;
    fp-=tens*10;
    fives=fp/5;
    fp-=fives*5;
    ones=fp/1;
    fp-=ones;
    fp*=100;
    quarters=fp/25;
    fp-=quarters*25;
    dimes=fp/10;
    fp-=dimes*10;
    nickels=fp/5;
    fp-=nickels*5;
    cents=(int)round(fp);

    return "change back on "+toCurrency(total)+" for purchase of "+toCurrency(purchase)+" is "+toCurrency(change)+" "+toString();
}

// read from stdin and process change-change command
// read change of customer payment
// read float of transaction cost
// calculate difference and compute change values
// output the results
string Money::processChangeChange() {
    double purchase,change;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents>>purchase;
    total=static_cast<double>(hundreds)*100+static_cast<double>(tens)*10+(static_cast<double>(fives)*5)+
          (static_cast<double>(ones)*1)+(static_cast<double>(quarters)*.25)+(static_cast<double>(dimes)*.10)+
          (static_cast<double>(nickels)*.05)+(static_cast<double>(cents)*.01);

    change=total-purchase;
    double fp=change;
    hundreds=fp/100;
    fp-=hundreds*100;
    tens=fp/10;
    fp-=tens*10;
    fives=fp/5;
    fp-=fives*5;
    ones=fp/1;
    fp-=ones;
    fp*=100;
    quarters=fp/25;
    fp-=quarters*25;
    dimes=fp/10;
    fp-=dimes*10;
    nickels=fp/5;
    fp-=nickels*5;
    cents=(int)round(fp);

  return "change back on "+toCurrency(total)+" for purchase of "+toCurrency(purchase)+" is "+toCurrency(change)+" which is "+toString();
}
