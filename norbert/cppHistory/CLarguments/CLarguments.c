#include <stdio.h>
#include <stdlib.h>
void WypiszArgumentyWierszaPolecen(int argc, char *argv[]){
		int i;
		printf("liczba argumentow w wierszu polecen %d\n", argc);
		for (i=0; i<argc; i++){
			printf("Element numer %d wiersza polecen ma wartosc %s\n",i,argv[i]);
		}
	}
int main (int argc, char *argv[]) {
	FILE *fp;
	char znaki[] = "Tekst do zapisania w pliku";
	if ((fp=fopen("text.txt", "w"))==NULL) {
		printf("Nie moge otworzyc pliku!");
		exit(1);
	}
	fprintf(fp, "%s", znaki);
	fclose(fp);
	WypiszArgumentyWierszaPolecen(argc, argv);

	return 0;
}
