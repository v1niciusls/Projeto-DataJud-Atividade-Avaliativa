#include <stdio.h>
#include "processo.h"

#define MAX_PROCESSOS 1000

int main()
{
    Processo processos[MAX_PROCESSOS];
    int n = carregar_processos("TJDFT_amostra.csv", processos, MAX_PROCESSOS);

    if (n < 0)
    {
        printf("!! Erro ao abrir o arquivo. !!\n");
        return 1;
    }

    printf("\n========== RESUMO GERAL \n");
    printf("-----------------------------------------------------------\n");
    printf("- Numero de processos: %d\n", contar_processos(processos, n));
    printf("- id_ultimo_oj do processo [323961065]: %d\n", obter_id_ultimo_oj(processos, n, 323961065));
    printf("- Processo mais antigo: [%d]\n\n\n", obter_processo_mais_antigo(processos, n));
    printf("========== CONTAGEM DE PROCESSOS POR TIPO \n");
    printf("-----------------------------------------------------------\n");
    printf("- Processos de violencia domestica: %d\n", contar_flag(processos, n, "violencia_domestica"));
    printf("- Processos de feminicidio: %d\n", contar_flag(processos, n, "feminicidio"));
    printf("- Processos de indigenas: %d\n", contar_flag(processos, n, "indigenas"));
    printf("- Processos ambientais: %d\n", contar_flag(processos, n, "ambiental"));
    printf("- Processos de quilombolas: %d\n", contar_flag(processos, n, "quilombolas"));
    printf("- Processos de infancia e juventude: %d\n\n\n", contar_flag(processos, n, "infancia"));
    
    int ind = 0;
    if(processos[ind].dt_resolvido[0] != '\0'){
        int diferenca = diferenca_dias(processos[ind].dt_recebimento, processos[ind].dt_resolvido);
        printf("========== TEMPO \n");
        printf("-----------------------------------------------------------\n");
        printf("- O processo [%d] levou %d dias para ser resolvido!\n\n\n", processos[ind].id_processo, diferenca);
    } else {
        printf("========== TEMPO \n");
        printf("-----------------------------------------------------------\n");
        printf("- O processo [%d] nao possui data de resolucao!\n\n\n", processos[ind].id_processo); 
    }

    printf("========== META 1\n");
    printf("-----------------------------------------------------------\n");
    printf("- Cumprimento da meta 1 --> %.2f%%\n\n\n", porcento_meta1(processos, n));
    
    gerar_csv(processos, n, "meta1_julgados.csv");
    printf("-----------------------------------------------------------\n");
    printf("**Arquivo 'meta1_julgados.csv' atualizado com sucesso! \n"); 
    printf("-----------------------------------------------------------\n\n");
    
    return 0;
}