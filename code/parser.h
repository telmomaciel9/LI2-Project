/**
 * @file parser.h 
 *
 * Ficheiro que contém as declarações das funções do ficheiro parser.c .
 */

#include "stack.h"
#include "variables.h"

/** 
 * \brief Esta é a função que vai fazer o parse de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void parse(char *line, STACK *s, VAR *v);

/** 
 * \brief Esta é a função que vai fazer as operações lógicas e de variáveis.
 * 
 * @param s Apontador para a stack.
 * @param v Apontador para VAR.
 * @param token Zona onde vão ser guardados os tokens. 
 */

void invocaLogica(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que vai fazer a leitura de uma linha.
 *
 * @param aux Cópia da line.
 * @param aux2 Zona onde vão ser guardados os tokens da linha que se vai ler.
 * @param s Apontador para a stack.
 * @param v Apontador para VAR.
 * @param token Zona onde vão ser guardados os tokens. 
 */

void lerlinha(char *aux2, STACK *s, char *token);

/** 
 * \brief Esta é a função que vai fazer a leitura de várias linhas.
 *
 * @param aux2 Zona onde vão ser guardados os tokens da linha que se vai ler.
 * @param s Apontador para a stack.
 * 
 */

//void lerlinhas(char *aux2, STACK *s);

/** 
 * \brief Esta é a função que imprime o topo da stack.
 *
 * @param s Apontador para a stack.
 * 
 */

//void imprimetopo(STACK *s);

/** 
 * \brief Esta é a função que vai duplicar uma string.
 * 
 * @param v String de origem.
 * 
 * @param s String para a qual vai ser copiada a original.
 *
 */

//void passData(char *v, char *s);

/** 
 * \brief Esta é a função que vai adicionar à stack o conteúdo de uma linha.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

//void parse2(char *line, STACK *s, VAR *v);

/** 
 * \brief Esta é a função que vai decidir o que fazer consoante o caratere que surge no input.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation(STACK *s, char *token, VAR *v);

/** 
 * \brief Esta é a função que vai decidir a operação a fazer.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation2(STACK *s, char *token, VAR *v);

/** 
 * \brief Esta é a função que vai decidir a operação a fazer.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation3(STACK *s, char *token);

/** 
 * \brief Esta é a função que vai converter tipos.
 * 
 * @param token O próximo caracter a analisar.
 * 
 * @param s Stack que vai ser usada ao longo do parse.
 *
 */

void operation4(STACK *s, char *token);

/** 
 * \brief Esta é a função que vai atribuir o valor pretendido a cada variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 * 
 * @param v Tipo de dados que engloba todas as variáveis.
 *
 * @param token O próximo caracter a analisar.
 */

void daVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que vai dar o valor default a cada variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 * 
 * @param v Tipo de dados que engloba todas as variáveis.
 *
 * @param token O próximo caracter a analisar.
 */

void variabLogica(STACK *s, char *token, VAR *v);

/** 
 * \brief Esta é a função que vai decidir a operação lógica a fazer.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void variabLogica2(STACK *s, char *token);

/** 
 * \brief Esta é a função que define as restantes operações lógicas.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void logica2(STACK *s, char *token);

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void auxdaVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux2daVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux3daVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux4daVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux5daVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que atribui um determinado valor a uma variável.
 * 
 * @param s Refere-se ao apontador para a stack.
 *
 * @param v Refere-se ao apontador para a stack.
 *
 * @param token O próximo caracter a analisar.
 */

void aux6daVariab(STACK *s, VAR *v, char *token);

/** 
 * \brief Esta é a função que vai obter o token através do input.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param rest aponta para uma string, que em si, é um apontador.
 *
 */

char *get_token(char *line, char **rest);

/** 
 * \brief Esta é a função que vai obter o token através do input.
 * 
 * @param line A linha que foi lida e ao qual se vai fazer o parse.
 * 
 * @param seps apontador para uma lista de caracteres.
 *
 * @param rest aponta para uma string, que em si, é um apontador.
 *
 */

char *get_delimited(char *line, char *seps, char **rest);
