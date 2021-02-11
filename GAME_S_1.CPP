
#include <time.h>
#include <conio.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#define up 72
#define down 80
#define right 77
#define left 75
#define space 32
#define esc 27

char c = left;
int x = 0;

int xuser = 74, yuser = 10, level = 0,
xc1 = 0, yc1 = 7,
xc2 = 0, yc2 = 3,
xc3 = 0, yc3 = 10,
xc4 = 0, yc4 = 20,
xc5 = 0, yc5 = 15,
c1 = 20, f1 = 0, c2 = 0, f2 = 0,
c4 = 0, f4 = 0, c5 = 0, f5 = 0, c3 = 0,
xyeryotuser, xyeryotc1_front = 0, xyeryotc4_front = 0, xyeryotc3_front = 0, xyeryotc5_front = 0, xyeryotc2_front = 0,
x_big_u = 72, y_big_u = 9, x_big_c = 1, y_big_c = 9,
_delay = 1, time_ = 0,
xt = 0, yt = 3,
xl = 0, yl = 12,
xp = 40, yp = 1,
life_ = 7,
flag1 = 40, flag2 = 40, flag3 = 40, flag4 = 40,
flag5 = 40,

color1 = 4, color1_timer = 0,
sx1 = 1, sy1 = 3, sx2 = 1, sy2 = 23, sx3 = 1, sy3 = 13,
sx4 = 1, sy4 = 17, sx5 = 1, sy5 = 19, sx6 = 1, sy6 = 8, sx7 = 1, sy7 = 5,
flag_yeriyot = 0, BLINK_1 = 0, f_blank = 0, f_s2 = 1, f_s3 = 1, f_s1 = 1, f_s4 = 1, f_s5 = 1, f_s6 = 1, f_s7 = 1, ps = 1, f_yeryot_user = 0;
//a ship war
char bord[5][68] = { {0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,0 },
					{ 0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0 },
					{ 0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0 },
					{ 0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,1,0 },
					{ 0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1 } };
char s[3][3] = { {0,2,0},
{2,0,2},
{0,2,0} };
char row[3][5] = {{  0,42,0 ,0 ,0 },
				  { 42,42,42,42,42 },
				  {  0,42,0 ,0 ,0 } };


