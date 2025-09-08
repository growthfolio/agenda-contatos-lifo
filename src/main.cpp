/**
 * @file main.cpp
 * @brief Implementação de Agenda de Contatos usando Estrutura LIFO (Pilha)
 * @author Felipe Macedo
 * @course Bacharelado em Ciências da Computação - FMU | FIAM-FAAM
 * @disciplina Estrutura de Dados | Algoritimos e Programação
 * @date 2025
 * @version 1.0
 * 
 * @description
 * Este programa implementa uma agenda de contatos utilizando a estrutura
 * de dados Pilha com comportamento LIFO (Last In, First Out).
 * 
 * Funcionalidades:
 * - PUSH: Inserção de contatos no topo da pilha
 * - POP: Remoção do contato do topo da pilha
 * - TOP: Consulta do contato no topo sem remoção
 * - Listagem completa dos contatos
 * - Busca de contatos por nome
 * - Informações sobre o estado da pilha
 * 
 * Complexidade Temporal: O(1) para PUSH, POP, TOP | O(n) para busca
 * Complexidade Espacial: O(n) onde n é o número de contatos
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

using namespace std;

/**
 * @struct Contato
 * @brief Estrutura que representa um contato na agenda
 */
struct Contato {
    string nome;
    string telefone;
    string email;
    
    Contato(const string& n, const string& t, const string& e) 
        : nome(n), telefone(t), email(e) {}
};

/**
 * @class AgendaLIFO
 * @brief Implementação de agenda usando pilha (LIFO)
 */
class AgendaLIFO {
private:
    vector<Contato> pilhaContatos;
    static const size_t MAX_CONTATOS = 1000;
    
    // Easter egg: Contador de operações para detectar padrões
    size_t operacoes = 0;
    
public:
    /**
     * @brief Adiciona contato no topo da pilha (PUSH)
     * @param contato Contato a ser adicionado
     * @return true se adicionado com sucesso, false caso contrário
     */
    bool push(const Contato& contato) {
        if (pilhaContatos.size() >= MAX_CONTATOS) {
            return false;
        }
        
        pilhaContatos.push_back(contato);
        operacoes++;
        
        // Easter egg: Sequência de Fibonacci nas operações
        if (isFibonacci(operacoes)) {
            cout << "\n[SISTEMA] Operacao " << operacoes 
                 << " detectada - Sequencia harmoniosa identificada!\n";
        }
        
        return true;
    }
    
    /**
     * @brief Remove contato do topo da pilha (POP)
     * @return true se removido com sucesso, false se pilha vazia
     */
    bool pop() {
        if (isEmpty()) {
            return false;
        }
        
        pilhaContatos.pop_back();
        operacoes++;
        return true;
    }
    
    /**
     * @brief Consulta contato no topo sem remover (TOP)
     * @return Ponteiro para o contato no topo ou nullptr se vazia
     */
    const Contato* top() const {
        if (isEmpty()) {
            return nullptr;
        }
        return &pilhaContatos.back();
    }
    
    /**
     * @brief Verifica se a pilha está vazia
     * @return true se vazia, false caso contrário
     */
    bool isEmpty() const {
        return pilhaContatos.empty();
    }
    
    /**
     * @brief Retorna o tamanho atual da pilha
     * @return Número de contatos na pilha
     */
    size_t size() const {
        return pilhaContatos.size();
    }
    
    /**
     * @brief Lista todos os contatos (do topo para a base)
     */
    void listarContatos() const {
        if (isEmpty()) {
            cout << "\nAgenda vazia - Nenhum contato encontrado.\n";
            return;
        }
        
        cout << "\n===============================================\n";
        cout << "           LISTAGEM DE CONTATOS (LIFO)\n";
        cout << "===============================================\n";
        
        for (int i = pilhaContatos.size() - 1; i >= 0; i--) {
            cout << "Posicao [" << (pilhaContatos.size() - i) << "] ";
            if (i == pilhaContatos.size() - 1) cout << "(TOPO)";
            cout << "\n";
            cout << "Nome: " << pilhaContatos[i].nome << "\n";
            cout << "Telefone: " << pilhaContatos[i].telefone << "\n";
            cout << "Email: " << pilhaContatos[i].email << "\n";
            cout << "-----------------------------------------------\n";
        }
    }
    
    /**
     * @brief Busca contatos por nome (busca parcial)
     * @param nome Nome ou parte do nome a buscar
     */
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
        
        if (encontrados.empty()) {
            cout << "\nNenhum contato encontrado com o nome: " << nome << "\n";
            return;
        }
        
