# Projeto-APA

Projeto elaborado para a disciplina de Análise e Projeto de Algoritmos da UFPB.

## Descrição do Problema

Uma transportadora chamada Entrega Tudo entrou em contato com o seu grupo a fim de negociar uma consultoria. Essa empresa opera em toda a Paraíba e realiza um alto volume de entregas de produtos de grandes empresas do setor de e-commerce, como a Amazônia S.A. e Magazine Maria. Em uma primeira reunião, lhes foi explicado que a Entrega Tudo recebe diariamente demandas de diversas empresas e deve se planejar para realizar todas as entregas dentro do prazo estipulado. Visando elevar o n´nível de qualidade de serviço, todas as entregas devem ser realizadas no dia seguinte ao recebimento da demanda. Sendo assim, apesar de possuírem uma frota própria de veículos, existe a possibilidade de terceirizar parte das entregas para transportadoras menores de forma a garantir que toda a demanda será satisfeita. Atualmente, as rotas de entrega são criadas manualmente por um funcionário da empresa. Entretanto, devido ao rápido crescimento no volume de entregas, essa tarefa está ficando cada vez mais complexa e custosa. Sendo assim, a Entrega Tudo gostaria que vocês desenvolvessem um algoritmo capaz de gerar um plano de roteamento otimizado que vise reduzir ao máximo os custos para a empresa. Após a reunião, seu grupo se juntou para elaborar um esboço do projeto e formalizar o problema de otimização, de forma a descrever claramente todos os requisitos e objetivos. Vocês chegaram à conclusão de que, diariamente, a empresa deve resolver o seguinte problema:<br><br>
“Seja G = (V, A) um grafo orientado onde, V = {0, 1, . . ., n} é o conjunto de vértices, o vértice 0 representa o depósito, n é o número de clientes a serem atendidos, e A é o conjunto de arcos do grafo. Um arco (i, j) ∈ A representa o caminho que um veículo deve percorrer para ir do ponto i ao j, e o custo associado a tal arco é dado por cij . Cada cliente i possui uma demanda di de pacotes a serem entregues. A empresa possui uma frota com k veículos, todos do mesmo modelo e com capacidade Q. Todos os veículos devem iniciar e terminar suas rotas no depósito, a capacidade máxima deve ser respeitada e cada veículo utilizado incorre em um custo r para a empresa. Visto que existe a opção de terceirizar entregas, caso um cliente i não seja atendido por nenhum veículo, deve ser pago um valor pi para que a entrega seja realizada por outra empresa. A fim de garantir uma utilização mínima de sua frota e de seus funcionários, a empresa estabelece que ao menos L entregas devem ser realizas sem terceirização. O objetivo do problema ´e encontrar o conjunto de rotas que minimize a soma do custo de roteamento (custo dos arcos), do custo associado à utilização dos veículos e do total pago com a terceirização de entregas.”

## Etapas e Prazos

Este projeto contém os seguintes entregáveis:
1. Implementação de ao menos uma heurística de construção, que nada mais ´e do que um algoritmo guloso para a geração de uma solução viável.
2. Implementação de pelo menos 3 (três) estruturas de vizinhança, sendo que:
   - A primeira deve realizar movimentos envolvendo uma única rota;
   - A segunda deve realizar movimentos envolvendo múltiplas rotas;
   - A terceira deve ser capaz de lidar com entregas terceirizadas.
   - Observação: Todas as estruturas devem realizar uma busca exaustiva na vizinhança, o que significa que devem verificar todas as possíveis combinações.
3. Implementação do algoritmo de busca local VND (Variable Neighborhood Descent).
4. Implementação de uma meta-heurística (OPCIONAL). Sugestões: GRASP ou ILS.
5. Resultados computacionais: criar uma tabela que contenha os resultados obtidos pela(s) heurística(s) construtiva(s) e pelo VND, e que compare tais resultados com a solução ótima de cada instância. Essa tabela deverá conter os seguintes dados para cada heurística construtiva e para o VND:
   - Melhor solução encontrada; 
   - Média do tempo gasto pelo respectivo algoritmo; 
   - GAP para a solução ótima.
   - Caso exista algum fator aleatório no algoritmo, incluir a média do valor da solução, do tempo de execução e da métrica GAP de no mínimo 10 execuções para cada instância. Observação: Caso decida implementar a meta-heurística, é necessário adicionar uma coluna de resultados para ela na tabela. 
6. Todas as implementações devem vir acompanhadas de um arquivo makefile para a compilação. Tal arquivo deve ser preparado de forma a funcionar em sistemas UNIX.
7. Criar uma pasta contendo os arquivos de saída gerados durante os testes com cada instância. Favor incluir somente os resultados dos testes finais, com a versão a ser entregue. IMPORTANTE: O projeto deve ser entregue até às 23:59 do dia 29 de outubro de 2023 (Não haverá adiamento do prazo de entrega). Devem ser enviados via SIGAA, em um arquivo compactado, o código-fonte do projeto, o arquivo makefile, os arquivos de saída contendo as soluções encontradas, e um relatório em pdf contendo o nome dos integrantes do grupo e a tabela de resultados computacionais. Note que é necessário somente uma entrega por grupo e não serão aceitos envios por e-mail ou fora do prazo.
