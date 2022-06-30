#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include <cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

main(int argc, char** argv) {
	int input;
	cout << "Enter 1 For FCFS Scheduling Algorithm OR 2 For SJF Algorithm: ";
	cin >> input;
	if(input == 1){ //FCFS Will Be Executed
	int n, burst[50], wait[50], turnaround[50], arrival[50], execution_start[50], execution_end[50], rest_burst[50], exit_time[50];
	cout << "Enter Number of Processes: \n";
	cin >> n;
	//loop to take input of burst time
	for(int i = 0; i < n; i++){
		cout << "Enter Arrival Time For Process " << i + 1 << "]: ";
		cin >> arrival[i];
		cout << "Enter Burst Time For [Process " << i + 1 << "]: ";
		cin >> burst[i];
	}
	
	//calculating execution start and end time
	for(int i = 0; i < n; i++){
		if(i == 0){
			execution_start[i] = arrival[0];
			execution_end[i] = arrival[0] + burst[0];
		} else {
			execution_start[i] = execution_end[i-1];
			execution_end[i] = execution_start[i] + burst[i];
		}
		rest_burst[i] = burst[i] - (execution_end[i] - execution_start[i]);
	}
	
	//calculating exit time, wait time, turnaround time
	for(int i = 0; i < n; i++){
		exit_time[i] = execution_end[i];
		turnaround[i] = exit_time[i] - arrival[i];
		wait[i] = turnaround[i] - burst[i];
	}
	
	cout << "\nProcess Time" << "\t" << "Burst Time" << "\t" << "Waiting Time" << "\t" << "Turnarond Time";
	
	//showing output of process, burst, waiting and turnaround time
	
	for(int i = 0; i < n; i++){
		cout<< "\n[P" << i+1 << "]" << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << turnaround[i] << "\t\t";	
	}
	
	//Calculating Average Waiting Time & TurnAround Time
	float avgwait = 0, avgturnaround = 0;
	for(int i = 0; i < n; i++){
		avgwait = avgwait + wait[i];
		avgturnaround = avgturnaround + turnaround[i];
	}
	
	cout<<"\n\nAverage Waiting Time: " << avgwait / n;
	cout<<"\nAverage TurnAround Time: " << avgturnaround / n;
	
	//showing graphics now
	cout << "\n\n\nPress ENTER For Graphical view\n\n";
    system("pause"); //This is a Windows-specific command, which tells the OS to run the pause program.
	
	//add graphics code
	initwindow(1280,720,"Made By Ujjwal Tiwari",0,0,false,true);
	int font = 8;
    int direction = 0;
    int font_size = 1;
	settextstyle(font, direction, font_size); // font size and font type
	setcolor(LIGHTRED);
	outtextxy(210,10,"Question Table");
	outtextxy(840,10,"Execution table");
	
	int x = 100;
	int y = 53;
	setcolor(YELLOW);
	//loop to construct table
	for(int i = 0; i < (n+2); i++){ //for horizontal part
		line(x,y,520,y); //Question Table
		Sleep(100); //It accepts a time in seconds to delay the execution of the program to that period of time.
		line(660,y,1220,y); //Execution Table
		y = y + 53;
		Sleep(100);
	}
	
	for(int i=0;i<9;i++) //for verticle part
    {
        Sleep(100);
        line(x,53,x,(n+2)*53);
        x=x+140; //distance between cols
    }
	
	setcolor(LIGHTGREEN);
    outtextxy(130,70,"Process");
    Sleep(100);
    outtextxy(270,70,"Arrival");
    Sleep(100);
    outtextxy(415,70,"Burst");
    Sleep(100);
    /* Execution table */
    outtextxy(690,70,"Process");
    Sleep(100);
    outtextxy(820,70,"Execution");
    Sleep(100);
    outtextxy(950,70,"Turnaround");
    Sleep(100);
    outtextxy(1120,70,"State");
    Sleep(100);
    char str[20];
    char str2[]="Exit";
    char str3[]="Waiting";
    
    //Questions Table
     x=80;
     y=120;
     setcolor(WHITE);
     for(int i=0;i<n;i++)
     {
         sprintf(str,"Process %d",i+1);
         Sleep(100);
         outtextxy(x+40,y,str);
         Sleep(100);
         sprintf(str,"%d",arrival[i]);
         Sleep(100);
         outtextxy(x+220,y,str);
         Sleep(100);
         sprintf(str,"%d",burst[i]);
         Sleep(100);
         outtextxy(x+350,y,str);
         Sleep(100);
         y=y+53;
     }
     
     //Result Table
     x=620;
     y=120;
      for(int i=0;i<n;i++)
     {
         sprintf(str,"Process %d",i+1);
         Sleep(100);
         outtextxy(x+60,y,str);
         Sleep(100);
         //execution time
         sprintf(str,"%d - %d",execution_start[i],execution_end[i]);
         Sleep(100);
         outtextxy(x+220,y,str);
         Sleep(100);
         //turnaround time
         sprintf(str,"%d",turnaround[i]);
         Sleep(100);
         outtextxy(x+380,y,str);
         Sleep(100);
         //state of process
         if(rest_burst[i] == 0)
         outtextxy(x+510,y,"Exit");
          else
            outtextxy(x+510,y,"Waiting");
         y=y+53;
         Sleep(100);
     }
     
     outtextxy(1,480,"Press Any key to view Final Output table");
     getch();
     cleardevice();
     
     //Final Output Table
      x=100;
      y=52;
      setcolor(YELLOW);
      outtextxy(470,20,"Final Output table");
      for(int i=0;i<(n+2);i++)
        {
            Sleep(100);
            line(x,y,940,y);

            y=y+52;
        }
        
    for(int i=0;i<7;i++)
    {
        Sleep(100);
        line(x,52,x,(n+2)*52);
        x=x+140;
    }
    setcolor(LIGHTGREEN);
    outtextxy(125,67,"Process");
    Sleep(100);
    outtextxy(270,67,"Arrival");
    Sleep(100);
    outtextxy(430,67,"Exit");
    Sleep(100);
    outtextxy(535,67,"TurnAround");
    Sleep(100);
    outtextxy(700,67,"Burst");
    Sleep(100);
    outtextxy(820,67,"Wait Time");
    Sleep(100);
    
    //PUTTING THE VALUES OF VERIABLES IN OUTPUT TABLE
     x=20;
     y=120;
     setcolor(15);
     for(int i=0;i<n;i++)
     {
         sprintf(str,"Process %d",i+1);
         Sleep(100);
         outtextxy(x+100,y,str);
         sprintf(str,"%d",arrival[i]);
         Sleep(100);
         outtextxy(x+280,y,str);
         sprintf(str,"%d",exit_time[i]);
         Sleep(100);
         outtextxy(x+420,y,str);
         sprintf(str,"%d",turnaround[i]);
         Sleep(100);
         outtextxy(x+560,y,str);
         sprintf(str,"%d",burst[i]);
         Sleep(100);
         outtextxy(x+700,y,str);
         sprintf(str,"%d",wait[i]);
         Sleep(100);
         outtextxy(x+840,y,str);
         Sleep(100);
         y=y+52;
     } //fcfs code ends here
     getch();
} else if (input == 2) 
   {
	
	  int n,temp,execution_start[n],rest_burst[n], exit_time[n],min,d,i,j;// declaration of variables 
      double average_tat =0,average_wat=0,total_tat=0,total_wat=0;

      cout<<"enter no of process"<<endl;           // ask for n.of process
      cin>>n;                                   //take input as n no of process
      int arrival_t[n],burst_t[n],execution_end[n],turn_around_t[n],weighting_t[n]; //declaration of array variables usedin our program 
  
      for(i=0;i<n;i++)              //used for loop for taking all arrival time and burst time
      {
            cout<<"enter Arrival Time " << i + 1 << "]: ";       //input
            cin>>arrival_t[i];             
            cout<<"enter Burst Time " << i + 1 << "]: ";      //input
            cin>>burst_t[i];
      }
      
    //calculating execution_start and executyion end time
	  for(i = 0; i < n; i++){
		if(i == 0){
			execution_start[i] = arrival_t[0];
			execution_end[i] = arrival_t[0] + burst_t[0];
		} else {
			execution_start[i] = execution_end[i-1];
			execution_end[i] = execution_start[i] + burst_t[i];
		}
		rest_burst[i] = burst_t[i] - (execution_end[i] - execution_start[i]);
	}
	
      for(i=0;i<n;i++)           
      {
         for(j=i+1;j<n;j++)
      {         
           if(burst_t[i]>burst_t[j]) //coditional loop used forcomparing burst_t
               {
                 temp=arrival_t[i]; // temp is used to store temporary ar_t data
                 arrival_t[i] = arrival_t[j];
                 arrival_t[j] = temp;

                 temp=burst_t[i]; // temp is used to store temporary bur_t data
                 burst_t[i] = burst_t[j];
                 burst_t[j] = temp;
                }
          }
      }

      for(i=0;i<n;i++)
      {
            if(arrival_t[i] != min)
            {
                  execution_end[i]  = burst_t[i] + execution_end[i];
                  execution_start[i] = execution_end[i];
            }
      }
      for(i=0;i<n;i++)// for loop is ued to find value of diff var_ one by one
      {

            turn_around_t[i] = execution_end[i]-arrival_t[i];
            total_tat        = total_tat + turn_around_t[i];
            weighting_t[i]   = turn_around_t[i]-burst_t[i];
            total_wat         = total_wat + weighting_t[i];
            exit_time[i]     = execution_end[i];
      }
      average_tat=total_tat/n;
      average_wat=total_wat/n;
      cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

    for(i=0;i<n;i++)
    {
    cout<<"P"<<i+1<<"\t\t\t"<<arrival_t[i]<<"   \t\t\t"<<burst_t[i]<<"     \t\t\t"<<weighting_t[i]<<"     \t\t\t"<<turn_around_t[i]<<endl;
    }
    cout<<"averageweightingtime="<<average_wat<<" averageturnaroundt="<<average_tat;  //average waiting time and turn around time
	
	//add graphics code
	initwindow(1280,720,"Made By Ujjwal Tiwari",0,0,false,true);
	int font = 8;
    int direction = 0;
    int font_size = 1;
	settextstyle(font, direction, font_size); // font size and font type
	setcolor(LIGHTRED);
	outtextxy(210,10,"Question Table");
	outtextxy(840,10,"Execution table");
	
	int x = 100;
	int y = 53;
	setcolor(YELLOW);
	//loop to construct table
	for(int i = 0; i < (n+2); i++){ //for horizontal part
		line(x,y,520,y); //Question Table
		Sleep(100); //It accepts a time in seconds to delay the execution of the program to that period of time.
		line(660,y,1220,y); //Execution Table
		y = y + 53;
		Sleep(100);
	}
	
	for(int i=0;i<9;i++) //for verticle part
    {
        Sleep(100);
        line(x,53,x,(n+2)*53);
        x=x+140; //distance between cols
    }
	
	setcolor(LIGHTGREEN);
    outtextxy(130,70,"Process");
    Sleep(100);
    outtextxy(270,70,"Arrival");
    Sleep(100);
    outtextxy(415,70,"Burst");
    Sleep(100);
    /* Execution table */
    outtextxy(690,70,"Process");
    Sleep(100);
    outtextxy(820,70,"Execution");
    Sleep(100);
    outtextxy(950,70,"Turnaround");
    Sleep(100);
    outtextxy(1120,70,"State");
    Sleep(100);
    char str[20];
    char str2[]="Exit";
    char str3[]="Waiting";
    
    //Questions Table
     x=80;
     y=120;
     setcolor(WHITE);
     for(int i=0;i<n;i++)
     {
         sprintf(str,"Process %d",i+1);
         Sleep(100);
         outtextxy(x+40,y,str);
         Sleep(100);
         sprintf(str,"%d",arrival_t[i]);
         Sleep(100);
         outtextxy(x+220,y,str);
         Sleep(100);
         sprintf(str,"%d",burst_t[i]);
         Sleep(100);
         outtextxy(x+350,y,str);
         Sleep(100);
         y=y+53;
     }
     
    //Result Table
     x=620;
     y=120;
      for(int i=0;i<n;i++)
     {
         sprintf(str,"Process %d",i+1);
         Sleep(100);
         outtextxy(x+60,y,str);
         Sleep(100);
         //execution time
         sprintf(str,"%d - %d",execution_start[i],execution_end[i]);
         Sleep(100);
         outtextxy(x+220,y,str);
         Sleep(100);
         //turnaround time
         sprintf(str,"%d",turn_around_t[i]);
         Sleep(100);
         outtextxy(x+380,y,str);
         Sleep(100);
         //state of process
         if(rest_burst[i] == 0)
         outtextxy(x+510,y,"Exit");
          else
            outtextxy(x+510,y,"Waiting");
         y=y+53;
         Sleep(100);
     }
     
     outtextxy(1,480,"Press Any key to view Final Output table");
     getch();
     cleardevice();
     
     //Final Output Table
      x=100;
      y=52;
      setcolor(YELLOW);
      outtextxy(470,20,"Final Output table");
      for(int i=0;i<(n+2);i++)
        {
            Sleep(100);
            line(x,y,940,y);

            y=y+52;
        }
        
    for(int i=0;i<7;i++)
    {
        Sleep(100);
        line(x,52,x,(n+2)*52);
        x=x+140;
    }
    setcolor(LIGHTGREEN);
    outtextxy(125,67,"Process");
    Sleep(100);
    outtextxy(270,67,"Arrival");
    Sleep(100);
    outtextxy(430,67,"Exit");
    Sleep(100);
    outtextxy(535,67,"TurnAround");
    Sleep(100);
    outtextxy(700,67,"Burst");
    Sleep(100);
    outtextxy(820,67,"Wait Time");
    Sleep(100);
    
//    PUTTING THE VALUES OF VERIABLES IN OUTPUT TABLE
     x=20;
     y=120;
     setcolor(15);
     for(int i=0;i<n;i++)
     {
         sprintf(str,"Process %d",i+1);
         Sleep(100);
         outtextxy(x+100,y,str);
         sprintf(str,"%d",arrival_t[i]);
         Sleep(100);
         outtextxy(x+280,y,str);
         sprintf(str,"%d",exit_time[i]);
         Sleep(100);
         outtextxy(x+420,y,str);
         sprintf(str,"%d",turn_around_t[i]);
         Sleep(100);
         outtextxy(x+560,y,str);
         sprintf(str,"%d",burst_t[i]);
         Sleep(100);
         outtextxy(x+700,y,str);
         sprintf(str,"%d",weighting_t[i]);
         Sleep(100);
         outtextxy(x+840,y,str);
         Sleep(100);
         y=y+52;
	}
	getch();
	return 0;
 } else { //sjf code ends here
 	cout << "Enter 1 Or 2 To Get Desired Output";
 } 
}
