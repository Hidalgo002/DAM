#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TITULO 80
#define MAX_AUTOR 50
#define MAX_DE_LIBROS_PERMITIDOS 100

//1.
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

//CASE 1
//Void para saber el género:
void GENERO_LIBRO (const Book * genero_a_imprimir){
    //Void específico para género. Cost Book proporciona los libros de uno en uno sin permitir modificación alguna. genero_a_imprimir genero a imprimir guarda los datos del libro que el comparado en mi función if else.
    if(genero_a_imprimir->genero==0) //Accede al campo género del libro apuntado, si es 0, entonces imprimirá FICTION
        {printf("FICCIÓN");}
    else if(genero_a_imprimir->genero==1)
        {printf("NO FICCIÓN");}
    else if(genero_a_imprimir->genero==2)
        {printf("POESÍA");}
    else if(genero_a_imprimir->genero==3)
        {printf("TEATRO");}
    else if(genero_a_imprimir->genero==4)
        {printf("ENSAYO");}
}
//PRINTF PARA LOS DATOS DEL LIBRO:
void imprimirLibro ( const Book * libro_a_imprimir){
    printf("\t ID: %d \n"
            "\t Título: %s \n"
            "\t Autor: %s \n"
            "\t Precio: %.2f$ \n"
            "\t Género: %d \n"
            "\t Stock: %d \n", 
            libro_a_imprimir->id, libro_a_imprimir->titulo, libro_a_imprimir->autor, libro_a_imprimir->precio, libro_a_imprimir->genero, libro_a_imprimir->stock);
}

//BUCLE PARA RECORRER EL ARRAY E IMPRIMIR LOS DATOS DE LOS LIBROS-> Llamamos al void de imprimirlibro, nuestro bucle for recorre el array y se imprimen los datos ya que Book muestra los datos de los libros de forma individual
void imprimirTodosLosLibros(const Book * catalogo, int totalBooks){
    printf("Lista de todos los libros:\n");
    for (int i = 0; i < totalBooks; i++){
        printf("Libro %d: \n ", i+1);
        imprimirLibro(&catalogo[i]);}//Llama al void de imprimirLibro e imprime los datos
}

//CASE 2
void buscarID(const Book * catalogo, int totalBooks){
    int case2;
        printf("Introduzca el ID del libro: ");
        scanf("%d", &case2);
        
        if(case2 < 0 || case2>40){
            printf("ERROR.\n");}
        else{
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].id == case2){//Bucle que recorre el catálogo en el ID,
                    printf("Libro encontrado con el ID %d:\n", case2);
                    imprimirLibro(&catalogo[i]);
                    break;} //Una vez encuentra el libro, sale de este bucle.
                }//Final del FOR
        }//Final del else 
}//Final del Void

//CASE 3
void modificar( Book * catalogo, int totalBooks){
    int cantidad_nueva;
    int encontrar_ID;
        printf("Ingrese el ID del libro a reabastecer: ");
        scanf(" %d", &encontrar_ID); //Buscamos el ID

        if(encontrar_ID < 0 || encontrar_ID>40){
            printf("ERROR.\n");}
        else{
            //La primera parte del bucle nos busca el libro.
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].id == encontrar_ID){//Bucle que recorre el catálogo en el ID,
                    printf("Libro encontrado con el ID %d:\n", encontrar_ID);
                    imprimirLibro(&catalogo[i]);
            
            //La segunda parte del bucle almacena la cantidad nueva e imprime por pantalla los datos de nuevo con la alteración de la cantidad nueva        
            printf("Cantidad a añadir: ");
                scanf(" %d", &cantidad_nueva);
                if (cantidad_nueva<0){
                    printf("La cantidad ha de ser positiva. \n");
                }else{
                catalogo[i].stock = (cantidad_nueva + catalogo[i].stock);
                imprimirLibro(&catalogo[i]);}
                break;
            } //Final de if
        } //Final de For
    }//Final de Else
}//Final del Void

