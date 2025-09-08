# Agenda de Contatos - Estrutura LIFO

![Language](https://img.shields.io/badge/Language-C++-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Academic](https://img.shields.io/badge/Project-Academic-orange)
![University](https://img.shields.io/badge/University-FMU-red)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen)

## Descrição

Este projeto implementa uma **Agenda de Contatos** utilizando a estrutura de dados **Pilha (Stack)** com comportamento **LIFO (Last In, First Out)**. Desenvolvido como projeto acadêmico para a disciplina de Algoritimo e Programação do curso de Bacharelado em Ciências da Computação da FMU | FIAM-FAAM.

## Objetivos Acadêmicos

- Implementar e compreender a estrutura de dados Pilha
- Aplicar conceitos de LIFO em um contexto prático
- Desenvolver habilidades em C++ e programação orientada a objetos
- Praticar documentação técnica e versionamento com Git

## Estrutura LIFO (Last In, First Out)

```
    TOPO DA PILHA
    ┌─────────────┐
    │  Contato 3  │ ← Último inserido (será o primeiro a sair)
    ├─────────────┤
    │  Contato 2  │
    ├─────────────┤
    │  Contato 1  │ ← Primeiro inserido (será o último a sair)
    └─────────────┘
    BASE DA PILHA
```

### Operações Principais

| Operação | Descrição | Complexidade |
|----------|-----------|--------------|
| **PUSH** | Insere contato no topo da pilha | O(1) |
| **POP** | Remove contato do topo da pilha | O(1) |
| **TOP** | Consulta contato no topo (sem remover) | O(1) |
| **SEARCH** | Busca contatos por nome | O(n) |

## Funcionalidades

-  **Inserção de Contatos (PUSH)**: Adiciona novos contatos no topo da pilha
-  **Remoção de Contatos (POP)**: Remove o último contato inserido
-  **Consulta do Topo (TOP)**: Visualiza o último contato sem removê-lo
-  **Listagem Completa**: Exibe todos os contatos da pilha (do topo para a base)
-  **Busca por Nome**: Localiza contatos através de busca parcial
-  **Informações da Pilha**: Estatísticas e estado atual da estrutura
-  **Validação de Dados**: Verificação de formato de email e telefone
-  **Interface Profissional**: Menu limpo e intuitivo

## Estrutura do Projeto

```
agenda-contatos-lifo/
├── src/
│   └── main.cpp                 # Código principal da aplicação
├── docs/
│   ├── README.md               # Documentação principal (este arquivo)
│   ├── INSTALACAO.md           # Guia de instalação detalhado
│   └── DOCUMENTACAO_TECNICA.md # Documentação técnica completa
├── .gitignore                  # Arquivos ignorados pelo Git
├── LICENSE                     # Licença MIT personalizada
├── Makefile                    # Arquivo de build multiplataforma
└── CHANGELOG.md                # Histórico de mudanças
```

## Instalação e Uso

### Pré-requisitos

- Compilador C++ (GCC 7.0+ ou equivalente)
- Make (opcional, para usar o Makefile)
- Git (para versionamento)

### Compilação Rápida

```bash
# Clone o repositório
git clone https://github.com/growthfolio/agenda-contatos-lifo.git
cd agenda-contatos-lifo

# Compile usando Make
make build

# Ou compile diretamente
g++ -std=c++17 -Wall -Wextra -O2 src/main.cpp -o agenda

# Execute o programa
./agenda
```

Para instruções detalhadas de instalação, consulte [INSTALACAO.md](docs/INSTALACAO.md).

## Exemplo de Uso

```cpp
// Exemplo de operações LIFO
AgendaLIFO agenda;

// PUSH - Inserir contatos
agenda.push(Contato("João Silva", "(11) 99999-9999", "joao@email.com"));
agenda.push(Contato("Maria Santos", "(11) 88888-8888", "maria@email.com"));

// TOP - Consultar último inserido
const Contato* ultimo = agenda.top(); // Retorna "Maria Santos"

// POP - Remover último inserido
agenda.pop(); // Remove "Maria Santos"

// Agora o topo é "João Silva"
```

## Análise de Complexidade

| Operação | Melhor Caso | Caso Médio | Pior Caso | Espaço |
|----------|-------------|------------|-----------|---------|
| Push | O(1) | O(1) | O(1) | O(1) |
| Pop | O(1) | O(1) | O(1) | O(1) |
| Top | O(1) | O(1) | O(1) | O(1) |
| Search | O(1) | O(n/2) | O(n) | O(1) |
| List All | O(n) | O(n) | O(n) | O(1) |

**Complexidade Espacial Total**: O(n), onde n é o número de contatos armazenados.

## Casos de Teste

O sistema foi testado com os seguintes cenários:

1. **Pilha Vazia**: Operações em pilha sem elementos
2. **Inserção Sequencial**: Múltiplas operações PUSH
3. **Remoção Sequencial**: Múltiplas operações POP
4. **Busca Eficiente**: Localização de contatos por nome
5. **Validação de Dados**: Entrada de dados inválidos
6. **Limite de Capacidade**: Teste com 1000+ contatos

## Tecnologias Utilizadas

- **Linguagem**: C++17
- **Paradigma**: Programação Orientada a Objetos
- **Estrutura de Dados**: Pilha (Stack) implementada com std::vector
- **Compilador**: GCC/Clang compatível
- **Versionamento**: Git
- **Documentação**: Markdown

## Conceitos Aplicados

- **Algoritimos e Programação**: Implementação prática de Pilha
- **LIFO**: Last In, First Out - conceito fundamental
- **Encapsulamento**: Classes e métodos privados/públicos
- **Validação de Entrada**: Verificação de dados do usuário
- **Tratamento de Erros**: Gestão de casos excepcionais
- **Complexidade Algorítmica**: Análise de performance

## Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

## Autor

**Felipe Macedo**
- Bacharelando em Ciências da Computação - FMU | FIAM-FAAM (2025-2029)
- Analista de Sistemas - Sansuy S.A.
- GitHub: [@felipemacedo1](https://github.com/felipemacedo1)
- LinkedIn: [Felipe Macedo](https://www.linkedin.com/in/felipemacedo1/)
- Especialidade: Full Stack Development (Go,Java, React, JavaFx & etc...), Cloud, DevOps, Explorando CyberSec

## Contexto Acadêmico

**Instituição**: FMU | FIAM-FAAM  
**Curso**: Bacharelado em Ciências da Computação  
**Disciplina**: Algoritimos e Programação
**Período**: 2025  
**Objetivo**: Aplicação prática de conceitos de Pilha (Stack) e LIFO

---

*"In code we trust, in algorithms we excel."*