        cout << "\n===============================================\n";
        cout << "         RESULTADOS DA BUSCA: " << encontrados.size() << " contato(s)\n";
        cout << "===============================================\n";
        
        for (size_t idx : encontrados) {
            size_t posicao = pilhaContatos.size() - idx;
            cout << "Posicao na pilha: [" << posicao << "]";
            if (idx == pilhaContatos.size() - 1) cout << " (TOPO)";
            cout << "\n";
            cout << "Nome: " << pilhaContatos[idx].nome << "\n";
            cout << "Telefone: " << pilhaContatos[idx].telefone << "\n";
            cout << "Email: " << pilhaContatos[idx].email << "\n";
            cout << "-----------------------------------------------\n";
        }
    }
    
    /**
     * @brief Exibe informações detalhadas sobre o estado da pilha
     */
    void exibirInformacoes() const {
        cout << "\n===============================================\n";
        cout << "           INFORMACOES DA PILHA\n";
        cout << "===============================================\n";
        cout << "Estrutura: LIFO (Last In, First Out)\n";
        cout << "Contatos armazenados: " << size() << "/" << MAX_CONTATOS << "\n";
        cout << "Status: " << (isEmpty() ? "VAZIA" : "ATIVA") << "\n";
        cout << "Memoria utilizada: ~" << (size() * sizeof(Contato)) << " bytes\n";
        cout << "Operacoes realizadas: " << operacoes << "\n";
        
        if (!isEmpty()) {
            cout << "Ultimo contato (TOPO): " << top()->nome << "\n";
        }
        
        // Easter egg: Análise de eficiência
        if (operacoes > 0) {
            double eficiencia = (double)size() / operacoes * 100;
            cout << "Eficiencia de retencao: " << eficiencia << "%\n";
            
            if (eficiencia > 80) {
                cout << "[ANALISE] Excelente gestao de contatos!\n";
            } else if (eficiencia < 30) {
                cout << "[ANALISE] Muitas operacoes de remocao detectadas.\n";
            }
        }
        
        cout << "===============================================\n";
    }

private:
    /**
     * @brief Easter egg: Verifica se um número pertence à sequência de Fibonacci
     * @param n Número a verificar
     * @return true se for um número de Fibonacci
     */
    bool isFibonacci(size_t n) const {
        if (n <= 1) return true;
        
        size_t a = 0, b = 1;
        while (b < n) {
            size_t temp = a + b;
            a = b;
            b = temp;
        }
        return b == n;
    }
};

/**
 * @brief Limpa o buffer de entrada
 */
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * @brief Valida formato de email básico
 * @param email Email a validar
 * @return true se formato válido
 */
bool validarEmail(const string& email) {
    return email.find('@') != string::npos && email.find('.') != string::npos;
}

/**
 * @brief Valida formato de telefone (apenas números e alguns caracteres)
 * @param telefone Telefone a validar
 * @return true se formato válido
 */
bool validarTelefone(const string& telefone) {
    if (telefone.empty()) return false;
    
    for (char c : telefone) {
        if (!isdigit(c) && c != '(' && c != ')' && c != '-' && c != ' ' && c != '+') {
            return false;
        }
    }
    return true;
}

/**
 * @brief Exibe o menu principal do sistema
 */
void exibirMenu() {
    cout << "\n===============================================\n";
    cout << "    AGENDA DE CONTATOS - ESTRUTURA LIFO\n";
    cout << "    Projeto Academico - Ciencias da Computacao\n";
    cout << "    Desenvolvedor: Felipe Macedo - FMU\n";
    cout << "===============================================\n\n";
    cout << "MENU PRINCIPAL:\n";
    cout << "[1] Adicionar contato (PUSH)\n";
    cout << "[2] Remover ultimo contato (POP)\n";
    cout << "[3] Consultar ultimo contato (TOP)\n";
    cout << "[4] Listar todos os contatos\n";
    cout << "[5] Buscar contato por nome\n";
    cout << "[6] Informacoes da pilha\n";
    cout << "[7] Sobre o sistema\n";  // Easter egg menu
    cout << "[0] Encerrar programa\n\n";
    cout << "Selecione uma opcao: ";
}

/**
 * @brief Easter egg: Exibe informações sobre o sistema e desenvolvedor
 */
