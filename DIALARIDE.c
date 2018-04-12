#include<stdio.h>
#include<math.h>
float   caldistance(int ,int);
float   chargesedan(float);
float   chargeSUV(float);
float   chargeLIMO(float);
float   chargeLUXURY(float);
void    displaysedan(float ,char[],char[]);
void    displaySUV(float,char[],char[]);
void    displayLIMO(float,char[],char[]);
void    displayLUXURY(float,char[],char[]);
int     boss(int);
void    client();

void main()
{
    int ch;
    int i,j,car,n=0,k=0,p=0,l=0,m=0;
    float dis=0;
    float csedan=0,csuv=0,climo=0,cluxury=0;
    char start[10],destination[10];
    printf("\n\t\t\t  ********  WELCOME TO TRAVEL  *********** \n ");
    printf("\n\t\t\t   *******   CAB - AGENCIES    ********* \n");
    printf("\n\n Enter the type of car you need  : \n1.SEDAN \n2.SUV \n3.LIMO \n4.LUXURY \n Your need :- ");
    scanf("%d",&car);
    printf("\n The cars are present at the location : \n1.pethuwala\n2.graphic era gate 2\n3.grahic era gate 1 \n4.grahic era hill university \n5.clement town \n6.doiwala");
    printf("\n Enter the Pickup point : ");
    scanf("%s",&start);
    printf("\n Enter the destination point : ");
    scanf("%s",&destination);
    k=strlen(start);
    p=strlen(destination);
    if(k==9)
    {
        l=1;
    }
    if(k==18)
    {
        l=2;
    }
    if(k==17)
    {
        l=3;
    }
    if(k==26)
    {
        l=4;
    }
    if(k==12)
    {
        l=5;
    }
    if(k==7)
    {
        l=6;
    }
    n=boss(l);
    if(n==1)
    {
         if(p==9)
        {
            m=1;
        }
        if(p==18)
        {
            m=2;
        }
        if(p==17)
        {
            m=3;
        }
        if(p==26)
        {
            m=4;
        }
        if(p==12)
        {
            m=5;
        }
        if(p==7)
        {
            m=6;
        }
        dis=caldistance(k,p);
        printf("\nThe distance is :- %f",dis);
        switch(car)
        {
            case 1:
                    csedan = chargesedan(dis);
                    displaysedan(csedan,start,destination);
                    break;
            case 2 :
                    csuv = chargeSUV(dis);
                    displaySUV(csuv,start,destination);
                    break;
            case 3:
                    climo=chargeLIMO(dis);
                    displayLIMO(climo,start,destination);
                    break;
            case 4 :
                    cluxury=chargeLUXURY(dis);
                    displayLUXURY(cluxury,start,destination);
                    break;
            case 5 :
                    printf("Sorry sir we dont have that car !!!!  ");
                    break;
        }
    }
    else
    {
        printf("\n  SORRY !!!!  AT A TIME NO CAR IS AT YOUR LOCATION \n");

    }
}

int boss(int location)
{
    int check;
    printf("\nChecking the car !!! please wait .... \n");
    if(location == 1 || location == 2|| location ==3 || location ==4 || location ==5 ||location ==6)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
float caldistance(int k,int p)
{
    int i=0,o=0,j=0,l=0;
    int dis[6][6];
    float dist;
    static int a[6][6]={{2,4,3,5,6,9},{1,4,3,2,6,8},{7,1,34,8,6,12},{34,65,89,65,34,23},{12,11,13,19,8,20},{32,45,67,87,90,78}};
    for(i=0;i<6;i++)                   //algo for find shortest path
    {
        printf("\n");
        for(j=0;j<6;j++)
        {
            printf("%f",a[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<6;i++)                   //algo for find shortest path
    {
        for(j=0;j<6;j++)
        {
            dis[i][j]=a[i][j];
        }
    }
    printf("\n");
       for(i=0;i<6;i++)
        {
            for(j=0;j<6;j++)
            {
                if(dis[i][j]==o)
                {
                    if(0<=i+1<6 && o<=j<6 && dis[i+1][j]== -1)
                        dis[i+1][j]=o+1;
                    if(0<=i-1<6 && 0<=j<6 && dis[i-1][j]==-1)
                      dis[i-1][j]=o+1;
                    if(0<=i<6 && 0<=j+1<6 && dis[i][j+1]==-1)
                        dis[i][j+1]=o+j;
                     if(0<=i <6 && 0<=j-1<6 && dis[i][j-1]==-1)
                     dis[i][j-1]=o+1;
                     if(dis[i][j] == -3)
                      break;
                }
            }
            o++;
        }
    dist=dis[k][p];
    printf("The distance :- %f",dist);
    return(dist);
}
float chargesedan(float dist)
{
    float chargese=0;
    chargese=(dist*5)+150;    //150 charge of the SEDAN
    return(chargese);
}
float chargeSUV(float dist )
{
    float chargesu=0;
    chargesu=(dist*5)+250;   // 250 charge of the SUV
    return(chargesu);
}
float chargeLIMO(float dist )
{
    float chargeli=0;
    chargeli=(dist*5)+450;   // 450 charge of the LIMO
    return(chargeli);
}
float chargeLUXURY(float dist )
{
    float chargelux=0;
    chargelux=(dist*5)+750;   // 750 charge of the LUXURY
    return(chargelux);
}
void displaysedan(float csedan,char start[10],char destination[10])
{
    printf("\nWE CHARGE FOR THE LOWEST DISTANCE AND THERE IS 5 INR FOR EVERY KILOMETERS \n");
    printf("\nTHE CHARGE OF YOUR TRAVELING FROM LOCATION %s to %s  :- %d ",start,destination,csedan);
}
void displaySUV(float csuv,char start[10],char destination[10])
{
    printf("\nWE CHARGE FOR THE LOWEST DISTANCE AND THERE IS 5 INR FOR EVERY KILOMETERS \n");
    printf("\nTHE CHAGE OF YOUR TRAVELING FROM LOCATION %s TO %s :- %d ",start,destination,csuv);
}
void displayLIMO(float climo,char start[10],char destination[10])
{
    printf("\nWE CHARGE FOR THE LOWEST DISTANCE AND THERE IS 5 INR FOR EVERY KILOMETERS \n");
    printf("\nTHE CHAGE OF YOUR TRAVELING FROM LOCATION %s TO %s :- %d ",start,destination,climo);
}
void displayLUXURY(float cluxury,char start[10],char destination[10])
{
     printf("\nWE CHARGE FOR THE LOWEST DISTANCE AND THERE IS 5 INR FOR EVERY KILOMETERS \n");
     printf("\nTHE CHAGE OF YOUR TRAVELING FROM LOCATION %s TO %s :- %d ",start,destination,cluxury);
}
