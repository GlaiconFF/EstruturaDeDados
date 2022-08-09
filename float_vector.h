//ARQUIVO ESPECIFICACOES
typedef struct float_vector FloatVector;

FloatVector *create(int tam);
void destroy(FloatVector **ref_vector);
int size(const FloatVector *vector);
int capacity(const FloatVector *vector);
float at(const FloatVector *vector, int pos);
float get(const FloatVector *vector, int index);
void append(FloatVector *vector, float n);
void print(const FloatVector *vector);

//bool compare(FloatVector*, FloatVector*);
//void split(FloatVector*, FloatVector*);
//void join(FloatVector*, FloatVector*);
//bool isfull(FloatVector);
