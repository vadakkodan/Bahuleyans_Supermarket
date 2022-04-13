#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main_exit;
float amount(float rate, int quantity, float discount, float vat);
int inventory ();
struct {
  int itemcode;
  int total_qty;
  char itemname[30];
  float price;
  float value;
}add,del,sta,inv;
int stock_add();
int stock_deletion();
int stock_status();
int prepare_invoice();

//////////////////////////////////////////////////////////////////////////////
//--------------------------------STOCK ADDITION----------------------------//
/////////////////////////////////////////////////////////////////////////////

int stock_add() {
  int choice;
  FILE *ptr;
  ptr=fopen("record.dat","a+");

item_code:
  system("clear");
  printf("\t\t\t NEW ITEM ADDITION\n");
  printf("Enter Item Code:");
  scanf("%d", &sta.itemcode);
  while(fscanf(ptr,"%d %s %d %f\n",&add.itemcode,add.itemname,&add.total_qty,&add.price)!=EOF)
  {
    if(sta.itemcode==add.itemcode)
    {
      printf("Itemcode already in use!");
      goto item_code;
    }
  }
  add.itemcode=sta.itemcode;
  
  printf("\nEnter the Item Name: ");
  scanf("%s",add.itemname);

  printf("\nEnter the Total Quantity: ");
  scanf("%d",&add.total_qty);

  printf("\nEnter the item price: ");
  scanf("%f",&add.price);

  fprintf(ptr,"%d %s %d %f\n",add.itemcode,add.itemname,add.total_qty,add.price);
  
  fclose(ptr);
  printf("\n Entry created successfully");

add_invalid:
  printf("\n\n Enter 1 to go to the main menu and 0 to exit:");
  scanf("%d", &main_exit);
  system("clear");
  if (main_exit==1)
    menu();
  else if (main_exit==0)
    close();
  else
  {
    printf("\nInvalid!\a");
    goto add_invalid;
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////
//-------------------------CLOSE FUNCTION----------------------------------//
/////////////////////////////////////////////////////////////////////////////

void close(void)
{
  printf("\n\n\n\nA VADAKKODAN group Project\n");
}


int stock_deletion() {
  return 0;
}
///////////////////////////////////////////////////////////////////////////
//--------------------- STOCK DETAILS VIEW-------------------------------//
//////////////////////////////////////////////////////////////////////////

int stock_status() {
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("clear");
    printf("\nItem Code \tItem Name \tTotal Quantity \t\tPrice\n");

    while(fscanf(view,"%d %s %d %f\n",&add.itemcode,add.itemname,&add.total_qty,&add.price)!=EOF)
       {
           printf("\n%6d \t\t%10s \t\t%6d \t\t%0.2f",add.itemcode,add.itemname,add.total_qty,add.price);
           test++;
       }

    fclose(view);
    if (test==0) {
      system("clear");
      printf("\nNO RECORDS!!\n");
    }

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("clear");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
 
  return 0;
}

///////////////////////////////////////////////////////////////////////////
//------------------------- SUM CALCULATION -----------------------------//
//////////////////////////////////////////////////////////////////////////

float total(float p, int q)
{
	float z;
	z = (p * q );
	return z;
}


///////////////////////////////////////////////////////////////////////////
//--------------------- PREPARE INVOICE ---------------------------------//
//////////////////////////////////////////////////////////////////////////

int prepare_invoice() {
	printf("\t\t\t\tBAHULEYANS' MART");
	printf("\n----------------------------------------------------------------------------------------------------------------");
  printf("\n\t\t\t\tCIN:KL91400MHPL2163");
  printf("\n\t\t\t\tGSTIN:29AACCA8432H1ZM");
  printf("\n\t\t\t\tFSSAI NO: 11214333001591");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	printf("\n\t\t\t\tOnampalli Junction");
  printf("\n\t\t\tBinu Bhavanam, Kandalloor North");
  printf("\n\t\t\tPattolimarket PO, Alapuzha- 690531");
	printf("\n\t\t\t\tPhone: 9746516926\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
  printf("\t\t\t\t\t\t TAX INVOICE");
  printf("\nBill No:\t\t\t\tBill Date:");
  printf("\nVou.No:\t\t\t\tCashier:");
	printf("\n----------------------------------------------------------------------------------------------------------------\n");
	printf("CODE\tPARTICULARS\t\t\t\t\t\t\t\tQTY\t\t N/RATE\t\t VALUE\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");
 
   
bill:
  FILE *ptr;
  int test=0,rate;
  int choice;
  ptr=fopen("record.dat","r");
  scanf("%d", &inv.itemcode);
  choice = inv.itemcode;


  while(fscanf(ptr,"%d %s %d %f\n",&add.itemcode,add.itemname,&add.total_qty,&add.price)!=EOF) {
    if (add.itemcode == inv.itemcode) {
      test = 1;
      printf ("\t%s\t\t\t\t%02.f\t\t\t\t", add.itemname,add.price);
    }
  }

  scanf("%d", &inv.total_qty);
  getchar();
  inv.value = total (add.price, inv.total_qty);
  printf("\t\t\t\t\t\t\t\t%0.2f\n",inv.value);
 }
  return 0;
}





///////////////////////////////////////////////////////////////////////////
//------------------------------- MENU ---------------------------------//
//////////////////////////////////////////////////////////////////////////

int menu() {
  int choice;
	system("clear");
	printf("\t\t\t\t MAIN MENU \t\t\t\t\n");
	printf("1.Stock Add \n");
	printf("2.Stock Deletion\n");
	printf("3.Stock Status\n");
	printf("4.Prepare Invoice\n");
	printf("Enter Your Choice:\n");

	
  scanf("%d",&choice);

    system("clear");
    switch(choice)
    {
        case 1:stock_add();
        break;
        case 2:stock_deletion();
        break;
        case 3:stock_status();
        break;
        case 4:prepare_invoice ();
        break;
        default:prepare_invoice();
    }
    return 0;
    
}

///////////////////////////////////////////////////////////////////////////////////
//---------------------------MAIN FUNCTION--------------------------------------//
//////////////////////////////////////////////////////////////////////////////////

int main() {
  menu();
/*	int i=1,j, quantity, cash, w = 0;
	long cash_received, newt_amount;
	float rate, discount, vat, t_amount=0, amount1, float_part;
	char itemcode[5], date[20];
for(j = 1; j!= 0; j++)
	{
		fgets(itemcode, 5, stdin);
		if(strcmp(itemcode, "0\n") == 0) {
			inventory();
		}
		if(strcmp(itemcode, "1\n") == 0)
		{
			printf("\tSunsilk Anti Dandruff Smooth and Silky Shampoo(375ml bottle)\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 290.00;
			discount = 25;
			vat = 2.5;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "2\n") == 0)
		{
			printf("\tV-Three casual bagpack\t\t\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 745.00;
			discount = 50;
			vat = 10.5;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "3\n") == 0)
		{
			printf("\tAdidas Men's T-Shirt-Red (Size L)\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 275.00;
			discount = 30;
			vat = 7.25;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "4\n") == 0)
		{
			printf("\tCadbury Silk Chocolates - Pack Of 10\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 800.00;
			discount = 20;
			vat = 9;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "5\n") == 0)
		{
			printf("\tChings Chinese - Instant Noodles 100gm\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 10.00;
			discount = 0;
			vat = 0.25;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "6\n") == 0)
		{
			printf("\tTupperware Bottle - 750 ml\t\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 999.00;
			discount = 10;
			vat = 9.3;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "7\n") == 0)
		{
			printf("\tSensodyne Cavity Protection Regular Toothpaste Tube (75 ml)\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 93.95;
			discount = 2;
			vat = 4.5;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "8\n") == 0)
		{
			printf("\tPepsodent Super-Flexy toothbrush\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 17.00;
			discount = 4;
			vat = 3;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "9\n") == 0)
		{
			printf("\tNivia Tennis ball - Pack of 12\t\t\t\t\t\t\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 810.00;
			discount = 12;
			vat = 8.75;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, "10\n") == 0)
		{
			printf("\tSparx Men's Free Trainer 5.0 Outdoor Multisport Training Shoes (Size 8/9/10)\t\t   ");
			scanf("%d", &quantity);
			getchar();
			rate = 8000.00;
			discount = 18;
			vat = 14;
			amount1 = amount(rate, quantity, discount, vat);
			printf("\t%0.2f\n", amount1);
			t_amount += amount1;
			w += quantity;
		}
		else if(strcmp(itemcode, " \n") == 0)
		{
			printf("TOTAL AMOUNT :\t%0.2f\n", t_amount);
			printf("----------------------------------------------------------------------------------------------------------------\n");
			j = -1;
		}
		else
		{
			printf("PRODUCT DOES NOT EXIST\n");
		}
	}
	printf("Total number of items sold = %d\n", w);
	printf("BALANCE DUE                = %0.2f\n", t_amount);
	newt_amount = t_amount;
	float_part = t_amount - newt_amount;
	if(float_part > 0.50)
		newt_amount += 1;
	printf("BALANCE DUE AFTER ROUNDING = %ld\n", newt_amount);
	A:
	printf("CASH RECEIVED              = ");
	scanf("%ld", &cash_received);
	if(cash_received < newt_amount)
	{
		printf("Amount insufficient. Please provide more money.\n");
		goto A;
	}
	printf("CHANGE TO BE RETURNED      = %ld\n", cash_received - newt_amount);
	printf("----------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\tCustomer Care Phone # : 1800 133 6702\n");
	printf("\t\t\tCustomer Care E-mail : custcare@gmail.com\n");
	printf("\t\t\tStore Phone # : 080-23316509\n");
	printf("\n\t\t\tCALL FOR FREE HOME DELIVERY.\n");
	printf("\n\t\t\t\tNo cash refunds.\n");
	printf("\t\t\tTerms and conditions apply.*\n");
	printf("\t\t\t** Thank you for shopping with us **\n");
	printf("\n*Any goods purchased from us can be exchanged along with presenting the original cash memo within 15 days from the date of purchase on any working day. Any electrical appliance purchased, is eligible for repair under warranty only if the original cash memo is shown.\n");
*/
  return 0;
}
float amount(float p, int q, float r, float s)
{
	float z;
	z = ((p * q) - (p * q * r / 100)) + (((p * q) - (p * q * r / 100)) * s / 100);
	return z;
}

int inventory (){
    char *filename = "readme.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // read one character at a time and
    // display it to the output
    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    // close the file
    fclose(fp);

    return 0;
}

