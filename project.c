#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

//global variables decleartion...............

int access1,access2; //variable for access(granted/denied) after entering pw

/* global variables for restaurant*/
float rest_charges; 
int room_no_res;	
char cust_name[20];
	
//global struct variables declearation............

/* struct for user name & password */
struct user{				
		char user_name[10];
		char passw[15];
}csr1,csr2,mgr; 


/* struct for quantity of reserved and available rooms in room information option*/
struct res_ava{
	int res;
	int ava;
}R_A[13]; //declearing 13 variable for 13 room types


/* struct for 1st option in room information ie room info wrt type*/
struct ava_all{
	int s_no;
	char room_t[20];
	int tot_room;
	int charges;
};

/*Declearing & Initializing 13 variable of the above struct globally*/
/*13 variables for 13 room types */
struct ava_all r[13]={
	{1,"Single",10,3500},
	{2,"Double",8,5500},
	{3,"Double Double",5,7500},
	{4,"Twin",4,5000},
	{5,"Inter-Connecting",4,8500},
	{6,"Duplex",6,12000},
	{7,"Adjoining",3,9000},
	{8,"Cabana",3,7500},
	{9,"Parlor",2,9000},
	{10,"Efficiency",4,6000},
	{11,"Suite",5,14000},
	{12,"King",3,6000},
	{13,"Queen",3,6000}
};


/* struct for 2nd option in room info ie room info wrt to room number*/
struct ava_type{
	int room_no;
	char ava_ornot;
	int res_till;
}R[60]; //declearing 60 variables for 60 rooms


/* declearing struct & its variable for customer info which is used in reservation
and booking option*/ 
struct cust{
		char name[20];
		char address[40];
		char cell_no[20];
		char email[30];
		char nationality[20];
		int cnic;
		int passport;
		char room_type[20];
		int room_number;
		int occupants;
		int adults;
		int child;
		char guar;
		int credit_no;

		char e_checkin[10];
		char e_checkout[10];
		int reserved_till;
		float final_bill;	
	}c;
	
/* structure for restaurant*/	
	struct rest{
		char item_name[30];
		char item_chat[20];
		int unit;
		int charges;
	}res[20]; //20 variables each for a single order, so that a customer can not order more than 20 items at once


//functions prototype............

void gotoxy(short x, short y);//Decleare gotoxy() funtion, this function will be used to go to desired location in the screen by using columns and rows
void ascii_line(int); //function to print line of 80 columns of desired ascii character

void welcome(void); 
void intro(void); 
void login(void);  
void room_type(void); 
void room_fac(void);
void room_info(void);
void res_booking(void);
void room_rest(void);
void gen_bill(int , int, int);
void check_out(void);
void end(void);


int main(int argc, char *argv[]) {
	
	welcome();
	intro();
	printf("\n\n");
	system("pause");

	system("cls");
	login();
	printf("\n");
	system("pause");

/*if pw will be correct access1=1 && if user name will be correct access2=1
so the following code will run only if both access1 & access2 will be 
equal to 1 */
	if(access1==1&&access2==1)
	{
			
		char ans='y';
		do{
		system("cls");
		welcome();

		int choice;

		printf("\t\t\tChoose a category\n");
		printf("\t\t\t1. Room Type\n");
		printf("\t\t\t2. Room Facilities\n");
		printf("\t\t\t3. Room Information\n");
		printf("\t\t\t4. Reservation & Booking\n");
		printf("\t\t\t5. Room Service & Restaurant\n");
		printf("\t\t\t6. Customer Check-Out & Payment\n");
		printf("\t\t\t7. Exit\n");
		printf("\n\t\t\tYour Choice:");
		scanf("%d",&choice);

	switch(choice)
	{
	case 1:
		room_type();
		break;

	case 2:
		room_fac();
		break;

	case 3:
		room_info();
		break;

	case 4:
		res_booking();
		break;

	case 5:
		room_rest();
		break;
	
	case 6:
		check_out();		
		break;
		
	case 7:
		exit(0);

	default:
		printf("\n\n\t\t\tInvalid Choice");
	}
	printf("\n\nDo you want to continue:");
 	fflush(stdin);
 	ans=getch();
   }while(ans=='y'||ans=='Y');

	}
	
	else
	exit(1); // if access1 or access2 or both will not be equal to 1 the program execution will terminate with value 1

	return 0;
}



//function definations

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


void ascii_line(int k){

	int j;
	for(j=0;j<80;j++)
	printf("%c",k);
}

void welcome(){
   printf("\n                       |||||||||||||||||||||||||||||||||||||");
   printf("\n                       ||                                 ||");
   printf("\n                       ||     ***********************     ||");
   printf("\n                       ||     *                     *     ||");
   printf("\n                       ||     *      WELCOME TO     *     ||");
   printf("\n                       ||     *                     *     ||");
   printf("\n                       ||     *    ULYSSES'S PALACE *     ||");
   printf("\n                       ||     *                     *     ||");
   printf("\n                       ||     ***********************     ||");
   printf("\n                       ||                                 ||");
   printf("\n                       |||||||||||||||||||||||||||||||||||||\n\n");
}

void end(){
   printf("\n                       |||||||||||||||||||||||||||||||||||||");
   printf("\n                       ||                                 ||");
   printf("\n                       ||     ***********************     ||");
   printf("\n                       ||     *                     *     ||");
   printf("\n                       ||     *      THANKS FOR     *     ||");
   printf("\n                       ||     *       VISITING      *     ||");
   printf("\n                       ||     *    ULYSSES'S PALACE *     ||");
   printf("\n                       ||     *                     *     ||");
   printf("\n                       ||     ***********************     ||");
   printf("\n                       ||                                 ||");
   printf("\n                       |||||||||||||||||||||||||||||||||||||\n\n");
}





