# Projeto de Análise de Dados Jurídicos - DataJUD

Este projeto foi desenvolvido como requisito parcial para aprovação no segundo semestre da disciplina **Estrutura de Dados**, no curso de **Ciência da Computação** da **Universidade Católica de Brasília (UCB)**. 


## Objetivo

O projeto tem como objetivo analisar e processar dados do **DataJUD**, o Sistema de Estatística do Poder Judiciário. A partir de um arquivo CSV contendo informações de processos do Tribunal de Justiça do Distrito Federal e Territórios (**TJDFT**), o programa implementa um Tipo Abstrato de Dados (TAD) denominado `Processo`, que permite a manipulação estruturada dos dados. 


## Funcionalidades

### O código-fonte é capaz de realizar as seguintes operações:

01. Contagem do número total de processos na base de dados;
02. Identificar o `id_ultimo_oj` a partir do `id_processo`;
03. Determinar o processo `id_processo` com a data de recebimento `dt_recebimento` mais antiga;
04. Contabilizar processos relacionados a:
- Violência doméstica;
- Feminicídio; 
- Causas ambientais;
- Comunidades quilombolas;
- Povos indígenas;
- Infância e juventude;
05. Calcular o número de dias entre `dt_recebimento` e `dt_resolvido`;
06. Calcular o percentual de cumprimento da meta 1; 
07. Gerar um arquivo CSV com todos os processos julgados (mérito) relacionados à **Meta 1**;


## Estrutura do Projeto
A solução está organizada em três arquivos principais, seguindo a estrutura padrão de projetos com TADs. O objetivo final é demonstrar habilidades em: 
- Manipulação de arquivos; 
- Implementação de estruturas de dados; 
- Desenvolvimento de funções para resolver problemas práticos de análise de dados.


## Como compilar e executar
```bash
gcc main.c processo.c -o programa
.\programa dados.csv