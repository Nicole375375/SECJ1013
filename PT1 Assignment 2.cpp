//Assignment 2 PT1
//Nicole Lee A24CS0287
//Sam Wei Leng A24CS0295
//26.12.2024

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double getPrice_X50(int);
double getPrice_Exora(int);
double getPrice_Persona(int);
void showInfo(int,int,int);
double monthlyInstallment(double,double,double,int);

int main()
{
    int choice1,choice2,choice3,yrs;
    double price,down_payment,rate,installment;
    char ans;
    
    do{
    cout<<"Proton Car Loan Calculator"<<endl<<endl;
    cout<<"Model [1-X50, 2-Exora, 3-Persona]: ";
    cin>>choice1;
    
    //Input validation
    while(choice1 !=1 && choice1 !=2 && choice1!=3){
        cout<<"Invalid input.Only 1-3 is accepted."<<endl;
        cin>>choice1;
    }
    
    
        if(choice1==1){
         cout<<"Variants [1-1.5T Standard, 2-1.5T Executive, 3-1.5T Premium, 4-1.5TGDi Flagship]: ";
         cin>>choice2;
         cout<<"Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
         cin>>choice3;
         price=getPrice_X50(choice2);
         
         if(choice3==2){
         	price=price+2000.04;
		 }
    }
    
    else if(choice1==2){
         cout<<"Variants [1-1.6T Executive CVT, 2-1.6T Premium CVT]:";
         cin>>choice2;
         cout<<"Region [1-Peninsular Malaysia, 2-East Malaysia]:";
         cin>>choice3;
         price=getPrice_Exora(choice2);
         
         if(choice3==2){
         	price=price+2000.04;
		 }
    }
    
    else if(choice1==3){
        cout<<"Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
        cin>>choice2;
        cout<<"Region [1-Peninsular Malaysia, 2-East Malaysia]:";
        cin>>choice3;
        price=getPrice_Persona(choice2);
        
        if(choice3==2){
         	price=price+2000.04;
		 }
        
    }
    cout<<endl;
    showInfo(choice1,choice2,choice3);
    cout<<"Paint Type: Metallic"<<endl;
    cout << fixed << setprecision(2); 
    cout<<"Price (MYR): "<<price<<endl<<endl;
    
    cout<<"Down Payment (MYR): ";
    cin>>down_payment;
    cout<<"Interest Rate (%): ";
    cin>>rate;
    cout<<"Repayment period (in years): ";
    cin>>yrs;
    cout<<endl;
    
    installment=monthlyInstallment(down_payment,price,rate,yrs);
    cout << fixed << setprecision(2);
    cout<<"MONTHLY INSTALLMENT (MYR): "<<installment<<endl<<endl;
    cout<<"Do you want to enter other data? [Y @ N]: ";
    cin>>ans;
    }while(ans=='y' || ans=='Y');
    
    cout<<endl;
    cout<<"Thank you :)"<<endl;
    return 0;
}

//Get price of car X50 based on its variants
double getPrice_X50(int choice2){
	double price;
    switch(choice2){
        case 1 : price= 86300.00;
        break;
        
        case 2 : price= 93300.00;
        break;
        
        case 3 : price= 101800.00;
        break;
        
        case 4 : price= 113300.00;
        break;
        }
        return price;
}

//Get price of car Exora based on its variants
double getPrice_Exora(int choice2){
	double price;
    switch(choice2){
        case 1 : price= 62800.00;
        break;
        
        case 2 : price= 69800.00;
        break;
    }
    return price;
}

//Get price of car Persona based on its variants
double getPrice_Persona(int choice2){
	double price;
    switch(choice2){
        case 1 : price= 44600.00;
        break;
        
        case 2 : price= 54600.00;
        break;
    }
    return price;
}

void showInfo(int choice1,int choice2,int choice3){
    cout<<"Car Info"<<endl;
    //For Car model X50
    if (choice1==1){
        cout<<"Model: X50"<<endl;
        switch(choice2){
            case 1 : cout<<"Variant: 1.5T Standard"<<endl;
            break;
            
            case 2 : cout<<"Variant: 1.5T Executive"<<endl;
            break;
            
            case 3 : cout<<"Variant: 1.5T Premium"<<endl;
            break;
            
            case 4 : cout<<"Variant: 1.5TGDi Flagship"<<endl;
            break;
        }
    }
    
    //For car model Exora
     if (choice1==2){
        cout<<"Model: Exora"<<endl;
        switch(choice2){
            case 1 : cout<<"Variant: 1.6T Executive CVT"<<endl;
            break;
            
            case 2 : cout<<"Variant: 1.6T Premium CVT"<<endl;
            break;
        }
     }
     
     //For car model Persona
      if (choice1==3){
        cout<<"Model: Persona"<<endl;
        switch(choice2){
            case 1 : cout<<"Variant: 1.6L Standard CVT"<<endl;
            break;
            
            case 2 : cout<<"Variant: 1.6L Premium CVT"<<endl;
            break;
        }
      }
      
      switch(choice3){
            case 1 : cout<<"Region: Peninsular Malaysia"<<endl;
            break;
            
            case 2 : cout<<"Region: East Malaysia"<<endl;
            break;
        }
        
}

//Calculate monthlyInstallment 
double monthlyInstallment(double down_payment, double price, double rate, int yrs){
	double totalLoan, totalInterest, monthlyinstall;
	
	totalLoan = price - down_payment;
	totalInterest = (rate/100)*totalLoan*yrs;
	monthlyinstall = (totalLoan + totalInterest)/(yrs*12);
	
	return round(monthlyinstall * 100.0+0.5) / 100.0;
}


