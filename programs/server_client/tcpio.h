#define SHARE_FILES_PATH "/home/vishwanath/Documents/"

typedef struct {
    int size;
    char data[512]; 
}char_struct;

int say(int , const char *);
char_struct *accept_data(int);
void error( const char *);
void free_data_recv(void *);
int catch_signal(int, void (*)());
