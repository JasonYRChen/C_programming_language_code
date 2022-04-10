struct node {char *name; int count; struct node *left; struct node *right;};

char *copy_string(char *);
int compare_string(char *, char *);
struct node *create_node(char *, int, struct node *, struct node *);
void inorder_print(struct node *);
void free_postorderly(struct node *);
