#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "processo.h"

int carregar_processos(const char *filename, Processo *processos, int max) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return -1;

    char buffer[1024];
    int count = 0;

    fgets(buffer, sizeof(buffer), fp); 

    while (fgets(buffer, sizeof(buffer), fp) && count < max) {
        Processo p;
        char *token = strtok(buffer, ";\n");

       
        if (!token) continue;
        p.id_processo = atoi(token);

        
        token = strtok(NULL, ";\n");
        if (!token) continue;
        strncpy(p.numero_sigilo, token, MAX_STR);

        token = strtok(NULL, ";\n");
        strncpy(p.sigla_grau, token ? token : "", MAX_STR);

        token = strtok(NULL, ";\n");
        strncpy(p.procedimento, token ? token : "", MAX_STR);

        token = strtok(NULL, ";\n");
        strncpy(p.ramo_justica, token ? token : "", MAX_STR);

        token = strtok(NULL, ";\n");
        strncpy(p.sigla_tribunal, token ? token : "", MAX_STR);

        token = strtok(NULL, ";\n");
        p.id_tribunal = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.recurso = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.id_ultimo_oj = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        strncpy(p.dt_recebimento, token ? token : "", MAX_STR);
        
        token = strtok(NULL, ";\n");
        p.id_ultima_classe = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.flag_violencia_domestica = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.flag_feminicidio = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.flag_ambiental = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.flag_quilombolas = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.flag_indigenas = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.flag_infancia = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.decisao = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        strncpy(p.dt_resolvido, token ? token : "", MAX_STR);

        token = strtok(NULL, ";\n");
        p.cnm1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.primeirasentm1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.baixm1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.decm1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.mpum1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.julgadom1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.desm1 = token ? atoi(token) : 0;

        token = strtok(NULL, ";\n");
        p.susm1 = token ? atoi(token) : 0;

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

    return cont;
}