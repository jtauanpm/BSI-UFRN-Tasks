# aws-dynamodb-demo
Repository created for the demonstration of the Amazon DynamoDB database in a project for the discipline of project and database administration in the course of BSI - UFRN

## Tecnologias utilizadas 

* ![Python](https://img.shields.io/badge/Python-3e7aaa?style=for-the-badge&logo=python&logoColor=white)
* ![DynamoDB](https://img.shields.io/badge/DynamoDB-1a476f?&style=for-the-badge&logo=amazonaws&logoColor=white)
* ![Docker](https://img.shields.io/badge/Docker-2496ed?style=for-the-badge&logo=docker&logoColor=white)

## Instalação

Clone o projeto:
```console
git clone git@github.com:jtauanpm/aws-dynamodb-demo.git
```

Rode o docker compose:
```console
docker compose up -d
```

Instale as dependências da aplicação:
```console
pip install -r requirements.txt
```

Configure o aws na sua máquina:
```console
aws configure

AWS Access Key ID: "yourAccessKeyId"
AWS Secret Access Key: "yourAccessKey"
Default region name: "yourRegionName"
Default output format: "json"
```

Agora basta rodar a aplicação:
```console
python3 config/db.py
python3 server.py
```