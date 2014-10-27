typedef struct {
    int size;
    char data[512]; 
}char_struct;

int say(int , const char *);
char_struct *accept_data(int);
void error( const char *);

