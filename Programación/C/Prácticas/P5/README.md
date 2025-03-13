# Práctica 5

Entregables:

- Por parejas, en un repositorio nuevo creado para compartir código. Habrá alguna práctica más compartida.
- Un zip que comprima una carpeta llamada P5_NombreApellido_NombreApellido.zip
- La carpeta deberá contener:
    - Una carpeta: `Ejercicios`
        - Dentro de la carpeta ejercicios: ejercicio1.c y ejercicio2.c
    - Una carpeta `Prácticas`
        - Dentro de la carpeta prácticas: practica5_1.c, practica5_2.c,practica5_3.c
    - Un archivo `repo.txt` que solo debe contener el enlace al repositorio de git compartido.
- Recuerda: los comentarios no son opcionales. Conforme vayas programando, ve escribiendo comentarios.
- La calificación no será la misma para los 2. Será una cantidad a repartir entre las 2 personas.
- Seréis sometidos a un examen de prácticas que requiera, entre otras cosas, que hagas una modificación sobre el código entregado. Podrá tener parte oral individual.
- Fecha de entrega: 11/11.

## Ejercicios

### Ejercicio 1: Arrays multidimensionales:

---

Eres parte del equipo de programación de una gran empresa que gestiona el inventario mundial de productos electrónicos. La empresa tiene almacenes en múltiples **continentes**, cada continente tiene varias **sedes** de almacenes, cada sede almacena **categorías** de productos (por ejemplo, televisores, teléfonos, ordenadores), cada categoría contiene **modelos** específicos y cada modelo tiene diferentes **lotes**.

Tu tarea es modelar esta estructura con un array de cinco dimensiones que permita registrar la cantidad de unidades en cada lote de un modelo específico en la sede de un continente.

1. **Continente**: La empresa opera en 2 continentes (América y Europa).
2. **Sedes**: Cada continente tiene 3 sedes de almacenamiento.
3. **Categorías**: Cada sede almacena 4 categorías de productos (televisores, teléfonos, ordenadores y electrodomésticos).
4. **Modelos**: Cada categoría tiene 5 modelos específicos.
5. **Lotes**: Cada modelo tiene 10 lotes diferentes.

**Instrucciones**:

1. Define un array de cinco dimensiones `inventario` para almacenar la cantidad de unidades en cada lote del inventario.
    - `inventario[continente][sede][categoría][modelo][lote]`
2. Asigna algunos valores al array para simular cantidades de inventario, por ejemplo:
    - En América, en la primera sede, en la categoría de televisores, el modelo 0, en el lote 0, hay 50 unidades.
    - En Europa, en la segunda sede, en la categoría de teléfonos, el modelo 3, en el lote 2, hay 120 unidades.
3. Finalmente, muestra por pantalla la cantidad de unidades en al menos cinco posiciones distintas del array.

---

### Ejercicio 2:

**Mostrar palabras que no contienen una letra específica**:

- **Descripción**: Dada una lista de palabras, recorre cada una y utiliza `continue` para saltar las palabras que contienen la letra 'a'. Imprime solo las palabras que no tienen la letra 'a'.
- **Punto clave**: Uso de `continue` para omitir elementos basados en una condición específica.

# Prácticas

### Práctica 1: Análisis de Temperaturas en una Semana

Desarrolla un programa en C que permita almacenar y analizar las temperaturas de una semana completa. El programa deberá realizar las siguientes funciones:

1. **Ingreso de Datos**: Solicita al usuario que ingrese la temperatura promedio de cada día de la semana (lunes a domingo) y almacénala en un array de tipo `float`.
2. **Cálculo de la Temperatura Promedio Semanal**: Calcula la temperatura promedio de la semana utilizando un bucle `for` y muestra el resultado en pantalla.
3. **Detección de la Temperatura Máxima y Mínima**: Encuentra y muestra en pantalla la temperatura más alta y la más baja de la semana, indicando a qué día corresponde cada una.
4. **Contador de Días con Temperaturas Superiores a la Media**: Recorre el array de temperaturas para contar cuántos días tienen una temperatura superior al promedio semanal y muestra el resultado.
5. **Listado de Días con Temperaturas por Debajo del Promedio**: Utilizando un bucle `for`, muestra los días que tuvieron una temperatura inferior al promedio semanal, indicando la temperatura de cada uno.

**Ejemplo de Salida Esperada**:

