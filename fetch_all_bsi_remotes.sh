#!/bin/bash

# Lista de diretórios
DIRECTORIES=(
    "Assembly-MIPS"
    "aws-dynamodb-demo"
    "flutter_movies_app"
    "lol-champions"
    "POO-I"
    "prog-web"
    "projeto-admin-bd"
    "sdtp-redes"
    "SIG-Finance"
)

# Loop para cada diretório
for dir in "${DIRECTORIES[@]}"; do
    # Navegar até o diretório
    # cd "$dir"
    
    # Excluir o diretório .git
    git rm --cached "$dir"
    
    # Voltar para o diretório anterior
    cd ..
done
