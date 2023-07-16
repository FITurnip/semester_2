/* Deklarasi variabel global */
extern int indeks; // indeks karakter
extern char cc;    // karakter saat ini (current character)

/* Bagian memulai dan mengakhiri mesin karakter */
void START(char pita[]);
int EOP();

/* Bagian memajukan pita */
void INC(char pita[]); // memajukan satu karakter
void ADV(char pita[]); // maju hingga melewati spasi

/* Bagian mengambil atribut pita */
char GETCC();
int GETINDEX();