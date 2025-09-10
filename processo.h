// Definindo o TAD Processo
#ifndef PROCESSO_H
#define PROCESSO_H

// Definindo o TAD PROCESSO

#define ERRO -999

typedef struct {

    int id_processo;
    char numero_sigilo[50];       
    char sigla_grau[10];
    char procedimento[100];
    char ramo_justica[50];
    char sigla_tribunal[20];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[11];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    char decisao[200];
    char dt_resolvido[11];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;    
    int mpum1;
    int julgadom1; 
    int desm1;
    int susm1;

} Processo;

Processo * LerDados(char * NomeArquivo); 

#endif