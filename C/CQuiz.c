#include<stdio.h>  
#include<stdlib.h>  
#include<conio.h>  
  
int c_count,ic_count,score;
void check(int corr_ans,int ans);
void grade();
void start();  
void instruct();  
  
void main()  
{  
  
       int chc=0; 
       
       score=0;
       c_count=0;
       ic_count=0;
          
  
    printf("Press 1 to see the instructions of the game\n2 to start the game\n3 to exit :   ");  
    scanf("%d",&chc);  
  
    switch(chc)  
    {  
        case 1:  
        instruct();  
        break;  
 
  
        case 2:  
        start();  
        break;  
  
          default:  
          exit(1);  
    }  
  
  getch();  
}  
  
void instruct()  
{  
     int ch;  
  
     printf("\n\n ************************* GAME INSTRUCTIONS *************************");  
     printf("\n -------------------------------------------------------------------------");  
     printf("\n .................... C program Quiz Game...........\n");  
     printf("\n >> There will be a total of 10 questions");  
     printf("\n >> You will be given 4 options and you have to press 1, 2 ,3 or 4 for the");  
     printf("\n    right option");  
     printf("\n >> Each question will carry 5 points");  
     printf("\n >> You will be asked questions continuously.");  
     printf("\n >> there is -1 as negative marking");  
  
    printf("\n\n ************************* BEST OF LUCK *************************\n\n");  
  
  
    printf("\nContinue playing ? (1/0) :  ");  
    scanf("%d",&ch);  
  
    if(ch==1)  
    {  
        start();  
    }  
    else  
    {  
        exit(1);  
    }  
  
}  
  
void start()  
{  
          int corr_ans, ans;  
          
          
        printf("******************* Welcome to C Quiz Game *************************** \n\n");  
  
  
        printf("Q(1).which function is used to print something on the consol \n 1.printf() \t\t2.scanf()\n 3.getch()\t\t 4.None of the above\n\n");  
  
        printf("Your answer: ");  
        scanf("%d",&ans);  
        corr_ans=1;
        check(corr_ans,ans);
        
  
        printf("Q(2) Which of the followingis NOT a relational operator \n 1.<\t\t2.> \n3.==\n4.=<\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
        corr_ans=4;
        check(corr_ans,ans);
        
  
        printf("Q(3) what symbol is used to make comments in C lang \n1.//\t\t2.#\n3.!!\t4.&\n\n");  
  
        printf("Your answer: ");  
        scanf("%d",&ans);  
         corr_ans=1;
        check(corr_ans,ans);
  
  
        printf("Q(4). C lang is a : \n1. low level lang\t2. middle level lang\n3.high level lang\t4.multilevel lang\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
          corr_ans=2;
        check(corr_ans,ans);
  
        printf("Q(5).what function must all C programs contain \n1.start()\t2.system()\n3.main()\t4.program()\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
          corr_ans=3;
        check(corr_ans,ans);
  
        printf("Q(6)which of the following is NOT a correct variable type.  \n1.int\t2.char\n3.array\t4.float\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
          corr_ans=3;
        check(corr_ans,ans);
  
        printf("Q(7). what is the range of int data type \n1. -32,768 to 32,767\t2. 0 to 65,535\n3. -128 to 127\t4.None of the above\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
           corr_ans=1;
         check(corr_ans,ans);
  
        printf("Q(8). what is the header file for getch() functionin C \n1. math.h \t2. stdlib.h\n3. conio.h\t4. ctype.h\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
           corr_ans=3;
         check(corr_ans,ans);
  
        printf("Q(9). which of the following is a 2-D array \n1.int arr[20,20]\t2. int arr[20][20]\n3. char arr[20]\t4.none of these\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
           corr_ans=2;
          check(corr_ans,ans);
  
        printf("Q(10). what does most lines in C end with \n1. .\t2. :\n3. ;\t4. !\n\n");  
        printf("Your answer: ");  
        scanf("%d",&ans);  
           corr_ans=3;
          check(corr_ans,ans);
         
  
      
  
        printf("\n\nyou scored: %d", score);
        printf("\ncorrect answers: %d",c_count);
        printf("\nincorrect answers: %d",ic_count);
        grade();
        
}  

void check(int corr_ans, int ans)
{
    if (corr_ans==ans)
    {
        ++c_count;
        score=score+5;
        printf("%d is correct !\n",ans);
    }
    else
    {
        ++ic_count;
        score=score-1;
        printf("%d is the correct answer :(\n",corr_ans);
    }
}

void grade()
{
    if(score>45)
     printf("\n\nyour grade is A1");
     
    else if(score>40)
     printf("\n\nyour grade is A2");
     
    else if(score>35)
     printf("\n\nyour grade is B1");
     
    else if(score>30)
     printf("\n\nyour grade is B2");
     
    else if(score>25)
     printf("\n\nyour grade is C1");
     
    else if(score>20)
     printf("\n\nyour grade is C2");
     
    else if(score>15)
     printf("\n\nyour grade is D1");
     
    else if(score>10)
     printf("\n\nyour grade is D2");
     
    else if(score>5)
     printf("\n\nyour grade is E");
     
    else 
      printf("\n\n\nyou have failed the quiz");
}
