#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int width=70,height=30,flag=0;
int x,y,fruitx,fruity,score,gameover;
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
               printf(" ");
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
{
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
           if(x<0||x>height||y>width||y<0)
               gameover=1;
           if(x==fruitx&&y==fruity)
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
      for(int m=0;m<10000;m++)
      for(int n=0;n<10000;n++)
      {
      }
      }


    return 0;
}