char island[22][20] = { { 1,1,1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

{ 1,1,1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
{ 1,1,1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0} };






















char seven[10][12] = { {1,1,1,1,1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0} };

char sc_b[6][9] = { { 0, 0,' ',0,219,16, ' ',0,0 },
					{ 0,0,' ',' ',219, ' ', ' ',0,0 },
					{ 219,219, 219, 219,219,219, 219,219,219 },
					{ 219, 219, 219, 219,219,219, 219,219 ,219 },
					{ 0,219, 219, 219,219,219, 219,219,0 },
					{ 0, 0, 219, 219, 219,219,219,0,0 } };

char su_b[6][9] = { {0, 0,' ',17,219,0, ' ',0,0 },
				  { 0,0,' ',' ',219, ' ', ' ',0,0 },
				  { 219,219, 219, 219,219,219, 219,219,219 },
				  {219, 219, 219, 219,219,219, 219,219 ,219},
				  { 0,219, 219, 219,219,219, 219,219,0 },
				  {0, 0, 219, 219, 219,219,219,0,0 } };

char line[80] = { 45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,45 };
char smiles[16] = { 17, 1, 45, 1,45,1,45, 1,45,1,45, 1,45, 1,16 };
//char timer[6] = { "TIMER " };
int l = 9;


char boom1[4][5] = { {42,' ',42,0,42 },
{ ' ',42,42, 42, ' ' },
{ 66, 79,79,77, 33 },
{ 0, 0, 0,0,0 } };

char shipc1[4][5] = { { ' ',' ',219,228,' ' },
{ ' ',' ',219, ' ', ' ' },
{ 219, 219,219,219, 219},
{ 0, 219, 219,219,0 } };

char shipc2[4][5] = { { ' ',' ',219,228,' ' },
{0,' ',219, ' ',0 },
{ 219, 219,219,219, 219 },
{0, 223, 223,223,0 } };

char shipc3[4][5] = { { ' ',' ',219,228,' ' },
{ ' ',' ',219, ' ', ' ' },
{ 219, 219,219,219, 219},
{  0, 219, 219,219,0 } };

char shipc4[4][5] = { { ' ',' ',219,228,' ' },
{ ' ',' ',219, ' ', ' ' },
{ 219, 219,219,219, 219 },
{ 0, 219, 219,219,0 } };

char shipc5[4][5] = { { ' ',' ',219,228,' ' },
{ ' ',' ',219, ' ', ' ' },
{ 219, 219,219,219, 219 },
{ 0, 219, 219,219,0 } };


char user[3][5] = { {' ',17 ,179,16, ' ' },
{ 219,219, 219,219, 219},
{ 0, 219, 219, 219,0 } };

//char s1[4][4] = { {}, };



void print_user_ship();
void the_shipc();
//void yeriyotc1();
void yeryotuser();
void move();
void delete_shipc1();
void delete_shipc2();
void delete_shipc3();
void delete_shipc4();
void delete_shipc4();
void delete_shipc5();

void print_shipc1();
void print_shipc2();
void print_shipc3();
void print_shipc4();
void print_shipc5();

void beginning();
void print_suprises();
void delete_user_ship();
void print_user_ship();
void get_c();
void boom();
void print_empty();
void print_paint1();
void print_paint2();
void print_paint3();
void smiles_full(int p);
void check_s_right(int *sx, int *sy, int *f_s);
void check_s_left(int *sx, int*sy, int *f_s);
void check_s_up(int *sx, int *sy, int *f_s);
void check_s_down(int *sx, int *sy, int *f_s);
void check_c_yeryot(int *c, int *f, int *xyeryotc_front, int *xc, int *yc);
void print_big_ship_c(); void print_big_ship_u();
void delete_big_ship_u();
void delete_big_ship_c();
void print_boom(int xc, int xy);
void chek_shipc_boom(int *xc, int *yc, int d, int *xyeryot, int *flag);
void next_step();
void print_s_begining(int color, int j_);
void print_rows();
void print_row1();
void print_row2();
void print_row3();



void main()
{
	randomize(); int i, j;
	//windos(1, 20, 80, 25);
	_setcursortype(_NOCURSOR);
	textbackground(0);
	clrscr();

	/*sy1 = rand() % 23;
	sy2 = rand() % 23;
	sy3 = rand() % 23;
	sy4 = rand() % 23;*/
	//sy1 = 5;
	//sy3 = 18;
	//sy4 = 23;
	//sy5 = rand() % 23;
	//sy6 = rand() % 23;
	beginning();
	//c = getch();
	gotoxy(34, 1);
	for (j = 0; j < 16; j++)
	{
		textcolor(6);
		cprintf("%c", smiles[j]);
	}


	//gotoxy(xl, yl);
	//cout << line;
	//cout << "\n";
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 11; j++)
	//	{
	//		cout << time_line[i][j];
	//	}
	//	cout << "\n";
	//}
	//print_paint1();
	//print_paint2();
	//print_paint3();

	//print_empty();
	gotoxy(4, 1);
	textcolor(4 /*+ BLINK*/);
	cprintf("life %c %d", 6, life_--);
	//xdollar = (rand() % 77) + 1;
	//ydollar = (rand() % 23) + 3;
	//gotoxy(xdollar, ydollar);
	//putch(6);


	while (c != esc)
	{
		print_user_ship();
		the_shipc();
		get_c();
		the_shipc();

	}
	getch();

}


void get_c()
{



	if (c == up || c == down || c == left || c == right)
	{
		move();
	}
	else
		if (c == space)
		{
			f_yeryot_user = 1;
			//if (xyeryotuser - 21 == xc + 7 && yc + 3 == yuser + 1)
			//{
			//	//delete_ship_c();
			//	xc = 0;
			//}
			/*if (chack_user_yeriyotc() == 0)
			cout << "yes;;;";*/
		}

}
//user ship move
void move()
{
	int i, j;
	delete_user_ship();

	if (c == up && yuser > 3)
	{
		check_s_up(&sx1, &sy1, &f_s1);
		check_s_up(&sx2, &sy2, &f_s2);
		check_s_up(&sx3, &sy3, &f_s3);
		check_s_up(&sx4, &sy4, &f_s4);
		check_s_up(&sx5, &sy5, &f_s5);
		check_s_up(&sx6, &sy6, &f_s6);
		check_s_up(&sx7, &sy7, &f_s7);

		//if (!(check_s_up(&sx1, &sy1, &f_s1)))//0
		//{
		//	if (!(check_s_up(&sx2, &sy2, &f_s2)))
		//	{
		//		if (!(check_s_up(&sx3, &sy3, &f_s3)))
		//		{
		//			if (!(check_s_up(&sx4, &sy4, &f_s4)))
		//			{
		//				if (!(check_s_up(&sx5, &sy5, &f_s5)))
		//				{
		//					if (!(check_s_up(&sx6, &sy6, &f_s6)))
		//						check_s_up(&sx7, &sy7, &f_s7);
		//				}

		//			}

		//		}

		//	}

		//}

		yuser--;
	}

	else
	{
		if (c == left && xuser > 1)
		{

			check_s_left(&sx1, &sy1, &f_s1);
			check_s_left(&sx2, &sy2, &f_s2);
			check_s_left(&sx3, &sy3, &f_s3);
			check_s_left(&sx4, &sy4, &f_s4);
			check_s_left(&sx5, &sy5, &f_s5);
			check_s_left(&sx6, &sy6, &f_s6);
			check_s_left(&sx7, &sy7, &f_s7);

			xuser--;
		}
		else
		{
			if (c == down && yuser < 21)
			{

				check_s_down(&sx1, &sy1, &f_s1);
				check_s_down(&sx2, &sy2, &f_s2);
				check_s_down(&sx3, &sy3, &f_s3);
				check_s_down(&sx4, &sy4, &f_s4);
				check_s_down(&sx5, &sy5, &f_s5);
				check_s_down(&sx6, &sy6, &f_s6);
				check_s_down(&sx7, &sy7, &f_s7);

				yuser++;
			}
			else
				if (c == right&&xuser < 78)
				{
					check_s_right(&sx1, &sy1, &f_s1);
					check_s_right(&sx2, &sy2, &f_s2);
					check_s_right(&sx3, &sy3, &f_s3);
					check_s_right(&sx4, &sy4, &f_s4);
					check_s_right(&sx5, &sy5, &f_s5);
					check_s_right(&sx6, &sy6, &f_s6);
					check_s_right(&sx7, &sy7, &f_s7);
					xuser++;
				}
		}
	}
	//if (xc1 + 5 == xuser && yc1 == yuser)
	//{
	//	boom();
	//}
	print_user_ship();
}
//void yeryotuser();
//{
//
//}
void check_s_right(int *sx, int *sy, int *f_s)
{
	if (*sx == xuser + 3 && *sy >= yuser&&*sy <= yuser + 4)
	{
		*f_s = 0;
		smiles_full(ps);
		ps += 2;
	}
}
void check_s_left(int *sx, int*sy, int *f_s)
{
	if (*sx == xuser&&*sy >= yuser&&*sy <= yuser + 4)
	{
		*f_s = 0;
		smiles_full(ps);
		ps += 2;
	}

}
void check_s_up(int *sx, int *sy, int *f_s)
{
	if (*sx >= xuser&&*sx <= xuser + 4 && *sy == yuser)
	{
		*f_s = 0;
		smiles_full(ps);
		ps += 2;
	}
}
void check_s_down(int *sx, int *sy, int *f_s)
{
	if (*sx >= xuser&&*sx <= xuser + 4 && *sy == yuser + 4)
	{
		*f_s = 0;
		smiles_full(ps);
		ps += 2;
	}
}


void the_shipc()
{
	while ((!(kbhit())) && time_ < 400 && life_ != 0)
	{
		gotoxy(56, 1);
		cprintf("TIMER %d ", time_++);

		/*switch (_delay)
		{
		case
		}
			break;

		default:
		}
	//	*/

		if (_delay > 24)
		{
			if (f_s7 == 1)
			{
				gotoxy(sx7, sy7);
				cprintf("%c", 2);
			}
		}
		if (_delay > 55)
		{
			if (f_s6 == 1)
			{
				gotoxy(sx6, sy6);
				cprintf("%c", 2);
			}
		}
		if (_delay > 75)
		{
			if (f_s5 == 1)
			{
				gotoxy(sx5, sy5);
				cprintf("%c", 2);
			}

		}
		if (_delay > 45 && flag1 >= 40)
		{
			print_shipc1();
			//check_c_yeryot(&c1, &f1, &xyeryotc1_front, &xc1, &yc1);
			if (c1 == 65)
			{
				c1 = 20; xyeryotc1_front = 0;
			}

			if (c1 >= 43 && c1 <= 65 && xc1 + 5 + xyeryotc1_front + 11 < 81)
			{

				gotoxy(xc1 + 5 + xyeryotc1_front, yc1 + 1);
				textcolor(4);
				cprintf("**  **  **");
				if ((xc1 + 4 + xyeryotc1_front <= xuser&&xc1 + 5 + xyeryotc1_front + 11 >= xuser&&yc1 + 1 >= yuser&&yc1 + 1 <= yuser + 4)/*|| (xc1 + 4 + xyeryotc1_front + 11==xuser)*/)
				{
					boom();
				}
				xyeryotc1_front++;
			}

			c1++;
		}
		if (_delay > 40)
		{
			if (f_s4 == 1)
			{
				gotoxy(sx4, sy4);
				cprintf("%c", 2);
			}
			if (flag4 >= 40)
			{
				print_shipc4();
				if (c4 == 38)
				{
					c4 = 0; xyeryotc4_front = 0;
				}

				if (c4 >= 17 && c4 <= 38 /*&& f4<24 */ && xc4 + 5 + xyeryotc4_front + 11 < 81)
				{
					gotoxy(xc4 + 5 + xyeryotc4_front, yc4 + 1);
					textcolor(4);
					cprintf("**  **  **");


				}
				c4++;
			}

		}

		if (_delay > 18)
		{
			if (f_s3 == 1)
			{
				gotoxy(sx3, sy3);
				cprintf("%c", 2);
			}
		}
		if (f_s1 == 1)
		{
			gotoxy(sx1, sy1);
				cprintf("%c", 2);
		}
		if (flag3 >= 40)
		{
			print_shipc3();
			if (c3 == 35)
			{
				c3 = 0; xyeryotc3_front = 0;
			}

			if (c3 >= 6 && c3 <= 35 && xc3 + 5 + xyeryotc3_front + 11 < 81)
			{
				gotoxy(xc3 + 5 + xyeryotc3_front, yc3 + 1);
				textcolor(4);
				cprintf("**  **  **");

				if ((xc3 + 4 + xyeryotc3_front <= xuser&&xc3 + 5 + xyeryotc3_front + 11 >= xuser&&yc3 + 1 >= yuser&&yc3 + 1 <= yuser + 4)/*|| (xc1 + 4 + xyeryotc1_front + 11==xuser)*/)
				{
					boom();
				}
				xyeryotc3_front++;
			}
			c3++;
		}


		if (_delay > 15 && flag5 >= 40)
		{
			print_shipc5();
			//check_c_yeryot(&c5, &f5, &xyeryotc5_front, &xc5, &yc5);
			if (c5 == 54)
			{
				c5 = 10; xyeryotc5_front = 0;
			}

			if (c5 >= 33 && c5 <= 54 /*&& f4<24 */ && xc5 + 5 + xyeryotc5_front + 11 < 81)
			{

				gotoxy(xc5 + 5 + xyeryotc5_front, yc5 + 1);
				textcolor(4);
				cprintf("**  **  **");

				if ((xc5 + 4 + xyeryotc5_front <= xuser&&xc5 + 5 + xyeryotc5_front + 11 >= xuser&&yc5 + 1 >= yuser&&yc5 + 1 <= yuser + 4)/*|| (xc1 + 4 + xyeryotc1_front + 11==xuser)*/)
				{
					boom();
				}
				xyeryotc5_front++;
			}
			c5++;
		}


		if (_delay > 12)
		{
			if (f_s2 == 1)
			{
				gotoxy(sx2, sy2);
				cprintf("%c", 2);
			}
			if (flag2 >= 40)
			{
				print_shipc2();
				if (c2 == 44)
				{
					c2 = 0; xyeryotc2_front = 0;
				}

				if (c2 >= 23 && c2 <= 44 /*&& f4<24 */ && xc2 + 5 + xyeryotc2_front + 11 < 81)
				{
					gotoxy(xc2 + 5 + xyeryotc2_front, yc2 + 1);
					textcolor(4);
					cprintf("**  **  **");
					if ((xc2 + 4 + xyeryotc2_front <= xuser&&xc2 + 5 + xyeryotc2_front + 11 >= xuser&&yc2 + 1 >= yuser&&yc2 + 1 <= yuser + 4)/*|| (xc1 + 4 + xyeryotc1_front + 11==xuser)*/)
					{
						boom();
					}
					xyeryotc2_front++;
				}

				c2++;
			}

		}
		while (f_yeryot_user == 1 && xuser - x - 10 > 1)
		{
			gotoxy(xuser - x - 10, yuser + 1);
			cprintf(" * * * * ");


			chek_shipc_boom(&xc1, &yc1, 45, &xyeryotc1_front, &flag1);
			chek_shipc_boom(&xc2, &yc2, 12, &xyeryotc2_front, &flag2);
			chek_shipc_boom(&xc3, &yc3, 0, &xyeryotc3_front, &flag3);
			chek_shipc_boom(&xc4, &yc4, 40, &xyeryotc4_front, &flag4);
			chek_shipc_boom(&xc5, &yc5, 15, &xyeryotc5_front, &flag5);


			/*if (xc1+4 == xuser - x - 10 && yuser + 1 >= yc1&&yuser + 1 <= yc1 + 4&& _delay>45)
			{
				print_boom(xc1 ,yc1);

				f_yeryot_user = 0;
				gotoxy(xc1 + 5 + xyeryotc1_front - 2, yc1 + 1);
				cprintf("          ");
				gotoxy(xuser - x - 10, yuser + 1);
				cprintf("         ");
				xc1 = -40; flag1 = 0;

			}*/
			/*	if (xc2 + 4 == xuser - x - 10 && yuser + 1 >= yc2&&yuser + 1 <= yc2 + 4 && _delay>12)
				{
					print_boom(xc2, yc2);

					xc2 = -40; flag2 = 0;
					f_yeryot_user = 0;

				}*/
				/*if (xc3 + 4 == xuser - x - 10 && yuser + 1 >= yc3&&yuser + 1 <= yc3 + 4 )
				{
					print_boom(xc3, yc3);

					xc3 = -40; flag3 = 0;
					f_yeryot_user = 0;

				}
				if (xc4 + 4 == xuser - x - 10 && yuser + 1 >= yc4&&yuser + 1 <= yc4 + 4 && _delay>40)
				{
					print_boom(xc4, yc4);

					xc4 = -40; flag4 = 0;
					f_yeryot_user = 0;

				}
				if (xc5 + 4 == xuser - x - 10 && yuser + 1 >= yc5&&yuser + 1 <= yc5 + 4 && _delay>15)
				{
					print_boom(xc5, yc5);

					xc5= -40; flag5 = 0;
					f_yeryot_user = 0;

				}
			*/
			delay(15);
			gotoxy(xuser - x - 10, yuser + 1);
			cprintf("         ");
			x++;
		}
		x = 0;
		flag1++; flag2++; flag3++; flag4++; flag5++;





		f_yeryot_user = 0;

		if ((((xuser + 3 >= xc1 && xuser + 3 <= xc1 + 3) || (xuser >= xc1&&xuser <= xc1 + 6)) && ((yuser >= yc1 && yuser <= yc1 + 3) || (yc1 >= yuser && yc1 <= yuser + 2)))
			|| (((xuser + 3 >= xc2 && xuser + 3 <= xc2 + 3) || (xuser >= xc2&&xuser <= xc2 + 6)) && ((yuser >= yc2 && yuser <= yc2 + 3) || (yc2 >= yuser && yc2 <= yuser + 2)))
			|| (((xuser + 3 >= xc3 && xuser + 3 <= xc3 + 3) || (xuser >= xc3&&xuser <= xc3 + 6)) && ((yuser >= yc3 && yuser <= yc3 + 3) || (yc3 >= yuser && yc3 <= yuser + 2)))
			|| (((xuser + 3 >= xc4 && xuser + 3 <= xc4 + 3) || (xuser >= xc4&&xuser <= xc4 + 6)) && ((yuser >= yc4 && yuser <= yc4 + 3) || (yc4 >= yuser && yc4 <= yuser + 2)))
			|| (((xuser + 3 >= xc5 && xuser + 3 <= xc5 + 3) || (xuser >= xc5&&xuser <= xc5 + 6)) && ((yuser >= yc5 && yuser <= yc5 + 3) || (yc5 >= yuser && yc5 <= yuser + 2)))
			)
		{
			boom();
		}
		//switch (_delay>)
		//{
		//case 24: sx7++;
		//}
		if (_delay > 24 && f_s7 == 1)
		{
			sx7++;
		}
		else
		{
			sx7 = NULL;
		}
		if (_delay > 55 && f_s6 == 1)
		{
			sx6++;
		}
		else
		{
			sx6 = NULL;
		}
		if (_delay > 75 && f_s5 == 1)
		{
			sx5++;
		}
		else
		{
			sx5 = NULL;
		}
		if (_delay > 18 && f_s3 == 1)
		{
			sx3++;
		}
		else
		{
			sx3 = NULL;
		}
		if (_delay > 15)
		{
			xc5++;
		}
		if (_delay > 45)
		{

			xc1++;
		}
		if (_delay > 40)
		{
			if (f_s4 == 1)
			{
				sx4++;
			}
			else { sx4 = NULL; }
			xc4++;
		}
		if (_delay > 12)
		{
			if (f_s2 == 1)
			{
				sx2++;
			}
			else { sx2 = NULL; }

			xc2++;
		}
		if (f_s1 == 1)
		{
			sx1++;
		}
		else { sx1 = NULL; }
		xc3++;
		delay(170);

		_delay++;
		if (_delay > 24)
		{
			if (f_s7 == 1)
			{
				gotoxy(sx7 - 1, sy7);
				cprintf("%c", 0);
			}
			if (sx7 - 1 == xuser&&sy7 >= yuser&&sy7 <= yuser + 3/*||(sx7>=xuser&&sx7<=xuser+3&&sy7==yuser)*/)
			{
				f_s7 = 0;
				smiles_full(ps);
				ps += 2;
			}
		}
		if (_delay > 55)
		{
			if (f_s6 == 1)
			{
				gotoxy(sx6 - 1, sy6);
				cprintf("%c", 0);
			}
			if (sx6 - 1 == xuser&&sy6 >= yuser&&sy6 <= yuser + 3)
			{
				f_s6 = 0;
				smiles_full(ps);
				ps += 2;
			}
		}
		if (_delay > 75)
		{
			if (f_s5 == 1)
			{
				gotoxy(sx5 - 1, sy5);
				cprintf("%c", 0);
			}
			if (sx5 - 1 == xuser&&sy5 >= yuser&&sy5 <= yuser + 3)
			{
				f_s5 = 0;
				smiles_full(ps);
				ps += 2;
			}
		}

		if (_delay > 40)
		{
			if (f_s4 == 1)
			{
				gotoxy(sx4 - 1, sy4);
				cprintf("%c", 0);
			}
			if (sx4 - 1 == xuser&&sy4 >= yuser&&sy4 <= yuser + 3)
			{
				f_s4 = 0;
				smiles_full(ps);
				ps += 2;
			}
			if (flag4 >= 40)
			{

				delete_shipc4();
				if (c4 >= 17 && c4 <= 38)
				{
					if ((xc4 + 4 + xyeryotc4_front <= xuser&&xc4 + 5 + xyeryotc4_front + 11 >= xuser&&yc4 + 1 >= yuser&&yc4 + 1 <= yuser + 4)/*|| (xc1 + 4 + xyeryotc1_front + 11==xuser)*/)
					{
						boom();
						gotoxy(xc4 + 5 + xyeryotc4_front, yc4 + 1);
						cprintf("          ");
					}
					xyeryotc4_front++;
					gotoxy(xc4 + 5 + xyeryotc4_front - 2, yc4 + 1);
					cprintf("          ");
				}

			}

		}
		if (_delay > 18)
		{
			if (f_s3 == 1)
			{
				gotoxy(sx3 - 1, sy3);
				cprintf("%c", 0);
			}
			if (sx3 - 1 == xuser&&sy3 >= yuser&&sy3 <= yuser + 3)
			{
				f_s3 = 0;
				smiles_full(ps);
				ps += 2;
			}
		}
		if (_delay > 12)
		{
			if (f_s2 == 1)
			{
				gotoxy(sx2 - 1, sy2);
				cprintf("%c", 0);
			}
			if (sx2 - 1 == xuser&&sy2 >= yuser&&sy2 <= yuser + 3)
			{
				f_s2 = 0;
				smiles_full(ps);
				ps += 2;
			}
			if (flag2 >= 40)
			{
				delete_shipc2();
				if (c2 >= 23 && c2 <= 45)
				{
					gotoxy(xc2 + 5 + xyeryotc2_front - 2, yc2 + 1);
					cprintf("          ");
				}
			}

		}
		if (f_s1 == 1)
		{
			gotoxy(sx1 - 1, sy1);
			cprintf("%c", 0);
		}
		if (sx1 - 1 == xuser&&sy1 >= yuser&&sy1 <= yuser + 3)
		{
			f_s1 = 0;
			smiles_full(ps);
			ps += 2;
		}
		if (_delay > 15 && flag5 >= 40)
		{
			delete_shipc5();
			if (c5 >= 33 && c5 <= 54)
			{
				gotoxy(xc5 + 5 + xyeryotc5_front - 2, yc5 + 1);
				cprintf("          ");
			}
		}
		if (_delay > 45 && flag1 >= 40)
		{
			delete_shipc1();
			if (c1 >= 43 && c1 <= 65)
			{
				gotoxy(xc1 + 5 + xyeryotc1_front - 2, yc1 + 1);
				cprintf("          ");
			}

		}
		if (flag3 >= 40)
		{
			delete_shipc3();
			if (c3 >= 6 && c3 <= 35)
			{
				gotoxy(xc3 + 5 + xyeryotc3_front - 2, yc3 + 1);
				cprintf("          ");
			}
		}

		if (sx7 > 79)
		{
			sx7 = 0;
		}
		if (sx6 > 77)
		{
			sx6 = 0;
		}
		if (sx5 > 77)
		{
			sx5 = 0;
		}
		if (sx1 > 77)
		{
			sx1 = 0;
		}
		if (sx2 > 77)
		{
			sx2 = 0;
		}
		if (sx3 > 77)
		{
			sx3 = 0;
		}
		if (sx4 > 77)
		{
			sx4 = 0;
		}



		if (xc1 > 77)
		{
			xc1 = 0;
			xyeryotc1_front = 0;
		}
		if (xc2 > 77)
		{
			xc2 = 0;			xyeryotc2_front = 0;

		}

		if (xc3 > 77)
		{
			xc3 = 0;			xyeryotc3_front = 0;

		}

		if (xc4 > 77)
		{
			xc4 = 0;			xyeryotc4_front = 0;

		}

		if (xc5 > 77)
		{
			xc5 = 0;			xyeryotc5_front = 0;

		}

		//if ((xc1 <= xuser&&xc1 + 5 >= xuser) && (yc1 <= yuser&&yc1 + 4 <= yuser))
		//{
		//	();
		//}


	}

	if (time_ == 400)
	{
		gotoxy(50, 11);
		cout << "Time is over!";
	}
	c = getch();
	if (c == 0)
	{
		c = getch();
	}
}

//void check_c_yeryot(int *c, int *f, int *xyeryotc_front, int *xc, int *yc)
//{
//	if (*c > 0 && *f<24 && *xc + 5 + *xyeryotc_front + 26<81)
//	{
//		*f++;
//		gotoxy(*xc + 5 + *xyeryotc_front, *yc + 1);
//		textcolor(4);
//		cprintf("*  *  *  *  *  *  *  *  *");
//		cout << *f; char c;
//		c = getch();
//		*xyeryotc_front++;
//		/*	if ((xc1 <= xuser&&xc1+26>=xuser &&yc1 + 1 >= yuser&&yc1 + 1 <= yuser + 3))
//		if (xc4 + 6 + xyeryotc4_front <= xuser&&xc4 + 6 + xyeryotc4_front + 26 >= xuser&&yc4 + 1 >= yuser&&yc4 + 1 <= yuser + 4)
//		{
//		boom();
//		}*/
//	}
//	else
//	{
//		*c = 0; *f = 0, *xyeryotc_front = 0;
//
//	}
//}

void delete_shipc1()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		gotoxy(xc1, i + yc1);
		for (j = 0; j < 5; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
}
void delete_shipc2()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		gotoxy(xc2, i + yc2);
		for (j = 0; j < 5; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
}
void delete_shipc3()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		gotoxy(xc3, i + yc3);
		for (j = 0; j < 5; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
}
void delete_shipc4()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		gotoxy(xc4, i + yc4);
		for (j = 0; j < 5; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
}
void delete_shipc5()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		gotoxy(xc5, i + yc5);
		for (j = 0; j < 5; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
}

void print_shipc1()
{
	int i, j;

	for (i = 0; i < 4; i++)//print
	{
		gotoxy(xc1 + 2, i + yc1);
		for (j = 0; j < 5; j++)
		{
			textcolor(4);
			putch(shipc1[i][j]);
		}
		cout << "\n";
	}
}
void print_shipc2()
{
	int i, j;

	for (i = 0; i < 4; i++)//print
	{
		gotoxy(xc2 + 2, i + yc2);
		for (j = 0; j < 5; j++)
		{
			textcolor(4);
			putch(shipc2[i][j]);
		}
		cout << "\n";
	}
}
void print_shipc3()
{
	int i, j;

	for (i = 0; i < 4; i++)
	{
		gotoxy(xc3 + 2, i + yc3);
		for (j = 0; j < 5; j++)
		{
			textcolor(4);
			putch(shipc3[i][j]);
		}
		cout << "\n";
	}
}
void print_shipc4()
{
	int i, j;

	for (i = 0; i < 4; i++)//print
	{
		gotoxy(xc4 + 2, i + yc4);
		for (j = 0; j < 5; j++)
		{
			textcolor(4);
			putch(shipc4[i][j]);
		}
		cout << "\n";
	}
}
void print_shipc5()
{
	int i, j;

	for (i = 0; i < 4; i++)//print
	{
		gotoxy(xc5 + 2, i + yc5);
		for (j = 0; j < 5; j++)
		{
			textcolor(4);
			putch(shipc5[i][j]);
		}
		cout << "\n";
	}
}
void print_boom(int xc, int yc)
{
	int i, j;

	for (i = 0; i < 4; i++)//print
	{
		gotoxy(xc + 2, i + yc);
		for (j = 0; j < 5; j++)
		{
			textcolor(9);
			putch(boom1[i][j]);
		}
		cout << "\n";
	}
	delay(900);
	for (i = 0; i < 4; i++)//delete
	{
		gotoxy(xc + 2, i + yc);
		for (j = 0; j < 5; j++)
		{
			putch(0);
		}
		cout << "\n";
	}
}



void delete_user_ship()
{
	int i, j;

	for (i = 0; i < 3; i++)//delete the ship
	{
		gotoxy(xuser, i + yuser);
		for (j = 0; j < 5; j++)
		{
			cout << " ";
		}
		cout << "\n";
	}
}
void print_user_ship()
{
	int i, j;
	if (xuser == 78)
	{
		xuser = 1;
	}
	for (i = 0; i < 3; i++)//print
	{
		gotoxy(xuser, i + yuser);
		for (j = 0; j < 5; j++)
		{
			textcolor(10);
			putch(user[i][j]);
		}
		cout << "\n";
	}
}

void boom()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		delete_user_ship();
		delay(500);
		print_user_ship();
		delay(500);

	}
	delete_user_ship();
	if (life_ > 0)
	{
		gotoxy(4, 1);
		cprintf("life %c %d", 6, life_--);
		if (life_ == 0)
		{

		}
		/* while(    (((xuser + 3 >= xc1 && xuser + 3 <= xc1 + 3) || (xuser >= xc1&&xuser <= xc1 + 6)) && ((yuser >= yc1 && yuser <= yc1 + 3) || (yc1 >= yuser && yc1 <= yuser + 2)))
				|| (((xuser + 3 >= xc2 && xuser + 3 <= xc2 + 3) || (xuser >= xc2&&xuser <= xc2 + 6)) && ((yuser >= yc2 && yuser <= yc2 + 3) || (yc2 >= yuser && yc2 <= yuser + 2)))
				|| (((xuser + 3 >= xc3 && xuser + 3 <= xc3 + 3) || (xuser >= xc3&&xuser <= xc3 + 6)) && ((yuser >= yc3 && yuser <= yc3 + 3) || (yc3 >= yuser && yc3 <= yuser + 2)))
				|| (((xuser + 3 >= xc4 && xuser + 3 <= xc4 + 3) || (xuser >= xc4&&xuser <= xc4 + 6)) && ((yuser >= yc4 && yuser <= yc4 + 3) || (yc4 >= yuser && yc4 <= yuser + 2)))
				|| (((xuser + 3 >= xc5 && xuser + 3 <= xc5 + 3) || (xuser >= xc5&&xuser <= xc5 + 6)) && ((yuser >= yc5 && yuser <= yc5 + 3) || (yc5 >= yuser && yc5 <= yuser + 2)))
			){*/


		yuser = (rand() % 20) + 2;
		xuser = (rand() % 78) + 1;

		//} 
		/*if (xuser <= 6)
		{
			xuser = 74;
		}
		else
		{
		xuser -=7;

		}*/
		print_user_ship();

	}
	else
	{
		gotoxy(7, 1);
		cprintf("GAME OVER");
		c = getch();
	}

}


