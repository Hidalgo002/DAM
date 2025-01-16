#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITULO 80
#define MAX_AUTOR 50
#define MAX_DE_LIBROS_PERMITIDOS 100
int totalBooks = 40; //Variable global referenciada a lo largo del programa, nuestro array principal ocupaba 40 libros.

//ESTRUCTURA DE DATOS
    typedef enum{
    	FICTION, //0
    	NON_FICTION, //1
    	POETRY, //2
    	THEATER, //3
    	ESSAY //4
    } generos;

    typedef struct{
    	int id;
    	char titulo[MAX_TITULO];
    	char autor[MAX_AUTOR];
    	float precio;
    	generos genero;
    	int stock;
    } Book;

void inicializarLibro(Book * datos, int id, const char *  titulo, const char * autor, float precio, generos genero, int stock);

void imprimirLibro ( const Book * libro_a_imprimir);

void imprimirTodosLosLibros(const Book * catalogo, int totalBooks);

void anadirLibro(Book **catalogo, int *totalBooks);

void buscarID(const Book * catalogo, int totalBooks, int case2);

void modificar( Book * catalogo, int totalBooks, int encontrar_ID, int cantidad_nueva);

void buscar_Cat(const Book * catalogo, int totalBooks, char respuesta[20]);

void mostrar_Autor(Book * catalogo, int totalBooks, char * respuesta);



