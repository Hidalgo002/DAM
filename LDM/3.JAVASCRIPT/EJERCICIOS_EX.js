/*1. Codificador de texto.Utiliza un campo input para que el usuario introduzca el texto a
codificar, el texto se debe codificar inmediatamente según escribe el usuario. Las
letras se codifican con el número de la posición que ocupan en el abecedario
español, por ejemplo si el usuario escribe ABC o abc (no diferencia entre mayúsculas
y minúsculas) debe aparecer debajo resultado:123
 */
const abecedario = 'abcdefghijklmnñopqrstuvwxyz';

function codificarTexto(texto) {
  texto = texto.toLowerCase();
  let codificado = '';

  for (let char of texto) {
    const index = abecedario.indexOf(char);
    if (index !== -1) {
      codificado += (index + 1);
    }
  }

  return codificado;
}

function manejarEntrada(inputElement, outputElement) {
  inputElement.addEventListener('keydown', (event) => {
    if (event.key === 'Enter') {
      event.preventDefault(); // evita comportamiento por defecto
      const texto = inputElement.value;
      const resultado = codificarTexto(texto);
      outputElement.textContent = resultado;
    }
  });
}

function main() {
  const input = document.getElementById('textInput');
  const output = document.getElementById('output');

  if (input && output) {
    manejarEntrada(input, output);
  } else {
    console.error("No se encontraron los elementos de entrada o salida.");
  }
}

  document.addEventListener('DOMContentLoaded', main);