void beginning() {

	int i, j;
	for (i = 0; i < 10; i++)//����� ����
	{
		gotoxy(33, 7 + i);
		for (j = 0; j < 12; j++)
		{
			textcolor(14);
			cprintf("%c", seven[i][j]);
		}
		cout << "\n";

	}//the seven

	for (i = 0; i < 25; i++)
	{
		print_big_ship_c();
		print_big_ship_u();
		delay(120);
		delete_big_ship_c();
		delete_big_ship_u();
		x_big_c++;
		x_big_u--;
	}
	print_big_ship_c();
	print_big_ship_u();
	for (i = 0; i < 10; i++)//����� ����
	{
		gotoxy(33, 7 + i);
		for (j = 0; j < 12; j++)
		{
			if (seven[i][j] == 1)
			{
				seven[i][j] = 2;
				textcolor(14);
				gotoxy(33 + j, 7 + i);
				cprintf("%c", seven[i][j]);
			}

			delay(10);
		}
		cout << "\n";
	}//the seven
	int y;
	for (y = 0; y < 3; y++)//��� �����
	{
		for (i = 0; i < 10; i++)//����� ����
		{
			gotoxy(33, 7 + i);
			for (j = 0; j < 12; j++)
			{
				if (seven[i][j] == 2)
				{
					gotoxy(33 + j, 7 + i);
					cprintf("%c", 0);
				}
			}
			cout << "\n";
		}//the seven
		//c = getch();
		delay(400);
		for (i = 0; i < 10; i++)//����� ����
		{
			gotoxy(33, 7 + i);
			for (j = 0; j < 12; j++)
			{
				if (seven[i][j] == 2)
				{
					textcolor(14);
					gotoxy(33 + j, 7 + i);
					cprintf("%c", 2);
				}
			}
			cout << "\n";
		}
		delay(500);
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 68; j++)
		{
			if (bord[i][j] == 1)
			{
				bord[i][j] = 4;
				gotoxy(4 + j, 1 + i);
				cprintf("%c", bord[i][j]);
			}
		}
		delay(100);
	}	
	gotoxy(40, 23);
	cout << "LET'S START!";
	delay(7000);
	clrscr();
	next_step();
}
void print_big_ship_c()
{
	int i, j;
	for (i = 0; i < 5; i++)//����� �����
	{
		gotoxy(x_big_c, y_big_c + i);
		for (j = 0; j < 9; j++)
		{
			textcolor(3);

			cprintf("%c", sc_b[i][j]);
		}
		cout << "\n";
	}
}
void delete_big_ship_c()
{
	int i, j;
	for (i = 0; i < 5; i++)//����� �����
	{
		gotoxy(x_big_c, y_big_c + i);
		for (j = 0; j < 9; j++)
		{
			textcolor(3);
			cprintf("%c", 0);
		}
		cout << "\n";
	}
}
void print_big_ship_u()
{
	int i, j;
	for (i = 0; i < 5; i++)//����� �����
	{
		gotoxy(x_big_u, y_big_u + i);
		for (j = 0; j < 9; j++)
		{
			textcolor(4);

			cprintf("%c", su_b[i][j]);
		}
		cout << "\n";
	}
}
void delete_big_ship_u()
{
	int i, j;
	for (i = 0; i < 5; i++)//����� �����
	{
		gotoxy(x_big_u, y_big_u + i);
		for (j = 0; j < 9; j++)
		{
			textcolor(4);

			cprintf("%c", 0);
		}
		cout << "\n";
	}
}
void smiles_full(int p) {
	smiles[p] = 2;
	gotoxy(34 + p, 1);
	textcolor(10);
	cprintf("%c", smiles[p]);
	if (ps == 13)
	{
		int e, r;
		while ((!(kbhit())))
		{   e= (rand() % 20) + 2;
		r = (rand() % 69) + 1;
		gotoxy(e, r);
		int t= (rand() % 15) + 1;
		textcolor(t);
		cout << "DONE!!!";
		delay(1000);

		}
		level++;
		next_step();
	}
}
void chek_shipc_boom(int *xc, int *yc, int d, int *xyeryot, int *flag)
{
	if (*xc + 4 == xuser - x - 10 && yuser + 1 >= *yc&&yuser + 1 <= *yc + 4 && _delay > d)
	{
		print_boom(*xc, *yc);

		f_yeryot_user = 0;
		gotoxy(*xc + 5 + *xyeryot - 2, *yc + 1);
		cprintf("          ");
		gotoxy(xuser - x - 10, yuser + 1);
		cprintf("         ");
		*xc = -40; *flag = 0;

	}
}
void next_step()
{
	int i, j;
	textbackground(3);
	clrscr();
	for (i = 0; i < 22; i++)
	{
		for (j = 0; j < 20; j++)
		{
			gotoxy(1 + j, i + 3);
			if (island[i][j] == 2)
			{
				island[i][j] = 42;
				textcolor(15);
			}
			else
			{
				if (island[i][j] == 1)
				{
					island[i][j] = 219;
					textcolor(6);
				}

			}

			cprintf("%c", island[i][j]);


			//
			//{island[i][j] = 219;
			//	textcolor(14);
			//	cprintf("%c", island[i][j]);
			//}

			//	textcolor(3);
			//	cprintf("%c", island[i][j]);
		}
	}
	
	//int y = 15;

	print_s_begining(5, 60);
	print_s_begining(9, 43);
	print_s_begining(13, 25);


	if (level != 0)
	{
		if(level==1)
			for (i = 0; i < 6; i++)
			{
				print_user_ship();
				xuser--;
			}
	}
	else
	{
	print_user_ship();
	}
	//for (int k = 0; k < 3; k++)
	gotoxy(45, 2);
	cout << "ENTER";

	print_rows();

	c = getch();
	clrscr();
}