int main(int argc, char*argv[]){

    //argc-> CUENTA CON NÚMEROS el número de argumentos que metemos en el terminal.
    //char*argv [ ] →Puntero que apunta a donde empiezan mis argumentos
    printf("Lista de Argumentos: \n");
    
    for(int i = 0; i<argc; i++){
        printf("\t Argumento %d: %s\n",i+1, argv[i]);}
    //Bucle que  recorre todos los argumentos pasados al programa desde el terminal y los imprime en la consola. ARGC como he dicho antes, cuenta el número de comandos pasados por el terminal

//MIS LIBROS:
     Book * catalogo = (Book*) malloc(40*sizeof(Book)); //Los libros se almacenen en inicializar libro, que tiene una estructura para soportarlos. 
     //SINTAXIS-> Creamos un puntero que vaya de Book (NUESTRA ESTRUCTURA DE DATOS) a catálogo, QUE ES EL PUNTERO NUEVO. Catálogo almacena (Book*) es un CASTING, ¿qué quiere decir? pues malloc obligatoriamente es un VOID, pero nosotros estamos trabajando en un puntero BOOK, no un puntero int o char, en un BOOK. Por lo que hacemos un casting que lo que hace es modificar malloc para que todo este trabajando en el mismo modo  + malloc, reserva un espacio de memoria de 40 multiplicado por el sizeof un solo Book, CON TODOS SUS SECCIONES DE ID, PRECIO... 
     //RESULTADO DE ESTA OPERACIÓN-> BOOK apunta a un bloque de memoria (catálogo) que puede contener 40 elementos de tipo Book.

        inicializarLibro(&catalogo[0], 1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10);
        inicializarLibro(&catalogo[1], 2, "1984", "George Orwell", 12.49, FICTION, 5);
        inicializarLibro(&catalogo[2], 3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8);
        inicializarLibro(&catalogo[3], 4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12);
        inicializarLibro(&catalogo[4], 5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7);
        inicializarLibro(&catalogo[5], 6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9);
        inicializarLibro(&catalogo[6], 7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6);
        inicializarLibro(&catalogo[7], 8, "The Odyssey", "Homer", 17.49, FICTION, 4);
        inicializarLibro(&catalogo[8], 9, "Ulysses", "James Joyce", 25.00, FICTION, 2);
        inicializarLibro(&catalogo[9], 10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3);
        inicializarLibro(&catalogo[10], 11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11);
        inicializarLibro(&catalogo[11], 12, "The Iliad", "Homer", 18.50, FICTION, 7);
        inicializarLibro(&catalogo[12], 13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15);
        inicializarLibro(&catalogo[13], 14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20);
        inicializarLibro(&catalogo[14], 15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13);
        inicializarLibro(&catalogo[15], 16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6);
        inicializarLibro(&catalogo[16], 17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5);
        inicializarLibro(&catalogo[17], 18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8);
        inicializarLibro(&catalogo[18], 19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4);
        inicializarLibro(&catalogo[19], 20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14);
        inicializarLibro(&catalogo[20], 21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6);
        inicializarLibro(&catalogo[21], 22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8);
        inicializarLibro(&catalogo[22], 23, "Othello", "William Shakespeare", 10.99, THEATER, 7);
        inicializarLibro(&catalogo[23], 24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5);
        inicializarLibro(&catalogo[24], 25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4);
        inicializarLibro(&catalogo[25], 26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10);
        inicializarLibro(&catalogo[26], 27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9);
        inicializarLibro(&catalogo[27], 28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3);
        inicializarLibro(&catalogo[28], 29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15);
        inicializarLibro(&catalogo[29], 30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10);
        inicializarLibro(&catalogo[30], 31, "Paradise Lost", "John Milton", 12.00, POETRY, 7);
        inicializarLibro(&catalogo[31], 32, "Beowulf", "Anonymous", 15.00, POETRY, 5);
        inicializarLibro(&catalogo[32], 33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4);
        inicializarLibro(&catalogo[33], 34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9);
        inicializarLibro(&catalogo[34], 35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11);
        inicializarLibro(&catalogo[35], 36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8);
        inicializarLibro(&catalogo[36], 37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5);
        inicializarLibro(&catalogo[37], 38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12);
        inicializarLibro(&catalogo[38], 39, "The Republic", "Plato", 16.00, ESSAY, 6);
        inicializarLibro(&catalogo[39], 40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10);


/***************************************************************************/
/**************************** EL TERMINAL **********************************/
/***************************************************************************/


//PRIMER CASO: El programa tal cual. UN ARGUMENTO-> ./P6_biblio_mejorada_Valeria.out
    if (argc==1){
        printf("\033[34mUso de la línea de comandos:\033[0m\n");
            printf("\033[32m\tPara mostrar toda la biblioteca:\033[0m './P6_biblio_mejorada_Valeria.out mostrar'.\n");
            printf("\033[32m\tPara buscar un libro mediante su ID:\033[0m './P6_biblio_mejorada_Valeria.out mostrar [ID]'.\n");
            printf("\033[32m\tPara aumentar el stock de un libro en concreto:\033[0m './P6_biblio_mejorada_Valeria.out stock [ID] [Cantidad]'\n");
            printf("\033[32m\tPara mostrar todos los libros de una categoría:\033[0m './P6_biblio_mejorada_Valeria.out categoria [Categoria]'\n");
            printf("\033[33m\tLas opciones para categoria son: FICCIÓN, NO_FICCIÓN, POESÍA, TEATRO y ENSAYO.\033[0m\n");
            printf("\033[32m\tPara mostrar todos los libros de un autor en concreto:\033[0m './P6_biblio_mejorada_Valeria.out autor [nombre]'\n");
            printf("\033[32m\tPara añadir un libro nuevo:\033[0m './P6_biblio_mejorada_Valeria.out añadir'\n");

    }
//SEGUNDO CASO: DOS ARGUMENTOS -> ./P6_biblio_mejorada_Valeria.out motrar y ./P6_biblio_mejorada_Valeria.out añadir
    else if (argc==2){
        if(strcmp(argv[1], "mostrar")==0){
            imprimirTodosLosLibros (catalogo, totalBooks);
        }
        else if(strcmp(argv[1],"añadir") == 0){
			anadirLibro(&catalogo, &totalBooks);// Accedemos/llamamos a la dirección, paso por referencia. Por lo que la función puede modificar las variables originales.
        }
        else{printf("Introduzca un argumento válido.\n");}
 }

//TERCER CASO: TRES ARGUMENTOS -> ./P6_biblio_mejorada_Valeria.out mostrar [ID] y ./P6_biblio_mejorada_Valeria.out categoria [Category]
    else if (argc==3){
        if(strcmp(argv[1], "mostrar")==0){
            int id = atoi(argv[2]); //Usamos el atoi porque el terminal no interpreta números como tal, todo son cadenas de caracteres por lo que el ATOI nos permite transformar esa tercera cadena en un número que asignamos a nuestra variable 'int id'. Despés la comparamos.
                if (id > 0 && id<totalBooks) {
                    buscarID(catalogo, totalBooks, id);
                }
                else{printf("Por favor, introduzca un ID válido.\n");}
        }
       else if(strcmp(argv[1], "categoria")==0){
            char respuesta[20]; 
            strcpy (respuesta, argv[2]); //Copiamos lo que se ha escrito en el terminal y lo guardamos en respuesta2.
                /*if(respuesta!=FICCIÓN ||)
            buscar_Cat(catalogo, totalBooks, respuesta);

                else{printf("Introduzca una categoria válida.\n")}*/
        }
        else if(strcmp(argv[1], "autor")==0){
            char respuesta[MAX_AUTOR];
            strcpy (respuesta, argv[2]);
            respuesta[MAX_AUTOR-1]='\0';
            mostrar_Autor(catalogo, totalBooks, respuesta);
        }
        else{printf("Introduzca un argumento válido.\n");}
    }

//CUARTO CASO: CUATRO ARGUMENTOS -> ./P6_biblio_mejorada_Valeria.out stock [ID] [quant]
    else if (argc==4){
        if(strcmp(argv[1], "stock")==0){
            int encontrar_ID = atoi(argv[2]);
            int cantidad_nueva = atoi(argv[3]);
            modificar(catalogo, totalBooks, encontrar_ID, cantidad_nueva);
        }
        else{printf("Introduzca un argumento válido.\n");}
    }

//DEFAULT-> En el terminal se escribió ./P6_biblio_mejorada_Valeria.out + un caracter cualquiera.
    else{
      printf("ERROR.\n");  
    }


free (catalogo); //Liberamos el espacio que reservamos para Book * catalogo = (Book*) malloc(40*sizeof(Book)) -> Siendo catalogo el puntero central de la biblioteca. Como la biblioteca está fuera de los casos, lo he colocado aquí.

return 0;
}

