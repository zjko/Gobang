
//According to different system modifications
#define __LINUX__       linux
//#define __WINDOWS__   windows

#ifdef __LINUX__
#define CLEARSCREEN 	system("clear")
#define PAUSE			system("pause")
#endif
#ifdef __WINDOWS__
#define CLEARSCREEN     system("cls")
#define PAUSE           system("pause")
#endif

//Game Setting
#define CB_Color_Space 	"\033[47;31;5m  \033[43;37;0m"
#define CB_Color_First 	"\033[44;37;5m  \033[43;37;0m"
#define CB_Color_Second "\033[43;37;5m  \033[43;37;0m"
#define CB_Color_Select "\033[42;37;5m[]\033[43;37;0m"
o apt-get install vim-youcompleteme
vim-addons install youcompleteme
//Operation Key Setting
#define Keying          InputOptional()
#define Operation_Down 	'2'
#define Operation_Up	'8'
#define Operation_Left 	'4'
#define Operation_Right '6'
#define Operation_Enter '5'
#define Operation_Undo 	'0'
#define Operation_Quit 	'q'


/*
//Service
#define ServiceIP
#define ServicePort
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<curses.h>
//#include<conio.h>
struct Gobang {

	char CB[15][15];		//Checkerboard
	bool CP = true;			//true is first;
	char *MSG="Welcome to play this game!";
	struct Position{
		unsigned int x:4;
		unsigned int y:4;
		int init(){
			x=0;y=0;
		};
	} position;
	
	struct History{
		struct Position p[225];
		unsigned int top;
		int init(){
			top=0;
		};
		int push(int x,int y){
			if(top<225){
				p[top].x=x;
				p[top].y=y;
				top++;
			}else {
				return -1;
			}
		};
		int pop(){
			if(top>0){
				return top--;	
			}else {
				return -1;
			}
		};
		int clearn(){
			top=0;
		};
	}history;
   
    char InputOptional(){
        //Windows
#ifdef __WINDOWS__
       return getch();
#endif
        //Linux
#ifdef  __LINUX__
       char a,b;
        a=getchar();
        b=getchar();
        if(a=='\n')return b;
        else return a;
#endif
    }
    
	int MenuView() {
		while(1) {
			puts("a. AI");
			puts("b. Online");
			puts("c. Player by Yourself");
			printf("x. %s (Select to Change)\n",!CP?CB_Color_First:CB_Color_Second);
			puts("y. FAQ");
			puts("z. About");
			puts("Q. Quit");
			switch(Keying) {		//select
				case 'a':GameView();AI();							break;
				case 'b':GameView();Online();					break;
				case 'c':GameView();PlayByYourself();CLEARSCREEN;	break;
				case 'x':CP = !CP;CLEARSCREEN;				break;
				case 'y':FAQ();												break;
				case 'z':About();											break;
				case 'Q':return puts("Game will quit,Bye!");
				default:
					CLEARSCREEN;	puts("Bad Input,Please try again");
			}
		}

	};	
	void About(){
		CLEARSCREEN;
		printf("*****About*****\n");
		printf("---------------\n");
		printf("Developer:ZJKo\n");
		printf("Github:ZJKo\n");
		printf("Blog:zjko.vip\n");
		printf("Email:zjko@outlook.com\n");
		PAUSE;
        getchar();
		CLEARSCREEN;
	};
	void FAQ(){
		CLEARSCREEN;
		printf("***Welcome to play this game!***\n");
		printf("--------------------------------\n");
		printf("Input Define\n");
		printf("Up:%c\n",Operation_Up);
		printf("Down:%c\n",Operation_Down);
		printf("Left:%c\n",Operation_Left);
		printf("Right:%c\n",Operation_Right);
		printf("Enter:%c\n",Operation_Enter);
		printf("Undo:%c\n",Operation_Undo);
		printf("Quit:%c\n",Operation_Quit);	
		PAUSE;
		CLEARSCREEN;
	}
   
	int GameView() {
		CLEARSCREEN;
		for(int i=0; i<15;i++,putchar('\n'))
			for(int j=0; j<15; j++) {
				
				if((i == position.x )&& (j== position.y)) {
					printf(CB_Color_Select);
					continue;
				}
				
				switch(CB[i][j]) {
					case 0:printf(CB_Color_Space);break;
					case 1:printf(CB_Color_First);break;
					case 2:printf(CB_Color_Second);break;
					default :
						CLEARSCREEN;
						puts("DATA ERROR! Plear Check CB DATA");
						break;
				}
			}
		printf("MSG:%s\n",MSG);
		
	};

	int GameControl(int x,int y) { // -1 bad input
		if(x<0||x>14||y<0||y>14||CB[x][y]!=0) {
			MSG = "Bad Input";
			return 0;
		}
		CB[x][y] =  CP+1;
		history.push(x,y);
		CP = !CP;	//Chess Player Change
		//MSG = "Next:";
		//strcat(MSG,!CP?CB_Color_First:CB_Color_Second);
		MSG = const_cast<char*>(!CP?CB_Color_First:CB_Color_Second);
		GameView();	//Refresh GameView
		return 0;
	};

	int Operation() {
		//return 0 is normal  other  is  option
		
		while(1){
//			printf("x %d y %d\n",position.x,position.y);
			switch(Keying) {
				case Operation_Up		:if(position.x-1>=0)position.x--;break;
				case Operation_Down	:if(position.x+1<15)position.x++;break;
				case Operation_Left	:if(position.y-1>=0)position.y--;break;
				case Operation_Right:if(position.y+1<15)position.y++;break;
				case Operation_Enter:
					GameControl(position.x,position.y);
					return 0;
				case Operation_Undo	:
					Undo();
					Undo();
					MSG="Undo";
					break;
				case Operation_Quit: 
					puts("Do you want Quit?,Enter Q to confirm");
					if(Keying == 'Q')return 1;
				default: MSG="Undefine Input";
			}
			GameView();
		}
	}
	
	int Undo(){
		if(history.top >0){
				CB[history.p[history.top-1].x][history.p[history.top-1].y]=0;
				history.pop();
		}
	};
	int PlayByYourself(){
		while(!Operation());
	}
	int AI() {


	};
	int Online(){
		




			return 0; 
		}
	int init(){
		for(int i=0;i<15;i++)
			for(int j=0;j<15;j++)
				CB[i][j]=0;
		position.init();
		history.init();
		MenuView();
	};
		
};

int main(){
	struct Gobang game;
	game.init();
	
}


