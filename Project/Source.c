#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
int bid; float total; int t;
FILE* start, * safe;
struct tm tm;
typedef struct
{
	char name_f[20];
	char name_l[20];
	int selection;
	int travel_city;
	int travel_mode;
	char travel_cityn[10];
	char travel_moden[10];
	int day;
	int month;
	int year;
	int package_no;
	int package_class;
	char package_details[500];
	int adults;
	int children;
	int infants;
	char payment_method[25];
	int tot;
	float bill;
	char date[10];
	char cardnum[20];
}trips;
basic(); basicanim(); travel(); packages(); card(); upi(); netbanking(); billprint(); bill();
char str1[100] = "Welcome to Karnataka\n";
char str2[100] = "\"One state Many Worlds\"\n\n";
char str3[100] = "GoTo...UrAdvisor\nEnjoy our services\n\n";
char receipt[10000];
char str[10];
buildrec()
{
	safe = fopen("exec.txt", "w");
	fprintf(safe, "%d", 1);
	fclose(safe);
}
recovery()
{
again:
	start = fopen("exec.txt", "r");
	if (start == NULL)
	{
		buildrec();
		goto again;
	}
	fscanf(start, "%d", &bid);
	fclose(start);
}
int primary(trips* a)
{
	time_t t = time(NULL);
	tm = *localtime(&t);
	int c;
	char date[20];
	printf("Please select the service you need\n\n");
	printf("1 : For a New Booking\n");
	printf("2 : To View or Print Previous Bill\n");
	printf("0 : To Exit program\n\n");
	scanf("%d", &c);
	printf("\n");
	if (c == 1)
	{
		printf("Enter your first name : ");
		scanf("%s", a->name_f);
		printf("\nEnter your last name : ");
		scanf("%s", a->name_l);
		printf("\nEnter the date of travelling\n");
	year: printf("Year : ");
		scanf("%d", &a->year);
		if (a->year == tm.tm_year + 1900)
		{
		month:	printf("\nMonth: ");
			scanf("%d", &a->month);
			if (a->month < 1 || a->month>12)
			{
				printf("\nThis month does not exist\nPlease enter a different month\n");
				goto month;
			}
			if (a->month == tm.tm_mon + 1)
			{
			day:	printf("\nDay  : ");
				scanf("%d", &a->day);
				if (a->day < 1 || a->day>31)
				{
					printf("\nThis day does not exist\nPlease enter a different day\n");
					goto day;
				}
				if (a->day >= (tm.tm_mday + 3));
				else
				{
					printf("\nThe bookings are closed for the entered day please choose another day");
					goto day;
				}
			}
			else if (a->month > tm.tm_mon + 1)
			{
			day1:
				printf("\nDay  : ");
				scanf("%d", &a->day);
				if (a->day < 1 || a->day > 31)
				{
					printf("\nThis day does not exist\nPlease enter a different day\n");
					goto day1;
				}
			}
			else
			{
				printf("Invalid input of month Enter another month");
				goto month;
			}
		}
		else if (a->year > tm.tm_year + 1900)
		{
		month2:
			printf("\nMonth: ");
			scanf("%d", &a->month);
			if (a->month < 1 || a->month>12)
			{
				printf("\nThis month does not exist\nPlease enter a different month\n");
				goto month2;
			}
		day2:
			printf("\nDay  : ");
			scanf("%d", &a->day);
			if (a->day < 1 || a->day > 31)
			{
				printf("\nThis day does not exist\nPlease enter a different day\n");
				goto day2;
			}
		}
		else
		{
			printf("Invalid input of year Enter another year\n");
			goto year;
		}
		sprintf(date, "%d/%d/%d", a->day, a->month, a->year);
		strcpy(a->date, date);
		system("CLS");
		basic();
	choice:
		printf("\nPlease enter the suitable choice for you\n\n");
		printf("1 : Book travel to Bangalore\n");
		printf("2 : Book travel package in Karnataka\n");
		printf("0 : To Exit program\n\n");
		scanf("%d", &c);
		a->selection = c;
		if (c == 0)exit(0);
		if (c < 0 || c>2)
		{
			{
				printf("Invalid input. Please verify ur choice and enter\n"); Sleep(1500); system("CLS");
				basic();
				goto choice;
			}
		}
		return(c);
	}
	else if (c == 2)
	{
		printf("\nPlease enter the suitable choice for you\n\n");
		printf("1 : View previous booking to Bangalore\n");
		printf("2 : View previously booked travel package in Karnataka\n");
		printf("0 : To Exit program\n\n");
		if (c == 0)exit(0);
		if (c < 0 || c>2)
		{
			{
				printf("Invalid input. Please verify ur choice and enter\n"); Sleep(2000); system("CLS");
				basic();
				primary(a);
			}
		}
		return(c + 2);
	}
	else if (c == 0)exit(0);
	else
	{
		printf("Invalid input. Please verify ur choice and enter\n"); Sleep(2000); system("CLS");
		basic();
		primary(a);
	}
}
basicanim()
{
	for (int i = 0; i < strlen(str3); i++)
	{
		printf("%c", str3[i]);
		Sleep(100);
	}
	Sleep(500);
	for (int i = 0; i < strlen(str1); i++)
	{
		printf("%c", str1[i]);
		Sleep(100);
	}
	Sleep(500);
	for (int i = 0; i < strlen(str2); i++)
	{
		printf("%c", str2[i]);
		Sleep(100);
	}
	Sleep(750);
}
basic()
{
	printf("%s", str3);
	printf("%s", str1);
	printf("%s", str2);
}
travel(trips* a)
{
	char mode[5][10] = { "Flight","Train","Bus","Car rental","\0" };
	char city[6][10] = { "Delhi","Mumbai","Goa","Chennai","Cochin","\0" };
	basic();
	int ch1, ch2;
con1:
	printf("FROM CITY..\n\n");
	printf("1 : Delhi\n2 : Mumbai\n3 : Goa\n4 : Chennai\n5 : Cochin\n\n");
	scanf("%d", &ch1);
	if (ch1 < 1 || ch1>5)
	{
		printf("Invalid input for city\nPlease Enter the correct city\n\n");
		Sleep(1500);
		system("CLS");
		basic(); goto con1;
	}
	a->travel_city = ch1;
	strcpy(a->travel_cityn, city[ch1 - 1]);
con2:printf("\nHow would u like to travel to Bengaluru\n\n");
	printf("1 : Flight\n2 : Train\n3 : Bus\n4 : Cab Rental\n\n");
	scanf(" %d", &ch2);
	if (ch2 < 1 || ch2>4)
	{
		printf("Invalid input for travel mode\nPlease select the right mode to travel\n");
		goto con2;
	}
	else;
	a->travel_mode = ch2;
	strcpy(a->travel_moden, mode[ch2 - 1]);
}
packages(trips* a)
{
	int ch1, ch2;
	basic();
	char str[6][200] = { "1 : Gems of South\n\t - 2N Coorg\n\t - 2N Ooty\n\t - 1N Mysore\n\n",
						 "2 : A 6 Nights holiday to South\n\t- 1N Bangalore\n\t- 1N Mysore\n\t- 2N Coorg\n\t- 2N Ooty\n\n",
						 "3 : Explore the Vijayanagar Empire\n\t- 2N Hampi\n\n",
						 "4 : Discovering waterfall of Karnataka\n\t- 2N Shimoga\n\t- 1N Siganduru\n\n",
						 "5: Amazing South (Luxury Honeymoon Special)\n\t- 1N Bangalore\n\t- 1N Mysore\n\t- 2N Ooty\n\t- 2N Kodaikanal\n\n",
						 "6 : Upclose to Nature in Kabini\n\t- 2N Kabini\n\n" };
pack:
	printf("Select a package to continue\n\n");
	for (int i = 0; i < 6; i++)
		printf(str[i]);
	scanf("%d", &ch1);
	if (ch1 < 1 || ch1>6)
	{
		printf("Invalid package selection\nPlease enter the right package\n");
		Sleep(1500);
		system("CLS");
		basic();
		goto pack;
	}
	a->package_no = ch1;
	strcpy(a->package_details, str[ch1 - 1]);
priv:
	printf("\nSelect class of package\n\n");
	printf("1 : Economy\n");
	printf("2 : Semi-Premium\n");
	printf("3 : Premium\n\n");
	scanf("%d", &ch2);
	if (ch2 < 1 || ch2>3)
	{
		printf("Invalid choice of travel class\nPlease select the right class of travel\n");
		goto priv;
	}
	a->package_class = ch2;
}
details(trips* a)
{
	basic();
	int ad, c, i;
	printf("Please enter the following details to continue booking\n");
	printf("\nEnter the number of Adults   ( 18+ )     : ");
	scanf("%d", &ad);
	printf("\nEnter the number of Children ( 3 to 18 ) : ");
	scanf("%d", &c);
	printf("\nEnter the number of infants  ( under 3 ) : ");
	scanf("%d", &i);
	a->adults = ad;
	a->children = c;
	a->infants = i;
	a->tot = ad + c + i;
}
bill(trips* a)
{
	switch (a->selection)
	{
	case 1:
	{
		int c[5] = { 6000,5000,4500,3000,4000 };
		switch (a->travel_mode)
		{
		case 1:
		{
			total = ((a->adults * c[a->travel_city - 1]) + (a->children * c[a->travel_city - 1] / 2.0));
			break;
		}
		case 2:
		{
			total = ((a->adults * c[a->travel_city - 1] / 4) + (a->children * c[a->travel_city - 1] / 8.0));
			break;
		}
		case 3:
		{
			total = ((a->adults * c[a->travel_city - 1] / 6) + (a->children * c[a->travel_city - 1] / 12.0));
			break;
		}
		case 4:
		{
			if (a->tot <= 4)
			{
				total = c[a->travel_city - 1];
			}
			else if (a->tot > 4 && a->tot <= 7)
			{
				total = c[a->travel_city - 1] * 1.6;
			}
		}break;
		}
	}break;
	case 2:
	{
		int cost[6] = { 33500,42200,24000,38400,80000,44490 };
		if (a->package_class == 1)
			total = ((a->adults * cost[a->package_no - 1]) + (a->children * cost[a->package_no - 1] / 2) * .6);
		if (a->package_class == 2)
			total = ((a->adults * cost[a->package_no - 1]) + (a->children * cost[a->package_no - 1] / 2));
		if (a->package_class == 3)
			total = ((a->adults * cost[a->package_no - 1]) + (a->children * cost[a->package_no - 1] / 2) * 1.4);
	}break;
	}
	a->bill = (total + (total * (5.0 / 100)));//including gst
}
payment(trips* a)
{
	time_t t = time(NULL);
	int l = 0;
	char strl[20] = "Loading...";
	char strb[30] = "Payment is being processed";
	int ch;
	printf("Enter your choice for payment method\n\n");
	printf("1 : Debit or Credit Card\n");
	printf("2 : Bank UPI\n");
	printf("3 : Netbanking\n\n");
	scanf("%d", &ch);
	system("CLS");
	switch (ch)
	{
	case 1:
	{
		char card[1000];
		char cnum[100], expiry[20], yy[2], mm[2];
		int check, m, y, cvv;
		strcpy(a->payment_method, "Card - ");
	card_num:
		check = 0;
		printf("Enter the 16 digit card number\n");
		scanf("%s", cnum);
		for (int i = 0; cnum[i] != '\0'; i++)
		{
			check++;
		}
		if (check != 16)
		{
			printf("Invalid card number\nPlease check and enter again\n\n");
			goto card_num;
		}
		printf("\n");
	exp:
		printf("Enter expiry date in the format of MM/YY\n");
		scanf("%s", &expiry);
		if (strlen(expiry) != 5)
		{
			printf("Invalid Expiry date\nPlease check and enter again\n");
			goto exp;
		}
		for (int i = 0; i < 2; i++)
		{
			yy[i] = expiry[i + 3];
			mm[i] = expiry[i];
		}
		m = atoi(mm);
		y = atoi(yy);
		y = y + 2000;
		if (m < 1 || m>12)
		{
			printf("\nThis month does not exist\nPlease enter a different month\n\n");
			goto exp;
		}
		if (y > (tm.tm_year + 1900));
		else if (y == (tm.tm_year + 1900))
		{
			if (m >= (tm.tm_mon + 1));
			else
			{
				printf("Card already expired\nPlease enter a new card\n");
				goto card_num;
			}
		}
		else
		{
			printf("Card already expired\nPlease enter a new card\n");
			goto card_num;
		}
		printf("\n");
	cvv:
		check = 0;
		printf("Enter the cvv of the card (back of the card)\n");
		scanf("%d", &cvv);
		for (int i = 0; cvv != 0; i++)
		{
			check++;
			cvv = cvv / 10;
		}
		if (check != 3)
		{
			printf("Invalid cvv number\nPlease check and enter again\n\n");
			goto cvv;
		}
		int j = 0;
		for (int i = 0; i < 16; i++)
		{
			if ((j + 1) % 5 == 0)
			{
				a->cardnum[j] = ' ';
				j++;
			}
			if (i < 4 || i>11)
				a->cardnum[j] = cnum[i];
			else
				a->cardnum[j] = 'X';
			j++;
		}a->cardnum[j] = '\0';
		strcat(a->payment_method, a->cardnum);
		int it = 0;
		char ex1[100] = "\n[   CARD         "; char ex2[100] = "    ]";
		strcat(ex1, expiry);
		strcat(ex1, ex2);
		char nu1[100] = "\n[   "; char nu2[100] = "   ]";
		strcat(nu1, a->cardnum);
		strcat(nu1, nu2);
		char staend[40] = "\n[-------------------------]";
		char space[40] = "\n[                         ]";
		strcpy(card, staend);
		strcat(card, space);
		strcat(card, ex1);
		strcat(card, space);
		strcat(card, nu1);
		strcat(card, space);
		strcat(card, staend);
		for (it = 0; it < 40; it++)
		{
			for (int a = 0; card[a] != '\0'; a++)
			{
				if (card[a] == '[')
				{
					for (int j = 0; j < it; j++)
						printf("  ");
				}
				printf("%c", card[a]);
			}
			Sleep(50);
			system("CLS");
		}
		printf("Payment recieved through card");
		printf("\n");
		break;
	}
	case 2:
	{
		strcpy(a->payment_method, "UPI");
	loop1:
		printf("Please scan the respective QR code and pay through your phone\n\n");
		printf("\n___|||||----||||");
		printf("\n||||||---|||||0|");
		printf("\n---|||||--||||||");
		printf("\n||||||||||||--||");
		printf("\n|||--||0|| --||_");
		printf("\n|||||--||-||--|-");
		printf("\n|||--|||||---|||\n\n");
		for (int j = 0; j < strlen(strl); j++)
		{
			printf("%c", strl[j]);
			Sleep(200);
		}
		if (l < 4)
		{
			system("CLS");
			l++;
			goto loop1;
		}
		else
		{
			printf("\n\nPayment recieved through UPI\n");
			break;
		}
	}
	case 3:
	{
		strcpy(a->payment_method, "Netbanking");
		l = 0;
	loop2:
		printf("||NETBANKING||\n\n");
		printf("You are being directed to the bank website\n");

		if (l < 3)
		{
			for (int j = 0; j < strlen(strl); j++)
			{
				printf("%c", strl[j]);
				Sleep(200);
			}
			system("CLS");
			l++;
			goto loop2;
		}
		else if (l >= 3 && l < 5)
		{
			for (int j = 0; j < strlen(strb); j++)
			{
				printf("%c", strb[j]);
				Sleep(100);
			}
			system("CLS");
			l++;
			goto loop2;
		}
		else
		{
			printf("Payment recieved successfully\n");
			Sleep(2500);
		}
	}break;
	default:printf("Invalid Payment method\nPlease choose the correct method\n");
		payment(a);
		break;
	}
}
billgen(trips* a)
{
	char strr1[200], stri[20];
	sprintf(str, "%d", bid);//to convert int to string
	strcat(str, ".txt");
	if (a->selection == 1)
	{
		strcpy(strr1, a->travel_cityn);
		strcat(strr1, " to Bangalore\nMode : ");
		strcat(strr1, a->travel_moden);
	}
	if (a->selection == 2)
	{
		strcpy(strr1, a->package_details);
		if (a->package_class == 1)
			strcat(strr1, "Class : Economy");
		if (a->package_class == 2)
			strcat(strr1, "Class : Semi-Premium");
		if (a->package_class == 3)
			strcat(strr1, "Class : Premium");
	}
	strcpy(receipt, str3);
	strcat(receipt, "Thank you for choosing our services : )\n\n");
	strcat(receipt, str1);
	strcat(receipt, str2);
	strcat(receipt, "Passenger name : ");
	strcat(a->name_f, " ");
	strcat(a->name_f, a->name_l);
	strcat(receipt, a->name_f);
	strcat(receipt, "\n\nTravel date : ");
	strcat(receipt, a->date);
	strcat(receipt, "\n\n");
	strcat(receipt, strr1);
	strcat(receipt, "\n\nTotal Number of passengers : ");
	sprintf(stri, "%d", a->tot);
	strcat(receipt, stri);
	strcat(receipt, "\n\nNumber of Adults(18 + ) : ");
	sprintf(stri, "%d", a->adults);
	strcat(receipt, stri);
	strcat(receipt, "\nNumber of Children(3 to 18) : ");
	sprintf(stri, "%d", a->children);
	strcat(receipt, stri);
	strcat(receipt, "\nNumber of Adults(under 3) : ");
	sprintf(stri, "%d", a->infants);
	strcat(receipt, stri);
	strcat(receipt, "\n\nTotal bill = ");
	sprintf(strr1, "%0.2f", a->bill);
	strcat(receipt, strr1);
	printf("%s", receipt);
	printf("\nPayment pending...\n\n");
}
billprint(trips* a)
{
	char pay[4][20] = { "card", "upi", "netbanking","\0" };
	FILE* fp;
	fp = fopen(str, "w");
	fprintf(fp, "%s", receipt);
	fprintf(fp, "\nPayment Done\n");
	fprintf(fp, "Payment Method : %s\n\n", a->payment_method);
	fprintf(fp, "Have a Wonderful Safe Journey!!\n");
	fclose(fp);
	bid++;
}
book(trips* t, int ch)
{
booking:
	if (ch == 1)travel(t);
	if (ch == 2)packages(t);
	system("CLS");
	details(t);
	if (t->tot > 7)
	{
		if (t->travel_mode == 4)
		{
			printf("\nCab rental available only for 7 or less than 7 people\n");
			Sleep(2000);
			printf("Please select different mode of travel or different number of people to travel\n");
			Sleep(2500);
			printf("You will be redirected back to the travel city page\n");
			Sleep(2000);
			system("CLS");
			goto booking;
		}
	}
	system("CLS");
	bill(t);
	billgen(t);
	payment(t);
	printf("\nThe Travelling BILL ID is %d\n", bid);
	printf("\nPlease note down the BILL ID for future refernce\n");
	Sleep(2000);
	billprint(t);
}
view(trips* a)
{
	char c;
	int i = 0;
	FILE* fp2;
	char bill_id[10], print[10000];
	printf("Enter your bill id to be printed\n");
	scanf("%s", bill_id);
	strcat(bill_id, ".txt");
	fp2 = fopen(bill_id, "r");
	system("CLS");
	if (fp2 == NULL)
	{
		printf("Bill not found\n");
		exit(0);
	}
	do
	{
		c = fgetc(fp2);
		if (feof(fp2))
			break;
		print[i] = c;
		i++;
	} while (1);
	print[i] = '\0';
	fclose(fp2);
	printf("%s", print);
}
main()
{
	trips p;
	trips* t = &p;
	int i = 0;
	int ch, c;
	recovery();
	basicanim();
	do
	{
		ch = primary(t); system("CLS");
		switch (ch)
		{
		case 1:
		{
			book(t, ch);
			break;
		}
		case 2:
		{
			book(t, ch);
			break;
		}
		case 3:
		case 4:view(t);
			break;
		}
		FILE* close;
		close = fopen("exec.txt", "w");
		fprintf(close, "%d", bid);
		fclose(close);
	choice:
		printf("\n\nEnter 1 to go back to the Main Menu or Enter 0 to Exit\n");
		scanf("%d", &c);
		if (c == 1)
		{
			system("CLS");
			basic();
			continue;
		}
		else if (c == 0)
		{
			printf("\nThis project is completed by : \n");
			printf(">Saanvi P Gowda\n");
			printf(">Samarth M N\n");
			printf(">Sampriti Gopisetti\n");
			exit(0);
		}
		else
		{
			printf("Invalid entry\n");
			goto choice;
		}
	} while (1);
}