void intro(void){
	
	printf("\n\t   Main Shahrah-e-Faisal, Scandal Point Road, Cantonment, Karachi.\n");
    printf("\n\n                              Ph. No.:021-37223959\n\n");
 
	printf("\tHotel ULYSSES'S PALACE is one of the newest Hotel in Karachi.\n");
	printf("\t The Hotel is owned by New World International Hotel Co. Ltd. \n");
	printf("    Hotel is the real one 5-star hotel labeled international brand which\n        is managed by IHG, the world's most globalized hotel company.\n");
	printf("    The Hotel is equipped with all the general amenities  and facilities\n     that go along with memorable stay.");
	printf(" Set amidst beautifully landscaped\n  gardens, it proves to be a ideal dream destination for perceptive traveler.\n\n\n");

	ascii_line(45);
	printf("\n\t\t\t\tHotel Amenities\n\n");
	ascii_line(45);

	printf("\n  \t\t\t1. Wi-Fi enabled\n");
	printf("  \t\t\t2. In house restaurants\n");
	printf("  \t\t\t3. 24-hour full service front desk\n");
	printf("  \t\t\t4. Gym\n");
	printf("  \t\t\t5. Foreign currency exchange\n");
	printf("  \t\t\t6. Cable and satellite television\n");
	printf("  \t\t\t7. Conference facilities\n");
	printf("  \t\t\t8. Free parking\n");
	printf("  \t\t\t9. Laundry and dry cleaning service\n");
}



void login(){
	
	struct user csr1={"csr-01","1234567"};
	struct user csr2={"csr-02","1234567"};
	struct user mgr={"","1234567"};

	char ch1='Y'; //do while loop to re-enter pw
	
	do
	{
		
	char ch,user_id[]="",pw[15]=""; 		//user name and pw to be entered
	int h,i,j;
	
	system("cls");
	ascii_line(177); 						//177 is actual argument. & its an ascii value for bottom half block
	printf("\n\n\t\t\t        USER LOGIN WINDOW\n\n");
	ascii_line(177);
	
	printf("\n%c Press 1 to Login as a Customer Service Representative(CSR).\n",4); //4 is the ascii value for diamond shape
	printf("%c Press 2 to Login as a Manager\nYour Choice:",4);
	scanf("%d",&h); 						//for switch case csr or manager
	printf("\n\n");
	
	ascii_line(45); //45 is ascii value for hyphen
	printf("                * Enter User Name & Password.\n");
	printf("\t\t* Password Should be 7 Characters Long.\n");
	ascii_line(45);
	
	gotoxy(26,17);	// to take the cursor at (x,y)=(26,18) and print the desired text at that position
	printf("User Name:");
	scanf("%s",user_id);
	
	gotoxy(26,18);	
	printf("Password:");


	/*here ch is initialized, this will be useful while re-entering pw, b/c at the end of pw enter key
	is hit and its saved in ch variable next time complier will read it as we hit the enter key without
	entering the pw*/
	
	ch='0';
	
	i=0;
	while(ch!=13)	//13 is acsii code for "enter key", so the loop will terminate on hitting enter key
	{
	ch=getch();		//initial value of i=0
	pw[i]=ch;		//after entering 7 digit pw, value of i=7
	//printf("%d",i);
	printf("*");	//enter key is hit to terminate the loop ,i=8
	i++;			
	}				//value is tested,, test fails and loop terminates
	pw[i]='\0';
	
	
	int x;				//pw comparision
	for(x=0;x<7;x++)
	{
	if(csr1.passw[x]==pw[x]);
	else
	{
		printf("\n\n%c Invalid Password",16);
		access1=0;
		break;
	}
	}
	if(x==7)
	{
	printf("\n\n%c Password is Valid",16);
	access1=1;	
	}
	

	//user name comparision, user name of manger will not be checked,, only pw will be compared
	switch(h)
	{case 1: //customer service rep(csr)
		
	if((strcmp(user_id,csr1.user_name)==0)||(strcmp(user_id,csr2.user_name)==0))
	{	
		printf("\n\n%c User Name is Valid",16);
		access2=1;
	}
	else
	{
		printf("\n\n%c Invalid User Name",16);
		access2=0;
	}
	break;
	
	case 2: //manager
	printf("\n\n%c User Name is Valid",16);	
	access2=1;
	}
	
	/*if username of pw or both will be incorrect than Re-entering username and pw option will appear */
	if(access1==0||access2==0)
	{
		printf("\n\nPress \"Y\" to Retry:");
		ch1=getche();
		
		if(ch1=='Y'||ch1=='y')
		system("cls");
	
	}
	
	/*otherwise ch1 will become N and do while loop will terminate */
	else
	ch1='N';
	
}while(ch1=='Y'||ch1=='y');

if(access1==1&&access2==1)
{	printf("\n\n");
	ascii_line(220);
	printf("\n\n\t\t\t\tAccess granted\n\n");
	ascii_line(220);
}

else
{	printf("\n\n");
	ascii_line(220);
	printf("\n\n\t\t\t\tAccess denied\n\n");
	ascii_line(220);
}

	
}