//InicializarLibro
    void inicializarLibro(Book * datos, int id, const char *  titulo, const char * autor, float precio, generos genero, int stock){//Función para guardar el el primer malloc con una reserva de 40 espacios los libros que ya tenemos
        datos->id = id;
        strcpy(datos-> titulo, titulo);
        strcpy(datos-> autor, autor);
        datos->precio = precio;
        datos->genero = genero;
        datos->stock = stock; 
        //EXPLICACIÓN PUNTEROS:
        //En nuestra función 'inicializar libro', hemos creado un puntero llamado DATOS, donde generamos espacio para guardar en orden todos nuestros datos. En puntero datos -> espacio de precio, se pueden guardar el precio. Mas adelante, cuando llamamos a la función de forma individual, se guardan los datos de forma ordenada. En el caso de titulo y autor, tenemos que tener en cuenta los parametros de estos datos, son char y por ende necesitan ser guardados de forma especial, esto se hace con strcpy, que copia cadenas tal cual,  la sintaxis es strcpy COPIAR (en nuestro espacio desiganos DATOS->AUTOR , COPIAMOS la cadema almacenada en AUTOR).  
    }

//CASE 1 -> imprimirTodosLosLibros (catalogo, totalBooks);
    //PRINTF PARA LOS DATOS DEL LIBRO:
    void imprimirLibro ( const Book * libro_a_imprimir){
        printf("\t ID: %d \n"
                "\t Título: %s \n"
                "\t Autor: %s \n"
                "\t Precio: %.2f$ \n",
                libro_a_imprimir->id, 
                libro_a_imprimir->titulo, 
                libro_a_imprimir->autor, 
                libro_a_imprimir->precio);

        if(libro_a_imprimir->genero==0)
                {printf("\t Género: FICCIÓN \n");}
            else if(libro_a_imprimir->genero==1)
                {printf("\t Género: NO FICCIÓN \n");}
            else if(libro_a_imprimir->genero==2)
                {printf("\t Género: POESÍA \n");}
            else if(libro_a_imprimir->genero==3)
                {printf("\t Género: TEATRO \n");}
            else if(libro_a_imprimir->genero==4)
                {printf("\t Género: ENSAYO \n");}

        printf("\t Stock: %d \n", libro_a_imprimir->stock);

    }

    //BUCLE PARA RECORRER EL ARRAY E IMPRIMIR LOS DATOS DE LOS LIBROS-> Llamamos al void de imprimirlibro, nuestro bucle for recorre el array y se imprimen los datos ya que Book muestra los datos de los libros de forma individual
    void imprimirTodosLosLibros(const Book * catalogo, int totalBooks){
        printf("Lista de todos los libros:\n");
        for (int i = 0; i < 40; i++){
            printf("Libro %d: \n ", i+1);
            imprimirLibro(&catalogo[i]);}//Llama al void de imprimirLibro e imprime los datos
    }

