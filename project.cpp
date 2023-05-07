//**********************************************************
//	PROJECT CRIMINAL MANAGEMENT
//**********************************************************

//**********************************************************
//	INCLUDED HEADER FILES
//**********************************************************

#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>


//**********************************************************
//	CLASS NAME : menu
//	DETAILS    : IT CONTROLLS OVER ALL THE FUNCTIONS
//**********************************************************

class menu
{
	public :
			void main_menu(void) ;
			void introduction(void) ;
			void CLEAR(int) ;
			void LINE_HOR(int, int, int, char) ;
			void LINE_VER(int, int, int, char) ;
			void BOX(int,int,int,int,char) ;
	private :
			void edit_menu(void) ;
} ;


//**********************************************************
//	CLASS NAME : criminal
//	DETAILS    : IT CONTROLLS OVER ALL THE FUNCTIONS
//                RELATED TO CRIMINAL CRIMINALS
//**********************************************************

class criminal
{
	public :
			void add_criminal(void) ;
			void delete_criminal(void) ;
			void modify_criminal(void) ;
			void list_of_criminal(void) ;
			void idn_list_of_criminal(void) ;
	private :
			int  last_code(void) ;
			void delete_record(int) ;
			void modify_record(int) ;
			void display_record(int) ;
			int  criminal_found(int) ;
			int  recordno(int) ;
			void sort(void) ;

			int   criminalcode ;
			char  criminalname[30],criminaliden[30],criminalpun[30] ;
			float criminalage, criminalpage ;
} ;


//**********************************************************
// THIS FUNCTION DELETES THE GIVEN ROW NO. ON THE SCREEN
//**********************************************************

void menu :: CLEAR(int row)
{
	gotoxy(3,row) ;
	cout <<"                                                                         " ;
}


//**********************************************************

// THIS FUNCTION DRAWS THE HORRIZONTAL LINE
//**********************************************************

void menu :: LINE_HOR(int column1, int column2, int row, char c)
{
	for ( column1; column1<=column2; column1++ )
	{
		gotoxy(column1,row) ;
		cout <<c ;
	}
}


//**********************************************************
// THIS FUNCTION DRAWS THE VERTICAL LINE
//**********************************************************

void menu :: LINE_VER(int row1, int row2, int column, char c)
{
	for ( row1; row1<=row2; row1++ )
	{
		gotoxy(column,row1) ;
		cout <<c ;
	}
}


//**********************************************************
// THIS FUNCTION DRAWS THE BOX
//**********************************************************

void menu :: BOX(int column1, int row1, int column2, int row2, char c)
{
	char ch=218 ;
	char c1, c2, c3, c4 ;
	char l1=196, l2=179 ;
	if (c == ch)
	{
		c1=218 ;
		c2=191 ;
		c3=192 ;
		c4=217 ;
		l1 = 196 ;
		l2 = 179 ;
	}
	else
	{
		c1=c ;
		c2=c ;
		c3=c ;
		c4=c ;
		l1 = c ;
		l2 = c ;
	}
	gotoxy(column1,row1) ;
	cout <<c1 ;
	gotoxy(column2,row1) ;
	cout <<c2 ;
	gotoxy(column1,row2) ;
	cout <<c3 ;
	gotoxy(column2,row2) ;
	cout <<c4 ;
	column1++ ;
	column2-- ;
	LINE_HOR(column1,column2,row1,l1) ;
	LINE_HOR(column1,column2,row2,l1) ;
	column1-- ;
	column2++ ;
	row1++ ;
	row2-- ;
	LINE_VER(row1,row2,column1,l2) ;
	LINE_VER(row1,row2,column2,l2) ;
}


//**********************************************************
//  THIS FUNCTION CREATES ITRODUCTION SCREEN
//**********************************************************

void menu :: introduction(void)
{
	clrscr() ;
	_setcursortype(_NOCURSOR);
	gotoxy(28,5) ;
	cout<<" Welcome to Project" ;
	textcolor(BLACK+BLINK) ; textbackground(WHITE) ;
	gotoxy(28,7) ;
	cprintf(" CRIMINAL MANAGMENT ") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	gotoxy(15,10) ;
	cout <<"This  Project Has Facility Of Maintaining Criminal" ;
	gotoxy(15,11) ;
	cout <<"Records ." ;
	gotoxy(15,13) ;
	cout <<"This  Project Can Hold More Than  10,000  Criminal" ;
	gotoxy(15,14) ;
	cout <<"Records ." ;
	gotoxy(15,16) ;
	cout <<"One Criminal Record Has One Indentification Field & " ;
	gotoxy(15,17) ;
	cout <<"Punishment Work Field To help The User ." ;
	gotoxy(15,19) ;
	cout <<"The Online Help Makes It Much Easier To Operate ." ;
	textcolor(LIGHTGRAY+BLINK) ;
	gotoxy(26,24) ;
	cprintf("Press any key to continue") ;
	textcolor(LIGHTGRAY) ;
	getch() ;
	_setcursortype(_NORMALCURSOR);
}