void room_type(){
	
	system("cls");
	
	
	ascii_line(177);
	printf("\n\n\t\t\t\tROOM TYPES\n\n");
	ascii_line(177);
	
	printf("\n%cFollowing are the available Room Types:\n",4);
	
	printf("\n\n1.  Single Room: \"A room with a single bed facility\"\n\n");
	printf("2.  Double Room: \"A room with a double bed facility\"\n\n");
	printf("3.  Double Double: \"A room with two double bed facility\"\n\n");
	printf("4.  Twin Room: \"A room with two single bed facility\"\n\n");
	printf("5.  Interconnecting Room: \"Two rooms which shares a common door\"\n\n");
	printf("6.  Duplex: \"A room which is been spread on two floors\"\n\n");
	printf("7.  Adjoining Room: \"Two rooms which shares a common wall\"\n\n");
	printf("8.  Cabana: \"A room near or beside swimming pool\"\n\n");
	printf("9.  Parlor: \"A room which is used for sitting & cannot be used for sleeping\"\n\n");
	printf("10. Efficiency Room: \"A room with a kitchen facility\"\n\n");
	printf("11. Suit Room: \"Room with two or more bedrooms, a living room & a dinning area\"\n\n");
	printf("12. King Room: \"A room with a King size bed\"\n\n");
	printf("13. Queen Room: \"A room with a Queen size bed\"\n\n");

}