//CASE 4. buscar_Cat(books, totalBooks);
void buscar_Cat(const Book * catalogo, int totalBooks){
    char respuesta[20]; //Respuesta del usuario para buscar categoría
    int buscador_de_cat;
    printf("Introduzca la categoría (FICCIÓN, NO_FICCIÓN, POESÍA, TEATRO, ENSAYO): ");
    scanf(" %s", respuesta);

//El siguiente bloque compara la respuesta con las categorías, dependiendo del resultado, se mete en un género u otro. Si está fuera de los parámetros de género (==!0), entonces nos saca. Si está dentro, entraremos en un bucle que solo imprimirá por pantalla los libros que pertenezcan a esa categoría.
    printf("Categoría %s:\n", respuesta); 

    if (strcmp(respuesta, "FICCIÓN") == 0){ //==0 -> Es verdadero o igual respuesta y mi valor
        buscador_de_cat = FICTION; //Si la respuesta metida en el terminal por el usuario coincide, en la variable buscador_de_cat se guarda FICTION, después, en el bucle se imprime solo aquellos resultados que coincidan con FICTION.
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].genero == buscador_de_cat){
                        printf("Libro: %d \n", i+1); //Posición del libro el el array.
                        imprimirLibro(&catalogo[i]);}}} //Impresión de datos

    else if(strcmp(respuesta, "NO_FICCIÓN") == 0){
        buscador_de_cat = NON_FICTION;
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].genero == buscador_de_cat){
                        printf("Libro: %d \n", i+1);
                        imprimirLibro(&catalogo[i]);}}}

    else if(strcmp(respuesta, "POESÍA") == 0){
        buscador_de_cat = POETRY;
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].genero == buscador_de_cat){
                        printf("Libro: %d \n", i+1);
                        imprimirLibro(&catalogo[i]);}}}

    else if(strcmp(respuesta, "TEATRO") == 0){
        buscador_de_cat = THEATER;
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].genero == buscador_de_cat){
                        printf("Libro: %d \n", i+1);
                        imprimirLibro(&catalogo[i]);}}}

    else if(strcmp(respuesta, "ENSAYO") == 0){
        buscador_de_cat = ESSAY;
            for (int i = 0; i < totalBooks; i++){
                if (catalogo[i].genero == buscador_de_cat){
                        printf("Libro: %d \n", i+1);
                        imprimirLibro(&catalogo[i]);}}}

    else if(strcmp(respuesta, "FICCIÓN") || strcmp(respuesta, "NO_FICCIÓN") || strcmp(respuesta, "POESÍA") || strcmp(respuesta, "TEATRO") || strcmp(respuesta, "ENSAYO") != 0){
        printf("No existe esa categoría.\n");}

}//Fin del VOID

//CASE 5. Bucar libro por autor mostrar_Autor(Book, totalBooks);
void mostrar_Autor(const Book * catalogo, int totalBooks){
    char NOMBRE_AUTOR[MAX_AUTOR]; //Respuesta del usuario para buscar el autor
    
    printf("Introduzca el nombre del autor: ");
    fgets(NOMBRE_AUTOR, MAX_AUTOR, stdin);
    
    printf("Libros de autor '%s':\n", NOMBRE_AUTOR);
    int encontrado = 0;
    for (int i = 0; i < totalBooks; i++) {
        if (strcmp(catalogo[i].autor, NOMBRE_AUTOR) == 0) {  // Comparamos el autor con el ingresado
            printf("Libro encontrado: %s\n", catalogo[i].titulo);
            encontrado = 1;
        }
    }
    
    if (!encontrado) {
        printf("No se encontraron libros del autor '%s'.\n", NOMBRE_AUTOR);
    }
}

int main(){

//2.
     Book books[40] = {
        {1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10},
        {2, "1984", "George Orwell", 12.49, FICTION, 5},
        {3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8},
        {4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12},
        {5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7},
        {6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9},
        {7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6},
        {8, "The Odyssey", "Homer", 17.49, FICTION, 4},
        {9, "Ulysses", "James Joyce", 25.00, FICTION, 2},
        {10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3},
        {11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11},
        {12, "The Iliad", "Homer", 18.50, FICTION, 7},
        {13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15},
        {14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20},
        {15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13},
        {16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6},
        {17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5},
        {18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8},
        {19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4},
        {20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14},
        {21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6},
        {22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8},
        {23, "Othello", "William Shakespeare", 10.99, THEATER, 7},
        {24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5},
        {25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4},
        {26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10},
        {27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9},
        {28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3},
        {29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15},
        {30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10},
        {31, "Paradise Lost", "John Milton", 12.00, POETRY, 7},
        {32, "Beowulf", "Anonymous", 15.00, POETRY, 5},
        {33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4},
        {34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9},
        {35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11},
        {36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8},
        {37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5},
        {38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12},
        {39, "The Republic", "Plato", 16.00, ESSAY, 6},
        {40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10}
    };

//3.
int eleccion;
printf("Determine que quiere hacer: \n"
       "\t 1. Mostrar todos los libros.\n"
       "\t 2. Buscar libro por su ID.\n"
       "\t 3. Modificar el stock de un libro.\n"
       "\t 4. Mostrar los libros según su categoría.\n"
       "\t 5. Mostrar los libros según su autor. \n"
       "\t 6. Salir del prgrama. \n"
       "Opción: ");
scanf("%d", &eleccion);

int totalBooks = 40;

switch (eleccion){
		case 1: //Mostrar todos los libros.
            imprimirTodosLosLibros (books, totalBooks);
		break;

		case 2: //Mostrar el libro que coincida con el ID o un mensaje de error.
            buscarID(books, totalBooks);
		break;

		case 3://Aumentar el stock del libro ID en la cantidad dada como argumento e imprimir la información pertinente.
            modificar(books, totalBooks);
		break;

		case 4://Mostrar todos los libros de la categoría dada como argumento.
            buscar_Cat(books, totalBooks);
        break;
            
		case 5:
            mostrar_Autor(books, totalBooks);
        break;

		case 6:
			printf("Saliendo del programa.\n");
		break;

		default:
			printf("ERROR");
}

return 0;
}