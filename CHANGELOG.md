# Changelog - Agenda de Contatos LIFO

Todas as mudanças notáveis neste projeto serão documentadas neste arquivo.

O formato é baseado em [Keep a Changelog](https://keepachangelog.com/pt-BR/1.0.0/),
e este projeto adere ao [Semantic Versioning](https://semver.org/lang/pt-BR/).

## [1.0.0] - 2025-01-09

### Lançamento Inicial

Primeira versão completa da Agenda de Contatos implementando estrutura de dados Pilha (LIFO).

### Funcionalidades Adicionadas

#### Core Features
- **Estrutura LIFO**: Implementação completa de pilha usando `std::vector<Contato>`
- **Operações Fundamentais**:
  - `PUSH`: Inserção de contatos no topo da pilha - O(1)
  - `POP`: Remoção do contato do topo - O(1)
  - `TOP`: Consulta do topo sem remoção - O(1)
- **Gestão de Contatos**:
  - Armazenamento de nome, telefone e email
  - Validação básica de formato de email e telefone
  - Limite de segurança de 1000 contatos

#### Interface e Usabilidade
- **Menu Profissional**: Interface textual limpa sem emojis/ícones
- **Navegação Intuitiva**: Sistema de menus numerados (0-7)
- **Feedback Claro**: Mensagens de sucesso, erro e aviso
- **Confirmação de Ações**: Confirmação para operações destrutivas

#### Funcionalidades Avançadas
- **Busca Inteligente**: 
  - Busca case-insensitive por nome
  - Suporte a busca parcial (substring)
  - Múltiplos resultados
- **Listagem Completa**: Exibição ordenada do topo para a base
- **Informações da Pilha**: Estatísticas detalhadas e análise de uso
- **Validação Robusta**: Tratamento de entrada inválida e casos extremos

#### Easter Eggs e Funcionalidades Especiais
- **Detecção de Fibonacci**: Identifica operações em números de Fibonacci
- **Análise de Eficiência**: Calcula taxa de retenção de contatos
- **Menu "Sobre"**: Informações detalhadas do sistema e desenvolvedor
- **Contador de Operações**: Tracking para análise de padrões de uso

### Aspectos Técnicos

#### Arquitetura
- **Linguagem**: C++17 com STL
- **Paradigma**: Programação Orientada a Objetos
- **Estrutura**: Classe `AgendaLIFO` encapsulando `vector<Contato>`
- **Complexidade**: O(1) para operações principais, O(n) para busca

#### Qualidade de Código
- **Documentação**: Headers completos com Doxygen-style
- **Tratamento de Erros**: Verificações de overflow/underflow
- **Memory Safety**: Uso de RAII e gerenciamento automático
- **Code Style**: Convenções consistentes e comentários em português

#### Build System
- **Makefile Multiplataforma**: Suporte Windows, Linux, macOS
- **Targets Múltiplos**: build, debug, profile, test, analyze
- **Flags Otimizadas**: Compilação com `-O2 -Wall -Wextra`
- **Análise Estática**: Integração com cppcheck e clang analyzer

### Documentação

#### Documentação Completa
- **README.md**: Documentação principal com badges e exemplos
- **INSTALACAO.md**: Guia detalhado para múltiplas plataformas
- **DOCUMENTACAO_TECNICA.md**: Análise algorítmica e benchmarks
- **Comentários Inline**: Documentação completa no código fonte

#### Recursos Educacionais
- **Diagramas ASCII**: Visualização da estrutura LIFO
- **Análise de Complexidade**: Tabelas detalhadas de performance
- **Casos de Teste**: Cenários de validação documentados
- **Exemplos Práticos**: Código de exemplo e uso

### Ferramentas e Configuração

#### Desenvolvimento
- **Git**: Configuração completa com .gitignore profissional
- **Makefile**: Automação de build com 15+ targets
- **Licença MIT**: Licença personalizada com contexto acadêmico
- **Changelog**: Documentação de versões (este arquivo)

#### Qualidade e Testes
- **Validação de Entrada**: Sanitização e verificação de dados
- **Testes Automatizados**: Suite básica via Makefile
- **Análise de Memória**: Suporte a Valgrind e sanitizers
- **Profiling**: Integração com gprof para análise de performance

### Destaques Técnicos

#### Inovações Implementadas
- **Efficiency Analysis**: Métricas de uso em tempo real
- **Cross-Platform**: Compatibilidade total Windows/Linux/macOS

#### Boas Práticas Aplicadas
- **Clean Code**: Código legível e bem estruturado
- **SOLID Principles**: Aplicação de princípios de design
- **Documentation First**: Documentação como cidadão de primeira classe

### Desenvolvedor

**Felipe Macedo**
-  **Formação**: Formado em Gestão da Tecnologia da Informação - UAM | (2022-2025) & Bacharelando em Ciências da Computação - FMU | FIAM-FAAM (2025-2029)
-  **Profissão**: Analista de Sistemas - Sansuy S.A.
-  **GitHub**: [@felipemacedo1](https://github.com/felipemacedo1)
-  **LinkedIn**: [Felipe Macedo](https://www.linkedin.com/in/felipemacedo1/)
-  **Especialidades**: Full Stack Development (Go,Java, React, JavaFx & etc...), Cloud, DevOps, Explorando CyberSec

*Este changelog é mantido de forma automatizada e segue as melhores práticas de documentação de software.*

**Projeto Acadêmico - FMU | FIAM-FAAM**  
**Desenvolvido por Felipe Macedo - 2025**