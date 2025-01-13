#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITULO 80
#define MAX_AUTOR 50
#define MAX_DE_LIBROS_PERMITIDOS 100

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

//InicializarLibro
    void inicializarLibro(Book * datos, int id, const char *  titulo, const char * autor, float precio, generos genero, int stock){//Función para guardar el el primer malloc con una reserva de 40 espacios los libros que ya tenemos
        datos->id = id;
        strcpy(datos-> titulo, titulo);
        strcpy(datos-> autor, autor);
        datos->precio = precio;
        datos->genero = genero;
        datos->stock = stock; 
        //En nuestra función 'inicializar libro', hemos creado un puntero llamado DATOS, donde generamos espacios para guardar en orden todos nuestros datos. En puntero datos -> espacio de precio, se pueden guardar el precio. Mas adelante, cuando llamamos a la función de forma individual, se guardan los datos de forma ordenada. En el caso de titulo y autor, tenemos que tener en cuenta los parametros de estos datos, son char y por ende necesitan ser guardados de forma especial, esto se hace con strcpy, que copia cadenas tal cual,  la sintaxis es strcpy COPIAR (en nuestro espacio desiganos DATOS->AUTOR , COPIAMOS la cadema almacenada en AUTOR).  
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
    Book * anadirLibro(Book * catalogo2, const int newBook){
        int id;
        char titulo[MAX_TITULO];
        char autor[MAX_AUTOR];
        float precio;
        generos genero;
        int stock;
	
	Book * Library = (Book *)realloc(catalogo2, (totalBooks + newBook) * sizeof(Book));
	
	for(int i = totalBooks; i < totalBooks + newBook; i++){
		printf("Rellene los datos del nuevo libro: \n");
        printf("\t ID: \n");
		scanf("%d", &id);
		printf("\t TÍTULO: \n");
		scanf("%s", titulo);
		printf("\t AUTOR: \n");
		scanf("%s", autor);
		printf("\t PRECIO: \n");
		scanf("%f", &precio);
		printf("\t GENERO: \n");
		scanf("%u", &genero);
		printf("\t CANTIDAD: \n");
		scanf("%d", &stock);
		
		InicializarLibro(&Library[i], id, titulo, autor, precio, genero, stock);
		
		printf("Has añadido el siguiente libro:\n");
		ImprimirLibro(&Library[i++]);

	}

	totalBooks += newBook;	

	return &Library[0];
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
        else if(strcmp(respuesta, "FICCIÓN") || strcmp(respuesta, "NO_FICCIÓN") || strcmp(respuesta, "POESÍA") || strcmp(respuesta, "TEATRO") || strcmp(respuesta, "ENSAYO") != 0){
            printf("No existe esa categoría.\n");}
        for (int i = 0; i < totalBooks; i++){
                    if (catalogo[i].genero == buscador_de_cat){
                            printf("Libro: %d \n", i+1);
                            imprimirLibro(&catalogo[i]);}}
            

    }//Fin del VOID

//CASE 6 -> mostrar_Autor(books, totalBooks);
    /*for (int i = 0; i < catalogo[MAX_DE_LIBROS_PERMITIDOS].autor; i++){
        catalogo[i].autor =
        i++
        strcmp(autor[i].autor+j, autor a encontrar )//compara todo
        strncmp(str1, str2, nº)//Compara la primera cadena con la segunda y el nº se saca con strlen(auntor a encontar)*/

/***************************************************************************/
/******************************* EL MAIN ***********************************/
/***************************************************************************/


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

    int totalBooks = 40; //Se deja porque lo hemos estado usando hasta ahora. Simplemente marca que tenemos estos libros de inicio. 
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


//PRIMER CASO: El programa tal cual. UN ARGUMENTO-> ./practica6.2.0.out
    if (argc==1){
        printf("Uso de la línea de comandos: \n" 
                "\t Para mostrar toda la biblioteca: './practica6.2.0.out mostrar'.\n"
                "\t Para buscar un libro mediante su ID: './practica6.2.0.out mostrar [ID]'.\n"
                "\t Para aumentar el stock de un libro en concreto: './practica6.2.0.out stock [ID] [Cantidad]'\n"
                "\t Para mostrar todos los libros de una categoría: './practica6.2.0.out categoria [Categoria]' \n"
                "\t Para mostrar todos los libros de un autor en concreto: './practica6.2.0.out autor [nombre]'\n"
                "\t Para añadir un libro nuevo: './practica6.2.0.out añadir'\n");

    }//Cerramos el primer if (argc==1)

//SEGUNDO CASO: DOS ARGUMENTOS -> ./practica6.2.0.out motrar y ./practica6.2.0.out añadir
    else if (argc==2){
        if(strcmp(argv[1], "mostrar")==0){
            imprimirTodosLosLibros (catalogo, totalBooks);
        }
        else if(strcmp(argv[1],"añadir") == 0){
			catalogo = anadirLibro(&catalogo[0], 1);
    }

//TERCER CASO: TRES ARGUMENTOS -> ./practica6.2.0.out mostrar [ID] y ./practica6.2.0.out categoria [Category]
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
            buscar_Cat(catalogo, totalBooks, respuesta);
        }
    }

//CUARTO CASO: CUATRO ARGUMENTOS -> ./practica6.2.0.out stock [ID] [quant]
    else if (argc==4){
        if(strcmp(argv[1], "stock")==0){
            int encontrar_ID = atoi(argv[2]);
            int cantidad_nueva = atoi(argv[3]);
            modificar(catalogo, totalBooks, encontrar_ID, cantidad_nueva);
        }
    }

//QUINTO CASO: SIETE ARGUMENTOS-> ./practica6.2.0.out añadir [ID][NOMBRE][AUTOR][PRECIO][GENERO][STOCK]
//DEFAULT-> En el terminal se escribió ./practica6.2.0.out + una caracter cualquiera.
    else{
      printf("ERROR.\n");  
    }


free (catalogo); //Liberamos el espacio que reservamos para Book * catalogo = (Book*) malloc(40*sizeof(Book)) -> Siendo catalogo el puntero central de la biblioteca. Como la biblioteca está fuera de los casos, lo he colocado aquí.

return 0;
}