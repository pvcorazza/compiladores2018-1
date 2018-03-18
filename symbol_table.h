#include <stdlib.h>
#include <search.h>
#include <string.h>
#include <stdbool.h>

/*
 * Constante: DICT_SIZE, representa o tamanho de uma tabela de símbolos
 */
#define DICT_SIZE 10240

typedef struct table_entry {
	char *key;
	void *value;
	int linha;    //numero da linha da ultima ocorrencia do lexema
	int tipo; //tipo do token
  	struct table_entry *next;  // ponteiro de overflow
} table_entry_t;

typedef struct symbol_table {
	int size;
  	int occupation;
  	int first_declaration_hash;
  	table_entry_t **data;
  	struct symbol_table* next;
  	struct symbol_table* prev;

} symbol_table_t;

int generate_hash(char *key, int limit);



/*
 * Função: symbol_table_new, cria uma nova tabela de símbolos. Retorna um
 * ponteiro para a nova tabela de símbolos ou aborta a execução do
 * programa caso algum erro de alocação de memória tenha ocorrido.
 */
symbol_table_t *symbol_table_new(void);

/*
* Função  para incluir uma nova entrada na tabela de simbolos
*/
table_entry_t * add_symbol_table_entry(symbol_table_t * symbol_table, char *key, int linha);

/*
 * Função: dict_debug_print, usada somente para visualizar os
 * ponteiros do dict.
 */
void debug_print_symbol_table(symbol_table_t *symbol_table);