void exibirSobre() {
    cout << "\n===============================================\n";
    cout << "              SOBRE O SISTEMA\n";
    cout << "===============================================\n";
    cout << "Sistema: Agenda LIFO v1.0\n";
    cout << "Algoritmo: Pilha (Stack) - Last In, First Out\n";
    cout << "Linguagem: C++ (ISO/IEC 14882)\n";
    cout << "Paradigma: Programacao Orientada a Objetos\n\n";
    cout << "Desenvolvedor: Felipe Macedo\n";
    cout << "Instituicao: FMU | FIAM-FAAM\n";
    cout << "Curso: Bacharelado em Ciencias da Computacao\n";
    cout << "GitHub: https://github.com/felipemacedo1\n";
    cout << "LinkedIn: https://www.linkedin.com/in/felipemacedo1/\n\n";
    cout << "\"In code we trust, in algorithms we excel.\"\n";
    cout << "===============================================\n";
}

/**
 * @brief Função principal do programa
 */
int main() {
    AgendaLIFO agenda;
    int opcao;
    
    // Easter egg: Seed para possíveis funcionalidades futuras
    srand(time(nullptr));
    
    cout << "Inicializando Agenda LIFO...\n";
    cout << "Sistema carregado com sucesso!\n";
    
    do {
        exibirMenu();
        
        if (!(cin >> opcao)) {
            cout << "\nERRO: Entrada invalida. Digite apenas numeros.\n";
            limparBuffer();
            continue;
        }
        
        limparBuffer();
        
        switch (opcao) {
            case 1: {
                cout << "\n--- ADICIONAR CONTATO (PUSH) ---\n";
                
                string nome, telefone, email;
                
                cout << "Nome completo: ";
                getline(cin, nome);
                
                if (nome.empty()) {
                    cout << "ERRO: Nome nao pode estar vazio.\n";
                    break;
                }
                
                cout << "Telefone: ";
                getline(cin, telefone);
                
                if (!validarTelefone(telefone)) {
                    cout << "AVISO: Formato de telefone pode estar incorreto.\n";
                }
                
                cout << "Email: ";
                getline(cin, email);
                
                if (!validarEmail(email)) {
                    cout << "AVISO: Formato de email pode estar incorreto.\n";
                }
                
                Contato novoContato(nome, telefone, email);
                
                if (agenda.push(novoContato)) {
                    cout << "\nSUCESSO: Contato adicionado ao topo da pilha.\n";
                } else {
                    cout << "\nERRO: Limite maximo de contatos atingido.\n";
                }
                break;
            }
            
            case 2: {
                cout << "\n--- REMOVER ULTIMO CONTATO (POP) ---\n";
                
                const Contato* topo = agenda.top();
                if (topo) {
                    cout << "Contato a ser removido: " << topo->nome << "\n";
                    cout << "Confirma remocao? (s/n): ";
                    
                    char confirmacao;
                    cin >> confirmacao;
                    limparBuffer();
                    
                    if (confirmacao == 's' || confirmacao == 'S') {
                        agenda.pop();
                        cout << "SUCESSO: Contato removido da pilha.\n";
                    } else {
                        cout << "Operacao cancelada.\n";
                    }
                } else {
                    cout << "ERRO: Pilha vazia - Nenhum contato para remover.\n";
                }
                break;
            }
            
            case 3: {
                cout << "\n--- CONSULTAR ULTIMO CONTATO (TOP) ---\n";
                
                const Contato* topo = agenda.top();
                if (topo) {
                    cout << "Contato no topo da pilha:\n";
                    cout << "Nome: " << topo->nome << "\n";
                    cout << "Telefone: " << topo->telefone << "\n";
                    cout << "Email: " << topo->email << "\n";
                } else {
                    cout << "Pilha vazia - Nenhum contato no topo.\n";
                }
                break;
            }
            
            case 4: {
                agenda.listarContatos();
                break;
            }
            
            case 5: {
                cout << "\n--- BUSCAR CONTATO ---\n";
                cout << "Digite o nome (ou parte do nome): ";
                
                string nomeBusca;
                getline(cin, nomeBusca);
                
                if (!nomeBusca.empty()) {
                    agenda.buscarContato(nomeBusca);
                } else {
                    cout << "ERRO: Nome de busca nao pode estar vazio.\n";
                }
                break;
            }
            
            case 6: {
                agenda.exibirInformacoes();
                break;
            }
            
            case 7: {
                exibirSobre();
                break;
            }
            
            case 0: {
                cout << "\nEncerrando sistema...\n";
                cout << "Agenda LIFO finalizada com sucesso.\n";
                cout << "Desenvolvido por Felipe Macedo - FMU\n";
                break;
            }
            
            default: {
                cout << "\nERRO: Opcao invalida. Selecione entre 0-7.\n";
                break;
            }
        }
        
        if (opcao != 0) {
            cout << "\nPressione ENTER para continuar...";
            cin.get();
        }
        
    } while (opcao != 0);
    
    return 0;
}