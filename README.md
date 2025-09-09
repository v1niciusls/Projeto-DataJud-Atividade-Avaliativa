Projeto de Análise de Dados Jurídicos do DataJUD
Este projeto, desenvolvido como parte da disciplina de Estrutura de dados da Universidade Católica de Brasília (UCB), tem como objetivo analisar e processar dados do DataJUD, o Sistema de Estatística do Poder Judiciário.

A partir de um arquivo CSV contendo informações de processos do Tribunal de Justiça do Distrito Federal e Territórios (TJDFT), o programa implementa um Tipo Abstrato de Dados (TAD) "Processo" para manipular os dados de forma estruturada.

O código-fonte é capaz de:

1. o número de processos presentes na base de dados;
2. o id_ultimo_oj a partir de id_processo;
3. o id_processo do processo com dt_recebimento mais antigo;
4. quantos processos estão relacionadas a causas de violência doméstica;
5. quantos processos estão relacionadas a causas de feminicídio;
6. quantos processos estão relacionadas a causas ambientais;
7. quantos processos estão relacionadas a causas de quilombolas;
8. quantos processos estão relacionadas a causas indígenas;
9. quantos processos envolve causas relacionadas a infância e juventude;
10. o número de dias entre dt_recebimento e dt_resolvido;
11. o percentual de cumprimento da meta 1; e
12. gerar um arquivo CSV com todos os processos julgados (mérito) na Meta 1

A solução é organizada em três arquivos, seguindo a estrutura padrão de projetos com TADs. O objetivo final é demonstrar habilidades em manipulação de arquivos, estruturas de dados e implementação de funções para resolver problemas práticos de análise de dados.
