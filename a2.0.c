/*-------------------------------------------------------------------*/
/* ITS60304– Assignment #1 */
/* C Programming */
/* Student Name: <Nicholas Lai Jin Yung> <Liew Chun Yu> */
/* Student ID: <0329795> <0323567> */
/*-------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

char customerID[5], customerName[40], k[5];//Customer ID, Customer Name, Scan Customer ID
int previousReading, currentReading, newReading;//Previous Reading, Current Reading, and New Reading
float totalUsage, totalRevenue;
float charges;//Current charges
float newCharges, x=0;//Calculated charges for case 1
FILE *f1;//File pointer

void recordUsage();//Function prototype
void addCutomer();
void editCustomer();
void deleteCustomer();
void showCustomer();
void passByReference(float i, float j);
void showTotalMontlyIncome();
int main(void)//Function main begins program execution

struct customerDetails//Structure for files
{
    char customerID[5];
    char customerName[40];
    int previousReading;
    int currentReading;
    int newReading;
};

{
    char z[99];//Switch Case and printf customer found

	do//Loop menu after every function
    {
        printf("------------------------------------\n"
        "Electricity Management System\n"
        "------------------------------------\n"
        "1. Record Usage\n"
        "2. Add customer\n"
        "3. Edit customer\n"
        "4. Delete customer\n"
        "5. Show customer\n"
        "6. Show total monthly income\n"
        "7. Exit\n"
        "------------------------------------\n"
        "Enter Option:");
        scanf("%s",&z[0]);
        printf("------------------------------------\n");//Menu
        switch(z[0])//Menu options
        {
            case '1'://Record Usage
                recordUsage();
                break;
            case '2'://Add new customer
                addCutomer();
                break;
            case '3'://Edit customer info
                editCustomer();
                break;
            case '4'://Delete customer
                deleteCustomer();
                break;
            case '5'://Display list of customer details
                showCustomer();
                break;
            case '6':
                showTotalMontlyIncome();
                break;
            case '7'://Exit program
                printf("Exiting . . .\n");
                return 0;
            default://If invalid input enter a new one
                printf("Invalid Option Please Choose Again\n");
                break;
        }//End Switch
    }while(z!=7);//End Do While loop if case is 7
	return 0;
}

void recordUsage()
{
    float a, b, c, d, e, f;//Case 1 calculation
    int y;

    if((f1 = fopen("customer.txt", "r")) == NULL)
    {
        puts("Information is corrupted");
    }
    else
    {
        printf("Enter Customer ID, -1 to exit: ");
        scanf("%s", k);
        while(strcmp(k, "-1") != 0)
        {
            while(!feof(f1))//Loop until end of file
            {
                fscanf(f1,"%[^;];%[^;];%d;%d;%f\n", customerID, customerName, &previousReading, &currentReading, &charges);//Scan file
                if((strcmp(k, customerID)) == 0)//If customer ID is found then do calculations
                {
                    a=0, b=0, c=0, d=0, e=0, f=0, y=0;//Reset values when looping
                    printf("Enter current reading (in kWh): ");//Enter new reading
                    scanf("%d", &newReading);
                    newCharges = newReading - currentReading;//Calculate new charge
                    if(newCharges>0, newCharges<=200)
                    {
                        a = newCharges;
                    }
                    else if(newCharges>200, newCharges<=300)
                    {
                        b = newCharges-200;
                        a = 200;
                        b = x;
                    }
                    else if(newCharges>300, newCharges<=600)
                    {
                        c = newCharges-300;
                        a = 200;
                        b = 100;
                    }
                    else if(newCharges>600, newCharges<=900)
                    {
                        d = newCharges-600;
                        a = 200;
                        b = 100;
                        c = 300;
                    }
                    else if(newCharges>900)
                    {
                        e = newCharges-900;
                        a = 200;
                        b = 100;
                        c = 300;
                        d = 300;
                    }

                    f = a*0.218+b*0.334+c*0.516+d*0.546+e*0.571;
                    if(f<3)
                        f=3;
                    printf("------------------------------------\n");
                    printf("Customer ID  :%s\n", customerID);//Bill
                    printf("Customer Name:%s\n\n", customerName);
                    printf("%-22s%-21s%-14s%s\n", "Block Tariff (kWh)", "Block Usage (kWh)", "Rate (RM)", "Charges (RM)");
                    printf(" %-21d%7.2f%20.3f%15.2f\n", 200, a, 0.218, a*0.218);
                    printf(" %-21d%7.2f%20.3f%15.2f\n", 100, b, 0.334, b*0.334);
                    printf(" %-21d%7.2f%20.3f%15.2f\n", 300, c, 0.516, c*0.516);
                    printf(" %-21d%7.2f%20.3f%15.2f\n", 300, d, 0.546, d*0.546);
                    printf("%-22s%7.2f%20.3f%15.2f\n", ">300", e, 0.571, e*0.571);
                    printf("%-22s%7.2f%35.2f\n\n", "Total", a+b+c+d+e, a*0.218+b*0.334+c*0.516+d*0.546+e*0.571);
                    printf("%-16s%8s%10.2f\n\n", "Amount due", "RM", f);
                    printf("%-19s%-9s%-6s\n", " Meter Reading   ", "Usage", "Unit");
                    printf("%-9s%s\n", "Previous", "Current");
                    printf("%-9d%-10d%-9.2f%s\n", currentReading, newReading, newCharges, "kWh");
                    printf("------------------------------------\n");
                    passByReference(f,newCharges);
                    break;//Break out of loop if user found
                }
                else y=1;//If customer ID not found then print not found
            }
            if(y==1)
            {
                printf("\nCustomer not found, enter existing customer\n");
                printf("------------------------------------\n");
            }
            rewind(f1);//Reset pointer
            printf("Enter Customer ID, -1 to exit: ");
            scanf("%s", k);
        }
    }
    fclose(f1);
    return;
}

void addCutomer()//Case 2
{
    printf("This option allows user to add new customer\n");
    return;
}

void editCustomer()//Case 3
{
    printf("This option allows user to edit customer info\n");
    return;
}

void deleteCustomer()//Case 4
{
    printf("This option allows user to delete customer\n");
    return;
}

void showCustomer()//Case 5
{
    if((f1 = fopen("customer.txt", "r")) == NULL)//Opens file, if file is not there then
    {
        puts("Information is corrupted");//Print info is corrupted
    }
    else//Otherwise Scan the file
    {
        printf("%-5s %-17s %-17s %-16s %s\n","ID","Name","Previous Reading","Current Reading", "Charges");
        while(!feof(f1))
        {
            fscanf(f1,"%[^;];%[^;];%d;%d;%f\n", customerID, customerName, &previousReading, &currentReading, &charges);
            printf("%-5s %-17s %-17d %-16d %.2f\n", customerID, customerName, previousReading, currentReading, charges);
        }
    }
    fclose(f1);
}

void passByReference(float i, float j)
{
    totalUsage = totalUsage + j;
    totalRevenue = totalRevenue + i;
    return;
}

void showTotalMontlyIncome()//Case 6
{
    printf("Total usageKWh : %7.0f\n", totalUsage);
    printf("Total Revenue  : RM %6.2f\n", totalRevenue);
    return;
}