//CASE 2-> añadirLibro (catalogo, totalBooks);
  void anadirLibro(Book **catalogo, int *totalBooks){
    /*Para seguir con lo visto en clase, para poder modificar el catálogo donde tenemos almacenados los libros, no solo basta con tener un puntero que apunte a catálogo, necesitamos un doble puntero. PORQUE NECESITAMOS MODIFICAR CATALOGO A TRAVES DE REFERENCIA.
    
    ¿Por qué no sirve utilizar un puntero simple?-> En este programa no solo queremos modificar los datos de catálogo, si no aumentar el espacio que ocupa en la memoria. Por lo que un puntero simple no sirve ya que solo nos permite hacer lo primero. El puntero doble nos permite modificar la dirección de catalogo también. Util para cuando usemos el realloc más adelante.

    int totalBooks se pasa como puntero para modificar el valor total de totalbooks, que era 40, cuando se ejecuta el programa, se aumenta su valor.*/

    Book nuevoLibro;

    /*Book a nuevoLibro es una variable local de esta función que almacena temporalmente los datos de nuestro nuevo libro. Todos los datos recogidos en el terminal son almacenados en nuevoLibro.[apartado de struct de Book]*/

    printf("Rellene los datos del nuevo libro:\n");

    printf("ID: ");
    int valor_retorno = scanf("%d", &nuevoLibro.id);
    /*if(valor_retorno == 0){
        printf("Introduzca un Id válido");
        printf("ID: ");
        scanf("%d", &nuevoLibro.id);
    }*/


    printf("TÍTULO: ");
    scanf(" %[^\n]", nuevoLibro.titulo);//[^\n]-> Sirve para leer cadenas con espacios, por ejemplo, aceptará el autor Hermann Hesse

    printf("AUTOR: ");
    scanf(" %[^\n]", nuevoLibro.autor);

    printf("PRECIO: ");
    scanf("%f", &nuevoLibro.precio);

    printf("GÉNERO (0: FICCIÓN, 1: NO_FICCIÓN, 2: POESÍA, 3: TEATRO, 4: ENSAYO): ");
    scanf("%d", (int *)&nuevoLibro.genero); //Necesitamos un Cast de tipo Int para guardar el número que nos da el usuario a través del terminal y poder almacenarlo. Más adelante, en la función imprimirLibro se vuelve a transformar en un 

    printf("CANTIDAD: ");
    scanf("%d", &nuevoLibro.stock);

    *catalogo = (Book *)realloc(*catalogo, (*totalBooks + 1) * sizeof(Book));
    /*Calculamos el espacio de nuestro nuevo Catalogo. 
    SINTAXIS->
        - *catalogo: apuntamos al inicio del catálogo actual (40libros). Como catalogo es un doble puntero (Book **catalogo), usamos *catalogo para referirnos a la memoria real que contiene los libros (40). Por lo que al asignarle un realloc, modificamos su tamaño 
        - (Book*): cast para que el realloc trabaje con datos tipo Book
        - realloc: reasignamos la memoria al tamaño de lo que está entre paréntesis a continuación
        -(*catalogo, (*totalBooks + 1) * sizeof(Book))-> pasamos el valor de catálogo, le sumamos el tamaño de totalBooks + 1(el libro nuevo) multiplicado por el tamaño de lo que ocupa un Book 
    */

    (*catalogo)[*totalBooks] = nuevoLibro;
    /*SINTAXIS->
        - (*catalogo) -> Como hemos visto antes, catalogo es un doble puntero (Book**Catalogo) Entoces es REFERNECIA de Book.
        - [*totalBooks] -> REFERENCIA donde se almacenan los libros
        - = nuevoLibro -> copia los datos del libro nuevo en su nueva posición 41
    */
    (*totalBooks)++;//Añadimos el libro aumentamos la varible de totalBooks

    printf("Libro nuevo agregado:\n");
    imprimirLibro(&(*catalogo)[*totalBooks - 1]);
    /*SINTAXIS->
        -(*catalogo)[*totalBooks - 1]-> Accede al LUGAR, LA DIRECCIÓN donde está almacenado el último libro añadido al catálogo (POR ESO ES IGUAL LA ASIGNACIÓN DE NUEVO LIBRO PERO ESTA VEZ EN LUGAR DE SUMAR, SE RESTA 1). Esto se hace usando el *totalBooks-1, igual que poner 41
    */
 }

