#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processo.h"

int carregar_processos(const char *filename, Processo *processos, int max) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("!! ERRO: arquivo nao pode ser aberto !!\n");
        exit(1);
    }

    char buffer[1024];
    int count = 0;

    // Pula a linha de cabeçalho
    fgets(buffer, sizeof(buffer), fp); 

    while (fgets(buffer, sizeof(buffer), fp) && count < max) {
        Processo p;
        char *token;
        int i = 0;

        token = strtok(buffer, ";\n");
        while (token != NULL && i < 28) {
            switch (i) {
                case 0: p.id_processo = atoi(token); break;
                case 1: strncpy(p.numero_sigilo, token, MAX_STR); break;
                case 2: strncpy(p.sigla_grau, token, MAX_STR); break;
                case 3: strncpy(p.procedimento, token, MAX_STR); break;
                case 4: strncpy(p.ramo_justica, token, MAX_STR); break;
                case 5: strncpy(p.sigla_tribunal, token, MAX_STR); break;
                case 6: p.id_tribunal = atoi(token); break;
                case 7: p.recurso = atoi(token); break;
                case 8: p.id_ultimo_oj = atoi(token); break;
                case 9: strncpy(p.dt_recebimento, token, MAX_STR); break;
                case 10: p.id_ultima_classe = atoi(token); break;
                case 11: p.flag_violencia_domestica = atoi(token); break;
                case 12: p.flag_feminicidio = atoi(token); break;
                case 13: p.flag_ambiental = atoi(token); break;
                case 14: p.flag_quilombolas = atoi(token); break;
                case 15: p.flag_indigenas = atoi(token); break;
                case 16: p.flag_infancia = atoi(token); break;
                case 17: p.decisao = atoi(token); break;
                case 18: strncpy(p.dt_resolvido, token, MAX_STR); break;
                case 19: p.cnm1 = atoi(token); break;
                case 20: p.primeirasentm1 = atoi(token); break;
                case 21: p.baixm1 = atoi(token); break;
                case 22: p.decm1 = atoi(token); break;
                case 23: p.mpum1 = atoi(token); break;
                case 24: p.julgadom1 = atoi(token); break;
                case 25: p.desm1 = atoi(token); break;
                case 26: p.susm1 = atoi(token); break;
                default: break;
            }
            token = strtok(NULL, ";\n");
            i++;
        }
        
        processos[count++] = p;
    }

    fclose(fp);
    return count;
}

int contar_processos(Processo *processos, int n) {
    (void)processos; 
    return n;
}

int obter_id_ultimo_oj(Processo *processos, int n, int id_processo) {
    for (int i = 0; i < n; i++) {
        if (processos[i].id_processo == id_processo) {
            return processos[i].id_ultimo_oj;
        }
    }
    return -1;
}

int obter_processo_mais_antigo(Processo *processos, int n) {
    if (n == 0) return -1;

    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(processos[i].dt_recebimento, processos[indice].dt_recebimento) < 0) {
            indice = i;
        }
    }
    return processos[indice].id_processo;
}

int contar_flag(Processo *processos, int n, const char *flag) {
    int cont = 0;

    if (strcmp(flag, "violencia_domestica") == 0) {
        for (int i = 0; i < n; i++) {
            if (processos[i].flag_violencia_domestica)
                cont++;
        }
    } else if (strcmp(flag, "feminicidio") == 0) {
        for (int i = 0; i < n; i++) {
            if (processos[i].flag_feminicidio)
                cont++;
        }
    }
     else if (strcmp(flag, "indigenas") == 0) {
        for (int i = 0; i < n; i++) {
            if (processos[i].flag_indigenas)
                cont++;
        }
    }
    else if (strcmp(flag, "infancia") == 0) {
        for (int i = 0; i < n; i++) {
            if (processos[i].flag_infancia)
                cont++;
        }
    }
    else if (strcmp(flag, "quilombolas") == 0) {
        for (int i = 0; i < n; i++) {
            if (processos[i].flag_quilombolas)
                cont++;
        }
    }
    else if (strcmp(flag, "ambiental") == 0) {
        for (int i = 0; i < n; i++) {
            if (processos[i].flag_ambiental)
                cont++;
        }
    }

    return cont;
}

int diferenca_dias(const char *data1, const char *data2){

    int dia1, mes1, ano1, dia2, mes2, ano2;
    sscanf(data1, "%d-%d-%d", &ano1, &mes1, &dia1);
    sscanf(data2, "%d-%d-%d", &ano2, &mes2, &dia2);
    int resultado = (ano2 - ano1) * 365 + (mes2 - mes1) * 30 + (dia2 - dia1);

    return resultado;
} 

float porcento_meta1(Processo *processos, int n){

    int cnm1 = 0, julgadom1 = 0, desm1 = 0, susm1 = 0;
        for(int i = 0; i < n; i++){
            cnm1 += processos[i].cnm1; 
            julgadom1 += processos[i].julgadom1;
            desm1 += processos[i].desm1;
            susm1 += processos[i].susm1;
        }

    if(julgadom1 == 0){
        return 0.00f;
    }

    float resultado = ((float)(cnm1 + desm1 - susm1) / julgadom1) * 100.0;
    
    return resultado; 
}

void gerar_csv(Processo *processos, int n, const char *gerar){

    FILE *fp = fopen(gerar, "w");
        if(fp == NULL){
            printf("!! ERRO: arquivo nao pode ser aberto !!\n");
            exit(1);
        }
    

    fprintf(fp, "id_processo; julgadom1\n");
    for(int i = 0; i < n; i++){
        if(processos[i].julgadom1 > 0){
            fprintf(fp, "%d; %d\n", processos[i].id_processo, processos[i].julgadom1);
        }
    }

    fclose(fp);
}