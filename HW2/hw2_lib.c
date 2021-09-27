/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include "hw2_lib.h"
#include <math.h>


int find_weekday_of_data(int day, int month, int year){ /*Find the date of the given year with using Zeller's Algorithm */
	if((day>31 || day<0) || (month>12 || month<1) || year<0){
	printf("Enter a valid date");
	}
	/*for to use Zeller's algorithm, we have to shift the months as: march:3, april: 4, may: 5,.... february: 14 */
	int i,w,c,y,Y; /* y is the last 2 digit of the year  */
	int m=3; /* for shifting the months */
	int month_array[12];
	
	/*********** checking the month: monday:2 tuesday:3 .... saturday: 6 sunday: 1 ************/
	if(month==1 || month ==2){
		Y=year-1;	/*Y is the year minus 1 for January or February, and the year for any other month*/
	}
	
	if(month==1 || month ==2){
		if(month==1){
			month=13;
		}
		else if(month==2){
			month=14;
		}
	}
	/*********** checking the dates: monday:2 tuesday:3 .... saturday: 6 sunday: 1 ************/
	if(day<6){
	day+=1;
	}
	else{
		day= day%6;
	}
	for(i=0;i<12;i++){
		month_array[i]=m;
		m++;
	}
	/****************** checking the year's last 2 digits **************************/
	if(year>100){
			y= abs(year) % 100 ; /* if the year is moore than 100 then divide it to 100 to get last two digit */
					}
			else{
			  y=year; /* if the year is less than 100 then last two digit is year's itself */
			}
	
	/****************** checking the year's first 2 digits **************************/	
	if(year>=1000){
		for(i=0;i<2;i++){
			year= year/10;
		}
		c= year;
	}
	else if(year>=100 && year<1000){
			c= year/10;
		}
	
	else{
		c= year;
	}
	/****************** implementing the formula **************************/
	w= ((floor(13*(month+1)/5)+ floor(y/4)+ floor(c/4)+ day + y - 2*c)%7);
	w=(w+6)%7;
	
	
	return w;
}
	
	
int dayCounter(int day,int month, int year)
{
    int i;
    int day_count = 0;
    for( i = 0; i < year; i++)
    {
    	if((i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))){
    		day_count+=366; /* checking the lap years */
			}
        	else{
        	day_count+=365;
			}
    }
     i=1;
    while(i < month)
    {
    	if(i == 2) /* if the month is februrary then check for the lap year */
        {
            if((i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))){
    		day_count+=29;
			}
        	else{
        	day_count+=28;
			}
        }
        
		else if(i == 1 || i == 3|| i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            day_count += 31; /* for 31 date months */
            continue;
        }
        
        else{
		day_count += 30; /* else it has 30 days */
    	}
    	i++;
	}
    
    day_count += day;
   	return day_count;

}

int count_day_between_dates (int start_day, int start_month, int start_year, int end_day, int end_month, int end_year){
	int result;
	result=dayCounter( end_day, end_month, end_year)-dayCounter(start_day,start_month,start_year);
	return result; 
}
double find_angle (double a, double b, double c){
 	double alfa;
 	double cos_angle; /* calculating the angle using cosine theorem and median point rule (2/3) */
 	double vb= sqrt((2*pow(a,2)+2*pow(c,2)-pow(b,2))/4);
 	double vc= sqrt((2*pow(a,2)+2*pow(b,2)-pow(c,2))/4);
 	vb=(vb*2)/3;
 	vc=(vc*2)/3;
 	cos_angle= ((-pow(a,2)+pow(vb,2)+pow(vc,2))/(2*vb*vc)); /* finding the arccosine of the angle */
 	alfa= acos(cos_angle);
 	return alfa;
 }


void print_tabulated (unsigned int r11, double r12, int r13, unsigned int r21, double r22, 
int r23, unsigned int r31, double r32, int r33, char border){
int i;
unsigned int r1[3]; 
double r2[3];
int r3[3]; /* assigning the value to an array and printing the values */
r1[0]=r11; r1[1]=r21; r1[2]=r31;
	
r2[0]=r12; r2[1]=r22; r2[2]=r32;
	
r3[0]=r13; r3[1]=r23; r3[2]=r33;
if(border== '-'){
printf("+-------------------+----------------------------+---------------------+\n");
printf("|     Row 101       |      Row ABCDEFG           |      Row XYZ123     |\n");
printf("+-------------------+----------------------------+---------------------+\n");
for(i=0;i<3;i++){ 
	printf("|     %5u         |      %6.2f        	 |      %6d         |\n",r1[i],r2[i],r3[i]);
	printf("+-------------------+----------------------------+---------------------+\n");
	}
}
	
else if(border == '*'){
	printf("+*******************+****************************+*********************+\n");
printf("|     Row 101       |      Row ABCDEFG           |      Row XYZ123     |\n");
printf("+*******************+****************************+*********************+\n");
for(i=0;i<3;i++){ 
	printf("|     %5u         |      %6.2f        	 |      %6d         |\n",r1[i],r2[i],r3[i]);
	printf("+*******************+****************************+*********************+\n");
	
	}
}
}

