Sistema de Cadastro em C

Este projeto é um sistema de cadastro simples, desenvolvido em linguagem C, que permite registrar, listar e deletar pessoas de um array dinâmico.
O objetivo foi praticar manipulação de memória, ponteiros, estruturação de dados e operações básicas de CRUD em C.

#Sobre o projeto

Criei este sistema com a ideia de implementar um gerenciamento de cadastros utilizando malloc e realloc, garantindo que a estrutura possa crescer e reduzir conforme novos registros são adicionados ou removidos.

O programa funciona totalmente no terminal e oferece um menu interativo para facilitar o uso.

# Funcionalidades

 Adicionar cadastro
Registra nome, idade e CPF de uma pessoa.

 Listar cadastros
Exibe todos os registros armazenados dinamicamente.

 Deletar cadastro
Remove um cadastro pelo índice informado pelo usuário e realoca o array, ajustando sua capacidade.

 Sair
Finaliza o programa e libera toda a memória utilizada.

# Estrutura do código

struct Pessoa
Estrutura que guarda os dados básicos: nome, idade e CPF.

adicionarCadastro()
Realiza realocação de memória caso necessário e insere um novo registro no array.

listarCadastros()
Percorre o array e imprime todos os itens cadastrados.

deletarCadastro()
Remove um elemento e reorganiza o array, reduzindo capacidade quando possível.

main()
Controla o menu principal e gerencia as chamadas das funções.

# Tecnologias utilizadas

Linguagem C

Biblioteca padrão (stdio.h, stdlib.h, string.h)

Alocação dinâmica de memória (malloc, realloc, free)

# Como executar

Compile o código:

gcc main.c -o cadastro


Execute:

./cadastro

# Objetivo do desenvolvimento

Este código foi desenvolvido por mim com a intenção de:

Aprimorar lógica de programação em C

Praticar uso de structs e ponteiros

Trabalhar com realocação dinâmica de memória

Criar uma base para sistemas maiores no futuro

# Licença

Este projeto é livre para estudos e modificações.
