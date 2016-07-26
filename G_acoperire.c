#include <stdio.h>

int main()
{
	int MA[20][20]={0},LS[20][20]={0};
	int n,arc,i,j,t1,t2,v=0,u,cr=0,x=0,y=0,cr2=0,aux,cr3=0;
	int P ,F[2][30]={0} ,nev[20]={0},elimin[10];

	printf("\t\t\t GRAF DE ACOPERIRE :\r\n");
	printf("\r\n Introdu numarul de virfuri : ");
	scanf("%d",&n);
	printf("\r\n Introdu numarul de muchii : ");
	scanf("%d",&arc);

	for(i=0;i<arc;i++)
		{
			printf("\r\nOriginea -> ");
			scanf("%d",&t1); t1--;
			printf("\r\nDestinatia -> ");
			scanf("%d",&t2); t2--;
			MA[t1][t2]=1;
			MA[t2][t1]=1;
		}

	for(i=0;i<n;i++)
		nev[i]=i+1;

	u=0; v=1;

p2:	for(i=0;i<n;i++)
	{if(nev[i]!=0) F[u][0]=nev[i]; break;}

p3: 
	cr=0;
	for(i=0;i<30;i++)
	if(F[u][i]!=0) {cr=1;break;} //cr=1 sunt elemente in lista

	if(cr==0) goto p8;

	for(j=0;j<30;j++)
	if(F[u][j]!=0) {P=F[u][j];break;}

	nev[P-1]=0;
	F[u][i]=0;

p4:	for(i=0;i<n;i++)
	{

		if(MA[P-1][i]!=0)
		{
			cr2=0;
			t1=i+1;
			if (nev[t1-1]==0) cr2=0; else cr2=1;

			for(j=0;j<30;j++)
				if(t1==F[u][j]) cr2=0;

			if(cr2==1)
			F[v][x++]=t1;
			
		}
	}

p5 :  
	
	for(i=0;i<10;i++)
		elimin[i]=0;
	j=0;
	for(i=0;i<30;i++)
	if(F[v][i]!=0) elimin[j++]=F[v][i];

	t2=j;
	for(i=0;i<t2;i++)
	for(j=0;j<t2;j++)
	MA[elimin[i]-1][elimin[j]-1]=0;

p6:
	
	for(i=0;i<t2;i++)
	{
		y=0;
		if(MA[elimin[i]-1][P-1]==1) y++;

	for(j=0;j<30;j++)
	{	
		if(F[u][j]!=0)
		{	
			if(MA[elimin[i]-1][F[u][j]-1]==1) 
			{
				y++;
				if(y>1) { MA[elimin[i]-1][F[u][j]-1]=0; MA[F[u][j]-1][elimin[i]-1]=0; 	 }
			}

		}

	}
}

goto p3;

p8:
aux=u;
u=v;
v=aux; 


	cr3=0;
	for(i=0;i<30;i++)
	if(F[u][i]!=0) {cr3=1; break;}

	for(i=0;i<30;i++)
	if(F[v][i]!=0) {cr3=1; break;}

	if(cr3==1) goto p3;

	for(i=0;i<n;i++)
  { 
  v=0; LS[i][v++]=i+1;
  for(j=0;j<n;j++)

    {
    if(MA[i][j]==1)
    LS[i][v++]=j+1;
    else LS[i][v]=0;
    LS[i][v+1]=0;

    }

    }

  printf("\r\n\n GRAF DE ACOPERIRE \r\n");
     
    for(i=0;i<n;i++)
    {  printf("\r\n\t%d |",LS[i][0]);
    for(j=1;LS[i][j]!=0;j++)
      {
      printf(" %d",LS[i][j]);
      
      }
    }





}



