#!/bin/bash

# Email y usuario de GitHub
EMAIL="vhidalgodominguez@gmail.com"
GITHUB_USER="Hidalgo002"
REPO_NAME="DAM"
REPO_URL="git@github.com:$GITHUB_USER/$REPO_NAME.git"

# Paso 1: Generar clave SSH (si no existe ya)
echo "Verificando si tienes una clave SSH..."

if [ ! -f "$HOME/.ssh/id_ed25519" ]; then
  echo "Generando una nueva clave SSH..."
  ssh-keygen -t ed25519 -C "$EMAIL" -f "$HOME/.ssh/id_ed25519" -N ""
else
  echo "Ya tienes una clave SSH existente."
fi

# Paso 2: Iniciar el agente SSH y añadir la clave
echo "Iniciando el agente SSH..."
eval "$(ssh-agent -s)"
ssh-add "$HOME/.ssh/id_ed25519"

# Paso 3: Copiar la clave pública SSH al portapapeles (en sistemas Unix puedes usar 'pbcopy' o 'xclip', en Windows depende de tu entorno)
if command -v pbcopy >/dev/null; then
  cat "$HOME/.ssh/id_ed25519.pub" | pbcopy
  echo "Tu clave pública SSH ha sido copiada al portapapeles. Pégala en GitHub."
elif command -v xclip >/dev/null; then
  cat "$HOME/.ssh/id_ed25519.pub" | xclip -selection clipboard
  echo "Tu clave pública SSH ha sido copiada al portapapeles. Pégala en GitHub."
else
  echo "No pude copiar la clave pública. Aquí está tu clave pública para que la copies manualmente:"
  cat "$HOME/.ssh/id_ed25519.pub"
fi

# Paso 4: Agregar la clave pública a GitHub
echo "Agrega tu clave pública SSH a GitHub siguiendo estos pasos:"
echo "1. Ve a https://github.com/settings/keys"
echo "2. Haz clic en 'New SSH Key'"
echo "3. Pega tu clave pública en el campo 'Key' y asigna un nombre (por ejemplo, 'Mi clave SSH')"
echo "4. Haz clic en 'Add SSH Key'"

# Paso 5: Cambiar la URL remota de tu repositorio a SSH
echo "Cambiando la URL remota de tu repositorio a SSH..."
git remote set-url origin $REPO_URL

echo "¡Listo! Ahora tu repositorio usa SSH en lugar de HTTPS."


