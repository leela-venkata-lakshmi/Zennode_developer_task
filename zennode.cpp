#include <bits/stdc++.h>
using namespace std; 

//Function to calculate discount rule 1.
int discount_rule1(int cart_total_price){
    int discount_amount=0;
    if(cart_total_price>200)
    {
  
            cart_total_price=cart_total_price-10;
            discount_amount=10;
    }
    return discount_amount;
}

//Function to calculate discount rule 2.

int discount_rule2(int max){
    int discount_amount=0;
    
        if(max>10)
        {
          
           max=max*20;
           int temp=max*0.95;
           discount_amount=max-temp;
        }
    
    return discount_amount;
}

//Function to calculate discount rule 3.

int discount_rule3(int cart_total,int cart_total_price){

    int discount_amount=0;
    if(cart_total>20)
    {
     
      int temp=cart_total_price*0.90;
       discount_amount=cart_total_price-temp;
   }
   return discount_amount;
}

//Function to calculate discount rule 4.

int discount_rule4(int max,int cart_total){
    int discount_amount=0;
    int temp;
    
    if(cart_total>30)
   {
      
       if(max>15)
       {
           temp=max-15;
           temp*=50;
           temp/=2;
           discount_amount=temp;
        }
   
   }
   return discount_amount;
}

//main function

int main() 
{
    //Taking input from the user
   int A,B,C;
   cout<<"The quantity of product A:"<<endl;
   cin>>A;
   cout<<"The quantity of product B:"<<endl;
   cin>>B;
   cout<<"The quantity of product C:"<<endl;
   cin>>C;

   //finding max quantity of product
   int max;
   if(A>B && A>C){max=A;}else if(B>A && B>C){max=B;}else{max=C;}

   string discount_name;
   int discount_amount;
   
   //calculating number of units of user
   double num_of_units=A+B+C;
   
   cout<<"product: A"<<" "<<A<<" "<<A*20<<endl;
   cout<<"product: B"<<" "<<B<<" "<<B*40<<endl;
   cout<<"product: C"<<" "<<C<<" "<<C*50<<endl;
   
   //calculating total cart price of user
   int sub_total=(A*20)+(B*40)+(C*50);
   cout<<"Sub total is:"<<sub_total<<endl;
   
   //retrieving discounts of each rule from functions
   int flat_10_discount= discount_rule1(sub_total);
   int bulk_5_discount= discount_rule2(max);
   int bulk_10_discount= discount_rule3(num_of_units,sub_total);
   int tiered_50_discount= discount_rule4(max, num_of_units);
   
   //making a vector of pair with discount amount and discount name
   vector <pair<int,string>> pairs;
   pairs={{flat_10_discount,"flat_10_discount"},{bulk_5_discount,"bulk_5_discount"},{bulk_10_discount,"bulk_10_discount"},{tiered_50_discount,"tiered_50_discount"}};
   
   // Finding maximum discount
   const auto p = max_element(pairs.begin(), pairs.end());
    discount_amount=p->first;
    discount_name=p->second;
  
  // Printing discount name and discount amount
    cout<<"Discount Name is: "<<discount_name<<endl;
    cout<<"Discount Amount is:"<<discount_amount<<endl;
    
    //Subtracting discount amount from sub total
   
   sub_total=sub_total-discount_amount;
   int total_amount;
   total_amount=sub_total;
   // Inquiry regarding gift wrap
   cout<<"Enter yes if your product A is wrapped as a gift? "<<endl;
   string gift_wrap;
   int gift_wrap_fee=0;
   cin>>gift_wrap;
   if(gift_wrap=="yes")
   {
       gift_wrap_fee+=A;
       
   }
   cout<<"Enter yes if your product B is wrapped as a gift? "<<endl;
   cin>>gift_wrap;
   if(gift_wrap=="yes")
   {
       gift_wrap_fee+=B;
      
   }
   cout<<"Enter yes if your product C is wrapped as a gift? "<<endl;
   cin>>gift_wrap;
   if(gift_wrap=="yes")
   {
       gift_wrap_fee+=C;
   }
   cout<<"Gift wrap fee is:"<<gift_wrap_fee<<endl;
   //Adding gift wrap fee
   total_amount+=gift_wrap_fee;
   //Adding shipping fee
   num_of_units=ceil(num_of_units/10);
   num_of_units*=5;
   total_amount=total_amount+num_of_units;
   cout<<"Shipping fee is: "<<num_of_units<<endl;
   
   // Printing total amount.
   cout<<"Total amount is: "<<total_amount<<endl;
    
}