//CASE 3 -> buscarID(catalogo, totalBooks);
    void buscarID(const Book * catalogo, int totalBooks, int case2){
        if(case2 < 0 || case2>=totalBooks){
            printf("ERROR.\n");}
        else{
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].id == case2){//Bucle que recorre el catálogo en el ID,
                    printf("Libro encontrado con el ID %d:\n", case2);
                    imprimirLibro(&catalogo[i]);
                    return;} //Una vez encuentra el libro, sale de este bucle.
                    }//Final del FOR
            printf("No se encontró el libro.\n");
        }//Final del else 
    }//Final del Void

//CASE 4 -> modificar(catalogo, totalBooks);
    void modificar( Book * catalogo, int totalBooks, int encontrar_ID, int cantidad_nueva){
         if(encontrar_ID < 0 || encontrar_ID>40){
            printf("ERROR.\n");}
        else{
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].id == encontrar_ID){//Bucle que recorre el catálogo en el ID,
                    printf("Libro encontrado con el ID %d:\n", encontrar_ID);
                    imprimirLibro(&catalogo[i]);
                    
                if (cantidad_nueva<0){
                    printf("La cantidad ha de ser positiva para poder modificar el stock. \n");
                }else{
                catalogo[i].stock = (cantidad_nueva + catalogo[i].stock);
                printf("Libro + Stock: \n");
                imprimirLibro(&catalogo[i]);}
                break;
            }
        } //Final de For
    }//Final de Else
    }//Final del Void

//CASE 5 -> buscar_Cat(books, totalBooks);
    void buscar_Cat(const Book * catalogo, int totalBooks, char respuesta[20]){
            int buscador_de_cat;
    //El siguiente bloque compara la respuesta con las categorías, dependiendo del resultado, se mete en un género u otro. Si está fuera de los parámetros de género (==!0), entonces nos saca. Si está dentro, entraremos en un bucle que solo imprimirá por pantalla los libros que pertenezcan a esa categoría.
        printf("Categoría %s:\n", respuesta); 

        if (strcmp(respuesta, "FICCIÓN") == 0){ //==0 -> Es verdadero o igual respuesta y mi valor
            buscador_de_cat = FICTION;} //Si la respuesta metida en el terminal por el usuario coincide, en la variable buscador_de_cat se guarda FICTION, después, en el bucle se imprime solo aquellos resultados que coincidan con FICTION.
        else if(strcmp(respuesta, "NO_FICCIÓN") == 0){
            buscador_de_cat = NON_FICTION;}  
        else if(strcmp(respuesta, "POESÍA") == 0){
            buscador_de_cat = POETRY;}
        else if(strcmp(respuesta, "TEATRO") == 0){
            buscador_de_cat = THEATER;}
        else if(strcmp(respuesta, "ENSAYO") == 0){
            buscador_de_cat = ESSAY;}
        else {
            printf("No existe esa categoría.\n");
        }
        for (int i = 0; i < totalBooks; i++){
                    if (catalogo[i].genero == buscador_de_cat){
                            printf("Libro: %d \n", i+1);
                            imprimirLibro(&catalogo[i]);}}
            

    }//Fin del VOID

//CASE 6 -> mostrar_Autor(books, totalBooks);
    void mostrar_Autor(Book * catalogo, int totalBooks, char * respuesta){
    for (int i = 0; i <totalBooks; i++, catalogo++) {
        if (strncmp(catalogo->autor, respuesta , MAX_AUTOR) == 0){
            printf("LIBRO: \n");
            imprimirLibro(catalogo);
        }
    }
 }
     /* SINTAXIS->
        - Creamos un void llamada mostrar_Autor, en ella, primero colomamos una serie de PARÁMETROS. 
            -PARAMETRO 1: puntero dirigido al primer elemento del catálogo de Book. Se pasa por REFERENCIA.
            -PARAMETRO 2: bajamos la variable global de totalBooks
            -PARAMETRO 3: creamos un puntero tipo cadena de caracteres para almacenar el nombre del autor

        - BUCLE FOR: 
            -catalogo++: Nos movemos entre los elementos del array. Como catalogo es un puntero a una estructura Book, al incrementarlo, apunta al siguiente libro en memoria.

        -IF:
            -strncmp(catalogo->autor: catalogo apunta a nuestro array de libros, por lo que con el operador '->' accedemos al apartado de autor.
            -respuesta: donde se almacena el nombre del autor, con strncmp y ==0, comparamos nuestra el nombre del autor que estamos buscando con todos los autores que tenemos almacenados  
            -MAX_AUTOR: cerramos que tantos carácteres es capaz de leer el programa.

        -Finalmente, si se encuentra el autor, se imprime el libro, que recapitulando, se imprime con catalogo.

     */
