#!/bin/bash

# Comprobación: el usuario puede acceder a este script, es decir, eres sysadmin
if ! groups "$USER" | grep -q '\bsysadmin\b'; then
    echo "ACCESO DENEGADO"
    exit 1
fi

# CREACIÓN DE USUARIO Y ASIGNACIÓN DE GRUPO
crear_usuario() {
    echo "NOMBRE DEL USUARIO:"
    read usuario # read toma lo que escribe el usuario en el terminal y lo guarda en la variable de usuario

    echo "SELECCIONAR GRUPO (sysadmin, devs, office):"
    read grupo # read toma lo que escribe el usuario en el terminal y lo guarda en la variable de grupo

    # Verificamos si el grupo existe
    if ! getent group "$grupo" &>/dev/null; then
        echo "El grupo '$grupo' no existe."
        return
    fi

    # Crear el usuario
    sudo useradd -m -G "$grupo" "$usuario"
    echo "Usuario '$usuario' creado y asignado al grupo '$grupo'."
}

# ELIMINAR USUARIOS
eliminar_usuario() {
    echo "Introduzca el nombre del usuario a eliminar:"
    read usuario

    # Verificar si el usuario existe
    if id "$usuario" &>/dev/null; then #id nos proporciona la información del usuario, si existe, se borra con 'sudo userdel -r "$usuario"', si no se encuentra, simplemente mostramos un mensaje de error.
        sudo userdel -r "$usuario" # read toma lo que escribe el usuario en el terminal y lo guarda en la variable de usuario
        echo "Usuario '$usuario' eliminado."
    else
        echo "El usuario '$usuario' no existe."
    fi
}

# LISTA DE USUARIOS
listar_usuarios() {
    echo "Usuarios del sistema:"
    cut -d: -f1 /etc/passwd
    #Como hemos hecho antes para comprobar los grupos que existen en este sistema, hacemos la misma operación para ver los usuarios (cut). -d: hace que se corte la línea de datos en los ':', si no, se mostraría por pantalla una línea de datos más larga. '-f1' indica que queremos quedarmos con la primera mitad a partir de ':', si quisieramos la segunda parte, pondríamos '-f2'
}

# Menú interactivo

    echo "Gestión de Usuarios - Admin Menu"
    echo "1. Crear usuario"
    echo "2. Eliminar usuario"
    echo "3. Listar usuarios"
    echo "4. Salir"
    echo "Elija una opción (1-4):"
    read opcion

    case $opcion in
        1)
            crear_usuario
            ;;
        2)
            eliminar_usuario
            ;;
        3)
            listar_usuarios
            ;;
        4)
            echo "Saliendo..."
            exit 0
            ;;
        *)
            echo "Opción no válida. Por favor, elige de nuevo."
            ;; 

    esac