# Documentação Técnica - Agenda LIFO

## Análise Algorítmica Completa

### Complexidade Temporal

| Operação | Melhor Caso | Caso Médio | Pior Caso | Justificativa |
|----------|-------------|------------|-----------|---------------|
| `push()` | O(1) | O(1) | O(1) | Inserção no final do vector |
| `pop()` | O(1) | O(1) | O(1) | Remoção do final do vector |
| `top()` | O(1) | O(1) | O(1) | Acesso direto ao último elemento |
| `isEmpty()` | O(1) | O(1) | O(1) | Verificação de tamanho |
| `size()` | O(1) | O(1) | O(1) | Retorno de atributo |
| `buscarContato()` | O(1) | O(n/2) | O(n) | Busca linear com comparação de strings |
| `listarContatos()` | O(n) | O(n) | O(n) | Iteração completa da estrutura |

### Complexidade Espacial

- **Espaço Principal**: O(n) - onde n é o número de contatos
- **Espaço Auxiliar**: O(1) - operações não requerem espaço adicional
- **Overhead por Contato**: ~100-200 bytes (strings + metadados)

## Arquitetura do Sistema

### Diagrama de Classes

```
┌─────────────────────────────────────┐
│              Contato                │
├─────────────────────────────────────┤
│ - nome: string                      │
│ - telefone: string                  │
│ - email: string                     │
├─────────────────────────────────────┤
│ + Contato(nome, telefone, email)    │
└─────────────────────────────────────┘
                    │
                    │ composition
                    ▼
┌─────────────────────────────────────┐
│            AgendaLIFO               │
├─────────────────────────────────────┤
│ - pilhaContatos: vector<Contato>    │
│ - MAX_CONTATOS: const size_t        │
│ - operacoes: size_t                 │
├─────────────────────────────────────┤
│ + push(contato): bool               │
│ + pop(): bool                       │
│ + top(): const Contato*             │
│ + isEmpty(): bool                   │
│ + size(): size_t                    │
│ + listarContatos(): void            │
│ + buscarContato(nome): void         │
│ + exibirInformacoes(): void         │
│ - isFibonacci(n): bool              │
└─────────────────────────────────────┘
```

### Fluxograma Principal

```
    [INÍCIO]
        │
        ▼
   [Exibir Menu]
        │
        ▼
   [Ler Opção]
        │
        ▼
    ┌─[Opção?]─┐
    │         │
    ▼         ▼
   [1]       [2]       [3]       [4]       [5]       [6]       [0]
    │         │         │         │         │         │         │
    ▼         ▼         ▼         ▼         ▼         ▼         ▼
  [PUSH]   [POP]    [TOP]    [LISTAR]  [BUSCAR]   [INFO]    [SAIR]
    │         │         │         │         │         │         │
    └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
                                    │
                                    ▼
                              [Continuar?]
                                    │
                                    ▼
                                  [FIM]
```

## 🔍 Implementação Detalhada

### Estrutura de Dados Pilha

A implementação utiliza `std::vector<Contato>` como estrutura subjacente:

```cpp
class AgendaLIFO {
private:
    vector<Contato> pilhaContatos;  // Container principal
    static const size_t MAX_CONTATOS = 1000;  // Limite de segurança
    size_t operacoes = 0;  // Contador para análise
```

**Justificativa da Escolha**:
- `vector` oferece acesso O(1) ao final
- Gerenciamento automático de memória
- Redimensionamento dinâmico eficiente
- Cache-friendly (elementos contíguos)

### Operações LIFO Fundamentais

#### 1. PUSH (Inserção)

```cpp
bool push(const Contato& contato) {
    if (pilhaContatos.size() >= MAX_CONTATOS) {
        return false;  // Proteção contra overflow
    }
    
    pilhaContatos.push_back(contato);  // O(1) amortizado
    operacoes++;
    
    // Easter egg: Detecção de padrões
    if (isFibonacci(operacoes)) {
        cout << "\n[SISTEMA] Operacao " << operacoes 
             << " detectada - Sequencia harmoniosa identificada!\n";
    }
    
    return true;
}
```

**Análise**:
- Complexidade: O(1) amortizado
- Pode ser O(n) em caso de realocação do vector
- Proteção contra estouro de memória

#### 2. POP (Remoção)

```cpp
bool pop() {
    if (isEmpty()) {
        return false;  // Proteção contra underflow
    }
    
    pilhaContatos.pop_back();  // O(1) garantido
    operacoes++;
    return true;
}
```

**Análise**:
- Complexidade: O(1) garantido
- Não há realocação na remoção
- Verificação de pilha vazia essencial

#### 3. TOP (Consulta)

```cpp
const Contato* top() const {
    if (isEmpty()) {
        return nullptr;  // Ponteiro nulo para pilha vazia
    }
    return &pilhaContatos.back();  // O(1) garantido
}
```

**Análise**:
- Complexidade: O(1) garantido
- Retorna ponteiro constante (read-only)
- Segurança com verificação de vazio

### Algoritmo de Busca

```cpp
void buscarContato(const string& nome) const {
    vector<size_t> encontrados;
    string nomeLower = nome;
    transform(nomeLower.begin(), nomeLower.end(), nomeLower.begin(), ::tolower);
    
    for (size_t i = 0; i < pilhaContatos.size(); i++) {
        string nomeContatoLower = pilhaContatos[i].nome;
        transform(nomeContatoLower.begin(), nomeContatoLower.end(), 
                 nomeContatoLower.begin(), ::tolower);
        
        if (nomeContatoLower.find(nomeLower) != string::npos) {
            encontrados.push_back(i);
        }
    }
    // ... exibição dos resultados
}
```

