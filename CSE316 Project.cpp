#include<stdio.h> 
 
int main() 
{ 
      int i, ran, t= 0, x, count = 0, tq,j , wt= 0, tt= 0,position,z,p[10],priority[10], at[10], bt[10], temp[10],s; 
      
	  float avg_wt, avg_tt;
      
	  printf("\nEnter Total Number of Processes:"); 
      
	  scanf("%d", &ran); 
      
	  x = ran;
	  i=0;
      while(i<ran)
      {
	    p[i]=i+1;
	   
	    priority[i]=0;
            printf("\nEnter details of processes[%d]\n", i + 1);
            printf("AT:\t");
            scanf("%d", &at[i]);
            printf("BT:\t");
            scanf("%d", &bt[i]); 
            temp[i] = bt[i];
            i++;
      }
	   
      printf("\nEnter TQ:"); 
      scanf("%d", &tq); 
      printf("\nPID\t\tBT\t TT\t WT\t Prior\n");
      t = 0, i = 0;
	  while( x != 0)
      { 
        z=0;
		    while(z<ran)
		    {
			int temp1;
			position=z;
			j=z+1;
			while(j<ran)
			{
			    if(priority[j]<priority[position])
				position=j;
				j++;
			}
		 
		temp1=priority[z];
	
		priority[z]=priority[position];
	
		priority[position]=temp1;
		 
			temp1=bt[z];
			bt[z]=bt[position];
			bt[position]=temp1;
		 			temp1=at[z];
				at[z]=at[position];
			at[position]=temp1;

			temp1=p[z];
				p[z]=p[position];
			p[position]=temp1;

			temp1=temp[z];
				temp[z]=temp[position];
			temp[position]=temp1;
			z++;
		    }
            if(temp[i] <= tq&& temp[i] > 0) 
            { 
                  t= t+ temp[i]; 
                  temp[i] = 0; 
                  count = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - tq; 
                  t = t + tq; 
            } 

	s=0;
	while(s<ran)
		{
			if(s==i)
			priority[s]+=1;
			else
			priority[s]+=2;
			s++;
		}

            if(temp[i] == 0 && count == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i], bt[i], t - at[i], t - at[i] - bt[i],priority[i]);
                  wt = wt+ t- at[i] - bt[i]; 
                  tt = tt+ t - at[i]; 
                  count = 0; 
            } 
            if(i == ran - 1) 
            {
                  i = 0; 
            
			}
            else if(at[i + 1] <= t) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      return 0; 
}

