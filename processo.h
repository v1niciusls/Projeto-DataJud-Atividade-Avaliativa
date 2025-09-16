#ifndef PROCESSO_H
#define PROCESSO_H

#define MAX_STR 128

typedef struct {
    int id_processo;
    char numero_sigilo[MAX_STR];
    char sigla_grau[MAX_STR];
    char procedimento[MAX_STR];
    char ramo_justica[MAX_STR];
    char sigla_tribunal[MAX_STR];
    int id_tribunal;
    int recurso;
    int id_ultimo_oj;
    char dt_recebimento[MAX_STR];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    int decisao;
    char dt_resolvido[MAX_STR];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
} Processo;

int carregar_processos(const char *filename, Processo *processos, int max);
int contar_processos(Processo *processos, int n);
int obter_id_ultimo_oj(Processo *processos, int n, int id_processo);
int obter_processo_mais_antigo(Processo *processos, int n);
int contar_flag(Processo *processos, int n, const char *flag);

#endif