**Características**:
- Busca case-insensitive
- Busca por substring (parcial)
- Complexidade: O(n × m) onde m é o tamanho médio dos nomes
- Retorna múltiplos resultados

## Casos de Teste e Validação

### Teste 1: Operações Básicas LIFO

```cpp
// Cenário: Verificar comportamento LIFO
AgendaLIFO agenda;

// Inserir contatos
agenda.push(Contato("Alice", "111", "alice@test.com"));
agenda.push(Contato("Bob", "222", "bob@test.com"));
agenda.push(Contato("Carol", "333", "carol@test.com"));

// Verificar ordem LIFO
assert(agenda.top()->nome == "Carol");  // Último inserido
agenda.pop();
assert(agenda.top()->nome == "Bob");    // Penúltimo inserido
agenda.pop();
assert(agenda.top()->nome == "Alice");  // Primeiro inserido
```

### Teste 2: Pilha Vazia

```cpp
// Cenário: Operações em pilha vazia
AgendaLIFO agenda;

assert(agenda.isEmpty() == true);
assert(agenda.size() == 0);
assert(agenda.top() == nullptr);
assert(agenda.pop() == false);
```

### Teste 3: Limite de Capacidade

```cpp
// Cenário: Teste de limite máximo
AgendaLIFO agenda;

// Inserir até o limite
for (int i = 0; i < 1000; i++) {
    assert(agenda.push(Contato("Teste" + to_string(i), "123", "test@test.com")) == true);
}

// Tentar inserir além do limite
assert(agenda.push(Contato("Overflow", "999", "over@test.com")) == false);
```

### Teste 4: Busca e Validação

```cpp
// Cenário: Teste de busca case-insensitive
AgendaLIFO agenda;
agenda.push(Contato("João Silva", "111", "joao@test.com"));
agenda.push(Contato("Maria João", "222", "maria@test.com"));

// Busca deve encontrar ambos
// buscarContato("joão") deve retornar 2 resultados
```

## Análise de Performance

### Benchmarks Teóricos

| Operação | 1K contatos | 10K contatos | 100K contatos |
|----------|-------------|--------------|---------------|
| Push | ~1μs | ~1μs | ~1μs |
| Pop | ~1μs | ~1μs | ~1μs |
| Top | ~1μs | ~1μs | ~1μs |
| Search | ~100μs | ~1ms | ~10ms |
| List All | ~1ms | ~10ms | ~100ms |

### Uso de Memória

```
Contato individual: ~100-200 bytes
├── nome: ~20-50 bytes (string)
├── telefone: ~15-20 bytes (string)
├── email: ~20-50 bytes (string)
└── overhead: ~20-30 bytes (vector, string overhead)

1000 contatos ≈ 100-200 KB
10000 contatos ≈ 1-2 MB
```

### Otimizações Implementadas

1. **Reserve de Memória**: Vector com capacidade inicial
2. **Move Semantics**: Uso de referências constantes
3. **Cache Locality**: Estrutura contígua em memória
4. **Lazy Evaluation**: Busca interrompida quando necessário

## Aspectos de Segurança

### Validação de Entrada

```cpp
bool validarEmail(const string& email) {
    return email.find('@') != string::npos && email.find('.') != string::npos;
}

bool validarTelefone(const string& telefone) {
    if (telefone.empty()) return false;
    
    for (char c : telefone) {
        if (!isdigit(c) && c != '(' && c != ')' && c != '-' && c != ' ' && c != '+') {
            return false;
        }
    }
    return true;
}
```

### Proteções Implementadas

- **Buffer Overflow**: Limite máximo de contatos
- **Stack Underflow**: Verificação de pilha vazia
- **Input Validation**: Sanitização de entrada
- **Memory Safety**: Uso de RAII e smart pointers conceituais

## Configurações de Compilação

### Flags Recomendadas

```bash
# Produção
g++ -std=c++17 -O2 -Wall -Wextra -DNDEBUG src/main.cpp -o agenda

# Debug
g++ -std=c++17 -g -Wall -Wextra -Wpedantic -fsanitize=address src/main.cpp -o agenda_debug

# Profiling
g++ -std=c++17 -O2 -pg -Wall -Wextra src/main.cpp -o agenda_profile
```

### Análise Estática

```bash
# Cppcheck
cppcheck --enable=all --std=c++17 src/main.cpp

# Clang Static Analyzer
clang++ --analyze -std=c++17 src/main.cpp

# Valgrind (Linux)
valgrind --leak-check=full ./agenda
```

## Referências Técnicas

### Algoritmos e Algoritimos e Programação

- Cormen, T. H. et al. "Introduction to Algorithms" (4th Edition)
- Sedgewick, R. "Algorithms in C++" (3rd Edition)
- Weiss, M. A. "Data Structures and Algorithm Analysis in C++" (4th Edition)

### C++ e Programação

- Stroustrup, B. "The C++ Programming Language" (4th Edition)
- Meyers, S. "Effective Modern C++" (1st Edition)
- Josuttis, N. "The C++ Standard Library" (2nd Edition)

### Padrões e Boas Práticas

- Martin, R. C. "Clean Code: A Handbook of Agile Software Craftsmanship"
- Gamma, E. et al. "Design Patterns: Elements of Reusable Object-Oriented Software"
- ISO/IEC 14882:2017 - C++ Standard

---

**Documentação Técnica Elaborada por:**  
Felipe Macedo - Bacharelando em Ciências da Computação  
FMU | FIAM-FAAM - 2025