//**********************************************************
// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: main_menu(void)
{
	clrscr() ;
	char ch ;
	while (1)
	{
		clrscr() ;
		BOX(10,2,71,25,219) ;
		LINE_VER(3,24,11,219) ;
		LINE_VER(3,24,70,219) ;
		BOX(12,3,69,24,218) ;
		gotoxy(25,6) ;
		cout <<"C R I M I N A L   M A N A G M E N T";
		gotoxy(24,7) ;
		cout <<"*************************************" ;
		gotoxy(32,9) ;
		cout <<"1: ADD CRIMINALS" ;
		gotoxy(32,11) ;
		cout <<"2: LIST OF CRIMINALS" ;
		gotoxy(32,13) ;
		cout <<"3: EDIT CRIMINALS FILE" ;
		gotoxy(32,15) ;
		cout <<"4: IDENTIFICATION LIST" ;
		gotoxy(32,17) ;
		cout <<"0: QUIT" ;
		gotoxy(32,20) ;
		cout <<"Enter Your Choice : " ;
		ch = getche() ;
		if (ch == 27)
			return ;
		else
		if (ch == '1')
		{
			criminal p ;
			p.add_criminal() ;
		}
		else
		if (ch == '2')
		{
			criminal p ;
			p.list_of_criminal() ;
		}
		else
		if (ch == '3')
			edit_menu() ;
		else
		if (ch == '4')
		{
			criminal p ;
			p.idn_list_of_criminal() ;
		}
		else
		if (ch == '0')
			break ;
	}
}


//**********************************************************
// THIS FUNCTION CREATE EDIT MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: edit_menu(void)
{
	char ch ;
	while (1)
	{
		clrscr() ;
		BOX(10,2,71,25,219) ;
		LINE_VER(3,24,11,219) ;
		LINE_VER(3,24,70,219) ;
		BOX(12,3,69,24,218) ;
		gotoxy(32,6) ;
		cout <<"E D I T  M E N U" ;
		gotoxy(32,7) ;
		cout <<"****************" ;
		gotoxy(32,10) ;
		cout <<"1: MODIFY CRIMINALS" ;
		gotoxy(32,12) ;
		cout <<"2: DELETE CRIMINALS" ;
		gotoxy(32,14) ;
		cout <<"0: EXIT" ;
		gotoxy(32,17) ;
		cout <<"Enter Choice : " ;
		ch = getche() ;
		if (ch == 27)
			return ;
		else
		if (ch == '1')
		{
			criminal p ;
			p.modify_criminal() ;
			break ;
		}
		else
		if (ch == '2')
		{
			criminal p ;
			p.delete_criminal() ;
			break ;
		}
		else
		if (ch == '0')
			break ;
	}
}


//**********************************************************
// THIS FUNCTION RETURNS THE CODE OF THE LAST RECORD IN THE
// CRIMINAL FILE (CRIMINAL.DAT).
//**********************************************************

