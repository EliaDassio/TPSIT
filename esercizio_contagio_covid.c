#include<stdio.h>

int main()
{
	// inizializzo tutte le vriabili necessarie e le differenzio a seconda se devono essere numeri decimali o meno
	
	float R;
	float x[50];
	int N, i, con;

	// vado a chiedere in imput i dati che mi servono

	printf("inserire numero di persone contagiateda una sola persona ogni giorno in media : ");
	scanf("%f", &R);

	printf("\ninserire il numero di studenti nella classe : ");
	scanf("%d", &N);

	// iniziaalizzo il primo nuero dell'arrey come 1 dato che e' il primo contagiato

	x[0] = 1;

	// utilizzo il ciclo for per aumentare i giorni chiamati i e il numero di persone contagiate con da confrontare con la soglia da raggiungere

	for (i = 1, con = 1; con < N; i++)
	{
		x[i] = R * x[i - 1]; // calcolo il numero di contagiati
		con = x[i]; // salvo il numero di contagiati in una variabile a parte 
		printf("\nil numero di contagi al giorno %d e' %d", i, con); // stampo il bollettio giornaliero 
	}

	// stampo il numero di giorni calcolati

	printf("\nil numero di giorni richiesto per contagiare %d persone e' : %d", N, i-1);

	return 0;
}