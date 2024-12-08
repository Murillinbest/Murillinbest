# Sistema de Cadastro Dinâmico em C

Este projeto implementa um sistema básico de cadastro de pessoas em C utilizando alocação dinâmica de memória. O objetivo é permitir que o usuário insira, liste e remova cadastros de forma interativa.

## 🎯 Objetivo
Desenvolver um programa em C que utiliza **malloc**, **realloc** e **free** para gerenciar cadastros dinamicamente.

## 🛠️ Funcionalidades
- **Adicionar Cadastro**: Insira nome, idade e CPF de uma pessoa.
- **Listar Cadastros**: Exibe todos os cadastros armazenados.
- **Deletar Cadastro**: Remove um cadastro pelo índice.
- **Sair**: Encerra o programa liberando toda a memória.

## 📋 Estrutura de Dados
Cada cadastro armazena:
- **Nome**: String de até 50 caracteres.
- **Idade**: Inteiro.
- **CPF**: String de 11 caracteres.