int criminal :: last_code(void)
{
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int t=0 ;
	while (file.read((char *) this, sizeof(criminal)))
		t = criminalcode ;
	file.close() ;
	return t ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE  CRIMINALS
//**********************************************************

void criminal :: list_of_criminal(void)
{
	clrscr() ;
	menu M;
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0) ;
	int row = 6 , found = 0 ;
	gotoxy(30,2) ;
	M.BOX(1,1,80,25,219) ;
	cout <<"LIST OF CRIMINALS" ;
	gotoxy(3,4) ;
	cout <<"  CODE     NAME           AGE    P.AGE    IDENTIFICATION      PUNISH.. WORK   " ;
	gotoxy(2,5) ;
	cout <<"******************************************************************************" ;
	M.LINE_VER(1,24,12,219) ;
	M.LINE_VER(1,24,63,219) ;
	M.LINE_VER(1,24,1,219) ;
	M.LINE_VER(1,24,80,219) ;
	M.LINE_HOR(1,24,80,219) ;
	while (file.read((char *) this, sizeof(criminal)))
	{
		delay(20) ;
		found = 1 ;
		gotoxy(5,row) ;
		cout <<criminalcode ;
		gotoxy(14,row) ;
		cout	<<criminalname ;
		gotoxy(29,row) ;
		cout	<<criminalage ;
		gotoxy(36,row) ;
		cout	<<criminalpage ;
		gotoxy(45,row) ;
		cout	<<criminaliden ;
		gotoxy(65,row) ;
		cout	<<criminalpun ;
		if ( row == 22 )
		{
			row = 5 ;
			gotoxy(17,24) ;
			cout <<"Press any Key to continue..." ;
			getche() ;
			clrscr() ;
			gotoxy(30,2) ;
			cout <<"LIST OF CRIMINALS" ;
			gotoxy(3,4) ;
			cout <<"  CODE     NAME           AGE    P.AGE    IDENTIFICATION      PUNISH.. WORK   " ;
			gotoxy(2,5) ;
			cout <<"******************************************************************************" ;
		}
		else
			row++ ;
	}
	if ( !found )
	{
		gotoxy(17,10) ;
		cout <<"\7Records not found" ;
	}
	gotoxy(17,24) ;
	cout <<"Press any Key to continue..." ;
	getche() ;
	file.close () ;
}


//***********************************************************
// THIS FUNCTION ADD RECORDS IN THE CRIMINAL.DAT (CRIMINAL.DAT)
//***********************************************************

void criminal :: add_criminal(void)
{
	int tcode, valid ;
	char ch, t_criminalage[10], t_criminalpage[10] ;
	tcode = last_code() ;
	tcode++ ;
	do
	{
		clrscr() ;
		gotoxy(71,2) ;
		cout <<"<0>=Exit" ;
		gotoxy(27,3) ;
		cout <<"ADDITION OF CRIMINALS" ;
		gotoxy(26,4) ;
		cout <<"*********************" ;
		gotoxy(5,6) ;
		cout <<"Criminal Code            : " <<tcode ;
		gotoxy(5,8) ;
		cout <<"Criminal Name            : " ;
		gotoxy(5,10) ;
		cout <<"Criminal Identification  : " ;
		gotoxy(5,12) ;
		cout <<"Criminal Punishment      : " ;
		gotoxy(5,14) ;
		cout <<"Criminal Age             : " ;
		gotoxy(5,16) ;
		cout <<"Criminal P.age           : " ;
		do
		{
			valid = 1 ;
			gotoxy(1,8) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER CRIMINAL NAME TO ADD IN THE MENU" ;
			gotoxy(5,8) ;
			cout <<"Criminal Name            : " ;
			gets(criminalname) ;
			strupr(criminalname) ;
			if (criminalname[0] == '0')
				return ;
			if ((strlen(criminalname) < 1) || (strlen(criminalname) > 20))
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..20" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER CRIMINAL IDENTIFICATION TO ADD IN THE MENU" ;
			gotoxy(5,10) ;
			cout <<"Criminal Identification  : " ;
			gets(criminaliden) ;
			strupr(criminaliden) ;
			if (criminaliden[0] == '0')
				return ;
			if ((strlen(criminaliden) < 1) || (strlen(criminaliden) > 20))
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..20" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER PUNISHMENT WORK GIVEN TO THE PRISONER" ;
			gotoxy(5,12) ;
			cout <<"Criminal Punishment      : " ;
			gets(criminalpun) ;
			strupr(criminalpun) ;
			if (criminalpun[0] == '0')
				return ;
			if ((strlen(criminalpun) < 1) || (strlen(criminalpun) > 20))
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..20" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER CRIMINAL AGE TO ADD IN THE MENU" ;
			gotoxy(5,14) ;
			cout <<"Criminal Age             : " ;
			gets(t_criminalage) ;
			criminalage = atof(t_criminalage) ;
			if (t_criminalage[0] == '0')
				return ;
			if (criminalage < 1 || criminalage > 200)
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..200" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER CRIMINAL P.AGE TO ADD IN THE MENU" ;
			gotoxy(5,16) ;
			cout <<"Criminal P.age           : " ;
			gets(t_criminalpage) ;
			criminalpage = atof(t_criminalpage) ;
			if (t_criminalpage[0] == '0')
				return ;
			if (criminalpage < 1 || criminalpage > 200)
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..200" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(5,19) ;
			cout <<"Do you want to save this record (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'N' && ch != 'Y') ;
		if (ch == 'Y')
		{
			criminalcode = tcode ;
			fstream file ;
			file.open("CRIMINAL.DAT", ios::out | ios::app ) ;
			file.write((char *) this, sizeof(criminal)) ;
			file.close() ;
			tcode++ ;
		}
		do
		{
			gotoxy(1,17) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(5,22) ;
			cout <<"Do you want to add more records (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'N' && ch != 'Y') ;
	} while (ch == 'Y') ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD OF THE GIVEN CODE FROM
// THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

void criminal :: display_record(int tcode)
{
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(criminal)))
	{
		if (criminalcode == tcode)
		{
			gotoxy(5,3) ;
			cout <<"Criminal Code  : "<<criminalcode ;
			gotoxy(5,4) ;
			cout <<"Criminal Name  : "<<criminalname ;
			gotoxy(5,5) ;
			cout <<"Criminal Ide  : "<<criminaliden ;
			gotoxy(5,6) ;
			cout <<"Criminal Pun  : "<<criminalpun ;
			gotoxy(5,7) ;
			cout <<"Criminal Age  : "<<criminalage ;
			gotoxy(5,8) ;
			cout <<"Criminal P.age : "<<criminalpage ;
			break ;
		}
	}
	file.close() ;
}


//**********************************************************
// THIS FUNCTION RETURN THE VALUE 1 IF THE RECORD IS FOUND
// FOR THE GIVEN CODE IN THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

int criminal :: criminal_found(int tcode)
{
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(criminal)))
	{
		if (criminalcode == tcode)
		{
			found++ ;
			break ;
		}
	}
	file.close() ;
	return found ;
}


