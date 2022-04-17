#define MAX_THREADS 4

typedef struct {
  char *raw_line;
  char *compressed_line;
  char *file_name;
} Compressor;

Compressor *Compressor__init(char *file_name);

void Compressor__read(Compressor *self);

void Compressor__compress(Compressor *self);

void Compressor__printer(Compressor *self);

