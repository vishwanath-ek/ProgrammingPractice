#define SHARE_FILES_PATH "/home/vishwanath/Documents/"
#define NUM_OF_FILES 512

typedef struct {
    int size;
    char data[512]; 
}char_struct;

int say(int , const char *);
char_struct *accept_data(int);
void error( const char *);
void free_data_recv(void *);
char *get_full_path(char *, const char *);
int catch_signal(int, void (*)());