//**********************************************************
// THIS FUNCTION RETURN THE RECORD NO. OF THE GIVEN CODE IN
// THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

int criminal :: recordno(int tcode)
{
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(criminal)))
	{
		found++ ;
		if (criminalcode == tcode)
			break ;
	}
	file.close() ;
	return found ;
}


//**********************************************************
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

void criminal :: delete_record(int tcode)
{
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(criminal)) ;
		if ( file.eof() )
			break ;
		if ( criminalcode != tcode )
			temp.write((char *) this, sizeof(criminal)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("CRIMINAL.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(criminal)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(criminal)) ;
	}
	file.close() ;
	temp.close() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO DELETE RECORD FROM
// THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

void criminal :: delete_criminal(void)
{
	clrscr() ;
	char t_code[5], ch ;
	int t, tcode ;
	gotoxy(3,25) ;
	cout <<"Press <ENTER> to see the list" ;
	gotoxy(5,3) ;
	cout <<"Enter Criminal Code of the criminal to be deleted : " ;
	gets(t_code) ;
	t = atoi(t_code) ;
	tcode = t ;
	if (t_code[0] == '0')
		return ;
	if (tcode == 0)
	{
		list_of_criminal() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"Press <ENTER> to Exit" ;
		gotoxy(5,24) ;
		cout <<"Enter Criminal Code of the criminal to be deleted : " ;
		gets(t_code) ;
		t = atoi(t_code) ;
		tcode = t ;
		if (tcode == 0)
			return ;
	}
	clrscr() ;
	if (!criminal_found(tcode))
	{
		gotoxy(5,5) ;
		cout <<"\7Record not found" ;
		getch() ;
		return ;
	}
	display_record(tcode) ;
	do
	{
		gotoxy(1,8) ; clreol() ;
		gotoxy(5,10) ;
		cout <<"Do you want to delete this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	delete_record(tcode) ;
	gotoxy(5,15) ;
	cout <<"\7Record Deleted" ;
	getch() ;
}


//**********************************************************
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

void criminal :: modify_record(int tcode)
{
	int recno ;
	recno = recordno(tcode) ;
	int valid, t_code ;
	char ch, t_criminalage[10], t_criminalpage[10], t_criminalcode[5] ;
	gotoxy(71,2) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,12) ;
	cout <<"Criminal Code            : "<<tcode ;
	gotoxy(5,14) ;
	cout <<"Criminal Name            : " ;
	gotoxy(5,16) ;
	cout <<"Criminal Identification  : " ;
	gotoxy(5,18) ;
	cout <<"Criminal Punishment      : " ;
	gotoxy(5,20) ;
	cout <<"Criminal Age             : " ;
	gotoxy(5,22) ;
	cout <<"Criminal P.age           : " ;
	do
	{
		gotoxy(50,14) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,14) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER CRIMINAL NAME TO ADD IN THE MENU" ;
		gotoxy(5,14) ;
		cout <<"Criminal Name            : " ;
		gets(criminalname) ;
		strupr(criminalname) ;
		if (criminalname[0] == '0')
			return ;
		if ((strlen(criminalname) < 1) || (strlen(criminalname) > 20))
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..20" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(50,16) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,16) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER CRIMINAL IDENTIFICATION TO ADD IN THE MENU" ;
		gotoxy(5,16) ;
		cout <<"Criminal Identification  : " ;
		gets(criminaliden) ;
		strupr(criminaliden) ;
		if (criminaliden[0] == '0')
			return ;
		if ((strlen(criminaliden) < 1) || (strlen(criminaliden) > 20))
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..20" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(50,18) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,18) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER PUNISHMENT WORK GIVEN TO THE PRISONER" ;
		gotoxy(5,18) ;
		cout <<"Criminal Punishment      : " ;
		gets(criminalpun) ;
		strupr(criminalpun) ;
		if (criminalpun[0] == '0')
			return ;
		if ((strlen(criminalpun) < 1) || (strlen(criminalpun) > 20))
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..20" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(50,20) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,20) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER CRIMINAL AGE TO ADD IN THE MENU" ;
		gotoxy(5,20) ;
		cout <<"Criminal Age             : " ;
		gets(t_criminalage) ;
		criminalage = atof(t_criminalage) ;
		if (t_criminalage[0] == '0')
			return ;
		if (criminalage < 1 || criminalage > 200)
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..200" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(50,22) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,22) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER CRIMINAL PUNISHMENT AGE TO ADD IN THE MENU" ;
		gotoxy(5,22) ;
		cout <<"Criminal P.age           : " ;
		gets(t_criminalpage) ;
		criminalpage = atof(t_criminalpage) ;
		if (t_criminalpage[0] == '0')
			return ;
		if (criminalpage < 1 || criminalpage > 200)
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..200" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(1,21) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(5,24) ;
		cout <<"Do you want to save this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	clrscr();
	gotoxy(5,12) ;
	cout <<"Modified Record is       :-" ;
	gotoxy(5,12) ;
	cout <<"Criminal Code            : "<<tcode ;
	gotoxy(5,14) ;
	cout <<"Criminal Name            : "<<criminalname ;
	gotoxy(5,16) ;
	cout <<"Criminal Identification  : "<<criminaliden ;
	gotoxy(5,18) ;
	cout <<"Criminal Punishment      : "<<criminalpun ;
	gotoxy(5,20) ;
	cout <<"Criminal Age             : "<<criminalage ;
	gotoxy(5,22) ;
	cout <<"Criminal P.age           : "<<criminalpage ;
	fstream file ;
	file.open("CRIMINAL.DAT", ios::out | ios::ate) ;
	int location ;
	location = (recno-1) * sizeof(criminal) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(criminal)) ;
	file.close() ;
	sort() ;
	gotoxy(50,18) ;
	cout <<"\7Record Modified" ;
	getch() ;
}


