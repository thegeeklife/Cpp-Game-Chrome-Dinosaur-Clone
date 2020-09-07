#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int i=10,j=14,ob[4] ,score=0;

void gotoxy (int x,int y) 
{
	static HANDLE h = NULL ;
	if (!h)
	  h=GetStdHandle (STD_OUTPUT_HANDLE) ;
	COORD c ={x,y} ;
	SetConsoleCursorPosition(h,c) ;   
}

void dino(int x,int y) 
{
	gotoxy(x,y-1) ;
	printf("O") ;
	gotoxy(x,y) ;
	printf("O") ;
}

void dclr (int x,int y) 
{
	gotoxy(x,y-1) ;
	printf(" ") ;
	gotoxy(x,y) ;
	printf(" ") ;
}


void area() 
{
	int u;
	gotoxy(0,14) ;
	for (u=0;u<80;u++)
    printf("_") ;
	
}

void obst (int i,int j) 
{
	gotoxy(i,j) ;
	printf("%c",219) ;
	gotoxy(0,15) ;
    printf(" ") ;
}

void omove() 
{
	int l ;
	for(l=0;l<4;l++) 
	{  
	   gotoxy(ob[l],14) ;
	   printf("_") ;
	  
	   ob[l]-- ; 
	   obst(ob[l],14) ;
 	}  
}



void randplace (int k) 
{
	ob[k]=rand()%15 + 20 +k*15 ;
	obst(ob[k],14) ;
}

void r_p (int k) 
{
	ob[k]=rand()%5 + 60 +k*5 ;
	obst(ob[k],14) ;
}

int die () {
	int l,flag=0 ;
	for (l=0;l<4;l++)
	{  if (ob[l]==10)
	   {  if (j==14)
	       {  flag=1 ;
	          break ; 
		   }
	   }
	}
	return flag ;
}

char drt () 
{
	char ch ,l;
	int p;
	while(!kbhit())
	{  dino(i,j) ;
	 
 	     
	   omove () ;
	  for(l=0;l<4;l++)
	   {  if(ob[l]-1==0)
	      { gotoxy(ob[l],14) ;
		    printf("_") ;
		    r_p(l) ;
	      }
	   }     
	   if (die()==1)
	   {  ch='o' ;
	       return ch ;
	   }
	   Sleep(65) ;
	   
	   score++ ;
	   
	   gotoxy(65,9) ;
	   printf("SCORE : %d",score) ;
	   
	  
	}
	ch=getch() ;
	return ch ; 
}


char dup () 
{
	char ch ='d';
	int l;
	int flag=0 ,p=1,u=i,v=j;
	while (j!=14||flag!=1)
	{  gotoxy(10,14) ;
	   printf("_") ;
	   dino(i,j) ;  
	   omove () ;
	   for(l=0;l<4;l++)
	   {  if(ob[l]-1==0)
	      { gotoxy(ob[l],14) ;
		    printf("_") ;
		    r_p(l) ;
	      }
	   }   
       if (die()==1)
	   {  ch='o' ;
	       break ;
	   }
	   Sleep(45) ;
	   
	   if (flag==1)
	      j++ ;
	      
	   else if (j==10)  
		  flag=1 ;

	   else   
		  j-- ;
	   
	   dclr(u,v) ;
	   v=j ;
        
       score++ ;
      
	   
	   gotoxy(65,9) ;
	   printf("SCORE : %d",score) ;
	   
    }
    return ch ;
}

void gameplay() 
{
	char move ,ch;
	int l ;
	area() ;
	for(l=0;l<4;l++)
	 randplace(l) ;
	
	move=drt() ;
	while(move!='o')
	{  if (move==' ')
	   move =  dup() ; 
	   else 
	   move=drt () ;  
	}

system("cls");
printf("\n\n\n\n\n\n 				SCORE :%d",score);


}


int main() 
{
	printf("Welcome to the game!\nO\nO --> Player\n%c --> Obstacle\n",219);
	srand(time(NULL)) ;
 	gameplay() ;
 	
 	getch();
	return 0;
}

