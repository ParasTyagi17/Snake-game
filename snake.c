#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int width=70,height=30,flag=0;
int x,y,fruitx,fruity,score,gameover;
int tailx[100],taily[100],counttail=0;
//this function draws the border snake and fruit
void draw()
{   system("cls");
    for(int i=0;i<height;i++)
    {for(int j=0;j<width;j++)
     {
         if(i==0||i==height-1||j==0||j==width-1)
          printf("*");//border
          else
          { if(i==x&&j==y)
             printf("@");//snake head
             else if(i==fruitx&&j==fruity)
             printf("-");//fruit
             else
             {  int ch=0;
                for(int k=0;k<counttail;k++)
                {
                  if(i==tailx[k] && j==taily[k])
                  {
                     printf("*");
                     ch=1;
                  }
                }
                 if(ch==0)
                 printf(" ");
             }
          }

    }
     printf("\n");
    }
}
//this method sets up snake and fruit position
void setup()
{   gameover=0;
    x=(int)(height/2);//because we want our snake to be in the center
    y=(int)(width/2);//because we want our snake to be in the center
    label1:
    fruitx=rand()%30;//generates random value inside boundaries for fruit to appear
    if(fruitx==0)
     goto label1;

     label2:
    fruity=rand()%70;//generates random value inside boundaries for fruit to appear
    if(fruitx==0)
     goto label2;
     score=0;
}
//this function checks if any key is pressed
void check()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 't':
            flag=1;
             break;
            case 'g':
            flag=2;
             break;
             case 'f':
            flag=3;
             break;
             case 'h':
            flag=4;
             break;
            case 'x':
              gameover=1;
             break;
            default:
                break;

        }
    }
}
//this function moves the snake and fruits
void logic()
{  int i;
   int prevx=tailx[0];
   int prevy=taily[0];
   int prev2x,prev2y;
   tailx[0]=x;
   taily[0]=y;
   for(int i=1;i<counttail;i++)
   {
    prev2x=tailx[i];
    prev2y=taily[i];
    tailx[i]=prevx;
    taily[i]=prevy;
    prevx=prev2x;
    prevy=prev2y;
   }

          switch(flag)
           {case 1:
             x--;
             break;
           case 2:
             x++;
             break;
           case 3:
             y--;
             break;
           case 4:
             y++;
             break;
             default:
            break;
           }
           if(x<0||x>height-1||y>width-1||y<0)
               gameover=1;
               for(i=0;i<counttail;i++)
               {
                 if(x==tailx[i] && y==taily[i])
                     gameover=1;
               }
           if(x==fruitx && y==fruity)
           {
               label1:
            fruitx=rand()%30;//generates random value inside boundaries for fruit to appear
            if(fruitx==0)
            goto label1;

               label2:
              fruity=rand()%70;//generates random value inside boundaries for fruit to appear
            if(fruitx==0)
           goto label2;
             score+=10;
             counttail++;
           }

}


int main()
{
    setup();
    while(!gameover)
      {
      draw();
      check();
      logic();
      for(int m=0;m<10000;m++)// these methods are to slow down the execution
      for(int n=0;n<10000;n++)
      {
      }
      }


    return 0;
}