//**********************************************************
// THIS FUNCTION GIVES THE CODE NO. TO MODIFY RECORD FROM
// THE CRIMINAL FILE (CRIMINAL.DAT)
//**********************************************************

void criminal :: modify_criminal(void)
{
	clrscr() ;
	char t_code[5], ch ;
	int t, tcode ;
	gotoxy(3,25) ;
	cout <<"Press <ENTER> to see the list" ;
	gotoxy(5,3) ;
	cout <<"Enter Criminal Code of the criminal to be Modify : " ;
	gets(t_code) ;
	t = atoi(t_code) ;
	tcode = t ;
	if (t_code[0] == '0')
		return ;
	if (tcode == 0)
	{
		list_of_criminal() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"Press <ENTER> to Exit" ;
		gotoxy(5,24) ;
		cout <<"Enter Criminal Code of the criminal to be modify : " ;
		gets(t_code) ;
		t = atoi(t_code) ;
		tcode = t ;
		if (tcode == 0)
			return ;
	}
	clrscr() ;
	if (!criminal_found(tcode))
	{
		gotoxy(5,5) ;
		cout <<"\7Record not found" ;
		getch() ;
		return ;
	}
	display_record(tcode) ;
	do
	{
		gotoxy(5,10) ;
		cout <<"Do you want to Modify this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	modify_record(tcode) ;
}


//****************************************************************
// THIS FUNCTION SORT THE RECORD IN THE CRIMINAL FILE (CRIMINAL.DAT)
// ACCORDING TO THE CODE NOS.
//****************************************************************

void criminal :: sort(void)
{
	int i=0,j ;
	criminal arr[100] ;
	criminal temp ;
	fstream file ;
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) &arr[i], sizeof(criminal)))
		i++ ;
	int size ;
	size = i ;
	file.close() ;
	for (i=1; i<size; i++)
		for (j=0; j<size-i; j++)
		{
			if (arr[j].criminalcode > arr[j+1].criminalcode)
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	file.open("CRIMINAL.DAT", ios::out) ;
	for (i=0; i<size; i++)
		file.write((char *) &arr[i], sizeof(criminal)) ;
	file.close() ;
}


