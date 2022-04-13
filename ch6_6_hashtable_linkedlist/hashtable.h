#define BASE 5

struct node {char *key; char *value; struct node *next;};

unsigned int hashit(char *);
int string_compare(char *, char *);
struct node *seek(char *, struct node **);
void set(char *, char *, struct node **);
void free_node(struct node *);
void initialize_table(struct node **);
void error(char *);
