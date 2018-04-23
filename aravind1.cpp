//non premtive sjf
#include<stdio.h>
struct process
{
	int pro,at,Burst_time,burst,process_arrived,com;
	double priority;
}process[4];
void Pri(struct process *process_1,int t){	
	if(t>=process_1->at && process_1->Burst_time!=(-1)) 
			{
				process_1->priority=1+((t-process_1->at)/process_1->Burst_time);
			}
}
void sortprocess(struct process *process_1,struct process *process_2){
	if(process_1->priority<process_2->priority && process_1->process_arrived!=0 && process_2->process_arrived!=0)
				{
					double t1=process_1->priority;
					process_1->priority=process_2->priority;
					process_2->priority=t1;
					int t2=process_1->process_arrived;
					process_1->process_arrived=process_2->process_arrived;
					process_2->process_arrived=t2;
				}
				else if(process_1->priority==process_2->priority  && process_1->process_arrived!=0 && process_2->process_arrived!=0)
				{
					if(process_1->Burst_time<process_2->Burst_time)
					{
						int t=process_1->process_arrived;
						process_1->process_arrived=process_2->process_arrived;
						process_2->process_arrived=t;
					}
				}
			}

int main(){
	int Tme=0,i=0,bt=0,ii=0;
	for(i=0;i<4;i++)
	{
		printf("\nEnter Process ID:-");
		scanf("%d",&process[i].pro);
		printf("\nEnter  Process Arrival Time:-");
		scanf("%d",&process[i].at);
		printf("\nEnter Process Burst Time:-");
		scanf("%d",&process[i].Burst_time);
		process[i].burst=process[i].Burst_time;
		process[i].process_arrived=1;
		process[i].com=0;
		process[i].priority=0;
	}
	while(1)
	{
		int l;
		for(l=0;l<4;l++)
		{
			Pri(&process[l],Tme);
	
		}
		int p,q;
		for(p=0;p<4;p++)
		{
			for(q=0;q<4-1-p;q++)
			{
				sortprocess(&process[q],&process[q+1]);
			
			}
		}
		int y=process[0].process_arrived;
		bt=process[y-1].Burst_time;
		do
		{
		
			int x;
			for(x=0;x<4;x++)
			{
				if(Tme==process[x].at)
				{		
					process[x].process_arrived=x+1;
					printf("process %dhas  arrived\n",x);
				}	
			}
			bt=bt-1;
			Tme=Tme+1;
			if(bt==0)
			{
				printf("process %d has completed\n",y );
				process[y-1].com=Tme;
				ii=ii+1;
				process[y-1].Burst_time=-1;
			
				for(x=0;x<4;x++)
				{
					process[x].priority=0;
					if(process[x].process_arrived!=0)
					{
						process[x].process_arrived=x+1;
					}
				}
				break;
			}
		}while(1);
		if(ii==4)
			break;

	}
	
	int TATime[4]={0}, wt[4]={0};
	float Awt,ATAT;
	for(i=0;i<4;i++)
	{
		TATime[i]=process[i].com-process[i].at;
		wt[i]=TATime[i]-process[i].burst;
	}
	printf("**************Oder Of Execution********************\n");
	printf("Process\tArrival Tme\tBurst Tme\tTurnaround Tme\tWaiting Tme\n");
	for(i=0;i<4;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",i+1,process[i].at,process[i].burst,TATime[i],wt[i]);
	}
	Awt=wt[0]+wt[1]+wt[2]+wt[3];
	ATAT=TATime[0]+TATime[1]+TATime[2]+TATime[3];
	printf("\nAverage waiting Tme is %f .",Awt/4.0);
	printf("\nAverage turnaround Tme is %f .",ATAT/4.0);
}