//**********************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE  CRIMINALS
//**********************************************************

void criminal :: idn_list_of_criminal(void)
{
	clrscr() ;
	menu M;
	fstream file ;
	int row = 6 , found = 0 ;
	char ch,iden[30];
	gotoxy(72,1) ;
	cout <<"<0>=Exit" ;
	gotoxy(3,2) ;
	cout <<"Enter The Identification Of The Criminal To Be Searched :- " ;
	int valid=0 ;
	while (!valid)
	{
	valid = 1 ;
	gotoxy(5,25) ; clreol() ;
	cout <<"Enter the Identification String to be searched " ;
	gotoxy(62,2) ; clreol() ;
	gets(iden) ;
	strupr(iden) ;
	if (iden[0] == '0')
		return ;
	if (strlen(iden) < 1 || strlen(iden) > 20)
	{
		valid = 0 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"\7Enter correctly (Range: 1..20)" ;
		getch() ;
		}
	}
	file.open("CRIMINAL.DAT", ios::in) ;
	file.seekg(0) ;
	gotoxy(30,2) ;
	clrscr();
	M.BOX(1,1,80,25,219) ;
	cout <<"LIST OF CRIMINALS" ;
	gotoxy(3,4) ;
	cout <<"  CODE     NAME           AGE    P.AGE    IDENTIFICATION      PUNISH.. WORK   " ;
	gotoxy(2,5) ;
	cout <<"******************************************************************************" ;
	M.LINE_VER(1,24,12,219) ;
	M.LINE_VER(1,24,63,219) ;
	M.LINE_VER(1,24,1,219) ;
	M.LINE_VER(1,24,80,219) ;
	M.LINE_HOR(1,24,80,219) ;
	while (file.read((char *) this, sizeof(criminal)))
	{
		if (strstr(criminaliden,iden))
		{
		delay(20) ;
		found = 1 ;
		gotoxy(5,row) ;
		cout <<criminalcode ;
		gotoxy(14,row) ;
		cout	<<criminalname ;
		gotoxy(29,row) ;
		cout	<<criminalage ;
		gotoxy(36,row) ;
		cout	<<criminalpage ;
		gotoxy(45,row) ;
		cout	<<criminaliden ;
		gotoxy(65,row) ;
		cout	<<criminalpun ;
		if ( row == 22 )
		{
			row = 5 ;
			gotoxy(17,24) ;
			cout <<"Press any Key to continue..." ;
			getche() ;
			clrscr() ;
			gotoxy(30,2) ;
			cout <<"LIST OF CRIMINALS" ;
			gotoxy(3,4) ;
			cout <<"  CODE     NAME           AGE    P.AGE    IDENTIFICATION      PUNISH.. WORK   " ;
			gotoxy(2,5) ;
			cout <<"******************************************************************************" ;
		}
		else
			row++ ;
	}
	}
	if ( !found )
	{
		gotoxy(17,10) ;
		cout <<"\7Records not found" ;
	}
	gotoxy(17,24) ;
	cout <<"Press any Key to continue..." ;
	getche() ;
	file.close () ;
}


//**********************************************************
// THIS FUNCTION IS THE MAIN FUNCTION CALLING THE MAIN MENU
//**********************************************************

void main(void)
{
	clrscr() ;
	menu m ;
	m.introduction();
	m.main_menu() ;
}

//**********************************************************
