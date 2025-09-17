#include <stdio.h>
#include "processo.h"

#define MAX_PROCESSOS 1000

int main()
{
    Processo processos[MAX_PROCESSOS];
    int n = carregar_processos("TJDFT_amostra.csv", processos, MAX_PROCESSOS);

    if (n < 0)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Numero de processos: %d\n", contar_processos(processos, n));
    printf("id_ultimo_oj do processo 323961065: %d\n", obter_id_ultimo_oj(processos, n, 323961065));
    printf("Processo mais antigo: %d\n", obter_processo_mais_antigo(processos, n));
    printf("Processos de violencia domestica: %d\n", contar_flag(processos, n, "violencia_domestica"));
    printf("Processos de feminicidio: %d\n", contar_flag(processos, n, "feminicidio"));
    printf("Processos de indigenas: %d\n", contar_flag(processos, n, "indigenas"));
    printf("Processos ambientais %d\n", contar_flag(processos, n, "ambiental"));
    printf("Processos de quilombolas: %d\n", contar_flag(processos, n, "quilombolas"));
    printf("Processos de infancia e juventude: %d\n", contar_flag(processos, n, "infancia"));

    return 0;
}