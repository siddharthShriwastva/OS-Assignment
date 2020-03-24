/*
If a teacher is being served at the food mess and during the period when he is being served, another teacher comes,
then that teacher would get the service (food) next. This process might continue leading to increase in waiting time of students to get food.
 Ensure in your program that the waiting time of students is minimized.
*/
#include<stdio.h>

struct process{
	char name;
	int AT,BT,WT,TAT,priority;
}Q1[10],Q2[10],Q3[10];
//three queue declared Q1 for students Q2 for teachers and Q3 is final queue to arrange in FCFS.
int n,a=0,b=0;
void sortByArrival(process z[]){
	struct process temp;
	int i,j;
	if(z==Q1){
		int count=a;
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				printf("within loop Q1%d %d\n",Q1[i].AT,Q1[j].AT);
				if(Q1[i].AT > Q1[j].AT){
					temp=Q1[i];
					Q1[i]=Q1[j];
					Q1[j]=temp;
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	else if(z==Q2){
		int count=b;
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				printf("within loop Q2%d %d\n",Q2[i].AT,Q2[j].AT);
				if(Q2[i].AT > Q2[j].AT){
					temp=Q2[i];
					Q2[i]=Q2[j];
					Q2[j]=temp;
					printf("%d %d\n",i,j);
				}
			}
		}
	}
}
	

int main(){
	printf("name:-Siddharth Kumar\tSection:-K18HA\tReg.no:-11807346\n");
	int i,j,priority=0,d=0,e=0,count=0;
	char c;
	printf("enter no of processes\t");
	scanf("%d",&n);
	for(i=0,c='A';i<n;i++,c++){
		printf("enter the priority of process %c",c);
		scanf("%d",&priority);
		if(priority<3){
			if(priority==1){  								//when priority=1 it is for student and when 2 it is for teachers.
				Q1[d].name=c;
				Q1[d].priority=priority;
				printf("enter the Arrival time and Burst time for Q1 position %d\t",d);
				scanf("%d%d",&Q1[d].AT,&Q1[d].BT);
				d++;
				a++;
			}
			else if(priority==2){
				Q2[e].name=c;
				Q2[e].priority=priority;
				printf("enter the Arrival time and  Burst time for Q2 position %d\t",e);
				scanf("%d%d",&Q2[e].AT,&Q2[e].BT);
				e++;
				b++;
			}
		}
		else{
			printf("priority should be 1 for students and 2 for teachers not more than 2\n");
			break;
		
		}	
	}
	
	sortByArrival(Q1);
	sortByArrival(Q2);                                                  
	int sizeOfQ1=a;                                                    
	int sizeOfQ2=b;
	
	for(i=0;i<n;i++){
		for(j=count;j<n;j++){
			if(j<sizeOfQ2 && a!=0 ){		//it will work if there is some element in Q1 and j<size of Q2 
				if((Q1[i].AT)>=(Q2[j].AT)){	
					Q3[j]=Q2[j];
					count++;
//					break;
				}
				else{		
					Q3[i]=Q1[i];
					break;
				}
			}
			else if(a==0){		//if there is no any element in Q1
				Q3[j]=Q2[j];
				count++;
				break;
			}
			else{				//if any element of Q1 is greater than every element of Q2
				Q3[j]=Q1[i];
				count++;
				break;
			}
		}
	}

	
	for(i=0;i<a;i++){
		printf("Q1 element at position %d is %c\n ",i,Q1[i].name);
	}
	
	for(i=0;i<b;i++){
		printf("Q2 element at position %d is %c\n ",i,Q2[i].name);
	}
	
	for(i=0;i<n;i++){
	printf("Q3 element at position %d is %c\n ",i,Q3[i].name);
	}
	
	printf("no of elements in Q1 is :- %d\n",sizeOfQ1);
	printf("no of elements in Q2 is :- %d\n",sizeOfQ2);
	
	for(i=1;i<n;i++){ //calculate Waiting time 
		Q3[i].WT=Q3[i-1].BT + Q3[i-1].WT;
	}
	
	for(i=1;i<n;i++){  //calculate turn around time
		Q3[i].TAT=Q3[i].BT + Q3[i].WT;
	}
	
	printf("Process_name  priority  AT  BT  WT  TAT\n");
	
	for(i=0;i<n;i++){
		printf("%c\t\t%d\t%d  %d   %d  %d\n",Q3[i].name,Q3[i].priority,Q3[i].AT,Q3[i].BT,Q3[i].WT,Q3[i].TAT);
	}
	
}