```
Temperatura promedio de la semana: 23.5°C
Temperatura máxima: 30.0°C el día miércoles
Temperatura mínima: 15.0°C el día domingo
Número de días con temperaturas superiores al promedio: 3
Días con temperaturas por debajo del promedio:
Lunes: 22.0°C
Viernes: 20.5°C
Domingo: 15.0°C
```

---

### Práctica 2: Análisis Estadístico de Notas de Estudiantes

Escribe un programa en C para calcular el rendimiento académico de un grupo de estudiantes. El programa deberá funcionar de la siguiente manera:

1. **Ingreso de Notas**: Pide al usuario que ingrese la cantidad de estudiantes (un número entero positivo) y luego, usando un bucle `for`, permite que el usuario ingrese la nota final de cada estudiante, almacenándolas en un array de tipo `double`.
2. **Cálculo del Promedio**: Calcula la nota promedio del grupo. Imprime el resultado con dos decimales.
3. **Número de Aprobados y Suspensos**: Define que la nota mínima para aprobar es 5.0 (`#define`). Recorre el array con un bucle `for` para contar cuántos estudiantes han aprobado y cuántos han suspendido, mostrando el total de cada uno.
4. **Nota Máxima y Nota Mínima**: Identifica la nota más alta y la más baja en el array y muestra ambos valores junto con su posición en el listado (es decir, el índice del array correspondiente al estudiante).
5. **Listado de Notas por Encima del Promedio**: Muestra una lista con las notas que están por encima de la nota promedio del grupo.

**Ejemplo de Salida Esperada**:

```
Promedio de notas: 6.87
Número de estudiantes aprobados: 8
Número de estudiantes suspendidos: 2
Nota máxima: 9.5 (Estudiante en la posición 3)
Nota mínima: 4.0 (Estudiante en la posición 7)
Notas por encima del promedio:
Estudiante en la posición 1: 7.8
Estudiante en la posición 3: 9.5
Estudiante en la posición 6: 8.2
```

---

### Práctica 3: Gestión de Inventario de una Tienda

Desarrolla un programa en C que permita gestionar el inventario de una tienda de productos, cada uno con un nombre y una cantidad en stock. El programa debe realizar las siguientes operaciones:

1. **Ingreso de Productos y Cantidades**: Solicita al usuario que ingrese el número total de productos que desea gestionar (máximo 10). A continuación, pide el nombre de cada producto (máximo 20 caracteres) y su cantidad en stock, almacenándolos en dos arrays (un array de `char[]` para los nombres y un array de `int` para las cantidades).
2. **Mostrar Inventario Completo**: Muestra en pantalla el nombre de cada producto junto a su cantidad en stock.
3. **Reabastecimiento de Productos**: Pregunta al usuario si desea reabastecer algún producto. Si responde afirmativamente, permite que ingrese el nombre del producto y la cantidad a añadir, y actualiza el inventario. Realiza esta acción en un bucle hasta que el usuario decida no reabastecer más productos.
4. **Cálculo de Productos en Baja Existencia**: Define que un producto está en baja existencia si tiene menos de 5 unidades en stock. Utilizando un bucle `for`, muestra todos los productos en baja existencia.
5. **Buscar un Producto por Nombre**: Permite que el usuario ingrese el nombre de un producto y, usando un bucle `for`, busca el producto en el array. Si lo encuentra, muestra su cantidad en stock; si no, indica que no existe.
6. **Meta de stock diario**: Solicita al usuario que ingrese una cantidad de ventas diaria. Recorre el array y muestra el primer día en que se alcanzó la meta. Utiliza `break` para salir del bucle cuando se encuentra el primer día que cumple con la meta.

**Ejemplo de Salida Esperada**:

```
Inventario Completo:
Producto 1: Manzanas - 12 unidades
Producto 2: Naranjas - 3 unidades
Producto 3: Leche - 8 unidades
Producto 4: Huevos - 4 unidades

¿Desea reabastecer algún producto? (sí/no): sí
Ingrese el nombre del producto: Naranjas
Cantidad a añadir: 5

Productos en baja existencia:
Naranjas - 8 unidades
Huevos - 4 unidades

Ingrese el nombre del producto a buscar: Leche
Cantidad en stock: 8 unidades
```

---

Estas prácticas ayudan a reforzar el uso de bucles y arrays, así como las estructuras de control de flujo en C sin necesidad de manejar punteros, manteniendo el enfoque en variables básicas.