void room_info(void){
	
	/* i used three structurs in room info type 1.res_ava, 2.ava_all & 3. ava_type
	first two struct will show room info a/c to room type & the 3rd struct will show
	room info a/c to room number */
	
	system("cls");
	
	int choice,ch,counter1;
	
	ascii_line(177);
	printf("\n\n\t\t\t\tROOM INFORMATION\n\n");
	ascii_line(177);
	
	printf("\n");
	printf("\t\t\t1. Room Information By Type\n");
	printf("\t\t\t2. Room Information By Room Number\n\n");
	
	printf("\t\t\tYour choice:");
	scanf("%d",&choice);
	
	printf("\n");
	
	
/*initializing 60 variables of struct ava_type, everytime we access room info option this struct will be re-initialized*/				
struct ava_type R[60]={
		{1001,'Y',0},
		{1002,'Y',0},
		{1003,'Y',0},
		{1004,'Y',0},
		{1005,'Y',0},
		{1006,'Y',0},
		{1007,'Y',0},
		{1008,'Y',0},
		{1009,'Y',0},
		{1010,'Y',0}, //10 rooms single
		{1011,'Y',0},
		{1012,'Y',0},
		{1013,'Y',0},
		{1014,'Y',0},
		{1015,'Y',0},
		{1016,'Y',0},
		{1017,'Y',0},
		{1018,'Y',0},//8 rooms double
		{1019,'Y',0},
		{1020,'Y',0},
		{1021,'Y',0},
		{1022,'Y',0},
		{1023,'Y',0},//5 rooms double double
		{1024,'Y',0},
		{1025,'Y',0},
		{1026,'Y',0},
		{1027,'Y',0},//4 rooms twin 
		{1028,'Y',0},
		{1029,'Y',0},
		{1030,'Y',0},
		{1031,'Y',0},//4 rooms interconnecting
		{1032,'Y',0},
		{1033,'Y',0},
		{1034,'Y',0},
		{1035,'Y',0},
		{1036,'Y',0},
		{1037,'Y',0},//6 rooms duplex
		{1038,'Y',0},
		{1039,'Y',0},
		{1040,'Y',0},//3 rooms adjoining
		{1041,'Y',0},
		{1042,'Y',0},
		{1043,'Y',0},//3 rooms cabana
		{1044,'Y',0},
		{1045,'Y',0},//2 rooms parlor
		{1046,'Y',0},
		{1047,'Y',0},
		{1048,'Y',0},
		{1049,'Y',0},//4 rooms efficiency
		{1050,'Y',0},
		{1051,'Y',0},
		{1052,'Y',0},
		{1053,'Y',0},
		{1054,'Y',0},//5 rooms suite
		{1055,'Y',0},
		{1056,'Y',0},
		{1057,'Y',0},//3 rooms king
		{1058,'Y',0},
		{1059,'Y',0},
		{1060,'Y',0},//3 rooms queen
	};

			
/*initializing 13 variabels of struct res_ava, this will show the no or available and reserved rooms*/			
struct res_ava R_A[13]={
	{0,10},
	{0,8},
	{0,5},
	{0,4},
	{0,4},
	{0,6},
	{0,3},
	{0,3},
	{0,2},
	{0,4},
	{0,5},
	{0,3},
	{0,3}
};

/*opening the file "reservation & booking.dat", it will read the customer recored from file, compare the
 room number and make suitable changes in the cooresponding room info record*/
	FILE *fp;
	int r_n,t; //r_n for room number comparision
	
	fp=fopen("reservation & booking.dat","rb");
	
	if(fp==NULL)
	{
		printf("Error Opening File\n");
	}			
			
	while(fread(&c,sizeof(c),1,fp)==1)
	{
		
			
				for(r_n=1001;r_n<=1060;r_n++)
			{
				if(c.room_number==r_n)
				{	/* it will change the availability from Y(yes) to N(no) in the Structure ava_type*/
					R[r_n-1001].ava_ornot='N';
					/*it will display the number of days for which the room is reserved in the struct ava_type*/
					R[r_n-1001].res_till=c.reserved_till;	
	               
				   /*the following code will increase the number of reserved rooms and decrease the number of 
				   ava room by one unit in the struct res_ava */ 		
					if(r_n>=1001&&r_n<=1010)
					{	
						R_A[0].res++;
						R_A[0].ava--;
					}
					
					else if(r_n>=1011&&r_n<=1018)
					{
						R_A[1].res++;
						R_A[1].ava--;
					}
					
					else if(r_n>=1019&&r_n<=1023)
					{
						R_A[2].res++;
						R_A[2].ava--;
					}
					
					else if(r_n>=1024&&r_n<=1027)
					{
						R_A[3].res++;
						R_A[3].ava--;
					}
					
					else if(r_n>=1028&&r_n<=1031)
					{
						R_A[4].res++;
						R_A[4].ava--;
					}

					else if(r_n>=1032&&r_n<=1037)
					{
						R_A[5].res++;
						R_A[5].ava--;
					}
					
					else if(r_n>=1038&&r_n<=1040)
					{
						R_A[6].res++;
						R_A[6].ava--;
					}
					
					else if(r_n>=1041&&r_n<=1043)
					{
						R_A[7].res++;
						R_A[7].ava--;
					}
					
					else if(r_n>=1044&&r_n<=1045)
					{
						R_A[8].res++;
						R_A[8].ava--;
					}
					
					else if(r_n>=1046&&r_n<=1049)
					{
						R_A[9].res++;
						R_A[9].ava--;
					}
					
					else if(r_n>=1050&&r_n<=1054)
					{
						R_A[10].res++;
						R_A[10].ava--;
					}
					
					else if(r_n>=1055&&r_n<=1057)
					{
						R_A[11].res++;
						R_A[11].ava--;
					}
					
					else if(r_n>=1058&&r_n<=1060)
					{
						R_A[12].res++;
						R_A[12].ava--;
					}
			}
			
			
			}
		
			}		
			
	switch(choice)
	{
/* the following case will show info a/c to room type which is in the struct ava_all & res_ava*/	

	case 1:
		ascii_line(205);
		printf("\nS.No\tRoom Type\tTotal Rooms\tReserved\tAvailable    Charges\n\n");
		ascii_line(205);
		printf("\n\n");	
		
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[0].s_no,r[0].room_t,r[0].tot_room,R_A[0].res,R_A[0].ava,r[0].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[1].s_no,r[1].room_t,r[1].tot_room,R_A[1].res,R_A[1].ava,r[1].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[2].s_no,r[2].room_t,r[2].tot_room,R_A[2].res,R_A[2].ava,r[2].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[3].s_no,r[3].room_t,r[3].tot_room,R_A[3].res,R_A[3].ava,r[3].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[4].s_no,r[4].room_t,r[4].tot_room,R_A[4].res,R_A[4].ava,r[4].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[5].s_no,r[5].room_t,r[5].tot_room,R_A[5].res,R_A[5].ava,r[5].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[6].s_no,r[6].room_t,r[6].tot_room,R_A[6].res,R_A[6].ava,r[6].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[7].s_no,r[7].room_t,r[7].tot_room,R_A[7].res,R_A[7].ava,r[7].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[8].s_no,r[8].room_t,r[8].tot_room,R_A[8].res,R_A[8].ava,r[8].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[9].s_no,r[9].room_t,r[9].tot_room,R_A[9].res,R_A[9].ava,r[9].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[10].s_no,r[10].room_t,r[10].tot_room,R_A[10].res,R_A[10].ava,r[10].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n",r[11].s_no,r[11].room_t,r[11].tot_room,R_A[11].res,R_A[11].ava,r[11].charges);
		printf("%-7d %-19s %-14d %-15d %-9d %d Rs\n\n",r[12].s_no,r[12].room_t,r[12].tot_room,R_A[12].res,R_A[12].ava,r[12].charges);
	
		ascii_line(205);
	
	break;
	
/* the following case will show info a/c to room number which is in the struct ava_type*/	
	case 2:
		printf("Select a room type\n\n");
		
		printf("1.Single\n");
		printf("2.Double\n");
		printf("3.Double Double\n");
		printf("4.Twin\n");
		printf("5.Inter-Connecting\n");
		printf("6.Duplex\n");
		printf("7.Adjoining\n");
		printf("8.Cabana\n");
		printf("9.Parlor\n");
		printf("10.Efficiency\n");
		printf("11.Suite\n");
		printf("12.King\n");
		printf("13.Queen\n\n");
	
		printf("Room Type:");
		scanf("%d",&ch);	
		printf("\n");
	
		ascii_line(205);
		printf("\nRoom Number\t\t\tAvailability\t\t\tResereved For\n\n");	
		ascii_line(205);
		printf("\n\n");

		switch(ch)
		{
		case 1:
			for(counter1=0;counter1<10;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 2:
			for(counter1=10;counter1<18;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 3:
			for(counter1=18;counter1<23;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 4:
			for(counter1=23;counter1<27;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 5:
			for(counter1=27;counter1<31;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 6:
			for(counter1=31;counter1<37;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
		
			break;
	
		case 7:
			for(counter1=37;counter1<40;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 8:
			for(counter1=40;counter1<43;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
		
		case 9:
			for(counter1=43;counter1<45;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
		
		case 10:
			for(counter1=45;counter1<49;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 11:
			for(counter1=49;counter1<54;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
		
			break;
	
		case 12:
			for(counter1=54;counter1<57;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);
	
			break;
	
		case 13:
			for(counter1=57;counter1<60;counter1++)
			printf("   %-33d %-30c %d days\n",R[counter1].room_no,R[counter1].ava_ornot,R[counter1].res_till);

		}	
	
		printf("\n");
		ascii_line(205);
		
		
		
	}

}

void room_fac(void){
		
	system("cls");
	
	ascii_line(177);
	printf("\n\n\t\t\t\tROOM FACILITIES\n\n");
	ascii_line(177);
	
	printf("\nEach room has the following facilities:\n");
	printf("\n%cAir-conditioning\n",249);
	printf("\n%cComplimentary broadband Internet access\n",249);
	printf("\n%cComplimentary Wi Fi in all Rooms\n",249);
	printf("\n%cComplimentary Drinking Water\n",249);
	printf("\n%cWide screen 32\" LCD TV with cable channels & DVD player\n",249);
	printf("\n%cTea and coffee making facilities\n",249);
	printf("\n%cFull range of custom-made bathroom amenities\n",249);
	printf("\n%cMini fridge\n",249);
	printf("\n%cIroning board and iron available",249);

}


void res_booking(void){

/* declearing file pointers fp for orignal file and ft for a temperaray file which will be used in deleting record*/
	FILE *fp, *ft; 
	
		int	k=0; //customer number
		int	x=6; //used in gotoxy
	
	int choice1,p=0;
					
	char another;
	
	char cust_name[20]; //customer name for comparing

/* opening file in binary read/write mode*/
	fp=fopen("reservation & booking.dat","rb+");

/* if file doesnt exist then we will try to open the file in wb+ mode where the file will be created first*/
	if(fp==NULL)
	{
		fp=fopen("reservation & booking.dat","wb+");
		
		if(fp==NULL)
		{
			printf("Error Opening File\n");
			exit(2);
		}
	}
	
	
		system("cls");
		
		ascii_line(177);
		printf("\n\n\t\t\t     RESERVATION & BOOKING\n\n");
		ascii_line(177);
		printf("\n\n");
		
		printf("\t\t\t1. New Customer Reservation\n");
		printf("\t\t\t2. View Customer Record\n");
		printf("\t\t\t3. Modify Record\n");
		printf("\t\t\t4. Delete Record\n");
		
	
		printf("\n\t\t\tYour Choice:");
		scanf("%d",&choice1);
		
		switch(choice1)
		{
			/* for writing customer record to file */
			case 1:
				system("cls");
				ascii_line(177);
				printf("\n\n\t\t\t     NEW CUSTOMER RESERVATION\n\n");
				ascii_line(177);
				printf("\n\n");
		
		/* fseek funtion is used to take the file pointer at desired location
		so that we can read/write record, it takes 3 arguments the 1st is file pointer
		the 2nd is number of bytes to move, and the third is reference 
		
		reference is a macro and it could be of 3 types
		
		1. SEEK_SET: the pointer will be moved with reference to START
		2. SEEK_CUR the pointer will be moved with reference to current pointer position
		3. SEEK_END the pointer will be moved with reference to end of file*/
		
		/* addition of record in a file always take place at the end of the file so we use 
		SEEK_END and 0 bytes*/
		
				fseek(fp,0,SEEK_END);	
				printf("%cEnter Customer Record for Reservation:\n\n",4);
				printf("%c Name:",16);
				fflush(stdin);
				gets(c.name);
		
		/* fflush funtion is used to clear the buffer of stander i/o otherwise scanf may not work properly*/
			
				gotoxy(40,10);
				printf("%c Cell Number:",16);
				fflush(stdin);
				scanf("%s",c.cell_no);
			
				printf("\n%c Address:",16);	
				fflush(stdin);
				gets(c.address);
			
				gotoxy(40,12);
				printf("%c E-mail:",16);
				fflush(stdin);
				scanf("%s",c.email);
			
				printf("\n%c Nationality:",16);
				fflush(stdin);
				gets(c.nationality);
			
				gotoxy(40,14);
				printf("%c CNIC Number:",16);
				fflush(stdin);
				scanf("%d",&c.cnic);
			
				printf("\n%c Passport Number:",16);
				fflush(stdin);
				scanf("%d",&c.passport);
			
				gotoxy(40,16);
				printf("%c Room Type:",16);
				fflush(stdin);
				gets(c.room_type);
				
				printf("\n%c Room Number:",16);
				fflush(stdin);
				scanf("%d",&c.room_number);
			
				gotoxy(40,18);
				printf("%c No. of Occupants:",16);
				fflush(stdin);
				scanf("%d",&c.occupants);
			
				printf("\n%c No. of Adults:",16);
				fflush(stdin);
				scanf("%d",&c.adults);
			
				gotoxy(40,20);
				printf("%c No. of Children:",16);
				fflush(stdin);
				scanf("%d",&c.child);
			
				printf("\n%c Credit Card Guarantee:",16);
				fflush(stdin);
				scanf("%c",&c.guar);
			
				gotoxy(40,22);
				printf("%c Credit Card Number:",16);
				fflush(stdin);
				scanf("%d",&c.credit_no);
			
				printf("\n%c Check-In Date:",16);
				fflush(stdin);
				gets(c.e_checkin);
			
				gotoxy(40,24);
				printf("%c Expected Check-Out Date:",16);
				fflush(stdin);
				gets(c.e_checkout);
			
				printf("\n%c Reserved For(days):",16);
				fflush(stdin);
				scanf("%d",&c.reserved_till);
			
				
		/*c.final_bill will be used in billing*/		
			if(c.room_number>=1001&&c.room_number<=1010)
					{	
						c.final_bill=c.reserved_till*r[0].charges;
					}
					
				else if(c.room_number>=1011&&c.room_number<=1018)
					{
						c.final_bill=c.reserved_till*r[1].charges;
					}
					
				else if(c.room_number>=1019&&c.room_number<=1023)
					{
						c.final_bill=c.reserved_till*r[2].charges;
					}
					
				else if(c.room_number>=1024&&c.room_number<=1027)
					{
						c.final_bill=c.reserved_till*r[3].charges;
					}
					
				else if(c.room_number>=1028&&c.room_number<=1031)
					{
						c.final_bill=c.reserved_till*r[4].charges;
					}

				else if(c.room_number>=1032&&c.room_number<=1037)
					{
						c.final_bill=c.reserved_till*r[5].charges;
					}
					
				else if(c.room_number>=1038&&c.room_number<=1040)
					{
						c.final_bill=c.reserved_till*r[6].charges;
					}
					
				else if(c.room_number>=1041&&c.room_number<=1043)
					{
						c.final_bill=c.reserved_till*r[7].charges;
					}
					
				else if(c.room_number>=1044&&c.room_number<=1045)
					{
						c.final_bill=c.reserved_till*r[8].charges;
					}
					
				else if(c.room_number>=1046&&c.room_number<=1049)
					{
						c.final_bill=c.reserved_till*r[9].charges;
					}
					
				else if(c.room_number>=1050&&c.room_number<=1054)
					{
						c.final_bill=c.reserved_till*r[10].charges;
					}
					
				else if(c.room_number>=1055&&c.room_number<=1057)
					{
						c.final_bill=c.reserved_till*r[11].charges;
					}
					
				else if(c.room_number>=1058&&c.room_number<=1060)
					{
						c.final_bill=c.reserved_till*r[12].charges;
					}
				


		/*We have taken the customer record as input now we have to write it in file using fwrite which is used for binary files*/
		
		/*fwrite function is used to write data on file which is in binary mode
		it takes 4 arg the 1st one is address of struct variable ,2nd is size of variablei in bytes
		,3rd is number of struct to write and the 4th is struct pointer*/	

				fwrite(&c,sizeof(c),1,fp);
				break;
			
			
		case 2:
		/*fread funtion is the counter part of fwrite funtion it takes same arg
		as fwrite its return valus is equal to 3rd arg*/
		
		
		/*we have used while loop it will read all the customer record and print it
		when there is no record available fread will not return 1 and the loop terminates*/		 

		system("cls");
			while(fread(&c,sizeof(c),1,fp)==1)
			{	k++;
				printf("\n");
				ascii_line(205);
				printf("\n\t\t\t      CUSTOMER %d: \"%s\"\n\n",k,c.name);
				ascii_line(205);			
			
				printf("\n\n%c Name:",16);
				printf("%s",c.name);
			
				gotoxy(40,x+2);
				printf("%c Cell Number:",16);
				printf("%s",c.cell_no);
			
				printf("\n\n%c Address:",16);	
				printf("%s",c.address);
		
				gotoxy(40,x+4);
				printf("%c E-mail:",16);
				printf("%s",c.email);
				
				printf("\n\n%c Nationality:",16);
				printf("%s",c.nationality);
			
				gotoxy(40,x+6);
				printf("%c CNIC Number:",16);
				printf("%d",c.cnic);
			
				printf("\n\n%c Passport Number:",16);
				printf("%d",c.passport);
			
				gotoxy(40,x+8);
				printf("%c Room Type:",16);
				printf("%s",c.room_type);
			
			
				printf("\n\n%c Room Number:",16);
				printf("%d",c.room_number);
			
				gotoxy(40,x+10);
				printf("%c No. of Occupants:",16);
				printf("%d",c.occupants);
			
				printf("\n\n%c No. of Adults:",16);
				printf("%d",c.adults);
			
				gotoxy(40,x+12);
				printf("%c No. of Children:",16);
				printf("%d",c.child);
			
				printf("\n\n%c Credit Card Guarantee:",16);
				printf("%c",c.guar);
			
				gotoxy(40,x+14);
				printf("%c Credit Card Number:",16);
				printf("%d",c.credit_no);
			
			
				printf("\n\n%c Check-In Date:",16);
				printf("%s",c.e_checkin);
			
				gotoxy(40,x+16);
				printf("%c Expected Check-Out Date:",16);
				printf("%s",c.e_checkout);
			
				printf("\n\n%c Reserved For(days):",16);
				printf("%d",c.reserved_till);
				

				x=x+24;// x is incremented to position the next record using gotoxy
}

			break;
			
		case 3:
			system("cls");
			ascii_line(177);
			printf("\n\t\t\t    MODIFY CUSTOMER RECORD\n\n");
			ascii_line(177);
			
			
			printf("\nEnter Name of Customer To Modify Record:");
			fflush(stdin);
			gets(cust_name);
		
			printf("\n");
			
		/*rewind funtion takes the file pointer at the start*/	
			
			rewind(fp);
			
		/*fread will read the available record if it matches with cust_name
		the record will be re_entered ie modified*/
			
			while(fread(&c,sizeof(c),1,fp)==1)
			{
				if(strcmp(c.name,cust_name)==0)
				{
					printf("%c Name:",16);
					fflush(stdin);
					gets(c.name);
			
					gotoxy(40,8);
					printf("%c Cell Number:",16);
					fflush(stdin);
					scanf("%s",c.cell_no);
					
					printf("\n%c Address:",16);	
					fflush(stdin);
					gets(c.address);
				
					gotoxy(40,10);
					printf("%c E-mail:",16);
					fflush(stdin);
					scanf("%s",c.email);
				
					printf("\n%c Nationality:",16);
					fflush(stdin);
					gets(c.nationality);
			
					gotoxy(40,12);
					printf("%c CNIC Number:",16);
					fflush(stdin);
					scanf("%d",&c.cnic);
				
					printf("\n%c Passport Number:",16);
					fflush(stdin);
					scanf("%d",&c.passport);
				
					gotoxy(40,14);
					printf("%c Room Type:",16);
					fflush(stdin);
					gets(c.room_type);
			
					printf("\n%c Room Number:",16);
					fflush(stdin);
					scanf("%d",&c.room_number);
			
					gotoxy(40,16);
					printf("%c No. of Occupants:",16);
					fflush(stdin);
					scanf("%d",&c.occupants);
			
					printf("\n%c No. of Adults:",16);
					fflush(stdin);
					scanf("%d",&c.adults);
			
					gotoxy(40,18);
					printf("%c No. of Children:",16);
					fflush(stdin);
					scanf("%d",&c.child);
			
					printf("\n%c Credit Card Guarantee:",16);
					fflush(stdin);
					scanf("%c",&c.guar);
				
					gotoxy(40,20);
					printf("%c Credit Card Number:",16);
					fflush(stdin);
					scanf("%d",&c.credit_no);
			
					printf("\n%c Check-In Date:",16);
					fflush(stdin);
					gets(c.e_checkin);
			
					gotoxy(40,22);
					printf("%c Expected Check-Out Date:",16);
					fflush(stdin);
					gets(c.e_checkout);
			
					printf("\n%c Reserved For(days):",16);
					fflush(stdin);
					scanf("%d",&c.reserved_till);
		
				/*here fseek funtion is used with reference to current pointer position
				-sizeof(c) will take the pointer at the start of the record to be modified
				and it will be overwritted by fwrite below*/
					
					fseek(fp,-sizeof(c),SEEK_CUR);
			
					fwrite(&c,sizeof(c),1,fp);
					
					break;
			
				}
				
			}	
			
			if(fread(&c,sizeof(c),1,fp)!=1)		
			printf("\nRecord Not Found........!");	
			
			break;
			
			case 4:
				/*The Basic logic of deleting record is that first we will copy paste all the remaining record to a temperary file
				than we will delete the orignal file and rename the temp file as orignal file*/
				
				system("cls");
				ascii_line(177);
				printf("\n\t\t\t       DELETE RECORD\n\n");
				ascii_line(177);
			
				printf("\n\nEnter Name of Customer To Delete Record:");
				fflush(stdin);
				gets(cust_name);
				printf("\n\n");
			
				/*opening temp file in write binary mode*/
				ft=fopen("temp.dat","wb");
			
				rewind(fp);
			
				while(fread(&c,sizeof(c),1,fp)==1)
				{	/*if the record to be deleted exist than p=1 otherwise it will be zero*/
					if(strcmp(c.name,cust_name)==0)
					p=1;
					
					/*writing all the record except the record to be deleted to temp file*/				
					if(strcmp(c.name,cust_name)!=0)
					fwrite(&c,sizeof(c),1,ft);
					
				}
			
				if(p!=1)
				printf("\n%cRecord Not Found........!",4);
			
				if(p==1)
				printf("\n%cRequested Record Is Deleted........!",4);
		
				fclose(fp);
				fclose(ft);
				/*here deleting the org file & renaming the temp file as org file*/
				remove("reservation & booking.dat");
				rename("temp.dat","reservation & booking.dat");
				
				fp=fopen("reservation & booking.dat","rb+");
			
				break;		
						
			}
							
	
		fclose(fp);

}



void room_rest(void){
	
	
	system("cls");
	ascii_line(177);
	printf("\n\n\t\t\t    ROOM SERVICE &RESTAURANT\n\n");	
	ascii_line(177);
	
	printf("\n\nPress Any Key to See the Menu & Order Meal:");
	getch();
	system("cls");
	
	ascii_line(177);
	printf("\n\n\t\t\t\t    MENU\n\n");	
	ascii_line(177);
	
	printf("\n\n\n\t\t\t\t\"PAKISTANI CUSINE\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);

	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Biryani & Pulao",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Karahi",1200.00,"KG");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Shami Kababs",400.0,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Chicken Makhani",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Tandori Chicken",1050.00,"FULL");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Hyderabadi Chicken",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",7,"Chicken Handi Boneless",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",8,"Chicken Green Masala",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",9,"Chicken Achari",700.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",10,"Chicken Qorma",900.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",11,"Chicken Kofta",450.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",12,"Chicken Chargha",1300.00,"FULL");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",13,"Chicken Sindhi Biryani",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",14,"Nargisi Kofta",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",15,"Chapli Kababs",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",16,"Aloo Keema",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",17,"Mutton Karahi",1100.00,"KG");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",18,"Mutton Haandi",900.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",19,"Mutton Green Masala",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",20,"Mutton Qorma",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",21,"Plain Rice",300.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",22,"Mix Vegitable",400.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",23,"Andaa Chaana",350.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",24,"Daal",300.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",25,"Palak Paneer",450.00,"PLATE");
	
	ascii_line(205);
	
	
	printf("\n\n\n\n\t\t\t\t   \"BARBECUES\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);
	
	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Chicken Tikka",400.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Seekh Kababs",500.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Grilled Salmon Tikka",500.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Mutton Seekh Kababs",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Grilled Lamb Chops",750.00,"PLATE");
	
	ascii_line(205);
	
	printf("\n\n\n\n\t\t\t\t\"CHINESE & SOUPS\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);
	
	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Chicken Sizzler",900.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Shashlik",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Chicken Chilli Dry",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Chicken Tempure",800.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Chicken Chow Mien",750.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Chicken Sweet & Sour",700.00,"PLATE");
	ascii_line(205);
	
	printf("\n\n\n\n\t\t\t\t   \"SEA FOOD\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);
	
	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Karahi Prawn",1100.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Masala Fish",1000.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Prawn Tikka Masala",1050.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Tawa Chilli Prawn",1100.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Kurkuri Fried Fish",950.00,"PLATE");
	ascii_line(205);
	
	
	printf("\n\n\n\n\t\t\t     \"HAMBURGERS & SANDWICHES\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);
	
	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Zinger Burger",600.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Chicken Cheese Burger",650.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Beef Cheese Burger",600.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Oriental Chicken Burger",550.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Club Sandwich",400.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"French Fries",200.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",7,"Crispy Fried Burger",600.00,"PCS");
	
	
	ascii_line(205);
	
	
	printf("\n\n\n\n\t\t\t\t    \"DESSERTS\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);
	
	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Shahi Kheer",600.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Gulab Jamun",500.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Kulfi",400.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Rass Malai",550.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",5,"Halwa",600.00,"PLATE");
	
	ascii_line(205);
	
	

	printf("\n\n\n\n\t\t\t\t     \"OTHERS\"");
	printf("\n\n");
	ascii_line(205);
	printf("\n   %-10s %-30s %-20s %-10s \n\n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(205);
	
	printf("\n   %-10d %-30s %-20.0f %-10s \n",1,"Plain Naan",50.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",2,"Roghani",70.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",3,"Tandori Rooti",40.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",4,"Paratha",60.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",5,"Bread",60.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",6,"Tea",150.00,"CUP");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",7,"Raita",100.00,"PCS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",8,"Coffee",200.00,"CUP");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",9,"Halwa Puri",400.00,"PLATE");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",10,"Lassi",200.00,"GLASS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n",11,"Milk Shake",200.00,"GLASS");
	printf("\n   %-10d %-30s %-20.0f %-10s \n\n",12,"Omelette",120.00,"PCS");
	
	
	
	ascii_line(205);
	
	char ch='y';
	int bill,order_type; 
	int i=0;
	printf("\n\n%c Please Order the Meal From the Above Menu:\n",4);
	
	
	printf("\n\n         %cCustomer Name:",16);
	fflush(stdin);
	gets(cust_name);
	
	gotoxy(48,230);
	printf("%cRoom Number:",16);
	fflush(stdin);
	scanf("%d",&room_no_res);
	
	rest_charges=0; // this variable is for each item its not the final bill
	
	printf("\n\t %c Order Type(Restaurant=1 Room Service=2):",16);
	scanf("%d",&order_type);
	
	
	do{
		bill=0;
		printf("\n\n%c Category:",248);
		fflush(stdin);
		gets(res[i].item_chat);

		printf("\n%c Item Name:",248);
		fflush(stdin);
		gets(res[i].item_name);
		
		printf("\n%c Quantity:",248);
		fflush(stdin);
		scanf("%d",&res[i].unit);

		printf("\n%c Price:",248);
		scanf("%d",&res[i].charges);
		
		bill=res[i].unit*res[i].charges;			
		
		rest_charges+=bill;// this will increment the cost of each item to the final bill
	
	
		printf("\n\nDo You Want to Order Another Meal:");
 		i++;
		ch=getche();
	}
	while(ch=='y'||ch=='Y');
	
	printf("Press \"Y\" to Generate Bill:");
	
/*this function will generate the bill */
gen_bill(order_type,i,rest_charges);
	
	
}

void gen_bill(int order_type,int i,int bill_res){
	system("cls");
	
	/*the following two lines of code will display the current time in the bill*/
	time_t now;
 	time(&now);
 	int j,k=1;
 
	printf("\n\t\t\t\t ULYSSES RESTAURANT\n");
	printf("\t\t\t\tTel-No:021-363425633\n");
	printf("\t\t\t\t     CASH BILL\n");
	
	printf("\nOrder Tpye:",4);
	if(order_type==1)
	printf("Restaurant\n");
	else if(order_type==2)
	printf("Room Service");
	
	gotoxy(40,5);
	printf("           Time:");
  	printf("%s",ctime(&now));
	
	printf("\nCustomer Name:");
	puts(cust_name);
	gotoxy(51,8);
	printf("Room Number:%d",room_no_res);
	
	printf("\n");
	ascii_line(95);
	printf("\n      %-10s %-30s %-20s %-15s \n","S.No","Item Name","Rate(Rs.)","Unit");
	ascii_line(95);
	
	for(j=0;j<i;j++)
	{
	printf("\n      %-10d %-30s %-20d %-15d\n",k,res[j].item_name,res[j].charges,res[j].unit);
	k++;
	}
	ascii_line(95);
	
	
	
	printf("\n\t\t\t\t\"TOTAL BILL:%d\"",bill_res);
	printf("\n\n\t\t\t      THANK YOU & VISIT AGAIN");
	
}

void check_out(){
	time_t now;
 	time(&now);

	
	float bill;
	char cus_name[20];
	FILE *fp;
	fp=fopen("reservation & booking.dat","rb");
	
	if(fp==NULL)
	{
		printf("Error Opening File\n");
	}			
	system("cls");
	ascii_line(177);
	printf("\n\n\t\t\t  CUSTOMER CHECKOUT & PAYMENT\n\n");
	ascii_line(177);
	
	printf("\nEnter Name of Customer For Check-Out:");
	fflush(stdin);
	gets(cus_name);
	
	rewind(fp);
	end();					
	while(fread(&c,sizeof(c),1,fp)==1)
	{
		if(strcmp(c.name,cus_name)==0)
		{
			gotoxy(27,22);
			printf("%c Time: %s",16,ctime(&now));
			gotoxy(27,24);
			printf("%c CUSTOMER NAME: %s",16,c.name);
			gotoxy(27,26);
			printf("%c ROOM NUMBER: %d",16,c.room_number);
			gotoxy(27,28);
			printf("%c NUMBER OF DAYS: %d",16,c.reserved_till);
			gotoxy(27,30);
			printf("%c FINAL BILL: %.2f",16,c.final_bill);	
						
		}

	}

}
