
--SET FOREIGN_KEY_CHECKS=0; -- Desabilitar Foreign Keys

drop table if exists atividade cascade;
drop table if exists projeto cascade;
drop table if exists departamento cascade;
drop table if exists funcionario cascade;

--SET FOREIGN_KEY_CHECKS=1; -- Habilitando Foreign Keys

CREATE TABLE funcionario (
codigo SERIAL PRIMARY KEY,
nome varchar(50),
sexo char(1),
dtNasc date,
salario decimal(10,2),
codSupervisor int,
codDepto int,
FOREIGN KEY (codSupervisor) REFERENCES funcionario(codigo) on delete set null on update cascade
);

CREATE TABLE departamento (
codigo SERIAL PRIMARY KEY,
sigla varchar(10),
descricao varchar(50),
codGerente int,
UNIQUE (sigla),
FOREIGN KEY (codGerente) REFERENCES funcionario(codigo) on delete set null on update cascade
);

CREATE TABLE projeto (
codigo SERIAL PRIMARY KEY,
nome varchar(50),
descricao varchar(250),
codResponsavel int,
codDepto int,
dataInicio date,
dataFim date,
UNIQUE (nome),
FOREIGN KEY (codResponsavel) REFERENCES funcionario(codigo) on delete set null on update cascade,
FOREIGN KEY (codDepto) REFERENCES departamento(codigo) on delete set null on update cascade
);

CREATE TABLE atividade (
codigo SERIAL PRIMARY KEY,
descricao varchar(250),
codProjeto int,
dataInicio date,
dataFim date,
FOREIGN KEY (codProjeto) REFERENCES projeto(codigo) on delete set null on update cascade
);

ALTER TABLE funcionario ADD CONSTRAINT funcDeptoFK FOREIGN KEY (codDepto) REFERENCES departamento(codigo) on delete set null on update cascade;
