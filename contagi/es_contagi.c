#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_state_name_lenth 3
#define MAX_file_line_lenth 2000
#define MAX_latitude_char 100
#define MAX_longitude_char 100
#define MAX_char_reg 50
#define MAX_char_reg_code 50
#define MAX_num_cot_per_reg 60000000


typedef struct s_data{
    int anno;
    int mese;
    int giorno;
    int ora;
    int minuti;
    int secondi;
}data;

typedef struct s_regione{
    data data_odierna;
    char stato[MAX_state_name_lenth];
    char codice_regione[MAX_char_reg_code];
    char denominazione_regione[MAX_char_reg];
    char latitudine[MAX_latitude_char];
    char longitudine[MAX_longitude_char];
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    struct s_regione* puntatore_alla_prossima_regione;
}regione;


int get_data(regione* regione_iniziale, FILE* file_csv);
void top_3_reg_ric(regione* regione_iniziale, int numero_di_regioni);
void num_ric(regione* regione_iniziale, int numero_di_regioni);
void top_3_reg_less_con(regione* regione_iniziale, int numero_di_regioni);


int main(){
    
    bool* stato_operazione;
    bool var=true;
    stato_operazione=&var;

    FILE* fp;

    fp = fopen("contagi.csv", "r");

    if(fp==NULL){
        printf("\n\nerror during file opening\n\n");
        return -1;
    }

    regione* regione_iniziale = (regione*)malloc(sizeof(regione));

    int numero_regioni=get_data(regione_iniziale, fp);
    top_3_reg_ric(regione_iniziale, numero_regioni);
    num_ric(regione_iniziale, numero_regioni);
    top_3_reg_less_con(regione_iniziale, numero_regioni);
    
    return 0;
}

int get_data(regione* regione_iniziale, FILE* file_csv){
    regione *reg;
    reg=regione_iniziale;

    char* string_define;
    int numero_regioni=0;

    char riga_file[MAX_file_line_lenth];
    fgets(riga_file, MAX_file_line_lenth, file_csv);

    for(numero_regioni=0; fgets(riga_file, MAX_file_line_lenth, file_csv)!=NULL; numero_regioni++){

        string_define=strtok(riga_file, "-");
        reg->data_odierna.anno=atoi(string_define);

        string_define=strtok(riga_file, "-");
        reg->data_odierna.mese=atoi(string_define);

        string_define=strtok(riga_file, "T");
        reg->data_odierna.giorno=atoi(string_define);

        string_define=strtok(riga_file, ":");
        reg->data_odierna.ora=atoi(string_define);

        string_define=strtok(riga_file, ":");
        reg->data_odierna.minuti=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->data_odierna.secondi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        strcpy(reg->stato, string_define);

        string_define=strtok(riga_file, ",");
        strcpy(reg->codice_regione, string_define);

        string_define=strtok(riga_file, ",");
        strcpy(reg->denominazione_regione, string_define);

        string_define=strtok(riga_file, ",");
        strcpy(reg->latitudine, string_define);

        string_define=strtok(riga_file, ",");
        strcpy(reg->longitudine, string_define);

        string_define=strtok(riga_file, ",");
        reg->ricoverati_con_sintomi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->ricoverati_con_sintomi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->totale_ospedalizzati=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->isolamento_domiciliare=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->totale_positivi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->variazione_totale_positivi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->nuovi_positivi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->dimessi_guariti=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->deceduti=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->casi_da_sospetto_diagnostico=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->casi_da_screening=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->totale_casi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->tamponi=atoi(string_define);

        string_define=strtok(riga_file, ",");
        reg->casi_testati=atoi(string_define);

        reg->puntatore_alla_prossima_regione=(regione*)malloc(sizeof(regione));
        reg=reg->puntatore_alla_prossima_regione;

    }
    return numero_regioni;
}

void top_3_reg_ric(regione* regione_iniziale, int numero_di_regioni){
    regione *reg;
    reg=regione_iniziale;

    for(int y=0; y<3; y++){
    int max=regione_iniziale->terapia_intensiva;
    for(int i=0; i<numero_di_regioni; i++){

        if(reg->terapia_intensiva>max){
            max=reg->terapia_intensiva;
        }else if(reg->terapia_intensiva==max){
            reg->terapia_intensiva=-1;
        }else{

        }
        reg=reg->puntatore_alla_prossima_regione;
    }

    reg=regione_iniziale;

    for(int i=0; i<numero_di_regioni; i++){
        if(reg->terapia_intensiva==max){
            printf("\n\nthe region %d is the number %s for people contaged with %d\n\n", y, reg->denominazione_regione,max);
            reg->terapia_intensiva=-1;
        }
        reg=reg->puntatore_alla_prossima_regione;
    }
    }

    printf("\n\n");

}

void num_ric(regione* regione_iniziale, int numero_di_regioni){
    regione *reg;
    reg=regione_iniziale;

    int somma=0;

    for(int i=0; i<numero_di_regioni; i++){
        somma=somma+reg->terapia_intensiva;
        reg=reg->puntatore_alla_prossima_regione;
    }

    printf("\n\nthe national number of people in intensive cure is %d\n\n", somma);
}

void top_3_reg_less_con(regione* regione_iniziale, int numero_di_regioni){
    regione *reg;
    reg=regione_iniziale;

    for(int y=0; y<3; y++){
    int min=reg->totale_positivi;
    for(int i=0; i<numero_di_regioni; i++){

        if(reg->totale_positivi<min){
            min=reg->totale_positivi;
        }else if(reg->totale_positivi==min){
            reg->totale_positivi=MAX_num_cot_per_reg;
        }else{

        }
        reg=reg->puntatore_alla_prossima_regione;
    }

    reg=regione_iniziale;

    for(int i=0; i<numero_di_regioni; i++){
        if(reg->totale_positivi==min){
            printf("\n\nthe reagion number %d is the number %s for contages with %d\n\n", y, reg->denominazione_regione, min);
            reg->totale_positivi=MAX_num_cot_per_reg;
        }
        reg=reg->puntatore_alla_prossima_regione;
    }
    }

    printf("\n\n");
}