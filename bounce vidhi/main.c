#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <conio.h>
#include <time.h>
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
COORD coord={0,0};
 void gotoxy(int x,int y)
{
       coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void block1(int left,int left1,int top,int top1,char ch,char ch1,int val);
int score=0;
void page2();
void makebrick(int left,int left1);
void logic();
int delete_brick(int left,int top);
int delete_brick1(int left,int top);
int delete_brick2(int left,int top);
int delete_brick3(int left,int top);
void print();
//int delete_brick11(int left);
void block2(int left,int left1,int top,int top1);
int arr[10]={0},arr2[10]={0},arr3[10]={0};
void page1();
void page3();
void finalpage();
void level2();
void logic1();
int main()
{
    //system("color 7c");
    page1();
    page2();
    system("color 0c");
    page3();
    gotoxy(0,30);
    logic();
    gotoxy(0,30);
    return 0;
}
void block1(int left,int left1,int top,int top1,char ch,char ch1,int val)
{
    int temp;
    temp=left;
    while(temp<left1)
    {
        gotoxy(temp,top);
        printf("%c",ch);
        delay(val);
        temp++;
    }
    temp=top;
    while(temp<top1)
    {
        gotoxy(left1,temp);
        printf("%c",ch1);
        delay(val);
        temp++;
    }
    temp=left1;
    while(temp>left)
    {
        gotoxy(temp,top1);
        printf("%c",ch);
        delay(val);
        temp--;
    }
    temp=top1;
    while(temp>top)
    {
        gotoxy(left,temp);
        printf("%c",ch1);
        delay(val);
        temp--;
    }
}
void page3()
{
    hidecursor();
    system("cls");
    SetColor(14);
    block1(10,111,2,27,'$','$',5);
    gotoxy(55,1);
    SetColor(14);
    printf("PLAY AREANA");
    makebrick(10,111);
}
void makebrick(int left,int left1)
{
    int offset;
    SetColor(11);
    for(offset=11;offset<=110;offset=offset+10)
    {
        block1(offset,offset+9,3,5,'.','.',0);
    }
    SetColor(13);
    for(offset=11;offset<=110;offset=offset+10)
    {
        block1(offset,offset+9,6,8,'.','.',0);
    }
    SetColor(12);
    for(offset=11;offset<=110;offset=offset+10)
    {
        block1(offset,offset+9,9,11,'.','.',0);
    }
}
void logic()
{
    int left=55,top=25,left1=60,top1=24,offset,count=0,res=0,res1,val=0;
    SetColor(15);
    char ch;
    gotoxy(55,25);
    printf("----------");
     gotoxy(left+5,top-1);
    printf("0");
     a1:switch(ch)
    {
    case 'a' :
        {
           if(left>12)
           {
              gotoxy(left,top);
              printf("          ");
              gotoxy(left+5,top-1);
              printf(" ");
              left=left-4;
              gotoxy(left,top);
              printf("----------");
              if(count==0){gotoxy(left+5,top-1);
                  printf("0");left1=left+5;top1=top-1; goto r1;}
              if(count==1) goto a2;
              if(count==2) goto a3;
              if(count==3) goto a4;
              if(count==4) goto a5;
              if(count==5) goto a6;
              if(count==6) goto a7;
           }
           break;
        }
    case 'd':
        {
            if(left<99)
            {
              gotoxy(left,top);
              printf("          ");
              gotoxy(left+5,top-1);
              printf(" ");
              left=left+4;
              gotoxy(left,top);
              printf("----------");
              if(count==0){gotoxy(left+5,top-1);
              printf("0");left1=left+5;top1=top-1; goto r1;}
              if(count==1) goto a2;
              if(count==2) goto a3;
              if(count==3) goto a4;
              if(count==4) goto a5;
              if(count==5) goto a6;
              if(count==6) goto a7;
            }
            break;
        }
    }

    while(1)
    {
        r1:if(_kbhit())
        {
            ch=_getch();
            if((ch=='a')||(ch=='d')||(ch=='A')||(ch=='D'))
            {
                goto a1;
            }
            else if((ch=='p')||(ch=='P'))
            {
              ch=_getch();
              if((ch=='p')||(ch=='P'))
              {
                  while(ch=fgetc(stdin))
                  {
                        if(count==1) goto a2;
                      if(count==2) goto a3;
                     if(count==3) goto a4;
                    if(count==4) goto a5;
                    if(count==5) goto a6;
                    if(count==6) goto a7;
                  }
              }
            }
            else
            {
                if(val==0)
                {
                    val=1;
                   if(left>55)goto a5;
                   else goto a2;
                }
                else
                {
                     if(count==1) goto a2;
                      if(count==2) goto a3;
                     if(count==3) goto a4;
                    if(count==4) goto a5;
                    if(count==5) goto a6;
                    if(count==6) goto a7;
                }
            }
        }
    }
   a2:
            while(left1>=13 && top1>2)
           {
               count=1;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a7;}
               if(res==5) {res=0; goto a3;}
               if(res==10) {res=0; finalpage(); return;}
               left1=left1-1;
               top1--;
               if(top1>3 && left1<=11) goto a3;
               if(top1==3) goto a7;
           }
              a3: while(left1>=10 && top1>2)
              {
                  count=2;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a4;}
               if(res==5) {res=0; goto a6;}
               if(res==10) {res=0;finalpage(); return;}
               if(top1==3) goto a4;
               left1=left1+1;
               top1--;
             }
             a4:while(top1<=24 && left1<110)
              {
                  count=3;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               res1=check_tray(left1,left,top1);
               if(res1==1) goto a5;
               if(res1==0) goto end;
               if(left1==109) goto a7;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a7;}
               if(res==5) { res=0;goto a3;}
               if(res==10) {res=0; finalpage(); return;}
               left1=left1+1;
               top1++;
              }
        a5:     while(left1<110 && top1>3)
           {
               count=4;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a4;}
               if(res==5) { res=0;goto a6;}
               if(res==10) {res=0; finalpage(); return;}
               left1=left1+1;
               top1--;
               if(left1>=108 && top1>3) goto a6;
               if(top1==3) goto a4;
       }
        a6:while(top1>3)
       {
           count=5;
           gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a7;}
               if(res==5) { res=0;goto a3;}
               if(res==10) {res=0; finalpage(); return;}
                  left1=left1-1;
               top1--;
                  if(top1==3) goto a7;
       }
       a7:while(top1<25 && left1>=11)
       {
           count=6;
           gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               //delete_brick(left1,top1);
               res1=check_tray(left1,left,top1);
               if(res1==1) goto a2;
               if(res1==0) goto end;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a7;}
               if(res==5) { res=0;goto a6;}
               if(res==10) {res=0; finalpage(); return;}
               //else if(res==0) goto up3;
               left1=left1-1;
               top1++;
               if(left1==11) goto a4;
       }
       end: //gotoxy(55,10);
           SetColor(1);
       block1(41,80,5,15,'-','-',0);
       gotoxy(42,6);
       printf("                                      ");
       gotoxy(42,7);
       printf("                                      ");
       gotoxy(42,8);
       printf("                                      ");
       gotoxy(42,9);
       printf("                                      ");
       gotoxy(42,10);
       printf("                                      ");
       gotoxy(42,11);
       printf("                                      ");
       gotoxy(42,12);
       printf("                                      ");
       SetColor(12);
       gotoxy(51,9);
       printf("GAME IS OVER");
       gotoxy(51,10);
       printf("SCORE:%d",score);
}
int delete_brick(int left,int top)
{
    int val;
    if((top==12)||(top==9)||(top==6)||(top==10))//||(top==11)||(top==10))
    {
      if((top==12)||(top==10))
      {
          val=delete_brick1(left,top);
          if(score==150){return 10;}
          if(val==1) return 1;
          else return 2;
      }
      if((top==9)||(top==7))
      {
           val=delete_brick2(left,top);
           if(score==150) {return 10;}
          if(val==1) return 1;
          else return 2;
      }
      if((top==6)||(top==4))
      {
          val=delete_brick3(left,top);
          if(score==150) {return 10;}
            if(val==1) return 1;
          else return 2;
      }
    }
    else
    {
       return;
    }
}
int check_tray(int left1,int left,int top1)
{
    int offset;
    if(top1==24)
    {
      for(offset=0;offset<=10;offset++)
      {
        if(left1==(left+offset))
        {
            return 1;
        }
      }
      return 0;
    }
    else return;
}
void SetColor(int ForgC)
{
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void page1()
{
    char ch;
    hidecursor();
    system("color 1c");
    SetColor(12);
    block2(10,111,2,27);
   gotoxy(23,10);
   SetColor(14);
     printf("W    W    W   EEEEEE   L        CCCCCC   OOOOOO   MM         MM   EEEEEE\n");
    gotoxy(23,11);
    printf("W   W W   W   E        L        C        O    O   M  M      M M   E     \n");
    gotoxy(23,12);
    printf("W  W   W  W   EEEEEE   L        C        O    O   M   M    M  M   EEEEEE\n");
    gotoxy(23,13);
    printf("W W     W W   E        L        C        O    O   M    M  M   M   E     \n");
    gotoxy(23,14);
    printf("WW       WW   EEEEEE   LLLLLL   CCCCCC   OOOOOO   M     M     M   EEEEEE\n");
   gotoxy(43,24);
   SetColor(13);
   printf("ENTER ENTER KEY TO CONTINUE................");

}
void page2()
{
    system("cls");
    system("COLOR 0c");
    char ch;
    block2(12,111,2,27);
    print();
   ch=fgetc(stdin);
}
void block2(int left,int left1,int top,int top1)
{
    int temp,offset;
    temp=left;
     for(offset=left;offset<left1;offset=offset+2)
     {
         gotoxy(offset,top);
         printf("_");
         gotoxy(offset-1,top+1);
         printf("|_|");
         delay(5);
     }
     for(offset=top+1;offset<top1;offset++)
     {
        // offset=top+1;
         gotoxy(left1-1,offset);
         printf("_");
         gotoxy(left1-2,offset+1);
         printf("|_|");
         delay(5);
     }
     for(offset=left1-1;offset>left;offset=offset-2)
     {
         gotoxy(offset,top1);
         printf("_");
         gotoxy(offset-1,top1+1);
         printf("|_|");
         delay(5);
     }
     for(offset=top1;offset>top;offset--)
     {
        // offset=top1;
          gotoxy(left,offset);
         printf("_");
         gotoxy(left-1,offset+1);
         printf("|_|");
         delay(5);
     }
}
int delete_brick1(int left,int top)
{
    int offset;
      if(arr[0]==0)
        {
          for(offset=11;offset<=20;offset++)
          {
            if(left==offset)
            {
                arr[0]=1;
                block1(11,20,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if((top==10)&&(left==21))
           {
               arr[0]=1;
                block1(11,20,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[1]==0)
        {
           for(offset=21;offset<=30;offset++)
           {
            if(left==offset)
            {
                arr[1]=1;
                block1(21,30,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
           if(((top==10)&&(left==20))||((top==10)&&(left==31)))
           {
               arr[1]=1;
                block1(21,30,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[2]==0)
        {
           for(offset=31;offset<=40;offset++)
          {
            if(left==offset)
            {
                arr[2]=1;
                block1(31,40,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
          if(((top==10)&&(left==30))||((top==10)&&(left==41)))
           {
               arr[2]=1;
                block1(31,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[3]==0)
        {
           for(offset=41;offset<=50;offset++)
           {
            if(left==offset)
            {
                arr[3]=1;
                block1(41,50,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
           if(((top==10)&&(left==40))||((top==10)&&(left==51)))
           {
               arr[3]=1;
                block1(41,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[4]==0)
        {
            for(offset=51;offset<=60;offset++)
           {
            if(left==offset)
            {
                arr[4]=1;
                block1(51,60,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
          if(((top==10)&&(left==40))||((top==10)&&(left==51)))
           {
               arr[3]=1;
                block1(41,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[5]==0)
        {
             for(offset=61;offset<=70;offset++)
            {
            if(left==offset)
            {
                arr[5]=1;
                block1(61,70,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
           if(((top==10)&&(left==60))||((top==10)&&(left==71)))
           {
               arr[5]=1;
                block1(61,70,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[6]==0)
        {
           for(offset=71;offset<=80;offset++)
           {
            if(left==offset)
            {
                arr[6]=1;
                block1(71,80,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
           if(((top==10)&&(left==70))||((top==10)&&(left==81)))
           {
               arr[6]=1;
                block1(71,80,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[7]==0)
        {
             for(offset=81;offset<=90;offset++)
           {
            if(left==offset)
            {
                arr[7]=1;
                block1(81,90,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
          if(((top==10)&&(left==80))||((top==10)&&(left==91)))
           {
               arr[7]=1;
                block1(81,90,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[8]==0)
        {
          for(offset=91;offset<=100;offset++)
          {
            if(left==offset)
            {
                arr[8]=1;
                block1(91,100,9,11,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
          if(((top==10)&&(left==90))||((top==10)&&(left==101)))
           {
               arr[8]=1;
                block1(91,100,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr[9]==0)
        {
              for(offset=101;offset<=110;offset++)
             {
               if(left==offset)
               {
                arr[9]=1;
                block1(101,110,9,11,' ',' ',0);
                score=score+5;
                return 1;
               }
             }
             if(((top==10)&&(left==100))||((top==10)&&(left==111)))
           {
               arr[9]=1;
                block1(101,110,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
    return 2;
}
int delete_brick2(int left,int top)
{
    int offset;
      if(arr2[0]==0)
        {
          for(offset=11;offset<=20;offset++)
          {
            if(left==offset)
            {
                arr2[0]=1;
                block1(11,20,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if(((top==7)&&(left==20))||((top==7)&&(left==31)))
           {
               arr2[1]=1;
                block1(21,30,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[1]==0)
        {
           for(offset=21;offset<=30;offset++)
           {
            if(left==offset)
            {
                arr2[1]=1;
                block1(21,30,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
            if(((top==7)&&(left==20))||((top==7)&&(left==31)))
           {
               arr2[1]=1;
                block1(21,30,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[2]==0)
        {
           for(offset=31;offset<=40;offset++)
          {
            if(left==offset)
            {
                arr2[2]=1;
                block1(31,40,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if(((top==7)&&(left==30))||((top==7)&&(left==41)))
           {
               arr2[2]=1;
                block1(31,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[3]==0)
        {
           for(offset=41;offset<=50;offset++)
           {
            if(left==offset)
            {
                arr2[3]=1;
                block1(41,50,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
            if(((top==7)&&(left==40))||((top==7)&&(left==51)))
           {
               arr2[3]=1;
                block1(41,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[4]==0)
        {
            for(offset=51;offset<=60;offset++)
           {
            if(left==offset)
            {
                arr2[4]=1;
                block1(51,60,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if(((top==7)&&(left==40))||((top==7)&&(left==51)))
           {
               arr2[3]=1;
                block1(41,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[5]==0)
        {
             for(offset=61;offset<=70;offset++)
            {
            if(left==offset)
            {
                arr2[5]=1;
                block1(61,70,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
            if(((top==7)&&(left==60))||((top==7)&&(left==71)))
           {
               arr2[5]=1;
                block1(61,70,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[6]==0)
        {
           for(offset=71;offset<=80;offset++)
           {
            if(left==offset)
            {
                arr2[6]=1;
                block1(71,80,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
             if(((top==7)&&(left==70))||((top==7)&&(left==81)))
           {
               arr2[6]=1;
                block1(71,80,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[7]==0)
        {
             for(offset=81;offset<=90;offset++)
           {
            if(left==offset)
            {
                arr2[7]=1;
                block1(81,90,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
            if(((top==7)&&(left==80))||((top==7)&&(left==91)))
           {
               arr2[7]=1;
                block1(81,90,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[8]==0)
        {
          for(offset=91;offset<=100;offset++)
          {
            if(left==offset)
            {
                arr2[8]=1;
                block1(91,100,6,8,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
            if(((top==7)&&(left==90))||((top==7)&&(left==101)))
           {
               arr2[8]=1;
                block1(91,100,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr2[9]==0)
        {
              for(offset=101;offset<=110;offset++)
             {
               if(left==offset)
               {
                arr2[9]=1;
                block1(101,110,6,8,' ',' ',0);
                score=score+5;
                return 1;
               }
             }
                if(((top==7)&&(left==100))||((top==7)&&(left==111)))
           {
               arr2[9]=1;
                block1(101,110,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
    return 2;
}
int delete_brick3(int left,int top)
{
    int offset;
      if(arr3[0]==0)
        {
          for(offset=11;offset<=20;offset++)
          {
            if(left==offset)
            {
                arr3[0]=1;
                block1(11,20,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if(((top==4)&&(left==20))||((top==4)&&(left==31)))
           {
               arr3[1]=1;
                block1(21,30,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[1]==0)
        {
           for(offset=21;offset<=30;offset++)
           {
            if(left==offset)
            {
                arr3[1]=1;
                block1(21,30,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
            if(((top==4)&&(left==20))||((top==4)&&(left==31)))
           {
               arr3[1]=1;
                block1(21,30,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[2]==0)
        {
           for(offset=31;offset<=40;offset++)
          {
            if(left==offset)
            {
                arr3[2]=1;
                block1(31,40,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if(((top==4)&&(left==30))||((top==4)&&(left==41)))
           {
               arr3[2]=1;
                block1(31,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[3]==0)
        {
           for(offset=41;offset<=50;offset++)
           {
            if(left==offset)
            {
                arr3[3]=1;
                block1(41,50,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
            if(((top==4)&&(left==40))||((top==4)&&(left==51)))
           {
               arr3[3]=1;
                block1(41,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[4]==0)
        {
            for(offset=51;offset<=60;offset++)
           {
            if(left==offset)
            {
                arr3[4]=1;
                block1(51,60,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
           if(((top==4)&&(left==40))||((top==4)&&(left==51)))
           {
               arr3[3]=1;
                block1(41,40,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[5]==0)
        {
             for(offset=61;offset<=70;offset++)
            {
            if(left==offset)
            {
                arr3[5]=1;
                block1(61,70,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
            if(((top==4)&&(left==60))||((top==4)&&(left==71)))
           {
               arr3[5]=1;
                block1(61,70,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[6]==0)
        {
           for(offset=71;offset<=80;offset++)
           {
            if(left==offset)
            {
                arr3[6]=1;
                block1(71,80,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
           }
             if(((top==4)&&(left==70))||((top==4)&&(left==81)))
           {
               arr3[6]=1;
                block1(71,80,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[7]==0)
        {
             for(offset=81;offset<=90;offset++)
           {
            if(left==offset)
            {
                arr3[7]=1;
                block1(81,90,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
            if(((top==4)&&(left==80))||((top==4)&&(left==91)))
           {
               arr3[7]=1;
                block1(81,90,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[8]==0)
        {
          for(offset=91;offset<=100;offset++)
          {
            if(left==offset)
            {
                arr3[8]=1;
                block1(91,100,3,5,' ',' ',0);
                score=score+5;
                return 1;
            }
          }
            if(((top==4)&&(left==90))||((top==4)&&(left==101)))
           {
               arr3[8]=1;
                block1(91,100,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
        if(arr3[9]==0)
        {
              for(offset=101;offset<=110;offset++)
             {
               if(left==offset)
               {
                arr3[9]=1;
                block1(101,110,3,5,' ',' ',0);
                score=score+5;
                return 1;
               }
             }
                if(((top==4)&&(left==100))||((top==4)&&(left==111)))
           {
               arr3[9]=1;
                block1(101,110,9,11,' ',' ',0);
                score=score+5;
                return 5;
           }
        }
    return 2;
}
void print()
{
    int option;
    char ch;
    int offset;
    SetColor(12);
      gotoxy(50,5);
  printf(" ___");
  gotoxy(50,6);
  printf("|   |");
  gotoxy(50,7);
  printf("|   |");
  gotoxy(51,7);
  printf(" B");
  gotoxy(50,8);
  printf("|___|");
   gotoxy(55,5);
  printf(" ___");
  gotoxy(55,6);
  printf("|   |");
  gotoxy(55,7);
  printf("|   |");
  gotoxy(56,7);
  printf(" R");
  gotoxy(55,8);
  printf("|___|");
   gotoxy(60,5);
  printf(" ___");
  gotoxy(60,6);
  printf("|   |");
  gotoxy(60,7);
  printf("|   |");
  gotoxy(61,7);
  printf(" I");
  gotoxy(60,8);
  printf("|___|");
     gotoxy(65,5);
  printf(" ___");
  gotoxy(65,6);
  printf("|   |");
  gotoxy(65,7);
  printf("|   |");
  gotoxy(66,7);
  printf(" C");
  gotoxy(65,8);
  printf("|___|");
     gotoxy(70,5);
  printf(" ___");
  gotoxy(70,6);
  printf("|   |");
  gotoxy(70,7);
  printf("|   |");
  gotoxy(71,7);
  printf(" K");
  gotoxy(70,8);
  printf("|___|");
       gotoxy(45,10);
  printf(" ___");
  gotoxy(45,11);
  printf("|   |");
  gotoxy(45,12);
  printf("|   |");
  gotoxy(46,12);
  printf(" B");
  gotoxy(45,13);
  printf("|___|");
        gotoxy(50,10);
  printf(" ___");
  gotoxy(50,11);
  printf("|   |");
  gotoxy(50,12);
  printf("|   |");
  gotoxy(51,12);
  printf(" R");
  gotoxy(50,13);
  printf("|___|");
       gotoxy(55,10);
  printf(" ___");
  gotoxy(55,11);
  printf("|   |");
  gotoxy(55,12);
  printf("|   |");
  gotoxy(56,12);
  printf(" E");
  gotoxy(55,13);
  printf("|___|");
       gotoxy(60,10);
  printf(" ___");
  gotoxy(60,11);
  printf("|   |");
  gotoxy(60,12);
  printf("|   |");
  gotoxy(61,12);
  printf(" A");
  gotoxy(60,13);
  printf("|___|");
       gotoxy(65,10);
  printf(" ___");
  gotoxy(65,11);
  printf("|   |");
  gotoxy(65,12);
  printf("|   |");
  gotoxy(66,12);
  printf(" K");
  gotoxy(65,13);
  printf("|___|");
       gotoxy(70,10);
  printf(" ___");
  gotoxy(70,11);
  printf("|   |");
  gotoxy(70,12);
  printf("|   |");
  gotoxy(71,12);
  printf(" E");
  gotoxy(70,13);
  printf("|___|");
       gotoxy(75,10);
  printf(" ___");
  gotoxy(75,11);
  printf("|   |");
  gotoxy(75,12);
  printf("|   |");
  gotoxy(76,12);
  printf(" R");
  gotoxy(75,13);
  printf("|___|");
  gotoxy(52,16);
  printf("GENERAL INSTRUCTIONS");
  gotoxy(40,19);
  printf("Press D to move right and Press A to move left");
}
void finalpage()
{
    char ch;
    system("cls");
    SetColor(11);
    block2(10,109,2,24);
    SetColor(12);
    gotoxy(45,11);
    up:
    printf("CONGRATULATIONS....................");
    gotoxy(45,13);
    printf("YOU WON LEVEL 1");
    gotoxy(45,15);
    printf("                                                  ");
    gotoxy(45,15);
    printf("TO CONTINUE TO LEVEL 2 PRESS ENTER ELSE PRESS E");
    fflush(stdin);
    ch=fgetc(stdin);
    if(ch=='\n')
    {
      level2();
      logic1();
      //return;
    }
    else if((ch=='e')||(ch=='E'))
    {
        gotoxy(45,17);
        printf("Are u sure u want to exit?(Y/N)");
        fflush(stdin);
        ch=fgetc(stdin);
        if((ch=='Y')||(ch=='y'))
        {
            return;
        }
        else
        {
            gotoxy(45,17);
            printf("                                     ");
            goto up;
        }
    }
}
void level2()
{
    //block1(2)
     hidecursor();
    system("cls");
    SetColor(14);
    block1(10,111,2,27,'$','$',5);
    gotoxy(55,1);
    SetColor(14);
    printf("PLAY AREANA");
    makebrick(10,111);
}
void logic1()
{
       int left=55,top=25,left1=60,top1=24,offset,count=0,res=0,res1,val=0;
    SetColor(15);
    char ch;
    gotoxy(55,25);
    printf("----------");
     gotoxy(left+5,top-1);
    printf("0");
     a1:switch(ch)
    {
    case 'a' :
        {
           if(left>12)
           {
              gotoxy(left,top);
              printf("          ");
              gotoxy(left+5,top-1);
              printf(" ");
              left=left-4;
              gotoxy(left,top);
              printf("----------");
              if(count==0){gotoxy(left+5,top-1);
                  printf("0");left1=left+5;top1=top-1; goto r1;}
              if(count==1) goto a2;
              if(count==2) goto a3;
              if(count==3) goto a4;
              if(count==4) goto a5;
              if(count==5) goto a6;
              if(count==6) goto a7;
           }
           break;
        }
    case 'd':
        {
            if(left<99)
            {
              gotoxy(left,top);
              printf("          ");
              gotoxy(left+5,top-1);
              printf(" ");
              left=left+4;
              gotoxy(left,top);
              printf("----------");
              if(count==0){gotoxy(left+5,top-1);
              printf("0");left1=left+5;top1=top-1; goto r1;}
              if(count==1) goto a2;
              if(count==2) goto a3;
              if(count==3) goto a4;
              if(count==4) goto a5;
              if(count==5) goto a6;
              if(count==6) goto a7;
            }
            break;
        }
    }

    while(1)
    {
        r1:if(_kbhit())
        {
            ch=_getch();
            if((ch=='a')||(ch=='d')||(ch=='A')||(ch=='D'))
            {
                goto a1;
            }
            else if((ch=='p')||(ch=='P'))
            {
              ch=_getch();
              if((ch=='p')||(ch=='P'))
              {
                  while(ch=fgetc(stdin))
                  {
                        if(count==1) goto a2;
                      if(count==2) goto a3;
                     if(count==3) goto a4;
                    if(count==4) goto a5;
                    if(count==5) goto a6;
                    if(count==6) goto a7;
                  }
              }
            }
            else
            {
                if(val==0)
                {
                    val=1;
                   if(left>55)goto a5;
                   else goto a2;
                }
                else
                {
                     if(count==1) goto a2;
                      if(count==2) goto a3;
                     if(count==3) goto a4;
                    if(count==4) goto a5;
                    if(count==5) goto a6;
                    if(count==6) goto a7;
                }
            }
        }
    }
   a2:
            while(left1>=13 && top1>2)
           {
               count=1;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
              // res=delete_brick(left1,top1);
               //if(res==1) { res=0;goto a7;}
               //if(res==5) {res=0; goto a3;}
               //if(res==10) {res=0; finalpage(); return;}
               left1=left1-1;
               top1--;
               if(top1>3 && left1<=11) goto a3;
               if(top1==3) goto a7;
           }
              a3: while(left1>=10 && top1>2)
              {
                  count=2;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               //res=delete_brick(left1,top1);
               //if(res==1) { res=0;goto a4;}
               //if(res==5) {res=0; goto a6;}
               //if(res==10) {res=0;finalpage(); return;}
               if(top1==3) goto a4;
               left1=left1+1;
               top1--;
             }
             a4:while(top1<=24 && left1<110)
              {
                  count=3;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               res1=check_tray(left1,left,top1);
               if(res1==1) goto a5;
               if(res1==0) goto end;
               if(left1==109) goto a7;
               //res=delete_brick(left1,top1);
               //if(res==1) { res=0;goto a7;}
               //if(res==5) { res=0;goto a3;}
               //if(res==10) {res=0; finalpage(); return;}
               left1=left1+1;
               top1++;
              }
        a5:     while(left1<110 && top1>3)
           {
               count=4;
               gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               //res=delete_brick(left1,top1);
               //if(res==1) { res=0;goto a4;}
               //if(res==5) { res=0;goto a6;}
               //if(res==10) {res=0; finalpage(); return;}
               left1=left1+1;
               top1--;
               if(left1>=108 && top1>3) goto a6;
               if(top1==3) goto a4;
       }
        a6:while(top1>3)
       {
           count=5;
           gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               //res=delete_brick(left1,top1);
               //if(res==1) { res=0;goto a7;}
               //if(res==5) { res=0;goto a3;}
               //if(res==10) {res=0; finalpage(); return;}
                  left1=left1-1;
               top1--;
                  if(top1==3) goto a7;
       }
       a7:while(top1<25 && left1>=11)
       {
           count=6;
           gotoxy(left1,top1);
               printf("0");
               delay(65);
               gotoxy(left1,top1);
               printf(" ");
               if(_kbhit()) goto r1;
               //delete_brick(left1,top1);
               res1=check_tray(left1,left,top1);
               if(res1==1) goto a2;
               if(res1==0) goto end;
               res=delete_brick(left1,top1);
               if(res==1) { res=0;goto a7;}
               if(res==5) { res=0;goto a6;}
               if(res==10) {res=0; finalpage(); return;}
               //else if(res==0) goto up3;
               left1=left1-1;
               top1++;
               if(left1==11) goto a4;
       }
       end: //gotoxy(55,10);
           SetColor(1);
       block1(41,80,5,15,'-','-',0);
       gotoxy(42,6);
       printf("                                      ");
       gotoxy(42,7);
       printf("                                      ");
       gotoxy(42,8);
       printf("                                      ");
       gotoxy(42,9);
       printf("                                      ");
       gotoxy(42,10);
       printf("                                      ");
       gotoxy(42,11);
       printf("                                      ");
       gotoxy(42,12);
       printf("                                      ");
       SetColor(12);
       gotoxy(51,9);
       printf("GAME IS OVER");
       gotoxy(51,10);
       printf("SCORE:%d",score);
}
