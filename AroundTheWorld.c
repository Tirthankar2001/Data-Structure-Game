#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define No_of_ques 15
#define Size_of_ques 100
#define Size_of_ans 50

int random[]={-1,-1,-1,-1,-1};

char question[No_of_ques][Size_of_ques]={"Where are the Whitsunday Islands located?!",
	"The Spanish Steps are a monument of which city?!",
	"How many provinces are there in Canada?!(Write in digits)",
	"In which country is Petra located?",
	"The Aruba Caribbean island is a territory of which European country?",
	"In which country are Baobab Trees found?",
	"What is the Capital of Canada",
	"Hanoi is the capital of which country?",
	"Where in Asia is the Chocolate hills located?",
	"How many Pyramids of Giza are there?(Write in digits)",
	"Where is this trigger fish humuhumunukunukuapua'a found?",
	"Where in Europe is Plitvice Lakes National Park found?",
	"Which state in India is Lake Chilika found?",
	"In which country is world's only UFO landing pad situated?",
	"Where did French Fries Originate from?"};
	char answer[No_of_ques][Size_of_ans]={"Australia","Rome","10","Jordan","Netherlands","Madagascar","Ottawa","Vietnam","Philipines","3","Hawaii","Croatia","Odisha","Canada","Belgium"};
	char ques[5][Size_of_ques];
	char ans[5][Size_of_ans];
	int top=-1;
	
	
int push(char ques[5][Size_of_ques],char ans[5][Size_of_ans], int *top, char q[Size_of_ques], char a[Size_of_ans] )
{
      if(*top == 4)
            return(-1);
      else
      {
            *top = *top + 1;
            strcpy(ques[*top], q);
            strcpy(ans[*top], a);
            return(1);
      }
}

void display(){
	int i;
	for(i=top;i>=-1;i--){
		printf("%s\n",ques[i]);
		printf("%s\n",ans[i]);
		printf("\n");
	}
}

void create_ques_set(){
	int reply;
	srand(time(0));
	int i,upper=14,lower=0,x=0,j,flag=0;
	//create random array
	while(x<5){
		flag=0;
		int num=(rand()%(upper-lower+1))+lower;
		//search in random array for presence
		for(j=0;j<5;j++){
			if(random[j]==num){
				flag=1;
				break;
			}			
		}
		if(flag==0)
		random[x++]=num;
	}
	for(i=0;i<5;i++){
		reply = push(ques,ans,&top,question[random[i]],answer[random[i]]);
		if(reply == -1)
        	printf("\n Stack is Full.\n");
	}
}	

int pop_ques(char ques[5][Size_of_ques],char ans[5][Size_of_ans], int *top, char data[Size_of_ques],char data1[Size_of_ans])
{
      if(*top == -1)
            return(-1);
      else
      {
            strcpy(data, ques[*top]);
            strcpy(data1, ans[*top]);
            *top = *top - 1;
            return(1);
      }
}

int main(){
	printf("Hello Player!! \n");
	printf("Welcome to 'Around The World !'\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("-------------------------------------------------------Rules !---------------------------------------------------------\n");
	printf("You will be presented five questions.\n Answer correctly to proceed to the next destination in the world!\n Here are your Questions!!! Have Fun !!\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	create_ques_set();
	int i,flag=0;
	char ques_in_game[Size_of_ques];
	char ans_in_game[Size_of_ans];
	char user_ans[Size_of_ans];
	for(i=0;i<5;i++){
		int reply = pop_ques(ques,ans,&top,ques_in_game,ans_in_game);
        if(reply == -1)
            printf("\n Stack is Empty \n");
        else
            printf("Ques : %s\n",ques_in_game);
        printf("Your answer :");
        scanf("%s",user_ans);
        //get stack answer
        if(strcmp(user_ans,ans_in_game)==0){
        	if(i==4)
        	printf("\nCorrect ! \n");
        	else
        	printf("\nCorrect ! Let's Move to destination for new ques !\n");
		}
		else{
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("Congratulations!! You completed the journey !");
	}
	else{
		printf("Oh no ! Your Answer was Wrong! Game Over ! ");
	}
	//display();
}
