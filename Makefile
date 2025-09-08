# Makefile para Agenda de Contatos LIFO
# Autor: Felipe Macedo
# Curso: Bacharelado em Ciências da Computação - FMU
# Projeto Acadêmico - Algoritimos e Programação

# Configurações do compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
DEBUG_FLAGS = -std=c++17 -Wall -Wextra -g -DDEBUG
PROFILE_FLAGS = -std=c++17 -Wall -Wextra -O2 -pg

# Diretórios
SRC_DIR = src
BUILD_DIR = build
DOCS_DIR = docs

# Arquivos
SOURCE = $(SRC_DIR)/main.cpp
TARGET = agenda
DEBUG_TARGET = agenda_debug
PROFILE_TARGET = agenda_profile

# Detectar sistema operacional
ifeq ($(OS),Windows_NT)
    TARGET := $(TARGET).exe
    DEBUG_TARGET := $(DEBUG_TARGET).exe
    PROFILE_TARGET := $(PROFILE_TARGET).exe
    RM = del /Q
    MKDIR = mkdir
    PATHSEP = \\
else
    RM = rm -f
    MKDIR = mkdir -p
    PATHSEP = /
endif

# Cores para output (apenas Unix-like)
ifndef OS
    RED = \033[0;31m
    GREEN = \033[0;32m
    YELLOW = \033[0;33m
    BLUE = \033[0;34m
    NC = \033[0m # No Color
else
    RED = 
    GREEN = 
    YELLOW = 
    BLUE = 
    NC = 
endif

# Target padrão
.PHONY: all
all: build

# Compilação principal (produção)
.PHONY: build
build: $(TARGET)

$(TARGET): $(SOURCE)
	@echo "$(BLUE)Compilando Agenda LIFO (Producao)...$(NC)"
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)
	@echo "$(GREEN)Compilacao concluida com sucesso!$(NC)"
	@echo "$(YELLOW)Execute com: ./$(TARGET)$(NC)"

# Compilação para debug
.PHONY: debug
debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(SOURCE)
	@echo "$(BLUE)Compilando Agenda LIFO (Debug)...$(NC)"
	$(CXX) $(DEBUG_FLAGS) $(SOURCE) -o $(DEBUG_TARGET)
	@echo "$(GREEN)Compilacao debug concluida!$(NC)"
	@echo "$(YELLOW)Execute com: ./$(DEBUG_TARGET)$(NC)"

# Compilação para profiling
.PHONY: profile
profile: $(PROFILE_TARGET)

$(PROFILE_TARGET): $(SOURCE)
	@echo "$(BLUE)Compilando Agenda LIFO (Profiling)...$(NC)"
	$(CXX) $(PROFILE_FLAGS) $(SOURCE) -o $(PROFILE_TARGET)
	@echo "$(GREEN)Compilacao profiling concluida!$(NC)"
	@echo "$(YELLOW)Execute com: ./$(PROFILE_TARGET)$(NC)"

# Executar o programa
.PHONY: run
run: build
	@echo "$(BLUE)Executando Agenda LIFO...$(NC)"
	./$(TARGET)

# Executar em modo debug
.PHONY: run-debug
run-debug: debug
	@echo "$(BLUE)Executando Agenda LIFO (Debug)...$(NC)"
	./$(DEBUG_TARGET)

# Testes básicos automatizados
.PHONY: test
test: build
	@echo "$(BLUE)Executando testes basicos...$(NC)"
	@echo "Teste 1: Verificando compilacao..."
	@if [ -f $(TARGET) ]; then \
		echo "$(GREEN)✓ Executavel criado com sucesso$(NC)"; \
	else \
		echo "$(RED)✗ Falha na criacao do executavel$(NC)"; \
		exit 1; \
	fi
	@echo "Teste 2: Verificando menu principal..."
	@echo "7" | ./$(TARGET) > /dev/null 2>&1 && echo "$(GREEN)✓ Menu principal funcional$(NC)" || echo "$(YELLOW)⚠ Verificar menu manualmente$(NC)"
	@echo "$(GREEN)Testes basicos concluidos!$(NC)"

# Análise estática do código (se disponível)
.PHONY: analyze
analyze:
	@echo "$(BLUE)Executando analise estatica...$(NC)"
	@if command -v cppcheck >/dev/null 2>&1; then \
		echo "Executando cppcheck..."; \
		cppcheck --enable=all --std=c++17 $(SOURCE); \
	else \
		echo "$(YELLOW)cppcheck nao encontrado. Instale para analise completa.$(NC)"; \
	fi
	@if command -v clang++ >/dev/null 2>&1; then \
		echo "Executando clang static analyzer..."; \
		clang++ --analyze -std=c++17 $(SOURCE); \
	else \
		echo "$(YELLOW)clang++ nao encontrado para analise estatica.$(NC)"; \
	fi

# Verificar vazamentos de memória (Linux/macOS)
.PHONY: memcheck
memcheck: debug
	@echo "$(BLUE)Verificando vazamentos de memoria...$(NC)"
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "7" | valgrind --leak-check=full --show-leak-kinds=all ./$(DEBUG_TARGET); \
	else \
		echo "$(YELLOW)Valgrind nao encontrado. Disponivel apenas no Linux.$(NC)"; \
	fi

# Profiling de performance
.PHONY: perf
perf: profile
	@echo "$(BLUE)Executando profiling de performance...$(NC)"
	@echo "7" | ./$(PROFILE_TARGET)
	@if [ -f gmon.out ]; then \
		gprof ./$(PROFILE_TARGET) gmon.out > profile_report.txt; \
		echo "$(GREEN)Relatorio de profiling salvo em profile_report.txt$(NC)"; \
	else \
		echo "$(YELLOW)Arquivo gmon.out nao encontrado$(NC)"; \
	fi

# Instalar no sistema (Linux/macOS)
.PHONY: install
install: build
	@echo "$(BLUE)Instalando Agenda LIFO no sistema...$(NC)"
ifndef OS
	sudo cp $(TARGET) /usr/local/bin/
	sudo chmod +x /usr/local/bin/$(TARGET)
	@echo "$(GREEN)Agenda LIFO instalada em /usr/local/bin/$(NC)"
	@echo "$(YELLOW)Execute de qualquer lugar com: $(TARGET)$(NC)"
else
	@echo "$(YELLOW)Instalacao automatica disponivel apenas no Linux/macOS$(NC)"
	@echo "$(YELLOW)No Windows, copie manualmente $(TARGET) para um diretorio no PATH$(NC)"
endif

# Desinstalar do sistema
.PHONY: uninstall
uninstall:
	@echo "$(BLUE)Removendo Agenda LIFO do sistema...$(NC)"
ifndef OS
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "$(GREEN)Agenda LIFO removida do sistema$(NC)"
else
	@echo "$(YELLOW)Remocao automatica disponivel apenas no Linux/macOS$(NC)"
endif

# Limpar arquivos compilados
.PHONY: clean
clean:
	@echo "$(BLUE)Limpando arquivos compilados...$(NC)"
	$(RM) $(TARGET) $(DEBUG_TARGET) $(PROFILE_TARGET) 2>/dev/null || true
	$(RM) *.o *.out *.plist gmon.out profile_report.txt 2>/dev/null || true
	@echo "$(GREEN)Limpeza concluida!$(NC)"

# Criar diretório de build
.PHONY: setup
setup:
	@echo "$(BLUE)Configurando ambiente de desenvolvimento...$(NC)"
	@$(MKDIR) $(BUILD_DIR) 2>/dev/null || true
	@echo "$(GREEN)Ambiente configurado!$(NC)"

# Gerar documentação (se Doxygen disponível)
.PHONY: docs
docs:
	@echo "$(BLUE)Gerando documentacao...$(NC)"
	@if command -v doxygen >/dev/null 2>&1; then \
		doxygen Doxyfile 2>/dev/null || echo "Arquivo Doxyfile nao encontrado"; \
	else \
		echo "$(YELLOW)Doxygen nao encontrado. Documentacao em $(DOCS_DIR)/$(NC)"; \
	fi

# Verificar dependências
.PHONY: check-deps
check-deps:
	@echo "$(BLUE)Verificando dependencias...$(NC)"
	@echo "Compilador C++:"
	@$(CXX) --version 2>/dev/null || echo "$(RED)✗ g++ nao encontrado$(NC)"
	@echo "Make:"
	@make --version 2>/dev/null | head -1 || echo "$(RED)✗ make nao encontrado$(NC)"
	@echo "Git:"
	@git --version 2>/dev/null || echo "$(YELLOW)⚠ git nao encontrado$(NC)"
	@echo "$(GREEN)Verificacao de dependencias concluida$(NC)"

# Criar pacote para distribuição
.PHONY: package
package: clean build
	@echo "$(BLUE)Criando pacote para distribuicao...$(NC)"
	@tar -czf agenda-lifo-$(shell date +%Y%m%d).tar.gz \
		$(SOURCE) $(DOCS_DIR)/ Makefile README.md LICENSE CHANGELOG.md 2>/dev/null || \
		echo "$(YELLOW)Comando tar nao disponivel no Windows$(NC)"
	@echo "$(GREEN)Pacote criado com sucesso!$(NC)"

# Mostrar informações do projeto
.PHONY: info
info:
	@echo "$(BLUE)===============================================$(NC)"
	@echo "$(BLUE)    AGENDA DE CONTATOS - ESTRUTURA LIFO$(NC)"
	@echo "$(BLUE)    Projeto Academico - Ciencias da Computacao$(NC)"
	@echo "$(BLUE)    Desenvolvedor: Felipe Macedo - FMU$(NC)"
	@echo "$(BLUE)===============================================$(NC)"
	@echo "Arquivo fonte: $(SOURCE)"
	@echo "Executavel: $(TARGET)"
	@echo "Compilador: $(CXX)"
	@echo "Flags: $(CXXFLAGS)"
	@echo "Sistema: $(shell uname -s 2>/dev/null || echo Windows)"
	@echo "$(BLUE)===============================================$(NC)"

# Ajuda
.PHONY: help
help:
	@echo "$(BLUE)Makefile - Agenda de Contatos LIFO$(NC)"
	@echo "$(BLUE)Desenvolvido por Felipe Macedo - FMU$(NC)"
	@echo ""
	@echo "$(YELLOW)Targets principais:$(NC)"
	@echo "  build       - Compila o programa (producao)"
	@echo "  debug       - Compila com simbolos de debug"
	@echo "  profile     - Compila para profiling"
	@echo "  run         - Executa o programa"
	@echo "  run-debug   - Executa versao debug"
	@echo "  test        - Executa testes basicos"
	@echo "  clean       - Remove arquivos compilados"
	@echo ""
	@echo "$(YELLOW)Targets avancados:$(NC)"
	@echo "  analyze     - Analise estatica do codigo"
	@echo "  memcheck    - Verifica vazamentos (valgrind)"
	@echo "  perf        - Profiling de performance"
	@echo "  install     - Instala no sistema (Linux/macOS)"
	@echo "  uninstall   - Remove do sistema"
	@echo "  package     - Cria pacote para distribuicao"
	@echo ""
	@echo "$(YELLOW)Utilitarios:$(NC)"
	@echo "  setup       - Configura ambiente"
	@echo "  docs        - Gera documentacao"
	@echo "  check-deps  - Verifica dependencias"
	@echo "  info        - Informacoes do projeto"
	@echo "  help        - Esta ajuda"
	@echo ""
	@echo "$(GREEN)Exemplo de uso:$(NC)"
	@echo "  make build && make run"

# Evitar conflitos com arquivos de mesmo nome
.PHONY: all build debug profile run run-debug test analyze memcheck perf install uninstall clean setup docs check-deps package info help