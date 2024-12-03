#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_ID 10
#define MAX_TITULO 80
#define MAX_AUTOR 50

//1.
typedef enum{
	FICTION,
	NON_FICTION,
	POETRY,
	THEATER,
	ESSAY
} generos;

typedef struct{
	int id[MAX_ID];
	char titulo[MAX_TITULO];
	char autor[MAX_AUTOR];
	float precio;
	generos genero;
	int stock;
} Book;
//CASE 1
//Imprime los datos del libro
void imprimirLibro ( Book * library){
	printf("Lista de todos los libros: \n ");
    printf("\t ID: %d. \n", libro_a_imprimir->id); //También se puede poner *(libro_a_imprimir).id
    printf("\t Título: %s. \n", libro_a_imprimir->titulo);
    printf("\t Autor: %s. \n", libro_a_imprimir->autor);
    printf("\t Precio: %f. \n", libro_a_imprimir->precio);
    printf("\t Género: %d. \n", libro_a_imprimir->genero);
    printf("\t Stock: %d. \n", libro_a_imprimir->stock);
}

//CASE 2 
// void printAllBooks(Book * catalog){
//    for(int i = 0; i<sizeof(catalog); i++){
//        printfBook (solo un libro);
//    }
// }




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


switch (eleccion){
		case 1:
            imprimirLibro (&books);
		break;

		case 2:
		break;

		case 3:
		break;

		case 4:
		break;

		case 5:
		break;

		case 6:
			printf("Saliendo del programa.\n");
		break;

		default:
			printf("ERROR");
}

return 0;
}
