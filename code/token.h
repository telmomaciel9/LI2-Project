char * get_token(char *line, char **rest);
char *get_delimited(char *line, char *seps, char **rest);
STACK *eval (char* line, STACK *init_stack);