//for (i = 0; i < 3; i++)
//{
//	gotoxy(50 + i, i + 11);
//
//	for (j = 0; j < 5; j++)
//	{
//		textcolor(9);
//		cprintf("%c", row[i][j]);
//
//	}
//
//}

void print_rows() {
	int i,j;
	while ((!(kbhit())))
	{
		print_row1();
		 delay(1000);
		print_row2();

		delay(1000);
		print_row3();

		delay(1000);
	}

}
void print_row1() {
	int i, j;
	for (i = 0; i < 3; i++)
	{

		for (j = 0; j < 5; j++)
		{
			gotoxy(29 + j, i + 11);

			cprintf("%c", ' ');

		}

	}

	for (i = 0; i < 3; i++)
	{
		gotoxy(64 + j, i + 11);

		for (j = 0; j < 5; j++)
		{
			textcolor(9);
			cprintf("%c", row[i][j]);

		}

	}
} 
void print_row2() {
	int i, j;
	for (i = 0; i < 3; i++)
	{
		gotoxy(64 + j, i + 11);

		for (j = 0; j < 5; j++)
		{
			cprintf("%c", ' ');

		}

	}		

	for (i = 0; i < 3; i++)
	{
		gotoxy(46 + j, i + 11);

		for (j = 0; j < 5; j++)
		{
			textcolor(9);
			cprintf("%c", row[i][j]);

		}

	}


}
void print_row3() {
	int i, j;
	for (i = 0; i < 3; i++)
	{
		gotoxy(46 + j, i + 11);

		for (j = 0; j < 5; j++)
		{
			cprintf("%c",' ');

		}

	}		
	for (i = 0; i < 3; i++)
	{
		gotoxy(29 + j, i + 11);

		for (j = 0; j < 5; j++)
		{
			textcolor(9);
			cprintf("%c", row[i][j]);

		}

	}
	for (i = 0; i < 3; i++)
	{
		gotoxy(29 + j, i + 11);

		for (j = 0; j < 5; j++)
		{
			textcolor(9);
			cprintf("%c", 0);

		}

	}

}
void print_s_begining(int color, int j_) {
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			textcolor(color);
			gotoxy(j_ + j, i + 11);
			cprintf("%c", s[i][j]);
		}

	}
}